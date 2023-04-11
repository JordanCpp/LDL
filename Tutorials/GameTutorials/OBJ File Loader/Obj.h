#ifndef _OBJ_H
#define _OBJ_H

#include <LDL/Core/Types.hpp>
#include <vector>

// This is our 3D point class.  This will be used to store the vertices of our model.
class CVector3
{
public:
	float x, y, z;
};

// This is our 2D point class.  This will be used to store the UV coordinates.
class CVector2
{
public:
	float x, y;
};

// This is our face structure.  This is is used for indexing into the vertex 
// and texture coordinate arrays.  From this information we know which vertices
// from our vertex array go to which face, along with the correct texture coordinates.
struct tFace
{
	int vertIndex[3];			// indicies for the verts that make up this triangle
	int coordIndex[3];			// indicies for the tex coords to texture this face
};

// This holds the information for a material.  It may be a texture map of a color.
// Some of these are not used, but I left them because you will want to eventually
// read in the UV tile ratio and the UV tile offset for some models.
struct tMaterialInfo
{
	char  strName[255];			// The texture name
	char  strFile[255];			// The texture file name (If this is set it's a texture map)
	uint8_t  color[3];				// The color of the object (R, G, B)
	int   texureId;				// the texture ID
	float uTile;				// u tiling of texture  (Currently not used)
	float vTile;				// v tiling of texture	(Currently not used)
	float uOffset;			    // u offset of texture	(Currently not used)
	float vOffset;				// v offset of texture	(Currently not used)
};

// This holds all the information for our model/scene. 
// You should eventually turn into a robust class that 
// has loading/drawing/querying functions like:
// LoadModel(...); DrawObject(...); DrawModel(...); DestroyModel(...);
struct t3DObject
{
	int  numOfVerts;			// The number of verts in the model
	int  numOfFaces;			// The number of faces in the model
	int  numTexVertex;			// The number of texture coordinates
	int  materialID;			// The texture ID to use, which is the index into our texture array
	bool bHasTexture;			// This is TRUE if there is a texture map for this object
	char strName[255];			// The name of the object
	std::vector <CVector3> pVerts;			// The object's vertices
	std::vector <CVector3> pNormals;		// The object's normals
	std::vector <CVector2> pTexVerts;		// The texture's UV coordinates
	std::vector <tFace> pFaces;				// The faces information of the object
};

// This holds our model information.  This should also turn into a robust class.
// We use STL's (Standard Template Library) vector class to ease our link list burdens. :)
struct t3DModel
{
	int numOfObjects;					// The number of objects in the model
	int numOfMaterials;					// The number of materials for the model
	std::vector<tMaterialInfo> pMaterials;	// The list of material information (Textures and colors)
	std::vector<t3DObject> pObject;			// The object list for our model
};

// This class can be used to load a .Obj file.  You will need the grab the
// structures in main.h as well if you want to use this, or create your own.
// I added a couple functions at the end of this class to help with the material
// problem that a .obj file has.  Obj files do not save material information, like
// the color, material name or the texture map file assigned to it.  Though the .obj
// file format isn't the best used for games, I thought I would help out a little.
// To be honest, it would be better to just add the information to the .obj and
// modify my code to read it in.  For instance, put a : c 255 0 255   for the color.

// This is our class for loading .obj files
class CLoadObj {

public:
	
	// This will be the only function that needs to be called by you.
	// Just pass in your model that will hold the information and the file name.
	bool ImportObj(t3DModel *pModel, char *strFileName);

	// This is the main loading loop that gets called in ImportObj()
	void ReadObjFile(t3DModel *pModel);

	// This is called in ReadObjFile() if we find a line starting with 'v'
	void ReadVertexInfo();

	// This is called in ReadObjFile() if we find a line starting with 'f'
	void ReadFaceInfo();

	// This is called when we are finished loading in the face information
	void FillInObjectInfo(t3DModel *pModel);

	// This isn't necessary for the loader, but it's nice to have vertex normals for lighting
	void ComputeNormals(t3DModel *pModel);

	// Since .obj files don't have texture/material names, we create a function to set them manually.
	// The materialID is the index into the pMaterial array for our model.
	void SetObjectMaterial(t3DModel *pModel, int whichObject, int materialID);

	// To make it easier to assign a material to a .obj object we create a funtion to do so.
	// We can pass in the model, the material name, the texture file name and the RGB colors.
	// If we just want a color, pass in NULL for strFile.
	void AddMaterial(t3DModel *pModel, char *strName, char *strFile, 
					 int r = 255,      int g = 255,   int b = 255);

private:

	// This holds our file pointer for reading in the file
	FILE *m_FilePointer;

	// This is an STL (Standard Template Library) vector that holds a list of vertices
	std::vector<CVector3>  m_pVertices;

	// This is an STL (Standard Template Library) vector that holds a list of faces
	std::vector<tFace> m_pFaces;

	// This is an STL (Standard Template Library) vector that holds a list of UV Coordinates
	std::vector<CVector2>  m_pTextureCoords;

	// This tells us if the current object has texture coordinates
	bool m_bObjectHasUV;

	// This tells us if we just read in face data so we can keep track of multiple objects
	bool m_bJustReadAFace;
};


#endif


/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// This tutorial shows how to load an .obj file.  These files are ASCII text files
// that contain very few information about the models, but are great for importing/exporting
// into almost every 3D software package as well as being easy to read in.
// 
// This header file holds the class information for CLoadObj.
// 
// 
// Ben Humphrey (DigiBen)
// Game Programmer
// DigiBen@GameTutorials.com
// ©2000-2005 GameTutorials
//
//

