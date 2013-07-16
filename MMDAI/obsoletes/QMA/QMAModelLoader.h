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

#ifndef QMAMODELLOADER_H
#define QMAMODELLOADER_H

#include <QtCore/QDir>
#include <QtCore/QString>

#include <MMDME/IModelLoader.h>
#include <MMDME/IMotionLoader.h>

class QFile;

class QMAModelLoader : public MMDAI::IModelLoader, public MMDAI::IMotionLoader
{
public:
    QMAModelLoader(const QString &system, const char *filename, bool nocompat);
    ~QMAModelLoader();

    bool loadModelData(unsigned char **ptr, size_t *size);
    void unloadModelData(unsigned char *ptr);

    bool loadMotionData(unsigned char **ptr, size_t *size);
    void unloadMotionData(unsigned char *ptr);

    bool loadImageTexture(MMDAI::PMDTexture *texture);
    bool loadModelTexture(const char *name, MMDAI::PMDTexture *texture);
    bool loadSystemTexture(int index, MMDAI::PMDTexture *texture);
    const char *getLocation() const;

private:
    bool loadImage(QString &path, MMDAI::PMDTexture *texture);
    void forceProcessEvents();

    QDir m_dir;
    QFile *m_file;
    const char *m_filename;
    bool m_nocompat;

    Q_DISABLE_COPY(QMAModelLoader)
};

#endif // QMAMODELLOADER_H
