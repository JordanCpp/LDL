#ifndef _CAMERA_H
#define _CAMERA_H

#include <LDL/Input/Mouse.hpp>
#include "CVector3.h"

// This is our camera class
class CCamera {

public:

	// Our camera constructor
	CCamera(int width, int height);

	// These are are data access functions for our camera's private data
	CVector3 Position() {	return m_vPosition;		}
	CVector3 View()		{	return m_vView;			}
	CVector3 UpVector() {	return m_vUpVector;		}
	CVector3 Strafe()	{	return m_vStrafe;		}
	
	// This changes the position, view, and up vector of the camera.
	// This is primarily used for initialization.
	void PositionCamera(float positionX, float positionY, float positionZ,
			 		    float viewX,     float viewY,     float viewZ,
						float upVectorX, float upVectorY, float upVectorZ);

	// This rotates the camera's view around the position depending on the values passed in.
	void RotateView(float angle, float X, float Y, float Z);

	// This moves the camera's view by the mouse movements (First person view)
	void SetViewByMouse(); 

	// This rotates the camera around a point (I.E. your character).
	void RotateAroundPoint(CVector3 vCenter, float X, float Y, float Z);

	// This strafes the camera left or right depending on the speed (+/-) 
	void StrafeCamera(float speed);

	// This will move the camera forward or backward depending on the speed
	void MoveCamera(float speed);

	// This checks for keyboard movement
	void CheckForMovement(float g_DT);

	// This updates the camera's view and other data (Should be called each frame)
	void Update(float g_DT);

	// This uses gluLookAt() to tell OpenGL where to look
	void Look();

	float Speed(float g_DT);

private:

	// The camera's position
	CVector3 m_vPosition;					

	// The camera's view
	CVector3 m_vView;						

	// The camera's up vector
	CVector3 m_vUpVector;		
	
	// The camera's strafe vector
	CVector3 m_vStrafe;			

	LDL::Input::Mouse _Mouse;

	int _Width;
	int _Height;
};

#endif


/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// Nothing was added to this file since the Camera5 tutorial on strafing.
//
//
// �2000-2005 GameTutorials
//
//
