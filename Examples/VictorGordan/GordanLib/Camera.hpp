#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "shaderClass.h"

#include <LDL/Events/Event.hpp>
#include <LDL/Input/Mouse.hpp>

class Camera
{
public:
	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	// Updates and exports the camera matrix to the Vertex Shader
	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
	void Matrix(Shader& shader, const char* uniform);
	// Handles camera inputs
	void Inputs(LDL::Event& window);

	LDL::Input::Mouse mMouse;
	// Stores the main vectors of the camera
	glm::vec3 Position;
	glm::vec3 Orientation;
	glm::vec3 Up;
	glm::mat4 cameraMatrix;

	// Prevents the camera from jumping around when first clicking left click
	bool firstClick;

	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed;
	float sensitivity;
};

#endif