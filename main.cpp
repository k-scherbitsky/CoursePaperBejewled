#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFigures.h"

GLuint texture[8];

void draw();


int main(int args, char **argv) {
    createWindow(args, argv, 550, 450);

    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeSize);
    glutIdleFunc(draw);

    texture[1] = LoadTexture((char *) "../resources/textures/Background.bmp", 0);
    texture[2] = LoadTexture((char *) "../resources/textures/Blue.bmp", 1);

    glutMainLoop();

    return 0;
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(
            0, 0, 10,
            0, 0, 0,
            0, 1, 0);
//    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    setColorRGB(255, 0, 255);
    drawFillRectangle(-5, 4, 5, -4, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    setColorRGB(255, 255, 0);
    glRotated(180,0,0,1);
    glTranslated(0.05, 0.40, 0);
    drawFillRectangle(-0.35, 0.35, 0.35, -0.35, 0.01);



    glutSwapBuffers();
}
