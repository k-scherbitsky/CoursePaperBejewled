#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFigures.h"
#include "Figures/figures.h"
#include "Menu/menu.h"
#include "Constants/constChar.h"
#include <iostream>

using namespace std;
int pos[8][8];
double interval = 0.7;
bool isShowMenu = false;

void draw();

void drawCell();
void cellFilling();

void processNormalKeys(unsigned char key, int x, int y);

int main(int args, char **argv) {
    createWindow(args, argv, 845, 700);
    cellFilling();
    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeSize);
    glutKeyboardFunc(processNormalKeys);
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
    setBackground();
    drawCell();
    menu(isShowMenu);
    glutSwapBuffers();
}

void cellFilling(){

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pos[i][j] = rand() % 6;
        }
    }

}

void drawCell() {
    glTranslated(-4, -1.5, 0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (pos[i][j]) {
                case 0:
                    glPushMatrix();
                    drawBlueGem(i * interval, j * interval);
                    glPopMatrix();
                    break;
                case 1:
                    glPushMatrix();
                    drawGreenGem(i * interval, j * interval);
                    glPopMatrix();
                    break;
                case 2:
                    glPushMatrix();
                    drawOrangeGem(i * interval, j * interval);
                    glPopMatrix();
                    break;
                case 3:
                    glPushMatrix();
                    drawPurpleGem(i * interval, j * interval);
                    glPopMatrix();
                    break;
                case 4:
                    glPushMatrix();
                    drawRedGem(i * interval, j * interval);
                    glPopMatrix();
                    break;
                case 5:
                    glPushMatrix();
                    drawYellowGem(i * interval, j * interval);
                    glPopMatrix();
                    break;
                default:break;
            }

        }
    }
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 27: {
            cout << "pressed esc" << endl;
            glutPostRedisplay();
            isShowMenu = !isShowMenu;
            cout << "=" << isShowMenu << endl << endl;
            break;
        }
        default:break;
    }
}
