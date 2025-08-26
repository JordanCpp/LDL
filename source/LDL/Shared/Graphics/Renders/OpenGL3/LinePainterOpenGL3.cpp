// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "LinePainterOpenGL3.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

LinePainter::LinePainter(ShaderLoader* shaderLoader) :
    _shaderLoader(shaderLoader)
{
    _shaderLoader->Load("LDL_Shaders/OpenGL3/LinePainter.vs");
    const char* vertexSource = _shaderLoader->Result();

    GLint success = 0;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    _shaderLoader->Load("LDL_Shaders/OpenGL3/LinePainter.fs");
    const char* fragmentSource = _shaderLoader->Result();

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

    glGenVertexArrays(1, &_vertexArraysObject);
    glGenBuffers(1, &_vertexBufferObject);
    glBindVertexArray(_vertexArraysObject);

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_lines), NULL, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
LinePainter::~LinePainter()
{
    glDeleteVertexArrays(1, &_vertexArraysObject);
    glDeleteBuffers(1, &_vertexBufferObject);
    glDeleteProgram(_shaderProgram);
}

void LinePainter::Draw(Mat4f proj, Vec3f start, Vec3f end, Vec3f color)
{
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);

    _lines[0].x = start.x;
    _lines[0].y = start.y;
    _lines[0].z = start.z;

    _lines[1].x = end.x;
    _lines[1].y = end.y;
    _lines[1].z = end.z;

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(_lines), _lines);

    glUseProgram(_shaderProgram);

    glUniformMatrix4fv(glGetUniformLocation(_shaderProgram, "projection"), 1, GL_FALSE, proj.Values());
    glUniform3fv(glGetUniformLocation(_shaderProgram, "color"), 1, (GLfloat*)&color);

    glBindVertexArray(_vertexArraysObject);
    glDrawArrays(GL_LINES, 0, 2);
}
