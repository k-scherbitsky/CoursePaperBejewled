#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFigures.h"
#include "Figures/figures.h"
#include <iostream>

using namespace std;
int pos[8][8];

void draw();


int main(int args, char **argv) {
    createWindow(args, argv, 850, 750);

    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeSize);
//    glutIdleFunc(draw);

    glutMainLoop();

    return 0;
}

void draw() {
    srand(time(0));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(
            0, 0, 10,
            0, 0, 0,
            0, 1, 0);
    setBackround();

    for (int i = -6; i < 2; i += rand() % 5) {
        for (int j = 5; j > -3; j -= rand() % 5 ) {
            glPushMatrix();
            glTranslatef(i * 0.7, j * 0.7, 0);
            drawBlueGem();
            glPopMatrix();
        }
    }

    for (int i = -6; i < 2; i += rand() % 5) {
        for (int j = 5; j > -3; j -= rand() % 5 ) {
            glPushMatrix();
            glTranslatef(i * 0.7, j * 0.7, 0);
            drawBlueGem();
            glPopMatrix();
        }
    }

    for (int i = -6; i < 2; i += rand() % 5) {
        for (int j = 5; j > -3; j -= rand() % 5 ) {
            glPushMatrix();
            glTranslatef(i * 0.7, j * 0.7, 0);
            drawGreenGem();
            glPopMatrix();
        }
    }

    for (int i = -6; i < 2; i += rand() % 5) {
        for (int j = 5; j > -3; j -= rand() % 5 ) {
            glPushMatrix();
            glTranslatef(i * 0.7, j * 0.7, 0);
            drawOrangeGem();
            glPopMatrix();
        }
    }

    for (int i = -6; i < 2; i += rand() % 5) {
        for (int j = 5; j > -3; j -= rand() % 5 ) {
            glPushMatrix();
            glTranslatef(i * 0.7, j * 0.7, 0);
            drawPurpleGem();
            glPopMatrix();
        }
    }

    for (int i = -6; i < 2; i += rand() % 5) {
        for (int j = 5; j > -3; j -= rand() % 5 ) {
            glPushMatrix();
            glTranslatef(i * 0.7, j * 0.7, 0);
            drawRedGem();
            glPopMatrix();
        }
    }

    for (int i = -6; i < 2; i += rand() % 5) {
        for (int j = 5; j > -3; j -= rand() % 5 ) {
            glPushMatrix();
            glTranslatef(i * 0.7, j * 0.7, 0);
            drawYellowGem();
            glPopMatrix();
        }
    }

    glutSwapBuffers();
}
