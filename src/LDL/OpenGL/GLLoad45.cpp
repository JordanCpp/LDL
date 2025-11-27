// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_5.hpp>
#include <LDL/OpenGL/GLLoad45.hpp>

LDL_OpenGLLoader_4_5::LDL_OpenGLLoader_4_5(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glClipControl = (PFNGLCLIPCONTROLPROC)_functions.Function("glClipControl");
	glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)_functions.Function("glCreateTransformFeedbacks");
	glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)_functions.Function("glTransformFeedbackBufferBase");
	glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)_functions.Function("glTransformFeedbackBufferRange");
	glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)_functions.Function("glGetTransformFeedbackiv");
	glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)_functions.Function("glGetTransformFeedbacki_v");
	glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)_functions.Function("glGetTransformFeedbacki64_v");
	glCreateBuffers = (PFNGLCREATEBUFFERSPROC)_functions.Function("glCreateBuffers");
	glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)_functions.Function("glNamedBufferStorage");
	glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)_functions.Function("glNamedBufferData");
	glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)_functions.Function("glNamedBufferSubData");
	glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)_functions.Function("glCopyNamedBufferSubData");
	glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)_functions.Function("glClearNamedBufferData");
	glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)_functions.Function("glClearNamedBufferSubData");
	glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)_functions.Function("glMapNamedBuffer");
	glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)_functions.Function("glMapNamedBufferRange");
	glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)_functions.Function("glUnmapNamedBuffer");
	glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)_functions.Function("glFlushMappedNamedBufferRange");
	glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)_functions.Function("glGetNamedBufferParameteriv");
	glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)_functions.Function("glGetNamedBufferParameteri64v");
	glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)_functions.Function("glGetNamedBufferPointerv");
	glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)_functions.Function("glGetNamedBufferSubData");
	glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)_functions.Function("glCreateFramebuffers");
	glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)_functions.Function("glNamedFramebufferRenderbuffer");
	glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)_functions.Function("glNamedFramebufferParameteri");
	glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)_functions.Function("glNamedFramebufferTexture");
	glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)_functions.Function("glNamedFramebufferTextureLayer");
	glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)_functions.Function("glNamedFramebufferDrawBuffer");
	glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)_functions.Function("glNamedFramebufferDrawBuffers");
	glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)_functions.Function("glNamedFramebufferReadBuffer");
	glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)_functions.Function("glInvalidateNamedFramebufferData");
	glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)_functions.Function("glInvalidateNamedFramebufferSubData");
	glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)_functions.Function("glClearNamedFramebufferiv");
	glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)_functions.Function("glClearNamedFramebufferuiv");
	glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)_functions.Function("glClearNamedFramebufferfv");
	glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)_functions.Function("glClearNamedFramebufferfi");
	glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)_functions.Function("glBlitNamedFramebuffer");
	glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)_functions.Function("glCheckNamedFramebufferStatus");
	glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)_functions.Function("glGetNamedFramebufferParameteriv");
	glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)_functions.Function("glGetNamedFramebufferAttachmentParameteriv");
	glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)_functions.Function("glCreateRenderbuffers");
	glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)_functions.Function("glNamedRenderbufferStorage");
	glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)_functions.Function("glNamedRenderbufferStorageMultisample");
	glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)_functions.Function("glGetNamedRenderbufferParameteriv");
	glCreateTextures = (PFNGLCREATETEXTURESPROC)_functions.Function("glCreateTextures");
	glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)_functions.Function("glTextureBuffer");
	glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)_functions.Function("glTextureBufferRange");
	glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)_functions.Function("glTextureStorage1D");
	glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)_functions.Function("glTextureStorage2D");
	glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)_functions.Function("glTextureStorage3D");
	glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)_functions.Function("glTextureStorage2DMultisample");
	glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)_functions.Function("glTextureStorage3DMultisample");
	glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)_functions.Function("glTextureSubImage1D");
	glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)_functions.Function("glTextureSubImage2D");
	glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)_functions.Function("glTextureSubImage3D");
	glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)_functions.Function("glCompressedTextureSubImage1D");
	glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)_functions.Function("glCompressedTextureSubImage2D");
	glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)_functions.Function("glCompressedTextureSubImage3D");
	glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)_functions.Function("glCopyTextureSubImage1D");
	glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)_functions.Function("glCopyTextureSubImage2D");
	glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)_functions.Function("glCopyTextureSubImage3D");
	glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)_functions.Function("glTextureParameterf");
	glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)_functions.Function("glTextureParameterfv");
	glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)_functions.Function("glTextureParameteri");
	glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)_functions.Function("glTextureParameterIiv");
	glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)_functions.Function("glTextureParameterIuiv");
	glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)_functions.Function("glTextureParameteriv");
	glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)_functions.Function("glGenerateTextureMipmap");
	glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)_functions.Function("glBindTextureUnit");
	glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)_functions.Function("glGetTextureImage");
	glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)_functions.Function("glGetCompressedTextureImage");
	glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)_functions.Function("glGetTextureLevelParameterfv");
	glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)_functions.Function("glGetTextureLevelParameteriv");
	glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)_functions.Function("glGetTextureParameterfv");
	glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)_functions.Function("glGetTextureParameterIiv");
	glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)_functions.Function("glGetTextureParameterIuiv");
	glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)_functions.Function("glGetTextureParameteriv");
	glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)_functions.Function("glCreateVertexArrays");
	glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)_functions.Function("glDisableVertexArrayAttrib");
	glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)_functions.Function("glEnableVertexArrayAttrib");
	glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)_functions.Function("glVertexArrayElementBuffer");
	glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)_functions.Function("glVertexArrayVertexBuffer");
	glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)_functions.Function("glVertexArrayVertexBuffers");
	glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)_functions.Function("glVertexArrayAttribBinding");
	glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)_functions.Function("glVertexArrayAttribFormat");
	glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)_functions.Function("glVertexArrayAttribIFormat");
	glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)_functions.Function("glVertexArrayAttribLFormat");
	glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)_functions.Function("glVertexArrayBindingDivisor");
	glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)_functions.Function("glGetVertexArrayiv");
	glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)_functions.Function("glGetVertexArrayIndexediv");
	glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)_functions.Function("glGetVertexArrayIndexed64iv");
	glCreateSamplers = (PFNGLCREATESAMPLERSPROC)_functions.Function("glCreateSamplers");
	glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)_functions.Function("glCreateProgramPipelines");
	glCreateQueries = (PFNGLCREATEQUERIESPROC)_functions.Function("glCreateQueries");
	glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)_functions.Function("glGetQueryBufferObjecti64v");
	glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)_functions.Function("glGetQueryBufferObjectiv");
	glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)_functions.Function("glGetQueryBufferObjectui64v");
	glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)_functions.Function("glGetQueryBufferObjectuiv");
	glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)_functions.Function("glMemoryBarrierByRegion");
	glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)_functions.Function("glGetTextureSubImage");
	glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)_functions.Function("glGetCompressedTextureSubImage");
	glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)_functions.Function("glGetGraphicsResetStatus");
	glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)_functions.Function("glGetnCompressedTexImage");
	glGetnTexImage = (PFNGLGETNTEXIMAGEPROC)_functions.Function("glGetnTexImage");
	glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC)_functions.Function("glGetnUniformdv");
	glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)_functions.Function("glGetnUniformfv");
	glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)_functions.Function("glGetnUniformiv");
	glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)_functions.Function("glGetnUniformuiv");
	glReadnPixels = (PFNGLREADNPIXELSPROC)_functions.Function("glReadnPixels");
	glGetnMapdv = (PFNGLGETNMAPDVPROC)_functions.Function("glGetnMapdv");
	glGetnMapfv = (PFNGLGETNMAPFVPROC)_functions.Function("glGetnMapfv");
	glGetnMapiv = (PFNGLGETNMAPIVPROC)_functions.Function("glGetnMapiv");
	glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC)_functions.Function("glGetnPixelMapfv");
	glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC)_functions.Function("glGetnPixelMapuiv");
	glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC)_functions.Function("glGetnPixelMapusv");
	glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC)_functions.Function("glGetnPolygonStipple");
	glGetnColorTable = (PFNGLGETNCOLORTABLEPROC)_functions.Function("glGetnColorTable");
	glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC)_functions.Function("glGetnConvolutionFilter");
	glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC)_functions.Function("glGetnSeparableFilter");
	glGetnHistogram = (PFNGLGETNHISTOGRAMPROC)_functions.Function("glGetnHistogram");
	glGetnMinmax = (PFNGLGETNMINMAXPROC)_functions.Function("glGetnMinmax");
	glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)_functions.Function("glTextureBarrier");
}

LDL_OpenGLLoader_4_5::~LDL_OpenGLLoader_4_5()
{
}
