/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Display(GLuint textureID)
{
	Identity();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);

	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.0f);

	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

GLuint CreateTexture(uint8_t* pixels, LDL_Vec2i size, int bpp) 
{
	GLuint textureID;
	GLenum format;

	if (bpp == 3) 
	{
		format = GL_RGB;
	}
	else 
	{
		format = GL_RGBA;
	}

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, format, size.x, size.y, 0, format, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}

int main()
{
	LDL_Result*       result;
	LDL_Context*      context;
	LDL_Window*       window;
	LDL_Event         event;
	LDL_OpenGLLoader* loader;
	LDL_BmpLoader*    bmp;
	GLuint            texture = 0;

	result  = LDL_ResultNew();
	context = LDL_ContextNew(LDL_ContextOpenGLLegacy);
	window  = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL - Rectangle red (OpenGL 1.2)", LDL_WindowModeResized);

	if (LDL_ResultIsOk(result))
	{
		loader = LDL_OpenGLLoaderNew(result, 1, 2);
		bmp    = LDL_BmpLoaderNew(result);

		if (LDL_BmpLoaderLoadFromFile(bmp, "LDL_24_256.bmp"))
		{
			texture = CreateTexture(LDL_BmpLoaderGetPixels(bmp), LDL_BmpLoaderGetSize(bmp), LDL_BmpLoaderGetBytesPerPixels(bmp));
		}

		while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
		{
			while (LDL_WindowGetEvent(window, &event))
			{
				if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
				{
					LDL_WindowStopEvent(window);
				}

				if (event.Type == LDL_EventIsResize)
				{
					glViewport(0, 0, (GLsizei)event.u.Resize.Width, (GLsizei)event.u.Resize.Height);
				}
			}

			Display(texture);

			LDL_WindowPresent(window);
		}

		LDL_BmpLoaderFree(bmp);
		LDL_OpenGLLoaderFree(loader);
		LDL_ContextFree(context);
		LDL_WindowFree(window);
		LDL_ResultFree(result);
	}

	if (LDL_ResultIsFail(result))
	{
		printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
	}

	return 0;
}
