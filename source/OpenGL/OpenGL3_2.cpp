#include <LDL/OpenGL/OpenGL3_2.hpp>

PFNGLDRAWELEMENTSBASEVERTEXPROC* glDrawElementsBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC* glDrawRangeElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC* glDrawElementsInstancedBaseVertex = NULL;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC* glMultiDrawElementsBaseVertex = NULL;
PFNGLPROVOKINGVERTEXPROC* glProvokingVertex = NULL;
PFNGLFENCESYNCPROC* glFenceSync = NULL;
PFNGLISSYNCPROC* glIsSync = NULL;
PFNGLDELETESYNCPROC* glDeleteSync = NULL;
PFNGLCLIENTWAITSYNCPROC* glClientWaitSync = NULL;
PFNGLWAITSYNCPROC* glWaitSync = NULL;
PFNGLGETINTEGER64VPROC* glGetInteger64v = NULL;
PFNGLGETSYNCIVPROC* glGetSynciv = NULL;
PFNGLGETINTEGER64I_VPROC* glGetInteger64i_v = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC* glGetBufferParameteri64v = NULL;
PFNGLFRAMEBUFFERTEXTUREPROC* glFramebufferTexture = NULL;
PFNGLTEXIMAGE2DMULTISAMPLEPROC* glTexImage2DMultisample = NULL;
PFNGLTEXIMAGE3DMULTISAMPLEPROC* glTexImage3DMultisample = NULL;
PFNGLGETMULTISAMPLEFVPROC* glGetMultisamplefv = NULL;
PFNGLSAMPLEMASKIPROC* glSampleMaski = NULL;