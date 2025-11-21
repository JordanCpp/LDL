// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Renders/GL3/TexGL3.hpp>
#include <LDL/Renders/GL3/PaintGL3.hpp>

TexturePainter::TexturePainter(ShaderLoader* shaderLoader) :
	_shaderLoader(shaderLoader),
    _shaderProgram(0),
    _vertexBufferObject(0),
    _vertexArraysObject(0),
    _elementBufferObject(0)
{
    _shaderLoader->Load("LDL_Shaders/OpenGL3/TexturePainter.vs");
    const char* vertexSource = _shaderLoader->LDL_Result();

    GLint success = 0;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    _shaderLoader->Load("LDL_Shaders/OpenGL3/TexturePainter.fs");
    const char* fragmentSource = _shaderLoader->LDL_Result();

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);

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

    glGenVertexArrays(1, &_vertexArraysObject);
    glGenBuffers(1, &_vertexBufferObject);

    glBindVertexArray(_vertexArraysObject);

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
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

void TexturePainter::Draw(Mat4f proj, LDL_ITexture* texture)
{
    LDL_UNUSED(proj);

    GLuint id = (GLuint)((TextureImplOpenGL3*)texture)->Id();

    glBindTexture(GL_TEXTURE_2D, id);

    glUseProgram(_shaderProgram);

    //glUniformMatrix4fv(glGetUniformLocation(_ShaderProgram, "projection"), 1, GL_FALSE, proj.Values());

    glBindVertexArray(_vertexArraysObject);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}
