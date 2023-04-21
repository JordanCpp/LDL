#include "TexturePainter.hpp"
#include "TextureImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TexturePainter::TexturePainter(ShaderLoader* shaderLoader) :
	_ShaderLoader(shaderLoader),
    _ShaderProgram(0),
    _VertexBufferObject(0),
    _VertexArraysObject(0),
    _ElementBufferObject(0)
{
    _ShaderLoader->Load("LDL_Shaders/OpenGL3/TexturePainter.vs");
    const char* vertexSource = _ShaderLoader->Result().c_str();

    GLint success = 0;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    _ShaderLoader->Load("LDL_Shaders/OpenGL3/TexturePainter.fs");
    const char* fragmentSource = _ShaderLoader->Result().c_str();

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    _ShaderProgram = glCreateProgram();
    glAttachShader(_ShaderProgram, vertexShader);
    glAttachShader(_ShaderProgram, fragmentShader);
    glLinkProgram(_ShaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] =
    {
         0.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
         0.0f,  0.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
         1.0f,  0.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,

         0.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
         1.0f,  0.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f
    };

    glGenVertexArrays(1, &_VertexArraysObject);
    glGenBuffers(1, &_VertexBufferObject);

    glBindVertexArray(_VertexArraysObject);

    glBindBuffer(GL_ARRAY_BUFFER, _VertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void TexturePainter::Draw(Mat4f proj, Texture* texture)
{
   glBindTexture(GL_TEXTURE_2D, (GLuint)texture->GetTextureImpl()->Id());

   glUseProgram(_ShaderProgram);

   //glUniformMatrix4fv(glGetUniformLocation(_ShaderProgram, "projection"), 1, GL_FALSE, proj.Values());

   glBindVertexArray(_VertexArraysObject);

   glDrawArrays(GL_TRIANGLES, 0, 6);
}