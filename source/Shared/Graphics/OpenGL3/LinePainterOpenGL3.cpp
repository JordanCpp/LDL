#include "LinePainterOpenGL3.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

LinePainter::LinePainter(ShaderLoader* shaderLoader) :
    _ShaderLoader(shaderLoader)
{
    _ShaderLoader->Load("LDL_Shaders/OpenGL3/LinePainter.vs");
    const char* vertexSource = _ShaderLoader->Result().c_str();

    GLint success = 0;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    _ShaderLoader->Load("LDL_Shaders/OpenGL3/LinePainter.fs");
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

    glGenVertexArrays(1, &_VertexArraysObject);
    glGenBuffers(1, &_VertexBufferObject);
    glBindVertexArray(_VertexArraysObject);

    glBindBuffer(GL_ARRAY_BUFFER, _VertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_Lines), NULL, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
LinePainter::~LinePainter()
{
    glDeleteVertexArrays(1, &_VertexArraysObject);
    glDeleteBuffers(1, &_VertexBufferObject);
    glDeleteProgram(_ShaderProgram);
}

void LinePainter::Draw(Mat4f proj, Vec3f start, Vec3f end, Vec3f color)
{
    glBindBuffer(GL_ARRAY_BUFFER, _VertexBufferObject);

    _Lines[0].x = start.x;
    _Lines[0].y = start.y;
    _Lines[0].z = start.z;

    _Lines[1].x = end.x;
    _Lines[1].y = end.y;
    _Lines[1].z = end.z;

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(_Lines), _Lines);

    glUseProgram(_ShaderProgram);

    glUniformMatrix4fv(glGetUniformLocation(_ShaderProgram, "projection"), 1, GL_FALSE, proj.Values());
    glUniform3fv(glGetUniformLocation(_ShaderProgram, "color"), 1, (GLfloat*)&color);

    glBindVertexArray(_VertexArraysObject);
    glDrawArrays(GL_LINES, 0, 2);
}