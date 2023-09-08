#ifndef LDL_Creators_hpp
#define LDL_Creators_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/EHandler.hpp>

LDL_IRender* RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window);
void Destroy(LDL_IRender* render);

LDL_IWindow* WindowCreate(LDL_ErrorHandler* errorHandler, LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
void Destroy(LDL_IWindow* window);

LDL_IRenderContext* RenderContextCreate();
void Destroy(LDL_IRenderContext* context);

#endif
