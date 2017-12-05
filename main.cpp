#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFigures.h"
#include "Figures/figures.h"
#include "Menu/menu.h"
#include "Score/score.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

int pos[8][8];
double interval = 0.7;
bool isShowMenu = true;
bool isShowAbout = false;
bool isMoveCursor = false;
double zGem = 0.0;
double xCursor = -4;
double yCursor = -1.5;

void draw();

void drawCell();

void cellFilling();

void processNormalKeys(unsigned char key, int x, int y);

int main(int args, char **argv) {
    sf::Music music;
    if (!music.openFromFile("../resources/music/background_music.ogg"))
        return -1;
    music.setVolume(10);
    music.play();
    music.setLoop(true);

    createWindow(args, argv, 845, 700);
    cellFilling();
    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeSize);
    glutKeyboardFunc(processNormalKeys);
    glutIdleFunc(draw);

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
    drawCursor(xCursor, yCursor, isMoveCursor);
    menu(isShowMenu);
    scoreGame();
    drawWindowAbout(isShowAbout);
    glutSwapBuffers();
}

void cellFilling() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pos[i][j] = rand() % 3;
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
                    drawBlueGem(i * interval, j * interval, zGem);
                    glPopMatrix();
                    break;
                case 1:
                    glPushMatrix();
                    drawGreenGem(i * interval, j * interval, zGem);
                    glPopMatrix();
                    break;
                case 2:
                    glPushMatrix();
                    drawOrangeGem(i * interval, j * interval, zGem);
                    glPopMatrix();
                    break;
                case 3:
                    glPushMatrix();
                    drawPurpleGem(i * interval, j * interval, zGem);
                    glPopMatrix();
                    break;
                case 4:
                    glPushMatrix();
                    drawRedGem(i * interval, j * interval, zGem);
                    glPopMatrix();
                    break;
                case 5:
                    glPushMatrix();
                    drawYellowGem(i * interval, j * interval, zGem);
                    glPopMatrix();
                    break;
                default:
                    break;
            }

        }
    }
    glTranslated(4, 1.5, 0);
}

void matchFinding() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (pos[i][j] == pos[i + 1][j] && pos[i][j] == pos[i - 1][j]) {
                pos[i][j] = pos[i][j + 1];
                pos[i + 1][j] = pos[i + 1][j + 1];
                pos[i - 1][j] = pos[i - 1][j + 1];
            }
            if (pos[i][j] == pos[i][j + 1] && pos[i][j] == pos[i][j - 1]) {
                pos[i][j - 1] = pos[i][j + 4];
                pos[i][j] = pos[i][j + 3];
                pos[i][j + 1] = pos[i][j + 2];

            }

        }
    }
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 27: { // ESC
            if (!isShowMenu) {
                isShowMenu = true;
                isMoveCursor = false;
            } else {
                isShowMenu = false;
                isMoveCursor = true;
            }

            if (isShowAbout) {
                isShowMenu = true;
                isShowAbout = false;
                isMoveCursor = false;
            }
            break;
        }
        case 32:{

            matchFinding();

            break;
        }
        case 51: { // 3
            if (isShowMenu)
                exit(0);
        }
        case 52: { // 4
            if (isShowMenu) {
                if (!isShowAbout) {
                    isShowAbout = true;
                    isMoveCursor = false;
                } else {
                    isShowAbout = false;
                    isMoveCursor = false;
                }
            }
            break;
        }
        case 87: //w
        case 119: {
            if (!isShowMenu) {
                yCursor += interval;
                if (yCursor > 3.4)
                    yCursor = -1.5;
            }
            break;
        }
        case 83: //s
        case 115: {
            if (!isShowMenu) {
                yCursor -= interval;
                if (yCursor < -1.5)
                    yCursor = 3.4;
            }
            break;
        }
        case 65://a
        case 97: {
            if (!isShowMenu) {
                xCursor -= interval;
                if (xCursor < -4)
                    xCursor = 0.9;
            }
            break;
        }
        case 68://d
        case 100: {
            if (!isShowMenu) {
                xCursor += interval;
                if (xCursor > 0.9)
                    xCursor = -4;
            }
            break;
        }
        default:
            break;
    }
}
