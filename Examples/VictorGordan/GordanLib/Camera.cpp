#include "Camera.hpp"
#include <stdlib.h>

using namespace LDL::Math;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Input;

Camera::Camera(int width, int height, glm::vec3 position) :
	Orientation(glm::vec3(0.0f, 0.0f, -1.0f)),
	Up(glm::vec3(0.0f, 1.0f, 0.0f)),
	cameraMatrix(glm::mat4(1.0f)),
	firstClick(true),
	speed(0.1f),
	sensitivity(100.0f)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Makes camera look in the right direction from the right position
	view = glm::lookAt(Position, Position + Orientation, Up);
	// Adds perspective to the scene
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	// Sets new camera matrix
	cameraMatrix = projection * view;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Makes camera look in the right direction from the right position
	view = glm::lookAt(Position, Position + Orientation, Up);
	// Adds perspective to the scene
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	// Exports the camera matrix to the Vertex Shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}

void Camera::Matrix(Shader& shader, const char* uniform)
{
	// Exports camera matrix
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::Inputs(Event& window)
{
	// Handles key inputs
	if (window.IsKeyPressed(KeyboardKey::W))
	{
		Position += speed * Orientation;
	}

	if (window.IsKeyPressed(KeyboardKey::A))
	{
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}

	if (window.IsKeyPressed(KeyboardKey::S))
	{
		Position += speed * -Orientation;
	}

	if (window.IsKeyPressed(KeyboardKey::D))
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}

	if (window.IsKeyPressed(KeyboardKey::Space))
	{
		Position += speed * Up;
	}

	if (window.IsKeyPressed(KeyboardKey::LeftControl))
	{
		Position += speed * -Up;
	}

	if (window.IsKeyPressed(KeyboardKey::Leftshift))
	{
		speed = 0.4f;
	}

	if (window.IsKeyReleased(KeyboardKey::Leftshift))
	{
		speed = 0.1f;
	}

	// Handles mouse inputs
	if (window.IsMousePressed(MouseButton::Left))
	{
		// Prevents camera from jumping on the first click
		if (firstClick)
		{
			mMouse.Pos(LDL::Math::Vec2u(width / 2, height / 2));
			firstClick = false;
		}

		// Stores the coordinates of the cursor
		double mouseX = (double)mMouse.Pos().x;
		double mouseY = (double)mMouse.Pos().y;

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		// Calculates upcoming vertical change in the Orientation
		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

		// Decides whether or not the next vertical Orientation is legal or not
		if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			Orientation = newOrientation;
		}

		// Rotates the Orientation left and right
		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		mMouse.Pos(LDL::Math::Vec2u(width / 2, height / 2));
	}
	else if (window.IsMouseReleased(MouseButton::Left))
	{
		// Makes sure the next time the camera looks around it doesn't jump
		//firstClick = true;
	}
}