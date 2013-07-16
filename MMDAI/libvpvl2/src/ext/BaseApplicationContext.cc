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

#include <vpvl2/extensions/BaseApplicationContext.h>

/* libvpvl2 */
#include <vpvl2/vpvl2.h>
#include <vpvl2/internal/util.h>
#include <vpvl2/extensions/Archive.h>
#include <vpvl2/extensions/gl/FrameBufferObject.h>
#include <vpvl2/extensions/gl/SimpleShadowMap.h>
#include <vpvl2/extensions/gl/Texture2D.h>
#include <vpvl2/extensions/icu4c/StringMap.h>

#ifdef VPVL2_ENABLE_EXTENSION_ARCHIVE
#include <vpvl2/extensions/Archive.h>
#endif

/* STL */
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wself-assign"
#pragma clang diagnostic ignored "-Wmissing-field-initializers"
#endif

/* Simple OpenGL Image Library */
#include "stb_image_aug.h"

/* FreeImage */
#ifdef VPVL2_LINK_FREEIMAGE
#include <FreeImage.h>
#else
#define FreeImage_Initialise()
#define FreeImage_DeInitialise()
#endif

/* GLI */
#include <gli/gli.hpp>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

/* GLM */
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/* Cg and ICU */
#include <unicode/udata.h>
#ifdef VPVL2_ENABLE_NVIDIA_CG
#include <vpvl2/extensions/fx/Util.h>
#include <unicode/regex.h>
#endif

using namespace vpvl2;
using namespace vpvl2::extensions;
using namespace vpvl2::extensions::icu4c;

namespace {

#include "ICUCommonData.inl"

static inline const char *DebugMessageSourceToString(GLenum value)
{
    switch (value) {
    case GL_DEBUG_SOURCE_API:
        return "OpenGL";
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        return "Window";
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        return "ShaderCompiler";
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        return "ThirdParty";
    case GL_DEBUG_SOURCE_APPLICATION:
        return "Application";
    case GL_DEBUG_SOURCE_OTHER:
        return "Other";
    default:
        return "Unknown";
    }
}

static inline const char *DebugMessageTypeToString(GLenum value)
{
    switch (value) {
    case GL_DEBUG_TYPE_ERROR:
        return "Error";
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        return "DeprecatedBehavior";
    case GL_DEBUG_TYPE_PORTABILITY:
        return "Portability";
    case GL_DEBUG_TYPE_PERFORMANCE:
        return "Performance";
    case GL_DEBUG_TYPE_OTHER:
        return "Other";
    default:
        return "Unknown";
    }
}

} /* namespace anonymous */

#ifndef VPVL2_LINK_GLOG
namespace google {
static inline void InstallFailureSignalHandler() {}
static inline void InitGoogleLogging(const char * /* argv0 */) {}
static inline void LogToStderr() {}
static inline void ShutdownGoogleLogging() {}
} /* namespace google */
static bool FLAGS_colorlogtostderr = false;
static bool FLAGS_logtostderr = false;
static int FLAGS_v = 0;
#endif

namespace vpvl2
{
namespace extensions
{
using namespace gl;
using namespace icu4c;

BaseApplicationContext::ModelContext::ModelContext(BaseApplicationContext *applicationContextRef, vpvl2::extensions::Archive *archiveRef, const IString *directory)
    : m_directoryRef(directory),
      m_archiveRef(archiveRef),
      m_applicationContextRef(applicationContextRef)
{
}

BaseApplicationContext::ModelContext::~ModelContext()
{
    m_archiveRef = 0;
    m_applicationContextRef = 0;
    m_directoryRef = 0;
}

void BaseApplicationContext::ModelContext::addTextureCache(const UnicodeString &path, ITexture *textureRef)
{
    if (textureRef) {
        m_textureRefCache.insert(std::make_pair(path, textureRef));
    }
}

bool BaseApplicationContext::ModelContext::findTextureCache(const UnicodeString &path, TextureDataBridge &bridge) const
{
    TextureCacheMap::const_iterator it = m_textureRefCache.find(path);
    if (it != m_textureRefCache.end()) {
        bridge.dataRef = it->second;
        return true;
    }
    return false;
}

bool BaseApplicationContext::ModelContext::cacheTexture(const UnicodeString &key, ITexture *textureRef, TextureDataBridge &bridge)
{
    bool ok = textureRef != 0;
    if (textureRef) {
        glBindTexture(GL_TEXTURE_2D, static_cast<GLuint>(textureRef->data()));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        if (internal::hasFlagBits(bridge.flags, IApplicationContext::kToonTexture)) {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        }
        glBindTexture(GL_TEXTURE_2D, 0);
        bridge.dataRef = textureRef;
        addTextureCache(key, textureRef);
    }
    return ok;
}

int BaseApplicationContext::ModelContext::countCachedTextures() const
{
    return m_textureRefCache.size();
}

ITexture *BaseApplicationContext::ModelContext::uploadTexture(const void *ptr,
                                                              const BaseSurface::Format &format,
                                                              const Vector3 &size,
                                                              bool mipmap,
                                                              bool canOptimize) const
{
    Texture2D *texture = new (std::nothrow) Texture2D(format, size, 0);
    if (texture) {
        texture->create();
        texture->bind();
        if (GLEW_ARB_texture_storage) {
            glTexStorage2D(format.target, 1, format.internal, GLsizei(size.x()), GLsizei(size.y()));
            glTexSubImage2D(format.target, 0, 0, 0, GLsizei(size.x()), GLsizei(size.y()), format.external, format.type, ptr);
        }
        else {
#if defined(GL_APPLE_client_storage) && defined(GL_APPLE_texture_range)
            if (canOptimize) {
                glTexParameteri(format.target, GL_TEXTURE_STORAGE_HINT_APPLE, GL_STORAGE_CACHED_APPLE);
                glPixelStorei(GL_UNPACK_CLIENT_STORAGE_APPLE, GL_TRUE);
            }
#endif
            glTexImage2D(format.target, 0, format.internal, GLsizei(size.x()), GLsizei(size.y()), 0, format.external, format.type, ptr);
        }
        if (mipmap) {
            generateMipmap(format.target);
        }
        texture->unbind();
    }
    return texture;
}

ITexture *BaseApplicationContext::ModelContext::uploadTexture(const uint8 *data, vsize size, bool mipmap)
{
    Vector3 textureSize;
    ITexture *texturePtr = 0;
    int x = 0, y = 0, ncomponents = 0;
#ifdef VPVL2_LINK_FREEIMAGE
    FIMEMORY *memory = FreeImage_OpenMemory(const_cast<uint8_t *>(data), size);
    FREE_IMAGE_FORMAT format = FreeImage_GetFileTypeFromMemory(memory);
    if (format != FIF_UNKNOWN) {
        if (FIBITMAP *bitmap = FreeImage_LoadFromMemory(format, memory)) {
            if (FIBITMAP *bitmap32 = FreeImage_ConvertTo32Bits(bitmap)) {
                FreeImage_FlipVertical(bitmap32);
                BaseSurface::Format format(GL_BGRA, GL_RGBA8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_TEXTURE_2D);
                textureSize.setValue(FreeImage_GetWidth(bitmap32), FreeImage_GetHeight(bitmap32), 1);
                texturePtr = uploadTexture(FreeImage_GetBits(bitmap32), format, textureSize, mipmap, false);
                FreeImage_Unload(bitmap);
                FreeImage_Unload(bitmap32);
                return texturePtr;
            }
            else {
                VPVL2_LOG(WARNING, "Cannot convert loaded image to 32bits image");
            }
            FreeImage_Unload(bitmap);
        }
        else {
            VPVL2_LOG(WARNING, "Cannot decode the image");
        }
    }
    else {
        VPVL2_LOG(WARNING, "Cannot detect image format");
    }
    FreeImage_CloseMemory(memory);
#endif
    /* Loading major image format (BMP/JPG/PNG/TGA/DDS) texture with stb_image.c */
    if (stbi_uc *ptr = stbi_load_from_memory(data, size, &x, &y, &ncomponents, 4)) {
        textureSize.setValue(Scalar(x), Scalar(y), 1);
        BaseSurface::Format format(GL_RGBA, GL_RGBA8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_TEXTURE_2D);
        texturePtr = uploadTexture(ptr, format, textureSize, mipmap, false);
        stbi_image_free(ptr);
    }
    return texturePtr;
}

Archive *BaseApplicationContext::ModelContext::archiveRef() const
{
    return m_archiveRef;
}

const IString *BaseApplicationContext::ModelContext::directoryRef() const
{
    return m_directoryRef;
}

void BaseApplicationContext::ModelContext::generateMipmap(GLenum target) const
{
#ifdef VPVL2_LINK_GLEW
    if (GLEW_ARB_framebuffer_object) {
        glGenerateMipmap(target);
    }
#elif !defined(VPVL2_ENABLE_GLES2)
    const void *procs[] = { "glGenerateMipmap", "glGenerateMipmapEXT", 0 };
    typedef void (*glGenerateMipmapProcPtr)(GLuint);
    if (glGenerateMipmapProcPtr glGenerateMipmapProcPtrRef = reinterpret_cast<glGenerateMipmapProcPtr>(m_applicationContextRef->findProcedureAddress(procs)))
        glGenerateMipmapProcPtrRef(target);
#endif /* VPVL2_LINK_GLEW */
}

bool BaseApplicationContext::ModelContext::uploadTextureCached(const UnicodeString &path, TextureDataBridge &bridge)
{
    if (path[path.length() - 1] == '/' || findTextureCache(path, bridge)) {
        VPVL2_VLOG(2, String::toStdString(path) << " is already cached, skipped.");
        return true;
    }
    ITexture *texturePtr = 0;
    MapBuffer buffer(m_applicationContextRef);
    /* Loading major image format (BMP/JPG/PNG/TGA/DDS) texture with stb_image.c */
    if (m_applicationContextRef->mapFile(path, &buffer)) {
        texturePtr = uploadTexture(buffer.address, buffer.size, internal::hasFlagBits(bridge.flags, IApplicationContext::kGenerateTextureMipmap));
        if (!texturePtr) {
            VPVL2_LOG(WARNING, "Cannot load texture from " << String::toStdString(path) << ": " << stbi_failure_reason());
            return false;
        }
    }
    return cacheTexture(path, texturePtr, bridge);
}

bool BaseApplicationContext::ModelContext::uploadTextureCached(const uint8 *data, vsize size, const UnicodeString &key, TextureDataBridge &bridge)
{
    if (findTextureCache(key, bridge)) {
        VPVL2_VLOG(2, String::toStdString(key) << " is already cached, skipped.");
        return true;
    }
    ITexture *texturePtr = uploadTexture(data, size, internal::hasFlagBits(bridge.flags, IApplicationContext::kGenerateTextureMipmap));
    if (!texturePtr) {
        VPVL2_LOG(WARNING, "Cannot load texture with key " << String::toStdString(key) << ": " << stbi_failure_reason());
        return false;
    }
    return cacheTexture(key, texturePtr, bridge);
}

bool BaseApplicationContext::initializeOnce(const char *argv0)
{
    VPVL2_CHECK(argv0);
#if !defined(_WIN32)
    google::InstallFailureSignalHandler();
#endif
    google::InitGoogleLogging(argv0);
#ifndef NDEBUG
    google::LogToStderr();
    FLAGS_colorlogtostderr = true;
    FLAGS_logtostderr = true;
    FLAGS_v = 2;
#endif
    UErrorCode err = U_ZERO_ERROR;
    udata_setCommonData(g_icudt50l_dat, &err);
    return err == U_ZERO_ERROR;
}

void BaseApplicationContext::terminate()
{
    Scene::terminate();
    google::ShutdownGoogleLogging();
}

BaseApplicationContext::BaseApplicationContext(Scene *sceneRef, IEncoding *encodingRef, const StringMap *configRef)
    : m_configRef(configRef),
      m_sceneRef(sceneRef),
      m_encodingRef(encodingRef),
      m_currentModelRef(0),
      m_renderColorFormat(GL_RGBA, GL_RGBA8, GL_UNSIGNED_BYTE, GL_TEXTURE_2D),
      m_lightWorldMatrix(1),
      m_lightViewMatrix(1),
      m_lightProjectionMatrix(1),
      m_cameraWorldMatrix(1),
      m_cameraViewMatrix(1),
      m_cameraProjectionMatrix(1),
      m_textureSampler(0),
      m_toonTextureSampler(0)
    #ifdef VPVL2_ENABLE_NVIDIA_CG
    ,
      m_effectPathPtr(0),
      m_msaaSamples(0)
    #endif /* VPVL2_ENABLE_NVIDIA_CG */
{
    FreeImage_Initialise();
}

void BaseApplicationContext::initialize(bool enableDebug)
{
    std::istringstream in(reinterpret_cast<const char *>(glGetString(GL_EXTENSIONS)));
    std::string extension;
    while (std::getline(in, extension, ' ')) {
        m_extensions.insert(extension);
    }
    // const GLubyte *shaderVersionString = glGetString(GL_SHADING_LANGUAGE_VERSION);
    if (GLEW_ARB_debug_output && enableDebug) {
        glDebugMessageCallbackARB(reinterpret_cast<GLDEBUGPROC>(&BaseApplicationContext::debugMessageCallback), this);
    }
    if (GLEW_ARB_sampler_objects) {
        glGenSamplers(1, &m_textureSampler);
        glGenSamplers(1, &m_toonTextureSampler);
        glSamplerParameteri(m_textureSampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glSamplerParameteri(m_textureSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glSamplerParameteri(m_toonTextureSampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glSamplerParameteri(m_toonTextureSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glSamplerParameteri(m_toonTextureSampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glSamplerParameteri(m_toonTextureSampler, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
#ifdef VPVL2_ENABLE_NVIDIA_CG
    glGetIntegerv(GL_MAX_SAMPLES, &m_msaaSamples);
#endif /* VPVL2_ENABLE_NVIDIA_CG */
}

BaseApplicationContext::~BaseApplicationContext()
{
    release();
    m_encodingRef = 0;
    FreeImage_DeInitialise();
#ifdef VPVL2_ENABLE_NVIDIA_CG
    /* m_msaaSamples must not set zero at #release(), it causes multiple post effect will be lost */
    m_msaaSamples = 0;
#endif
}

bool BaseApplicationContext::uploadTexture(const IString *name, TextureDataBridge &bridge, void *userData)
{
    bool ret = false;
    bridge.dataRef = 0;
    ModelContext *context = static_cast<ModelContext *>(userData);
    const UnicodeString &name2 = static_cast<const String *>(name)->value();
    if (internal::hasFlagBits(bridge.flags, IApplicationContext::kToonTexture)) {
        if (!internal::hasFlagBits(bridge.flags, IApplicationContext::kSystemToonTexture)) {
            /* name2.isEmpty() = directory */
            if (name2.isEmpty()) {
                String d(toonDirectory());
                const UnicodeString &newToonPath = createPath(&d, UnicodeString::fromUTF8("toon0.bmp"));
                if (!context->findTextureCache(newToonPath, bridge)) {
                    /* fallback to default texture loader */
                    VPVL2_VLOG(2, "Try loading a system default toon texture from archive: " << String::toStdString(newToonPath));
                    ret = context->uploadTextureCached(newToonPath, bridge);
                }
            }
            else if (context->archiveRef()) {
                VPVL2_VLOG(2, "Try loading a model toon texture from archive: " << String::toStdString(name2));
                ret = uploadTextureCached(name2, UnicodeString(), bridge, context);
            }
            else if (const IString *directoryRef = context->directoryRef()) {
                const UnicodeString &path = createPath(directoryRef, name);
                VPVL2_VLOG(2, "Try loading a model toon texture: " << String::toStdString(path));
                ret = uploadTextureCached(name2, path, bridge, context);
            }
        }
        if (!ret) {
            bridge.flags |= IApplicationContext::kSystemToonTexture;
            VPVL2_VLOG(2, "Loading a fallback system toon texture: " << String::toStdString(name2));
            ret = uploadSystemToonTexture(name2, bridge, context);
        }
    }
    else if (const IString *directoryRef = context->directoryRef()) {
        const UnicodeString &path = createPath(directoryRef, name);
        VPVL2_VLOG(2, "Loading a model texture: " << String::toStdString(path));
        ret = uploadTextureCached(name2, path, bridge, context);
    }
    return ret;
}

bool BaseApplicationContext::uploadSystemToonTexture(const UnicodeString &name, TextureDataBridge &bridge, ModelContext *context)
{
    MapBuffer buffer(this);
    String s(toonDirectory());
    const UnicodeString &path = createPath(&s, name);
    /* open a (system) toon texture from library resource */
    return mapFile(path, &buffer) ? context->uploadTextureCached(buffer.address, buffer.size, path, bridge) : false;
}

bool BaseApplicationContext::uploadTextureCached(const UnicodeString &name, const UnicodeString &path, TextureDataBridge &bridge, ModelContext *context)
{
    Archive *archiveRef = context->archiveRef();
    if (archiveRef && !internal::hasFlagBits(bridge.flags, IApplicationContext::kSystemToonTexture)) {
        archiveRef->uncompressEntry(name);
        VPVL2_LOG(INFO, String::toStdString(name));
        if (const std::string *bytesRef = archiveRef->dataRef(name)) {
            const uint8 *ptr = reinterpret_cast<const uint8 *>(bytesRef->data());
            vsize size = bytesRef->size();
            if (name.endsWith(".jpg") || name.endsWith(".png") || name.endsWith(".bmp")) {
                return uploadTextureOpaque(ptr, size, name, context, bridge);
            }
            else {
                return context->uploadTextureCached(ptr, size, path, bridge);
            }
        }
        VPVL2_LOG(WARNING, "Cannot load a bridge from archive: " << String::toStdString(name));
        /* force true to continue loading texture if path is directory */
        return false;
    }
    else if (!existsFile(path)) {
        VPVL2_LOG(WARNING, "Cannot load inexist " << String::toStdString(path));
        return true; /* skip */
    }
    else if (name.endsWith(".jpg") || name.endsWith(".png") || name.endsWith(".bmp")) {
        return uploadTextureOpaque(path, context, bridge);
    }
    /* fallback to default texture loader */
    return context->uploadTextureCached(path, bridge);
}

bool BaseApplicationContext::uploadTextureOpaque(const uint8 *data, vsize size, const UnicodeString &key, ModelContext *context, TextureDataBridge &bridge)
{
    return context->uploadTextureCached(data, size, key, bridge);
}

bool BaseApplicationContext::uploadTextureOpaque(const UnicodeString &path, ModelContext *context, TextureDataBridge &bridge)
{
    return context->uploadTextureCached(path, bridge);
}

void BaseApplicationContext::getMatrix(float32 value[], const IModel *model, int flags) const
{
    glm::mat4x4 m(1);
    if (internal::hasFlagBits(flags, IApplicationContext::kShadowMatrix)) {
        if (internal::hasFlagBits(flags, IApplicationContext::kProjectionMatrix)) {
            m *= m_cameraProjectionMatrix;
        }
        if (internal::hasFlagBits(flags, IApplicationContext::kViewMatrix)) {
            m *= m_cameraViewMatrix;
        }
        if (model && internal::hasFlagBits(flags, IApplicationContext::kWorldMatrix)) {
            static const Vector3 plane(0.0f, 1.0f, 0.0f);
            const ILight *light = m_sceneRef->lightRef();
            const Vector3 &direction = light->direction();
            const Scalar dot = plane.dot(-direction);
            float matrix[16];
            for (int i = 0; i < 4; i++) {
                int offset = i * 4;
                for (int j = 0; j < 4; j++) {
                    int index = offset + j;
                    matrix[index] = plane[i] * direction[j];
                    if (i == j)
                        matrix[index] += dot;
                }
            }
            m *= glm::make_mat4x4(matrix);
            m *= m_cameraWorldMatrix;
            m = glm::scale(m, glm::vec3(model->scaleFactor()));
        }
    }
    else if (internal::hasFlagBits(flags, IApplicationContext::kCameraMatrix)) {
        if (internal::hasFlagBits(flags, IApplicationContext::kProjectionMatrix)) {
            m *= m_cameraProjectionMatrix;
        }
        if (internal::hasFlagBits(flags, IApplicationContext::kViewMatrix)) {
            m *= m_cameraViewMatrix;
        }
        if (model && internal::hasFlagBits(flags, IApplicationContext::kWorldMatrix)) {
            const IBone *bone = model->parentBoneRef();
            Transform transform;
            transform.setOrigin(model->worldPosition());
            transform.setRotation(model->worldRotation());
            Scalar matrix[16];
            transform.getOpenGLMatrix(matrix);
            m *= glm::make_mat4x4(matrix);
            if (bone) {
                transform = bone->worldTransform();
                transform.getOpenGLMatrix(matrix);
                m *= glm::make_mat4x4(matrix);
            }
            m *= m_cameraWorldMatrix;
            m = glm::scale(m, glm::vec3(model->scaleFactor()));
        }
    }
    else if (internal::hasFlagBits(flags, IApplicationContext::kLightMatrix)) {
        if (internal::hasFlagBits(flags, IApplicationContext::kWorldMatrix)) {
            m *= m_lightWorldMatrix;
            m = glm::scale(m, glm::vec3(model->scaleFactor()));
        }
        if (internal::hasFlagBits(flags, IApplicationContext::kProjectionMatrix)) {
            m *= m_lightProjectionMatrix;
        }
        if (internal::hasFlagBits(flags, IApplicationContext::kViewMatrix)) {
            m *= m_lightViewMatrix;
        }
    }
    if (internal::hasFlagBits(flags, IApplicationContext::kInverseMatrix)) {
        m = glm::inverse(m);
    }
    if (internal::hasFlagBits(flags, IApplicationContext::kTransposeMatrix)) {
        m = glm::transpose(m);
    }
    std::memcpy(value, glm::value_ptr(m), sizeof(float) * 16);
}

IString *BaseApplicationContext::loadShaderSource(ShaderType type, const IModel *model, void *userData)
{
    std::string file;
#ifdef VPVL2_ENABLE_NVIDIA_CG
    if (type == kModelEffectTechniques) {
        const IString *path = effectFilePath(model, static_cast<const IString *>(userData));
        return loadShaderSource(type, path);
    }
#else
    (void) userData;
#endif /* VPVL2_ENABLE_NVIDIA_CG */
    switch (model->type()) {
    case IModel::kAssetModel:
        file += "/asset/";
        break;
    case IModel::kPMDModel:
    case IModel::kPMXModel:
        file += "/pmx/";
        break;
    default:
        break;
    }
    switch (type) {
    case kEdgeVertexShader:
        file += "edge.vsh";
        break;
    case kEdgeFragmentShader:
        file += "edge.fsh";
        break;
    case kModelVertexShader:
        file += "model.vsh";
        break;
    case kModelFragmentShader:
        file += "model.fsh";
        break;
    case kShadowVertexShader:
        file += "shadow.vsh";
        break;
    case kShadowFragmentShader:
        file += "shadow.fsh";
        break;
    case kZPlotVertexShader:
        file += "zplot.vsh";
        break;
    case kZPlotFragmentShader:
        file += "zplot.fsh";
        break;
    case kEdgeWithSkinningVertexShader:
        file += "skinning/edge.vsh";
        break;
    case kModelWithSkinningVertexShader:
        file += "skinning/model.vsh";
        break;
    case kShadowWithSkinningVertexShader:
        file += "skinning/shadow.vsh";
        break;
    case kZPlotWithSkinningVertexShader:
        file += "skinning/zplot.vsh";
        break;
    case kModelEffectTechniques:
    case kMaxShaderType:
    default:
        break;
    }
    const UnicodeString &path = shaderDirectory() + UnicodeString::fromUTF8(file.c_str());
    MapBuffer buffer(this);
    if (mapFile(path, &buffer)) {
        std::string bytes(buffer.address, buffer.address + buffer.size);
        return new(std::nothrow) String(UnicodeString::fromUTF8("#version 120\n" + bytes));
    }
    else {
        return 0;
    }
}

IString *BaseApplicationContext::loadShaderSource(ShaderType type, const IString *path)
{
#ifdef VPVL2_ENABLE_NVIDIA_CG
    if (type == kModelEffectTechniques) {
        std::string bytes;
        MapBuffer buffer(this);
        if (path && mapFile(static_cast<const String *>(path)->value(), &buffer)) {
            uint8 *address = buffer.address;
            bytes.assign(address, address + buffer.size);
        }
        else {
            UnicodeString defaultEffectPath = effectDirectory();
            defaultEffectPath.append("/base.cgfx");
            if (mapFile(defaultEffectPath, &buffer)) {
                uint8 *address = buffer.address;
                bytes.assign(address, address + buffer.size);
            }
        }
        return bytes.empty() ? 0 : new (std::nothrow) String(UnicodeString::fromUTF8(bytes));
    }
#else
    (void) type;
    (void) path;
#endif /* VPVL2_ENABLE_NVIDIA_CG */
    return 0;
}

IString *BaseApplicationContext::loadKernelSource(KernelType type, void * /* userData */)
{
    std::string file;
    switch (type) {
    case kModelSkinningKernel:
        file += "skinning.cl";
        break;
    default:
        break;
    }
    UnicodeString path = kernelDirectory();
    path.append("/");
    path.append(UnicodeString::fromUTF8(file));
    MapBuffer buffer(this);
    if (mapFile(path, &buffer)) {
        std::string bytes(buffer.address, buffer.address + buffer.size);
        return new(std::nothrow) String(UnicodeString::fromUTF8(bytes));
    }
    else {
        return 0;
    }
}

IString *BaseApplicationContext::toUnicode(const uint8 *str) const
{
    if (const char *s = reinterpret_cast<const char *>(str)) {
        return m_encodingRef->toString(str, std::strlen(s), IString::kShiftJIS);
    }
    return 0;
}

bool BaseApplicationContext::hasExtension(const void *namePtr) const
{
    return m_extensions.find(static_cast<const char *>(namePtr)) != m_extensions.end();
}

void BaseApplicationContext::startProfileSession(ProfileType /* type */, const void * /* arg */)
{
}

void BaseApplicationContext::stopProfileSession(ProfileType /* type */, const void * /* arg */)
{
}

#ifdef VPVL2_ENABLE_NVIDIA_CG

void BaseApplicationContext::getViewport(Vector3 &value) const
{
    value.setValue(m_viewport.x, m_viewport.y, 1);
}

void BaseApplicationContext::getMousePosition(Vector4 &value, MousePositionType type) const {
    switch (type) {
    case kMouseLeftPressPosition:
        value.setValue(m_mouseLeftPressPosition.x,
                       m_mouseLeftPressPosition.y,
                       m_mouseLeftPressPosition.z,
                       m_mouseLeftPressPosition.w);
        break;
    case kMouseMiddlePressPosition:
        value.setValue(m_mouseMiddlePressPosition.x,
                       m_mouseMiddlePressPosition.y,
                       m_mouseMiddlePressPosition.z,
                       m_mouseMiddlePressPosition.w);
        break;
    case kMouseRightPressPosition:
        value.setValue(m_mouseRightPressPosition.x,
                       m_mouseRightPressPosition.y,
                       m_mouseRightPressPosition.z,
                       m_mouseRightPressPosition.w);
        break;
    case kMouseCursorPosition:
        value.setValue(m_mouseCursorPosition.x,
                       m_mouseCursorPosition.y,
                       m_mouseCursorPosition.z,
                       m_mouseCursorPosition.w);
        break;
    default:
        break;
    }
}

IModel *BaseApplicationContext::findModel(const IString *name) const
{
    IModel *model = m_sceneRef->findModel(name);
    if (!model) {
        if (IModel *const *value = m_basename2modelRefs.find(name->toHashString())) {
            model = *value;
        }
    }
    return model;
}

IModel *BaseApplicationContext::effectOwner(const IEffect *effect) const
{
    if (IModel *const *value = m_effectRef2modelRefs.find(effect)) {
        return *value;
    }
    return 0;
}

void BaseApplicationContext::setEffectOwner(const IEffect *effectRef, IModel *model)
{
    const IString *name = model->name(IEncoding::kDefaultLanguage);
    m_effectRef2owners.insert(effectRef, static_cast<const String *>(name)->value());
    m_effectRef2modelRefs.insert(effectRef, model);
}

void BaseApplicationContext::addModelPath(IModel *model, const UnicodeString &path)
{
    if (model) {
        UErrorCode status = U_ZERO_ERROR;
        RegexMatcher filenameMatcher(".+/((.+)\\.\\w+)$", 0, status);
        filenameMatcher.reset(path);
        if (filenameMatcher.find()) {
            const UnicodeString &basename = filenameMatcher.group(1, status);
            if (!model->name(IEncoding::kDefaultLanguage)) {
                String s(filenameMatcher.group(2, status));
                model->setName(&s, IEncoding::kDefaultLanguage);
            }
            m_basename2modelRefs.insert(String::toStdString(basename).c_str(), model);
            m_modelRef2Basenames.insert(model, basename);
        }
        else {
            if (!model->name(IEncoding::kDefaultLanguage)) {
                String s(path);
                model->setName(&s, IEncoding::kDefaultLanguage);
            }
            m_basename2modelRefs.insert(String::toStdString(path).c_str(), model);
        }
        m_modelRef2Paths.insert(model, path);
    }
}

UnicodeString BaseApplicationContext::effectOwnerName(const IEffect *effect) const
{
    if (const UnicodeString *value = m_effectRef2owners.find(effect)) {
        return *value;
    }
    return UnicodeString();
}

FrameBufferObject *BaseApplicationContext::createFrameBufferObject()
{
    return new FrameBufferObject(m_renderColorFormat, m_msaaSamples);
}

void BaseApplicationContext::getEffectCompilerArguments(Array<IString *> &arguments) const
{
    arguments.clear();
}

const IString *BaseApplicationContext::effectFilePath(const IModel *model, const IString *dir) const
{
    const UnicodeString &path = findModelPath(model);
    if (!path.isEmpty()) {
        UErrorCode status = U_ZERO_ERROR;
        RegexMatcher filenameMatcher("^.+/(.+)\\.\\w+$", 0, status);
        filenameMatcher.reset(path);
        const UnicodeString &s = filenameMatcher.find() ? filenameMatcher.group(1, status) : path;
        RegexMatcher extractMatcher("^.+\\[(.+)(?:\\.(?:cg)?fx)?\\]$", 0, status);
        extractMatcher.reset(s);
        const UnicodeString &cgfx = extractMatcher.find()
                ? extractMatcher.replaceAll("$1.cgfx", status) : s + ".cgfx";
        const UnicodeString &newEffectPath = createPath(dir, cgfx);
        m_effectPathPtr.reset(existsFile(newEffectPath) ? new String(newEffectPath) : 0);
    }
    if (!m_effectPathPtr.get()) {
        m_effectPathPtr.reset(new String(createPath(dir, UnicodeString::fromUTF8("default.cgfx"))));
    }
    return m_effectPathPtr.get();
}

void BaseApplicationContext::addSharedTextureParameter(const char *name, const SharedTextureParameter &parameter)
{
    SharedTextureParameterKey key(parameter.parameterRef, name);
    m_sharedParameters.insert(std::make_pair(key, parameter));
}

bool BaseApplicationContext::tryGetSharedTextureParameter(const char *name, SharedTextureParameter &parameter) const
{
    SharedTextureParameterKey key(parameter.parameterRef, name);
    SharedTextureParameterMap::const_iterator it = m_sharedParameters.find(key);
    if (it != m_sharedParameters.end()) {
        parameter = it->second;
        return true;
    }
    return false;
}

void BaseApplicationContext::setMousePosition(const glm::vec2 &value, bool pressed, MousePositionType type)
{
    switch (type) {
    case kMouseLeftPressPosition:
        m_mouseLeftPressPosition = glm::vec4(value.x, value.y, pressed, 0);
        break;
    case kMouseMiddlePressPosition:
        m_mouseMiddlePressPosition = glm::vec4(value.x, value.y, pressed, 0);
        break;
    case kMouseRightPressPosition:
        m_mouseRightPressPosition = glm::vec4(value.x, value.y, pressed, 0);
        break;
    case kMouseCursorPosition:
        m_mouseCursorPosition = glm::vec4(value.x, value.y, 0, 0);
        break;
    default:
        break;
    }
}

UnicodeString BaseApplicationContext::findModelPath(const IModel *modelRef) const
{
    if (const UnicodeString *value = m_modelRef2Paths.find(modelRef)) {
        return *value;
    }
    return UnicodeString();
}

UnicodeString BaseApplicationContext::findModelBasename(const IModel *modelRef) const
{
    if (const UnicodeString *value = m_modelRef2Basenames.find(modelRef)) {
        return *value;
    }
    return UnicodeString();
}

FrameBufferObject *BaseApplicationContext::findFrameBufferObjectByRenderTarget(const IEffect::OffscreenRenderTarget &rt, bool enableAA)
{
    FrameBufferObject *buffer = 0;
    if (const ITexture *textureRef = rt.textureRef) {
        if (FrameBufferObject *const *value = m_renderTargets.find(textureRef)) {
            buffer = *value;
        }
        else {
            int nsamples = enableAA ? m_msaaSamples : 0;
            buffer = m_renderTargets.insert(textureRef, new FrameBufferObject(m_renderColorFormat, nsamples));
        }
    }
    return buffer;
}

void BaseApplicationContext::bindOffscreenRenderTarget(OffscreenTexture *textureRef, bool enableAA)
{
    const IEffect::OffscreenRenderTarget &rt = textureRef->renderTarget;
    if (FrameBufferObject *buffer = findFrameBufferObjectByRenderTarget(rt, enableAA)) {
        buffer->bindTexture(textureRef->colorTextureRef, 0);
        buffer->bindDepthStencilBuffer(&textureRef->depthStencilBuffer);
    }
    static const GLuint buffers[] = { GL_COLOR_ATTACHMENT0 };
    static const int nbuffers = sizeof(buffers) / sizeof(buffers[0]);
    fx::Util::setRenderColorTargets(buffers, nbuffers);
}

void BaseApplicationContext::releaseOffscreenRenderTarget(const OffscreenTexture *textureRef, bool enableAA)
{
    const IEffect::OffscreenRenderTarget &rt = textureRef->renderTarget;
    if (FrameBufferObject *buffer = findFrameBufferObjectByRenderTarget(rt, enableAA)) {
        buffer->readMSAABuffer(0);
        buffer->unbind();
    }
}

void BaseApplicationContext::parseOffscreenSemantic(IEffect *effectRef, const IString *directioryRef)
{
    if (effectRef) {
        EffectAttachmentRuleList attachmentRules;
        std::string line;
        UErrorCode status = U_ZERO_ERROR;
        Vector3 size;
        RegexMatcher extensionMatcher("\\.(cg)?fx(sub)?$", 0, status),
                pairMatcher("\\s*=\\s*", 0, status);
        Array<IEffect::OffscreenRenderTarget> offscreenRenderTargets;
        effectRef->getOffscreenRenderTargets(offscreenRenderTargets);
        const int nOffscreenRenderTargets = offscreenRenderTargets.count();
        /* オフスクリーンレンダーターゲットの設定 */
        for (int i = 0; i < nOffscreenRenderTargets; i++) {
            const IEffect::OffscreenRenderTarget &renderTarget = offscreenRenderTargets[i];
            const IEffect::Parameter *parameter = renderTarget.textureParameterRef;
            const IEffect::Annotation *annotation = parameter->annotationRef("DefaultEffect");
            std::istringstream stream(annotation ? annotation->stringValue() : std::string());
            std::vector<UnicodeString> tokens(2);
            attachmentRules.clear();
            /* スクリプトを解析 */
            while (std::getline(stream, line, ';')) {
                int32 size = static_cast<int32>(tokens.size());
                if (pairMatcher.split(UnicodeString::fromUTF8(line), &tokens[0], size, status) == size) {
                    const UnicodeString &key = tokens[0].trim();
                    const UnicodeString &value = tokens[1].trim();
                    RegexMatcherSmartPtr regexp;
                    status = U_ZERO_ERROR;
                    /* self が指定されている場合は自身のエフェクトのファイル名を設定する */
                    if (key == "self") {
                        const IModel *model = effectOwner(effectRef);
                        const UnicodeString &name = findModelBasename(model);
                        regexp.reset(new RegexMatcher("\\A\\Q" + name + "\\E\\z", 0, status));
                    }
                    else {
                        UnicodeString pattern = "\\A\\Q" + key + "\\E\\z";
                        pattern.findAndReplace("?", "\\E.\\Q");
                        pattern.findAndReplace("*", "\\E.*\\Q");
                        pattern.findAndReplace("\\Q\\E", "");
                        regexp.reset(new RegexMatcher(pattern, 0, status));
                    }
                    IEffect *offscreenEffectRef = 0;
                    /* hide/none でなければオフスクリーン専用のモデルのエフェクト（オフスクリーン側が指定）を読み込む */
                    bool hidden = (value == "hide" || value == "none");
                    if (!hidden) {
                        const UnicodeString &path = createPath(directioryRef, value);
                        extensionMatcher.reset(path);
                        status = U_ZERO_ERROR;
                        const String s2(extensionMatcher.replaceAll(".cgfx", status));
                        offscreenEffectRef = createEffectRef(&s2);
                        if (offscreenEffectRef) {
                            offscreenEffectRef->setParentEffectRef(effectRef);
                            VPVL2_VLOG(2, "Loaded an individual effect by offscreen: path=" << internal::cstr(&s2, "") << " pattern=" << String::toStdString(key));
                        }
                    }
                    attachmentRules.push_back(EffectAttachmentRule(regexp.release(), std::make_pair(offscreenEffectRef, hidden)));
                }
            }
            if (!fx::Util::getSize2(parameter, size)) {
                Vector3 viewport;
                getViewport(viewport);
                size.setX(btMax(1.0f, viewport.x() * size.x()));
                size.setY(btMax(1.0f, viewport.y() * size.y()));
            }
            BaseSurface::Format format; /* unused */
            fx::Util::getTextureFormat(parameter, format);
            /* RenderContext 特有の OffscreenTexture に変換して格納 */
            m_offscreenTextures.append(new OffscreenTexture(renderTarget, attachmentRules, size));
        }
    }
}

void BaseApplicationContext::renderOffscreen()
{
    Array<IRenderEngine *> engines;
    m_sceneRef->getRenderEngineRefs(engines);
    const int nengines = engines.count();
    /* オフスクリーンレンダリングを行う前に元のエフェクトを保存する */
    Hash<HashPtr, IEffect *> effects;
    for (int i = 0; i < nengines; i++) {
        IRenderEngine *engine = engines[i];
        if (IEffect *starndardEffect = engine->effectRef(IEffect::kStandard)) {
            effects.insert(engine, starndardEffect);
        }
        else if (IEffect *postEffect = engine->effectRef(IEffect::kPostProcess)) {
            effects.insert(engine, postEffect);
        }
        else if (IEffect *preEffect = engine->effectRef(IEffect::kPreProcess)) {
            effects.insert(engine, preEffect);
        }
        else {
            effects.insert(engine, 0);
        }
    }
    /* オフスクリーンレンダーターゲット毎にエフェクトを実行する */
    const int ntextures = m_offscreenTextures.count();
    for (int i = 0; i < ntextures; i++) {
        OffscreenTexture *offscreenTexture = m_offscreenTextures[i];
        const EffectAttachmentRuleList &rules = offscreenTexture->attachmentRules;
        const IEffect::OffscreenRenderTarget &renderTarget = offscreenTexture->renderTarget;
        const IEffect::Parameter *parameter = renderTarget.textureParameterRef;
        bool enableAA = false;
        /* セマンティクスから各種パラメータを設定 */
        if (const IEffect::Annotation *annotation = parameter->annotationRef("AntiAlias")) {
            enableAA = annotation->booleanValue();
        }
        /* オフスクリーンレンダリングターゲットを割り当ててレンダリング先をそちらに変更する */
        bindOffscreenRenderTarget(offscreenTexture, enableAA);
        const ITexture *texture = renderTarget.textureRef;
        const Vector3 &size = texture->size();
        updateCameraMatrices(glm::vec2(size.x(), size.y()));
        glViewport(0, 0, GLsizei(size.x()), GLsizei(size.y()));
        if (const IEffect::Annotation *annotation = parameter->annotationRef("ClearColor")) {
            int nvalues;
            const float *color = annotation->floatValues(&nvalues);
            if (nvalues == 4) {
                glClearColor(color[0], color[1], color[2], color[3]);
            }
        }
        else {
            glClearDepth(1);
        }
        /* オフスクリーンレンダリングターゲットに向けてレンダリングを実行する */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        for (int j = 0; j < nengines; j++) {
            IRenderEngine *engine = engines[j];
            const IModel *model = engine->parentModelRef();
            const UnicodeString &basename = findModelBasename(model);
            EffectAttachmentRuleList::const_iterator it2 = rules.begin();
            bool hidden = false;
            while (it2 != rules.end()) {
                const EffectAttachmentRule &rule = *it2;
                RegexMatcher *matcherRef = rule.first;
                matcherRef->reset(basename);
                if (matcherRef->find()) {
                    const EffectAttachmentValue &v = rule.second;
                    IEffect *effectRef = v.first;
                    engine->setEffect(effectRef, IEffect::kStandardOffscreen, 0);
                    hidden = v.second;
                    break;
                }
                ++it2;
            }
            if (!hidden) {
                engine->update();
                engine->renderModel();
                engine->renderEdge();
            }
        }
        /* オフスクリーンレンダリングターゲットの割り当てを解除 */
        releaseOffscreenRenderTarget(offscreenTexture, enableAA);
    }
    for (int i = 0; i < nengines; i++) {
        IRenderEngine *engine = engines[i];
        IEffect *const *effect = effects.find(engine);
        engine->setEffect(*effect, IEffect::kAutoDetection, 0);
    }
}

IEffect *BaseApplicationContext::createEffectRef(const IString *path)
{
    IEffect *effectRef = 0;
    const HashString key(path->toHashString());
    if (IEffect *const *value = m_effectCaches.find(key)) {
        effectRef = *value;
    }
    else if (existsFile(static_cast<const String *>(path)->value())) {
        IEffectSmartPtr effectPtr(m_sceneRef->createEffectFromFile(path, this));
        if (!effectPtr.get() || !effectPtr->internalPointer()) {
            VPVL2_LOG(WARNING, "Cannot compile an effect: " << internal::cstr(path, "(null)") << " error=" << cgGetLastListing(static_cast<CGcontext>(effectPtr->internalContext())));
        }
        else if (!m_effectCaches.find(key)) {
            effectRef = m_effectCaches.insert(key, effectPtr.release());
        }
        else {
            VPVL2_LOG(INFO, "Duplicated effect was found and ignored it: " << internal::cstr(path, "(null)"));
        }
    }
    else {
        effectRef = m_effectCaches.insert(key, m_sceneRef->createDefaultStandardEffect(this));
        if (!effectRef || !effectRef->internalPointer()) {
            VPVL2_LOG(WARNING, "Cannot compile an effect: " << internal::cstr(path, "(null)") << " error=" << cgGetLastListing(static_cast<CGcontext>(effectRef->internalContext())));
        }
    }
    return effectRef;
}

IEffect *BaseApplicationContext::createEffectRef(IModel *modelRef, const IString *directoryRef)
{
    const UnicodeString &pathForKey = static_cast<const String *>(effectFilePath(modelRef, directoryRef))->value();
    const String s(pathForKey);
    IEffect *effectRef = createEffectRef(&s);
    if (effectRef) {
        setEffectOwner(effectRef, modelRef);
        VPVL2_LOG(INFO, "Loaded an model effect: model=" << internal::cstr(modelRef->name(IEncoding::kDefaultLanguage), "(null)") << " path=" << internal::cstr(&s, ""));
    }
    return effectRef;
}

#endif /* VPVL2_ENABLE_NVIDIA_CG */

IModel *BaseApplicationContext::currentModelRef() const
{
    return m_currentModelRef;
}

void BaseApplicationContext::setCurrentModelRef(IModel *value)
{
    m_currentModelRef = value;
}

Scene *BaseApplicationContext::sceneRef() const
{
    return m_sceneRef;
}

void BaseApplicationContext::setSceneRef(Scene *value)
{
    release();
    m_sceneRef = value;
}

void BaseApplicationContext::getCameraMatrices(glm::mat4x4 &world, glm::mat4x4 &view, glm::mat4x4 &projection)
{
    world = m_cameraWorldMatrix;
    view = m_cameraViewMatrix;
    projection = m_cameraProjectionMatrix;
}

void BaseApplicationContext::setCameraMatrices(const glm::mat4x4 &world, const glm::mat4x4 &view, const glm::mat4x4 &projection)
{
    m_cameraWorldMatrix = world;
    m_cameraViewMatrix = view;
    m_cameraProjectionMatrix = projection;
}

void BaseApplicationContext::setViewport(const glm::vec2 &value)
{
    m_viewport = value;
}

void BaseApplicationContext::updateCameraMatrices(const glm::vec2 &size)
{
    const ICamera *camera = m_sceneRef->cameraRef();
    Scalar matrix[16];
    camera->modelViewTransform().getOpenGLMatrix(matrix);
    const glm::mediump_float &aspect = glm::max(size.x, size.y) / glm::min(size.x, size.y);
    const glm::mat4x4 world, &view = glm::make_mat4x4(matrix),
            &projection = glm::infinitePerspective(camera->fov(), aspect, camera->znear());
    setCameraMatrices(world, view, projection);
    setViewport(size);
}

void BaseApplicationContext::createShadowMap(const Vector3 &size)
{
    if (Scene::isSelfShadowSupported()) {
        m_shadowMap.reset(new SimpleShadowMap(vsize(size.x()), vsize(size.y())));
        m_shadowMap->create();
        m_sceneRef->setShadowMapRef(m_shadowMap.get());
    }
}

void BaseApplicationContext::renderShadowMap()
{
    if (m_shadowMap.get()) {
        m_shadowMap->bind();
        const Vector3 &size = m_shadowMap->size();
        glViewport(0, 0, GLsizei(size.x()), GLsizei(size.y()));
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Array<IRenderEngine *> engines;
        m_sceneRef->getRenderEngineRefs(engines);
        const int nengines = engines.count();
        for (int i = 0; i < nengines; i++) {
            IRenderEngine *engine = engines[i];
            engine->renderZPlot();
        }
        m_shadowMap->unbind();
    }
}

const UnicodeString BaseApplicationContext::createPath(const IString *directoryRef, const UnicodeString &name)
{
    UnicodeString n = name;
    return static_cast<const String *>(directoryRef)->value() + "/" + n.findAndReplace('\\', '/');
}

const UnicodeString BaseApplicationContext::createPath(const IString *directoryRef, const IString *name)
{
    const UnicodeString &d = static_cast<const String *>(directoryRef)->value();
    UnicodeString n = static_cast<const String *>(name)->value();
    return d + "/" + n.findAndReplace('\\', '/');
}

UnicodeString BaseApplicationContext::toonDirectory() const
{
    return m_configRef->value("dir.system.toon", UnicodeString(":textures"));
}

UnicodeString BaseApplicationContext::shaderDirectory() const
{
    return m_configRef->value("dir.system.shaders", UnicodeString(":shaders"));
}

UnicodeString BaseApplicationContext::effectDirectory() const
{
    return m_configRef->value("dir.system.effects", UnicodeString(":effects"));
}

UnicodeString BaseApplicationContext::kernelDirectory() const
{
    return m_configRef->value("dir.system.kernels", UnicodeString(":kernels"));
}

void BaseApplicationContext::debugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                                  GLsizei /* length */, const GLchar *message, GLvoid * /* userParam */)
{
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        VPVL2_LOG(ERROR, "ID=" << id << " Type=" << DebugMessageTypeToString(type) << " Source=" << DebugMessageSourceToString(source) << ": " << message);
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        VPVL2_LOG(WARNING, "ID=" << id << " Type=" << DebugMessageTypeToString(type) << " Source=" << DebugMessageSourceToString(source) << ": " << message);
        break;
    case GL_DEBUG_SEVERITY_LOW:
        VPVL2_LOG(INFO, "ID=" << id << " Type=" << DebugMessageTypeToString(type) << " Source=" << DebugMessageSourceToString(source) << ": " << message);
        break;
    default:
        break;
    }
}

void BaseApplicationContext::release()
{
    if (GLEW_ARB_sampler_objects) {
        glDeleteSamplers(1, &m_textureSampler);
        glDeleteSamplers(1, &m_toonTextureSampler);
    }
    m_sceneRef = 0;
    m_currentModelRef = 0;
#ifdef VPVL2_ENABLE_NVIDIA_CG
    m_offscreenTextures.releaseAll();
    m_renderTargets.releaseAll();
    m_basename2modelRefs.clear();
    m_modelRef2Paths.clear();
    m_effectRef2modelRefs.clear();
    m_effectRef2owners.clear();
    m_sharedParameters.clear();
    m_effectPathPtr.reset();
    m_effectCaches.releaseAll();
#endif
}

} /* namespace extensions */
} /* namespace vpvl2 */
