/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2009-2011  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                2010-2011  hkrn                                    */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the MMDAI project team nor the names of     */
/*   its contributors may be used to endorse or promote products     */
/*   derived from this software without specific prior written       */
/*   permission.                                                     */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

#include "OpenJTalkSpeechEngine.h"

#include <QtCore/QtCore>
#include <vpvl2/vpvl2.h>
#include <portaudio.h>

#include <HTS_engine.h>

#ifdef Q_OS_WIN32
#include <mecab.h>
#include <njd.h>
#include <jpcommon.h>
#include <text2mecab.h>
#include <mecab2njd.h>
#include <njd2jpcommon.h>
#include <njd_set_pronunciation.h>
#include <njd_set_digit.h>
#include <njd_set_accent_phrase.h>
#include <njd_set_accent_type.h>
#include <njd_set_unvoiced_vowel.h>
#include <njd_set_long_vowel.h>
#else
#include <OpenJTalk/mecab.h>
#include <OpenJTalk/njd.h>
#include <OpenJTalk/jpcommon.h>
#include <OpenJTalk/text2mecab.h>
#include <OpenJTalk/mecab2njd.h>
#include <OpenJTalk/njd2jpcommon.h>
#include <OpenJTalk/njd_set_pronunciation.h>
#include <OpenJTalk/njd_set_digit.h>
#include <OpenJTalk/njd_set_accent_phrase.h>
#include <OpenJTalk/njd_set_accent_type.h>
#include <OpenJTalk/njd_set_unvoiced_vowel.h>
#include <OpenJTalk/njd_set_long_vowel.h>
#endif

class OpenJTalkSpeechEngine::PrivateContext : public QObject
{
public:
    static const float kMinLF0Val;
    static const float kHanfTone;
    static const float kMaxHanfTone;
    static const float kMinHanfTone;
    static const float kAlpha;
    static const float kMaxAlpha;
    static const float kMinAlpha;
    static const float kVolume;
    static const float kMaxVolume;
    static const float kMinVolume;
    static const bool kLogGain;
    static const int kGamma = 0;
    static const int kSamplingRate = 48000;
    static const int kFPeriod = 240;
    static const int kMaxFPeriod = 48000;
    static const int kMinFPeriod = 1;

    explicit PrivateContext(QObject *parent = 0);
    ~PrivateContext();

    void loadSetting(const QString &path, const QString &config);
    void loadDictionary(const QString &mecab);
    void setText(const QString &text);
    void setStyle(const QString &style);
    int getDuration() const;
    const QString getPhonemeSequence();
    QByteArray finalize(bool withHeader);

    Mecab m_mecab;
    NJD m_njd;
    JPCommon m_jpcommon;
    HTS_Engine m_engine;
    QList<double> m_weights;
    QList<QString> m_models;
    QHash<QString, int> m_styles;
    int m_duration;
    double m_f0Shift;

    Q_DISABLE_COPY(PrivateContext)
};

const float OpenJTalkSpeechEngine::PrivateContext::kMinLF0Val = log(10.0);
const float OpenJTalkSpeechEngine::PrivateContext::kHanfTone = 0.0;
const float OpenJTalkSpeechEngine::PrivateContext::kMaxHanfTone = 24.0;
const float OpenJTalkSpeechEngine::PrivateContext::kMinHanfTone = -24.0;
const float OpenJTalkSpeechEngine::PrivateContext::kAlpha = 0.55;
const float OpenJTalkSpeechEngine::PrivateContext::kMaxAlpha = 1.0;
const float OpenJTalkSpeechEngine::PrivateContext::kMinAlpha = 0.0;
const float OpenJTalkSpeechEngine::PrivateContext::kVolume = 1.0;
const float OpenJTalkSpeechEngine::PrivateContext::kMaxVolume = 10.0;
const float OpenJTalkSpeechEngine::PrivateContext::kMinVolume = 0.0;
const bool OpenJTalkSpeechEngine::PrivateContext::kLogGain = false;

static int OpenJTalkSpeechGetCount(QTextStream &stream) {
    QString line = stream.readLine();
    int count = line.toInt();
    if (count == 0) {
        do {
            line = stream.readLine();
            count = line.toInt();
            if (count > 0)
                break;
        } while (!line.isNull());
    }
    return count;
}

OpenJTalkSpeechEngine::PrivateContext::PrivateContext(QObject *parent) :
    QObject(parent),
    m_f0Shift(0.0)
{
    Mecab_initialize(&m_mecab);
    NJD_initialize(&m_njd);
    JPCommon_initialize(&m_jpcommon);
    HTS_Engine_initialize(&m_engine, 3);
    HTS_Engine_set_gamma(&m_engine, kGamma);
    HTS_Engine_set_log_gain(&m_engine, kLogGain);
    HTS_Engine_set_sampling_rate(&m_engine, kSamplingRate);
    HTS_Engine_set_fperiod(&m_engine, kFPeriod);
    HTS_Engine_set_alpha(&m_engine, kAlpha);
    HTS_Engine_set_volume(&m_engine, kVolume);
    HTS_Engine_set_audio_buff_size(&m_engine, 0); /* disable direct audio output */
    m_f0Shift = kHanfTone;
}

OpenJTalkSpeechEngine::PrivateContext::~PrivateContext()
{
    Mecab_clear(&m_mecab);
    NJD_clear(&m_njd);
    JPCommon_clear(&m_jpcommon);
    HTS_Engine_clear(&m_engine);
}

void OpenJTalkSpeechEngine::PrivateContext::loadSetting(const QString &path, const QString &config)
{
    QFile file(config);
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        stream.setCodec("Shift-JIS");
        int nmodels = OpenJTalkSpeechGetCount(stream);
        for (int i = 0; i < nmodels; i++) {
            QString model = stream.readLine();
            if (model.isEmpty())
                break;
            model = model.trimmed();
            if (model[0] == '#') {
                i--;
                continue;
            }
            model.replace(QChar(0xa5), QChar('/')).replace(QChar('\\'), QChar('/'));
            m_models.append(path + "/" + model);
        }
        int nstyles = OpenJTalkSpeechGetCount(stream);
        for (int i = 0; i < nstyles; i++) {
            QString style = stream.readLine();
            if (style.isEmpty())
                break;
            style = style.trimmed();
            if (style[0] == '#') {
                i--;
                continue;
            }
            QStringList weights = style.split(QRegExp("\\s"), QString::SkipEmptyParts);
            QString name = weights[0];
            weights.removeFirst();
            int nweights = weights.count();
            int expected = 3 * nmodels + 4;
            if (nweights != expected)
                break;
            m_styles[name] = i;
            for (int j = 0; j < nweights; j++) {
                m_weights.append(weights[j].toDouble());
            }
        }
        file.close();
    }
}

void OpenJTalkSpeechEngine::PrivateContext::loadDictionary(const QString &mecab)
{
    int nmodels = m_models.count();
    if (nmodels == 0)
        return;

    char *dic = strdup(mecab.toUtf8().constData());
    Mecab_load(&m_mecab, dic);
    free(dic);

    char **fn_ws_mcp = static_cast<char **>(calloc(3, sizeof(char *)));
    char **fn_ws_lf0 = static_cast<char **>(calloc(3, sizeof(char *)));
    char **fn_ws_lpf = static_cast<char **>(calloc(1, sizeof(char *)));
    char **fn_ts_dur = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ts_mcp = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ts_lf0 = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ts_lpf = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ms_dur = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ms_mcp = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ms_lf0 = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ms_lpf = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ts_gvm = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ts_gvl = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ms_gvm = static_cast<char **>(calloc(nmodels, sizeof(char *)));
    char **fn_ms_gvl = static_cast<char **>(calloc(nmodels, sizeof(char *)));

    QString model = m_models[0];
    QString mgc1 = model + "/mgc.win1";
    fn_ws_mcp[0] = strdup(mgc1.toUtf8().constData());
    QString mgc2 = model + "/mgc.win2";
    fn_ws_mcp[1] = strdup(mgc2.toUtf8().constData());
    QString mgc3 = model + "/mgc.win3";
    fn_ws_mcp[2] = strdup(mgc3.toUtf8().constData());
    QString lf01 = model + "/lf0.win1";
    fn_ws_lf0[0] = strdup(lf01.toUtf8().constData());
    QString lf02 = model + "/lf0.win2";
    fn_ws_lf0[1] = strdup(lf02.toUtf8().constData());
    QString lf03 = model + "/lf0.win3";
    fn_ws_lf0[2] = strdup(lf03.toUtf8().constData());
    QString lpf = model + "/lpf.win1";
    fn_ws_lpf[0] = strdup(lpf.toUtf8().constData());
    QString gvSwitch = model + "/gv-switch.inf";
    char *fn_gv_switch = strdup(gvSwitch.toUtf8().constData());

    for (int i = 0; i < nmodels; i++) {
        model = m_models[i];
        QString treeDur = model + "/tree-dur.inf";
        fn_ts_dur[i] = strdup(treeDur.toUtf8().constData());
        QString treeMgc = model + "/tree-mgc.inf";
        fn_ts_mcp[i] = strdup(treeMgc.toUtf8().constData());
        QString treeLf0 = model + "/tree-lf0.inf";
        fn_ts_lf0[i] = strdup(treeLf0.toUtf8().constData());
        QString treeLpf = model + "/tree-lpf.inf";
        fn_ts_lpf[i] = strdup(treeLpf.toUtf8().constData());
        QString dur = model + "/dur.pdf";
        fn_ms_dur[i] = strdup(dur.toUtf8().constData());
        QString mgc = model + "/mgc.pdf";
        fn_ms_mcp[i] = strdup(mgc.toUtf8().constData());
        QString lf0 = model + "/lf0.pdf";
        fn_ms_lf0[i] = strdup(lf0.toUtf8().constData());
        QString lpf = model + "/lpf.pdf";
        fn_ms_lpf[i] = strdup(lpf.toUtf8().constData());
        QString treeGvMgc = model + "/tree-gv-mgc.inf";
        fn_ts_gvm[i] = strdup(treeGvMgc.toUtf8().constData());
        QString treeGvLf0 = model + "/tree-gv-lf0.inf";
        fn_ts_gvl[i] = strdup(treeGvLf0.toUtf8().constData());
        QString gvMgc = model + "/gv-mgc.pdf";
        fn_ms_gvm[i] = strdup(gvMgc.toUtf8().constData());
        QString gvLf0 = model + "/gv-lf0.pdf";
        fn_ms_gvl[i] = strdup(gvLf0.toUtf8().constData());
    }

    HTS_Engine_load_duration_from_fn(&m_engine, fn_ms_dur, fn_ts_dur, nmodels);
    HTS_Engine_load_parameter_from_fn(&m_engine, fn_ms_mcp, fn_ts_mcp, fn_ws_mcp, 0, /* FALSE */ 0, 3, nmodels);
    HTS_Engine_load_parameter_from_fn(&m_engine, fn_ms_lf0, fn_ts_lf0, fn_ws_lf0, 1, /* TRUE */  1, 3, nmodels);
    HTS_Engine_load_parameter_from_fn(&m_engine, fn_ms_lpf, fn_ts_lpf, fn_ws_lpf, 2, /* FALSE */ 0, 1, nmodels);
    HTS_Engine_load_gv_from_fn(&m_engine, fn_ms_gvm, fn_ts_gvm, 0, nmodels);
    HTS_Engine_load_gv_from_fn(&m_engine, fn_ms_gvl, fn_ts_gvl, 1, nmodels);
    HTS_Engine_load_gv_switch_from_fn(&m_engine, fn_gv_switch);

    for (int i = 0; i < 3; i++) {
        free(fn_ws_mcp[i]);
        free(fn_ws_lf0[i]);
    }
    for (int i = 0; i < 1; i++) {
        free(fn_ws_lpf[i]);
    }
    free(fn_ws_mcp);
    free(fn_ws_lf0);
    free(fn_ws_lpf);
    free(fn_gv_switch);
    for (int i = 0; i < nmodels; i++) {
        free(fn_ts_dur[i]);
        free(fn_ts_mcp[i]);
        free(fn_ts_lf0[i]);
        free(fn_ts_lpf[i]);
        free(fn_ms_dur[i]);
        free(fn_ms_mcp[i]);
        free(fn_ms_lf0[i]);
        free(fn_ms_lpf[i]);
        free(fn_ts_gvm[i]);
        free(fn_ts_gvl[i]);
        free(fn_ms_gvm[i]);
        free(fn_ms_gvl[i]);
    }
    free(fn_ts_dur);
    free(fn_ts_mcp);
    free(fn_ts_lf0);
    free(fn_ts_lpf);
    free(fn_ms_dur);
    free(fn_ms_mcp);
    free(fn_ms_lf0);
    free(fn_ms_lpf);
    free(fn_ts_gvm);
    free(fn_ts_gvl);
    free(fn_ms_gvm);
    free(fn_ms_gvl);
}

QByteArray OpenJTalkSpeechEngine::PrivateContext::finalize(bool withHeader)
{
    QByteArray ret;
    if (JPCommon_get_label_size(&m_jpcommon) > 2) {
        QBuffer buffer(&ret);
        buffer.open(QBuffer::WriteOnly);
        HTS_Engine_create_gstream(&m_engine);
        HTS_GStreamSet *gss = &m_engine.gss;
        HTS_Global *global = &m_engine.global;
        int nsamples = HTS_GStreamSet_get_total_nsample(gss);
        if (withHeader) {
            int samplingRate = global->sampling_rate;
            char data_01_04[] = { 'R', 'I', 'F', 'F' };
            int data_05_08 = nsamples * sizeof(short) + 36;
            char data_09_12[] = { 'W', 'A', 'V', 'E' };
            char data_13_16[] = { 'f', 'm', 't', ' ' };
            int data_17_20 = 16;
            short data_21_22 = 1;
            short data_23_24 = 1;
            int data_25_28 = samplingRate;
            int data_29_32 = samplingRate * sizeof(short);
            short data_33_34 = sizeof(short);
            short data_35_36 = (short) (sizeof(short) * 8);
            char data_37_40[] = { 'd', 'a', 't', 'a' };
            int data_41_44 = nsamples * sizeof(short);
            buffer.write(reinterpret_cast<const char *>(data_01_04), sizeof(data_01_04));
            buffer.write(reinterpret_cast<const char *>(&data_05_08), sizeof(data_05_08));
            buffer.write(reinterpret_cast<const char *>(data_09_12), sizeof(data_09_12));
            buffer.write(reinterpret_cast<const char *>(data_13_16), sizeof(data_13_16));
            buffer.write(reinterpret_cast<const char *>(&data_17_20), sizeof(data_17_20));
            buffer.write(reinterpret_cast<const char *>(&data_21_22), sizeof(data_21_22));
            buffer.write(reinterpret_cast<const char *>(&data_23_24), sizeof(data_23_24));
            buffer.write(reinterpret_cast<const char *>(&data_25_28), sizeof(data_25_28));
            buffer.write(reinterpret_cast<const char *>(&data_29_32), sizeof(data_29_32));
            buffer.write(reinterpret_cast<const char *>(&data_33_34), sizeof(data_33_34));
            buffer.write(reinterpret_cast<const char *>(&data_35_36), sizeof(data_35_36));
            buffer.write(reinterpret_cast<const char *>(data_37_40), sizeof(data_37_40));
            buffer.write(reinterpret_cast<const char *>(&data_41_44), sizeof(data_41_44));
        }
        for (int i = 0; i < nsamples; i++) {
            short sample = HTS_GStreamSet_get_speech(gss, i);
            buffer.write(reinterpret_cast<const char *>(&sample), sizeof(sample));
        }
        m_duration = ((double) HTS_PStreamSet_get_total_frame(&m_engine.pss) * global->fperiod / global->sampling_rate) * 1000;
        HTS_Engine_refresh(&m_engine);
        buffer.close();
    }
    JPCommon_refresh(&m_jpcommon);
    NJD_refresh(&m_njd);
    Mecab_refresh(&m_mecab);
    return ret;
}

void OpenJTalkSpeechEngine::PrivateContext::setText(const QString &text)
{
    HTS_Engine_set_stop_flag(&m_engine, false);

    char *buff = static_cast<char *>(calloc(2 * text.length() + 1, sizeof(char)));
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    QByteArray bytes = codec->fromUnicode(text);
    char *str = strdup(bytes.constData());
    if (buff == NULL || str == NULL) {
        free(buff);
        free(str);
        return;
    }
    text2mecab(buff, str);
    Mecab_analysis(&m_mecab, buff);
    free(buff);
    free(str);

    mecab2njd(&m_njd, Mecab_get_feature(&m_mecab), Mecab_get_size(&m_mecab));
    njd_set_pronunciation(&m_njd);
    njd_set_digit(&m_njd);
    njd_set_accent_phrase(&m_njd);
    njd_set_accent_type(&m_njd);
    njd_set_unvoiced_vowel(&m_njd);
    njd_set_long_vowel(&m_njd);
    njd2jpcommon(&m_jpcommon, &m_njd);
    JPCommon_make_label(&m_jpcommon);

    if (JPCommon_get_label_size(&m_jpcommon) > 2) {
        char **labelFeature = NULL;
        int labelSize = 0;
        /* decision of state durations */
        labelFeature = JPCommon_get_label_feature(&m_jpcommon);
        labelSize = JPCommon_get_label_size(&m_jpcommon);
        HTS_Engine_load_label_from_string_list(&m_engine, &labelFeature[1], labelSize - 1); /* skip first silence */
        HTS_Engine_create_sstream(&m_engine);
        /* parameter generation */
        if (m_f0Shift != 0.0) {
            for (int i = 0; i < HTS_Engine_get_total_state(&m_engine); i++) {
                double f = HTS_Engine_get_state_mean(&m_engine, 1, i, 0);
                f += m_f0Shift * log(2.0) / 12;
                if (f < kMinLF0Val)
                    f = kMinLF0Val;
                HTS_Engine_set_state_mean(&m_engine, 1, i, 0, f);
            }
        }
        HTS_Engine_create_pstream(&m_engine);
    }
}

int OpenJTalkSpeechEngine::PrivateContext::getDuration() const
{
    return m_duration;
}

const QString OpenJTalkSpeechEngine::PrivateContext::getPhonemeSequence()
{
    QString ret;
    int size = JPCommon_get_label_size(&m_jpcommon);
    char **feature = JPCommon_get_label_feature(&m_jpcommon);
    int nstate = HTS_Engine_get_nstate(&m_engine);
    int fperiod = HTS_Engine_get_fperiod(&m_engine);
    int sampling_rate = HTS_Engine_get_sampling_rate(&m_engine);

    if (size <= 2)
        return ret;

    /* skip first and final silence */
    size -= 2;
    feature = &feature[1];

    for (int i = 0; i < size; i++) {
        if (i > 0)
            ret += ",";
        /* get phoneme from full-context label */
        char *start = strchr(feature[i], '-');
        char *end = strchr(feature[i], '+');
        if (start != NULL && end != NULL) {
            for (char *ch = start + 1; ch != end; ch++)
                ret += QChar(*ch);
        } else {
            ret += feature[i];
        }
        /* get ms */
        int j = 0, k = 0;
        for (; j < nstate; j++)
            k += (HTS_Engine_get_state_duration(&m_engine, i * nstate + j) * fperiod * 1000) / sampling_rate;
        ret += QString(",%1").arg(k);
    }

    return ret;
}

void OpenJTalkSpeechEngine::PrivateContext::setStyle(const QString &style)
{
    if (!m_styles.contains(style))
        return;

    int styleIndex = m_styles[style];
    int nmodels = m_models.count();
    int index = styleIndex * (nmodels * 3 + 4);

    for (int i = 0; i < nmodels; i++)
        HTS_Engine_set_parameter_interpolation_weight(&m_engine, 0, i, m_weights[index + nmodels * 0 + i]);
    for (int i = 0; i < nmodels; i++)
        HTS_Engine_set_parameter_interpolation_weight(&m_engine, 1, i, m_weights[index + nmodels * 1 + i]);
    for (int i = 0; i < nmodels; i++)
        HTS_Engine_set_duration_interpolation_weight(&m_engine, i, m_weights[index + nmodels * 2 + i]);

    double value = m_weights[index + nmodels * 3 + 0];
    if (value == 0)
        value = 1;

    /* speed */
    double speed = kFPeriod / value;
    if(speed > kMaxFPeriod)
        HTS_Engine_set_fperiod(&m_engine, kMaxFPeriod);
    else if(speed < kMinFPeriod)
        HTS_Engine_set_fperiod(&m_engine, kMinFPeriod);
    else
        HTS_Engine_set_fperiod(&m_engine, (int) speed);

    /* pitch */
    double pitch = m_weights[index + nmodels * 3 + 1];
    if(pitch > kMaxHanfTone)
        m_f0Shift = kMaxHanfTone;
    else if(pitch < kMinHanfTone)
        m_f0Shift = kMinHanfTone;
    else
        m_f0Shift = pitch;

    /* alpha */
    double alpha = m_weights[index + nmodels * 3 + 2];
    if(alpha > kMaxAlpha)
        HTS_Engine_set_alpha(&m_engine, kMaxAlpha);
    else if(alpha < kMinAlpha)
        HTS_Engine_set_alpha(&m_engine, kMinAlpha);
    else
        HTS_Engine_set_alpha(&m_engine, alpha);

    /* volume */
    double volume = m_weights[index + nmodels * 3 + 3];
    if(volume > kMaxVolume)
        HTS_Engine_set_volume(&m_engine, kMaxVolume);
    else if(volume < kMinVolume)
        HTS_Engine_set_volume(&m_engine, kMinVolume);
    else
        HTS_Engine_set_volume(&m_engine, volume);
}

const QString OpenJTalkSpeechEngine::kSynthStartCommand = "SYNTH_START";
const QString OpenJTalkSpeechEngine::kSynthStopCommand =  "SYNTH_STOP";
const QString OpenJTalkSpeechEngine::kSynthStartEvent = "SYNTH_EVENT_START";
const QString OpenJTalkSpeechEngine::kSynthStopEvent = "SYNTH_EVENT_STOP";
const QString OpenJTalkSpeechEngine::kLipSyncStartCommand = "LIPSYNC_START";
const QString OpenJTalkSpeechEngine::kLipSyncStopCommand = "LIPSYNC_STOP";

const QByteArray kOpenJTalkCodecName = "Shift-JIS";

OpenJTalkSpeechEngine::OpenJTalkSpeechEngine(QObject *parent)
    : QObject(parent)
{
    PaError err = Pa_Initialize();
    if (err != paNoError)
        qWarning("Pa_Initialized failed: %s", Pa_GetErrorText(err));
}

OpenJTalkSpeechEngine::~OpenJTalkSpeechEngine()
{
    qDeleteAll(m_models);
    PaError err = Pa_Terminate();
    if (err != paNoError)
        qWarning("Pa_Terminate failed: %s", Pa_GetErrorText(err));
}

void OpenJTalkSpeechEngine::load(const QDir &dir, const QString &baseName)
{
    if (m_base.isEmpty()) {
        const QString base = dir.absolutePath();
        const QString config = dir.absoluteFilePath(QString("%1.ojt").arg(baseName));
        const QString resdir = QDir("MMDAIResources:OpenJTalk").absolutePath();
        if (QFile::exists(base) && QFile::exists(config) && QFile::exists(resdir)) {
            m_base = base;
            m_config = config;
            m_dir = resdir;
        }
    }
}

void OpenJTalkSpeechEngine::speech(const QString &name, const QString &style, const QString &text)
{
    QtConcurrent::run(this, &OpenJTalkSpeechEngine::run, name, style, text);
}

void OpenJTalkSpeechEngine::run(const QString &name, const QString &style, const QString &text)
{
    OpenJTalkSpeechEngine::PrivateContext *model;
    if (m_models.contains(name)) {
        model = m_models[name];
    }
    else {
        model = new OpenJTalkSpeechEngine::PrivateContext(this);
        model->loadSetting(m_base, m_config);
        model->loadDictionary(m_dir);
        m_models[name] = model;
    }
    model->setStyle(style);
    model->setText(text);
    QString sequence = model->getPhonemeSequence();
    QByteArray bytes = model->finalize(false);

    QList<QVariant> arguments;
    arguments << name;
    eventDidPost(kSynthStartEvent, arguments);
    arguments.clear();
    arguments << name << sequence;
    commandDidPost(kLipSyncStartCommand, arguments);

    PaError err;
    PaStream *stream;
    PaStreamParameters output;
    output.device = Pa_GetDefaultOutputDevice();
    if (output.device == paNoDevice) {
        qWarning("No device to output found");
        goto final;
    }
    output.channelCount = 1;
    output.sampleFormat = paInt16;
    output.suggestedLatency = Pa_GetDeviceInfo(output.device)->defaultLowOutputLatency;
    output.hostApiSpecificStreamInfo = NULL;
    err = Pa_OpenStream(&stream, NULL, &output, OpenJTalkSpeechEngine::PrivateContext::kSamplingRate, 1024, paClipOff, NULL, NULL);
    if (err != paNoError) {
        qWarning("Pa_OpenStream failed: %s", Pa_GetErrorText(err));
        goto final;
    }
    if (stream != NULL) {
        err = Pa_StartStream(stream);
        if (err != paNoError) {
            qWarning("Pa_StartStream failed: %s", Pa_GetErrorText(err));
            goto final;
        }
        err = Pa_WriteStream(stream, bytes.constData(), bytes.size() / sizeof(short));
        if (err != paNoError) {
            qWarning("Pa_WriteStream failed: %s", Pa_GetErrorText(err));
            goto final;
        }
        err = Pa_CloseStream(stream);
        if (err != paNoError) {
            qWarning("Pa_StartStream failed: %s", Pa_GetErrorText(err));
            goto final;
        }
    }

final:
    arguments.clear();
    arguments << name;
    eventDidPost(kSynthStopEvent, arguments);
}
