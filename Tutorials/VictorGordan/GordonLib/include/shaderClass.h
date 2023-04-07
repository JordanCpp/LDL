#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <LDL/OpenGL/OpenGL3_3.hpp>

#include <string>


std::string get_file_contents(const std::string& filename);

class Shader
{
public:
	// Reference ID of the Shader Program
	GLuint ID;
	// Constructor that build the Shader Program from 2 different shaders
	Shader(const std::string& vertexFile, const std::string& fragmentFile);

	// Activates the Shader Program
	void Activate();
	// Deletes the Shader Program
	void Delete();
private:
	// Checks if the different Shaders have compiled properly
	void compileErrors(unsigned int shader, const char* type);
};


#endif