# /* ----------------------------------------------------------------- */
# /*                                                                   */
# /*  Copyright (c) 2010-2011  hkrn (libMMDAI)                         */
# /*                                                                   */
# /* All rights reserved.                                              */
# /*                                                                   */
# /* Redistribution and use in source and binary forms, with or        */
# /* without modification, are permitted provided that the following   */
# /* conditions are met:                                               */
# /*                                                                   */
# /* - Redistributions of source code must retain the above copyright  */
# /*   notice, this list of conditions and the following disclaimer.   */
# /* - Redistributions in binary form must reproduce the above         */
# /*   copyright notice, this list of conditions and the following     */
# /*   disclaimer in the documentation and/or other materials provided */
# /*   with the distribution.                                          */
# /* - Neither the name of the MMDAgent project team nor the names of  */
# /*   its contributors may be used to endorse or promote products     */
# /*   derived from this software without specific prior written       */
# /*   permission.                                                     */
# /*                                                                   */
# /* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
# /* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
# /* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
# /* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
# /* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
# /* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
# /* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
# /* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
# /* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
# /* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
# /* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
# /* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
# /* POSSIBILITY OF SUCH DAMAGE.                                       */
# /* ----------------------------------------------------------------- */

include(QMACommon.pri)
exists(QMACustom.pri):include(QMACustom.pri)

QT += core gui opengl
TARGET = MMDAI
TEMPLATE = app

SOURCES += main.cc\
    QMATimer.cc \
    QMAWindow.cc \
    QMAModelLoader.cc \
    QMAModelLoaderFactory.cc \
    QMALipSyncLoader.cc \
    QMALogger.cc \
    QMALogViewWidget.cc \
    QMAPreference.cc \
    QMADebugRenderEngine.cc \
    QMATextRenderEngine.cc \
    QMAScenePlayer.cc \
    QMALicenseWidget.cc

HEADERS  += \
    QMAPlugin.h \
    QMATimer.h \
    QMAWindow.h \
    QMAModelLoader.h \
    QMAModelLoaderFactory.h \
    QMALipSyncLoader.h \
    QMALogger.h \
    QMALogViewWidget.h \
    QMAPreference.h \
    QMADebugRenderEngine.h \
    QMATextRenderEngine.h \
    QMAScenePlayer.h \
    QMALicenseWidget.h

TRANSLATIONS += res/translations/QMA.ts

RESOURCES += QMA.qrc

win32 {
    RC_FILE = res/MMDAI.rc
}
macx {
    ICON = res/MMDAI.icns
    QMAKE_INFO_PLIST = res/Info.plist
    FILETYPES.files = res/translations/QMA_ja.qm \
                      res/translations/QMAJuliusPlugin_ja.qm
    FILETYPES.path = Contents/Resources
    QMAKE_BUNDLE_DATA += FILETYPES
}

CODECFORTR = UTF-8
