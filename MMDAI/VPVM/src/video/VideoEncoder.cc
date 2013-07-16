/**

 Copyright (c) 2010-2013  hkrn

 All rights reserved.

 Redistribution and use in source and binary forms, with or
 without modification, are permitted provided that the following
 conditions are met:

 - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 - Redistributions in binary form must reproduce the above
   copyright notice, this list of conditions and the following
   disclaimer in the documentation and/or other materials provided
   with the distribution.
 - Neither the name of the MMDAI project team nor the names of
   its contributors may be used to endorse or promote products
   derived from this software without specific prior written
   permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.

*/

#include "VideoEncoder.h"

#include <QtCore/QtCore>
#include <QtGui/QtGui>

namespace {

using namespace vpvm;

static int UIAVCodecLockCallback(void ** /* mutex */, AVLockOp op)
{
    /*
     * Video::initialize の内部で行なっている av_lockmgr_register で必要
     * これがないとスレッドセーフではないことが明記されている avcodec_open で失敗する
     */
    static QMutex mutex;
    switch (op) {
    case AV_LOCK_CREATE:
    default:
        return 0;
    case AV_LOCK_OBTAIN:
        return mutex.tryLock() ? 0 : -1;
    case AV_LOCK_RELEASE:
    case AV_LOCK_DESTROY:
        mutex.unlock();
        return 0;
    }
}

static void UIAddUtVideoCodecs(const QString &extension, QList<IVideoEncoder::Setting> &settings)
{
    /* 現在出力が透過に対応していないため */
    // settings << IVideoEncoder::Setting("utvideo", extension, "utra", QString("UtVideo codec RGBA format (.%1)").arg(extension));
    settings << IVideoEncoder::Setting("utvideo", extension, "utrg", QString("UtVideo codec RGB format (.%1)").arg(extension));
    settings << IVideoEncoder::Setting("utvideo", extension, "uty2", QString("UtVideo codec YUV422 format (.%1)").arg(extension));
    settings << IVideoEncoder::Setting("utvideo", extension, "uty0", QString("UtVideo codec YUV420 format (.%1)").arg(extension));
}

struct AVFormatContextCleaner
{
    static void cleanup(AVFormatContext *context) {
        if (context) {
            const int nstreams = context->nb_streams;
            for (int i = 0; i < nstreams; i++) {
                AVStream *stream = context->streams[i];
                av_freep(&stream->codec);
                av_freep(&stream);
            }
            if (!(context->flags & AVFMT_NOFILE) && context->pb)
                avio_close(context->pb);
            av_free(context);
        }
    }
};

struct AVStreamCleaner
{
    static void cleanup(AVStream *stream) {
        if (stream)
            avcodec_close(stream->codec);
    }
};

struct AVFrameCleaner
{
    static void cleanup(AVFrame *frame) {
        if (frame) {
            avpicture_free(reinterpret_cast<AVPicture *>(frame));
            av_free(frame);
        }
    }
};

struct SWScaleContextCleaner
{
    static void cleanup(struct SwsContext *context) {
        if (context)
            sws_freeContext(context);
    }
};

static bool g_initialized = false;

}

namespace vpvm
{

bool VideoEncoder::isSupported()
{
    return true;
}

void VideoEncoder::initializeEncoder()
{
    if (!g_initialized) {
        avcodec_register_all();
        av_register_all();
        av_lockmgr_register(UIAVCodecLockCallback);
        g_initialized = true;
    }
}

VideoEncoder::VideoEncoder(QObject *parent)
    : QThread(parent),
      m_audioCodec(AV_CODEC_ID_PCM_S16LE),
      m_videoCodec(AV_CODEC_ID_PNG),
      m_videoPixelFormat(AV_PIX_FMT_RGB24),
      m_fps(0),
      m_videoBitrate(0),
      m_audioBitrate(0),
      m_audioSampleRate(0),
      m_running(false)
{
    initializeEncoder();
}

VideoEncoder::~VideoEncoder()
{
    m_images.clear();
    m_videoBitrate = 0;
    m_audioBitrate = 0;
    m_audioSampleRate = 0;
    m_running = false;
}

int64_t VideoEncoder::sizeofVideoFrameQueue() const
{
    QMutexLocker locker(&m_videoQueueMutex); Q_UNUSED(locker);
    int size = m_images.size();
    return size;
}

int64_t VideoEncoder::sizeofAudioSampleQueue() const
{
    QMutexLocker locker(&m_audioBufferMutex); Q_UNUSED(locker);
    int size = m_audioBuffer.size();
    return size;
}

void VideoEncoder::startSession()
{
    m_running = true;
    start();
}

void VideoEncoder::stopSession()
{
    m_running = false;
}

void VideoEncoder::waitUntilComplete()
{
    stopSession();
    wait();
}

void VideoEncoder::setFileName(const QString &value)
{
    m_filename = value;
}

void VideoEncoder::setSceneFPS(int value)
{
    m_fps = value;
}

void VideoEncoder::setSceneSize(const QSize &value)
{
    m_size = value;
}

QList<IVideoEncoder::Setting> VideoEncoder::availableAudioSettings() const
{
    QList<Setting> settings;
    settings << Setting("pcm", "wav", "pcm", "PCM raw audio");
    return settings;
}

void VideoEncoder::selectAudioSetting(const Setting & /* value */)
{
    m_audioCodec = AV_CODEC_ID_PCM_S16LE;
}

QList<IVideoEncoder::Setting> VideoEncoder::availableVideoSettings() const
{
    QList<Setting> settings;
    settings << Setting("png", "mov", "png", "PNG codec RGB format (.mov)");
    UIAddUtVideoCodecs("mov", settings);
    UIAddUtVideoCodecs("avi", settings);
    return settings;
}

void VideoEncoder::selectVideoSetting(const Setting &value)
{
    const QString &codec = value.codec;
    if (codec.startsWith("ut")) {
        m_videoCodec = AV_CODEC_ID_UTVIDEO;
        if (codec.endsWith("rg")) {
            m_videoPixelFormat = AV_PIX_FMT_RGB24;
        }
        else if (codec.endsWith("ra")) {
            m_videoPixelFormat = AV_PIX_FMT_RGBA;
        }
        else if (codec.endsWith("y0")) {
            m_videoPixelFormat = AV_PIX_FMT_YUV420P;
        }
        else if (codec.endsWith("y2")) {
            m_videoPixelFormat = AV_PIX_FMT_YUV422P;
        }
    }
    else {
        m_videoCodec = AV_CODEC_ID_PNG;
        m_videoPixelFormat = AV_PIX_FMT_RGB24;
    }
}

void VideoEncoder::run()
{
    AVPixelFormat sourcePixelFormat = AV_PIX_FMT_RGBA;
    AVOutputFormat *videoOutputFormat = CreateVideoFormat(m_filename);
    QScopedPointer<AVFrame, AVFrameCleaner> videoFrame, tmpFrame;
    QScopedPointer<AVFormatContext, AVFormatContextCleaner> videoFormatContext(
                CreateVideoFormatContext(videoOutputFormat, m_filename));
    QScopedPointer<AVStream, AVStreamCleaner> audioStream, videoStream;
    QScopedPointer<struct SwsContext, SWScaleContextCleaner> scaleContext;
    QScopedArrayPointer<uint8_t> encodedAudioFrameBuffer, encodedVideoFrameBuffer;
    /* 動画と音声のフォーマット(AVFormatContext)をまず先に作成し、それからコーデック(AVCodecContext)を作成する */
    if (m_audioBitrate > 0 && m_audioSampleRate > 0) {
        audioStream.reset(OpenAudioStream(videoFormatContext.data(),
                                          videoOutputFormat,
                                          m_audioCodec,
                                          m_audioBitrate,
                                          m_audioSampleRate));
    }
    videoStream.reset(OpenVideoStream(videoFormatContext.data(),
                                      videoOutputFormat,
                                      m_videoCodec,
                                      m_videoPixelFormat,
                                      m_size,
                                      m_videoBitrate,
                                      m_fps));
    /* エンコード用のフレームを確保 */
    AVCodecContext *audioCodec = 0;
    int encodedAudioFrameBufferSize = 0;
    if (audioStream) {
        audioCodec = audioStream->codec;
        encodedAudioFrameBufferSize = audioCodec->sample_rate
                * audioCodec->frame_size
                * audioCodec->channels
                * av_get_bytes_per_sample(audioCodec->sample_fmt);
        encodedAudioFrameBuffer.reset(new uint8_t[encodedAudioFrameBufferSize]);
    }
    int width = m_size.width(), height = m_size.height();
    int encodedVideoFrameBufferSize = width * height * 4;
    encodedVideoFrameBuffer.reset(new uint8_t[encodedVideoFrameBufferSize]);
    /* 書き出し準備を行う。ファイルなので常に true になる */
    if (!(videoOutputFormat->flags & AVFMT_NOFILE)) {
        avio_open(&videoFormatContext->pb, m_filename.toLocal8Bit().constData(), AVIO_FLAG_WRITE);
    }
    /* libswscale の初期化。ピクセルのフォーマットが互いに異なるので、常に true になる */
    if (sourcePixelFormat != m_videoPixelFormat) {
        scaleContext.reset(sws_getContext(width, height, sourcePixelFormat,
                                          width, height, m_videoPixelFormat,
                                          SWS_BICUBIC, 0, 0, 0));
    }
    /* フレームを作成。2つあるのは上の実際のフレームと libswscale でスケールするための仮フレームがあるため */
    videoFrame.reset(CreateVideoFrame(m_size, m_videoPixelFormat));
    tmpFrame.reset(CreateVideoFrame(m_size, sourcePixelFormat));
    avformat_write_header(videoFormatContext.data(), 0);
    bool remainQueue = true;
    QImage image;
    QByteArray bytes;
    /* stop() で m_running が false になるが、キューが全て空になるまで終了しない */
    int64_t sizeofEncodedVideoFrame = 0, sizeofEncodedAudioSamples = 0;
    while (m_running || remainQueue) {
        double audioPTS = ComputePresentTimeStamp(audioStream.data());
        double videoPTS = ComputePresentTimeStamp(videoStream.data());
        /* 音声バッファが残っている */
        if (audioCodec && audioPTS < videoPTS && sizeofAudioSampleQueue() > encodedAudioFrameBufferSize) {
            /* 音声フレーム取り出し */
            dequeueAudioSamples(bytes, encodedAudioFrameBufferSize);
            /* 音声フレーム書き出し */
            WriteAudioFrame(videoFormatContext.data(),
                            audioStream.data(),
                            reinterpret_cast<const int16_t *>(bytes.constData()),
                            encodedAudioFrameBuffer.data(),
                            encodedAudioFrameBufferSize);
            sizeofEncodedAudioSamples++;
        }
        /* 画像キューが残っている */
        else if (sizeofVideoFrameQueue() > 0) {
            /* キューから画像取り出し */
            dequeueVideoFrame(image);
            /* 空フレームがきたらエンコードを終了させる */
            if (image.isNull()) {
                remainQueue = false;
                break;
            }
            /* 仮フレームを作成し、そこに画像データを埋める */
            const int w = image.width(), h = image.height();
            uint8_t *data = tmpFrame->data[0];
            int stride = tmpFrame->linesize[0];
            for (int y = 0; y < h; y++) {
                const int ystride = y * stride;
                for (int x = 0; x < w; x++) {
                    int index = ystride + x * 4;
                    const QRgb &rgb = image.pixel(x, y);
                    data[index + 0] = qRed(rgb);
                    data[index + 1] = qGreen(rgb);
                    data[index + 2] = qBlue(rgb);
                    data[index + 3] = qAlpha(rgb);
                }
            }
            /* 画像フレームを指定されたサイズとフォーマットでスケーリング */
            if (scaleContext) {
                sws_scale(scaleContext.data(),
                          tmpFrame->data, tmpFrame->linesize, 0, h,
                          videoFrame->data, videoFrame->linesize);
            }
            /* 画像フレーム書き出し */
            WriteVideoFrame(videoFormatContext.data(),
                            videoStream.data(),
                            scaleContext ? videoFrame.data() : tmpFrame.data(),
                            encodedVideoFrameBuffer.data(),
                            encodedVideoFrameBufferSize);
            sizeofEncodedVideoFrame++;
        }
    }
    av_write_trailer(videoFormatContext.data());
    qDebug("sizeofEncodedVideoFrames = %lld, sizeofEncodedAudioSamples = %lld",
           sizeofEncodedVideoFrame, sizeofEncodedAudioSamples);
}

void VideoEncoder::videoFrameDidQueue(const QImage &image)
{
    QMutexLocker locker(&m_videoQueueMutex); Q_UNUSED(locker);
    m_images.enqueue(image);
}

void VideoEncoder::audioSamplesDidQueue(const QByteArray &bytes)
{
    QMutexLocker locker(&m_audioBufferMutex); Q_UNUSED(locker);
    m_audioBuffer.append(bytes);
}

void VideoEncoder::dequeueVideoFrame(QImage &image)
{
    QMutexLocker locker(&m_videoQueueMutex); Q_UNUSED(locker);
    image = m_images.dequeue();
}

void VideoEncoder::dequeueAudioSamples(QByteArray &bytes, int size)
{
    QMutexLocker locker(&m_audioBufferMutex); Q_UNUSED(locker);
    bytes = m_audioBuffer.remove(0, size);
}

} /* namespace vpvm */
