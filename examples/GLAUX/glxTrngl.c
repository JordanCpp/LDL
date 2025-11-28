// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/GLAUX/glaux.h>

void Reshape(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); glVertex3f(-0.6f, -0.75f, 0.5f);
    glColor3f(0, 1, 0); glVertex3f(0.6f, -0.75f, 0.0f);
    glColor3f(0, 0, 1); glVertex3f(0.0f, 0.75f, 0.0f);
    glEnd();
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 640, 480);
    auxInitWindow(__FILE__);
    auxReshapeFunc(Reshape);
    auxMainLoop(Draw);

    return 0;
}
