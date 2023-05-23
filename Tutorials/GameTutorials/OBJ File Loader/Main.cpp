#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Time/Ticks.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>

#include <LDL/OpenGL/OpenGL1_1.hpp>
#include <LDL/OpenGL/OpenGLUtility.hpp>

#include "Obj.h"

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Time;

#define FILE_NAME  "foot.objm"							// This is the 3D file we will load.
#define MAX_TEXTURES  100

GLuint g_Texture[MAX_TEXTURES] = { 0 };						// This holds the texture info, referenced by an ID

CLoadObj g_LoadObj;										// This is OBJ class.  This should go in a good model class.
t3DModel g_3DModel;

int   g_ViewMode = GL_TRIANGLES;					// We want the default drawing mode to be normal
bool  g_bLighting = true;							// Turn lighting on initially
float g_RotateX = 0.0f;							// This is the current value at which the model is rotated
float g_RotationSpeed = 0.8f;

GLuint LoadTexture(const std::string& path, ImageLoader& loader)
{
	GLuint result = 0;

	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	loader.Load(path);

	GLenum format = 0;

	if (loader.BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, format, GL_UNSIGNED_BYTE, loader.Pixels());

	return result;
}

//////////////////////////// RESIZE OPENGL SCREEN \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function resizes the viewport for OpenGL.
/////
//////////////////////////// RESIZE OPENGL SCREEN \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
void SizeOpenGLScreen(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 150.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function renders the entire scene.
/////
///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The matrix

	//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

		// Give OpenGL our position,	then view,		then up vector
	gluLookAt(0, 1.5f, 12, 0, 0.5f, 0, 0, 1, 0);

	// We want the model to rotate around the axis so we give it a rotation
	// value, then increase/decrease it. You can rotate right of left with the arrow keys.

	glRotatef(g_RotateX, 0, 1.0f, 0);						// Rotate the object around the Y-Axis
	g_RotateX += g_RotationSpeed;							// Increase the speed of rotation

	// I am going to attempt to explain what is going on below up here as not to clutter the 
	// code below.  We have a model that has a certain amount of objects and textures.  We want 
	// to go through each object in the model, bind it's texture map to it, then render it.
	// To render the current object, we go through all of it's faces (Polygons).  
	// What is a face you ask?  A face is just (in this case) a triangle of the object.
	// For instance, a cube has 12 faces because each side has 2 triangles.
	// You might be thinking.  Well, if there are 12 faces in a cube, that makes
	// 36 vertices that we needed to read in for that object.  Not really true.  Because
	// a lot of the vertices are the same, since they share sides, they only need to save
	// 8 vertices, and ignore the duplicates.  Then, you have an array of all the
	// unique vertices in that object.  No 2 vertices will be the same.  This cuts down
	// on memory.  Then, another array is saved, which is the index numbers for each face,
	// which index in to that array of vertices.  That might sound silly, but it is better
	// than saving tons of duplicate vertices.  The same thing happens for UV coordinates.
	// You don't save duplicate UV coordinates, you just save the unique ones, then an array
	// that index's into them.  This might be confusing, but most 3D files use this format.
	// This loop below will stay the same for most file formats that you load, so all you need
	// to change is the loading code.  You don't need to change this loop (Except for animation).

	// Since we know how many objects our model has, go through each of them.
	for (int i = 0; i < g_3DModel.numOfObjects; i++)
	{
		// Make sure we have valid objects just in case. (size() is in the vector class)
		if (g_3DModel.pObject.size() <= 0) break;

		// Get the current object that we are displaying
		t3DObject* pObject = &g_3DModel.pObject[i];

		// Check to see if this object has a texture map, if so bind the texture to it.
		if (pObject->bHasTexture) {

			// Turn on texture mapping and turn off color
			glEnable(GL_TEXTURE_2D);

			// Reset the color to normal again
			glColor3ub(255, 255, 255);

			// Bind the texture map to the object by it's materialID (*ID Current Unused*)
			glBindTexture(GL_TEXTURE_2D, g_Texture[pObject->materialID]);
		}
		else {

			// Turn off texture mapping and turn on color
			glDisable(GL_TEXTURE_2D);

			// Reset the color to normal again
			glColor3ub(255, 255, 255);
		}

		// This determines if we are in wire frame or normal mode
		glBegin(g_ViewMode);					// Begin drawing with our selected mode (triangles or lines)

		// Go through all of the faces (polygons) of the object and draw them
		for (int j = 0; j < pObject->numOfFaces; j++)
		{
			// Go through each corner of the triangle and draw it.
			for (int whichVertex = 0; whichVertex < 3; whichVertex++)
			{
				// Get the vertex index for each point of the face
				int vertIndex = pObject->pFaces[j].vertIndex[whichVertex];

				// Give OpenGL the normal for this vertex.
				glNormal3f(pObject->pNormals[vertIndex].x, pObject->pNormals[vertIndex].y, pObject->pNormals[vertIndex].z);

				// If the object has a texture associated with it, give it a texture coordinate.
				if (pObject->bHasTexture) {

					// Make sure there was a UVW map applied to the object or else it won't have tex coords.
					if (pObject->pTexVerts.size()) {

						// Get the texture coordinate index
						int coordIndex = pObject->pFaces[j].coordIndex[whichVertex];

						// Assign the UV coordinates to the current vertex being rendered
						glTexCoord2f(pObject->pTexVerts[coordIndex].x, pObject->pTexVerts[coordIndex].y);
					}
				}
				else {

					// Make sure there is a valid material/color assigned to this object.
					// You should always at least assign a material color to an object, 
					// but just in case we want to check the size of the material list.
					// if the size is at least one, and the material ID != -1,
					// then we have a valid material.
					if (g_3DModel.pMaterials.size() && pObject->materialID >= 0)
					{
						// Get and set the color that the object is, since it must not have a texture
						uint8_t* pColor = g_3DModel.pMaterials[pObject->materialID].color;

						// Assign the current color to this model
						glColor3ub(pColor[0], pColor[1], pColor[2]);
					}

				}

				// Pass in the current vertex of the object (Corner of current face)
				glVertex3f(pObject->pVerts[vertIndex].x, pObject->pVerts[vertIndex].y, pObject->pVerts[vertIndex].z);
			}
		}

		glEnd();								// End the drawing
	}

}

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(SCREEN_WIDTH, SCREEN_HEIGHT), "LearnOpenGL");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Event report;

		FixedLinear allocator(Allocator::Mb * 4);
		ImageLoader loader(&allocator);

		SizeOpenGLScreen((int)window.Size().PosX(), (int)window.Size().PosY());

		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);

		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;

		g_LoadObj.ImportObj(&g_3DModel, FILE_NAME);			// Load our .Obj file into our model structure

		// Since the .obj file format doesn't hold material information like color
		// and image files, we need to manually do that in code (or add it to the .obj file yourself).
		// I created a couple functions in the CLoadObj to help us do that.

		// Here we create a material with a name, a bitmap name and RGB values.
		// If we didn't want to create a texture map material but a color, just pass in NULL
		// for the file name field.  Also, by default the color is (255, 255, 255) if you choose
		// not to set it.  I did so just to show you how and not to confuse anyone.
		g_LoadObj.AddMaterial(&g_3DModel, "Bone", "Bone.bmp", 255, 255, 255);

		// With this function we can assign a particular model to a material ID.
		// This is so the object can have a color OR texture map.  
		// Here we pass in our model, the index into the object list, and the material ID.
		g_LoadObj.SetObjectMaterial(&g_3DModel, 0, 0);

		// Here we go through all of the materials and check if we need to make a texture map.
		// We obviously know there is just one material but we should set this up for future use.
		for (int i = 0; i < g_3DModel.numOfMaterials; i++)
		{
			// Check if the current material has a file name
			if (strlen(g_3DModel.pMaterials[i].strFile) > 0) {

				// Create a texture map from the material's file name
				g_Texture[i] = LoadTexture(g_3DModel.pMaterials[i].strFile, loader);
			}

			// Assign the material ID to the current material
			g_3DModel.pMaterials[i].texureId = i;
		}

		// Here, we turn on a lighting and enable lighting.  We don't need to
		// set anything else for lighting because we will just take the defaults.
		// We also want color, so we turn that on

		glEnable(GL_LIGHT0);								// Turn on a light with defaults set
		glEnable(GL_LIGHTING);								// Turn on lighting
		glEnable(GL_COLOR_MATERIAL);						// Allow color 

		while (window.GetEvent(report))
		{
			float currentFrame = static_cast<float>(Ticks() / 1000.0f);
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			//render.Begin();
			
			RenderScene();

			Delay(1);

			render.End();

			if (report.IsMousePressed(MouseButton::Left))
			{
				if (g_ViewMode == GL_TRIANGLES)
					g_ViewMode = GL_LINE_STRIP;
				else
					g_ViewMode = GL_TRIANGLES;
			}

			if (report.IsMousePressed(MouseButton::Right))
			{
				g_bLighting = !g_bLighting;

				if (g_bLighting)
					glEnable(GL_LIGHTING);
				else
					glDisable(GL_LIGHTING);
			}

			if (report.IsKeyPressed(KeyboardKey::W))
				g_RotationSpeed += 0.05f;

			if (report.IsKeyPressed(KeyboardKey::S))
				g_RotationSpeed -= 0.05f;

			if (report.Type == IsResize)
			{
				SizeOpenGLScreen((int)report.Resize.Width, (int)report.Resize.Height);
			}

			if (report.Type == IsQuit || report.IsKeyPressed(KeyboardKey::Escape))
			{
				window.StopEvent();
			}
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}