#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFigures.h"
#include "Figures/figures.h"
#include <iostream>

using namespace std;
int pos[8][8];
double interval = 0.7;
struct piece {
    double x, y, col, row;
} grid[10][10];

enum gems {
    blue = 1, green, orange, purple, red, yellow
};

void draw();


void logic();

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
    logic();
    glutSwapBuffers();
}

void logic() {
    glTranslated(-4, -1.5, 0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pos[i][j] = rand() % 6;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (pos[i][j]) {
                case 0:
                    glPushMatrix();
                    drawBlueGem(i * interval, j * interval);
                    glPopMatrix();
                    continue;
                case 1:
                    glPushMatrix();
                    drawGreenGem(i * interval, j * interval);
                    glPopMatrix();
                    continue;
                case 2:
                    glPushMatrix();
                    drawOrangeGem(i * interval, j * interval);
                    glPopMatrix();
                    continue;
                case 3:
                    glPushMatrix();
                    drawPurpleGem(i * interval, j * interval);
                    glPopMatrix();
                    continue;
                case 4:
                    glPushMatrix();
                    drawRedGem(i * interval, j * interval);
                    glPopMatrix();
                    continue;
                case 5:
                    glPushMatrix();
                    drawYellowGem(i * interval, j * interval);
                    glPopMatrix();
                    continue;
            }

        }
    }
}
