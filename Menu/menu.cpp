//
// Created by konstantin on 29.11.17.
//

#include <GL/glut.h>
#include "menu.h"
#include "../BasicFunc/basicFigures.h"

const char *newGame = "New Game";
const char *score = "Score";
const char *exitGame = "Exit";
const char *about = "About";
const char *textAboutFirstLine = "Invented, painted, wrote the code - ";
const char *textAboutSecondLine = "Konstantin Scherbitsky(kostya.em2@gmail.com)";

void menu(bool isShowMenu) {
    if (!isShowMenu)
        return;

    drawWindowMenu();
    renderBitmapString(-1.5, 0.75, 0.22, GLUT_BITMAP_HELVETICA_18, newGame, 240, 230, 140);
    renderBitmapString(-1.5, 0.25, 0.22, GLUT_BITMAP_HELVETICA_18, score, 240, 230, 140);
    renderBitmapString(-1.5, -0.25, 0.22, GLUT_BITMAP_HELVETICA_18, exitGame, 240, 230, 140);
    renderBitmapString(-1.5, -0.75, 0.22, GLUT_BITMAP_HELVETICA_18, about, 240, 230, 140);
}

void drawWindowMenu() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    setColorRGBA(0, 0, 128, 95);

    glBegin(GL_POLYGON);
    glVertex3d(-3, 1.5, 0.2);
    glVertex3d(-2.5, 2, 0.2);
    glVertex3d(2.5, 2, 0.2);
    glVertex3d(3, 1.5, 0.2);
    glVertex3d(3, -1.5, 0.2);
    glVertex3d(2.5, -2, 0.2);
    glVertex3d(-2.5, -2, 0.2);
    glVertex3d(-3, -1.5, 0.2);
    glEnd();

    //Border
    glLineWidth(2.5);
    setColorRGBA(0, 191, 255, 95);

    glBegin(GL_LINE_LOOP);
    glVertex3d(-3, 1.5, 0.2);
    glVertex3d(-2.5, 2, 0.2);
    glVertex3d(2.5, 2, 0.2);
    glVertex3d(3, 1.5, 0.2);
    glVertex3d(3, -1.5, 0.2);
    glVertex3d(2.5, -2, 0.2);
    glVertex3d(-2.5, -2, 0.2);
    glVertex3d(-3, -1.5, 0.2);
    glEnd();

    glDisable(GL_BLEND);
}

void drawWindowAbout(bool isShowAbout) {
    if(!isShowAbout){
        return;
    }

    setColorRGBA(240, 255, 255, 98);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_POLYGON);
    glVertex3d(-1.5, 0.75, 0.3);
    glVertex3d(-1.25, 1, 0.3);
    glVertex3d(1.25, 1, 0.3);
    glVertex3d(1.5, 0.75, 0.3);
    glVertex3d(1.5, -0.75, 0.3);
    glVertex3d(1.25, -1, 0.3);
    glVertex3d(-1.25, -1, 0.3);
    glVertex3d(-1.5, -0.75, 0.3);
    glEnd();

    //Border
    glLineWidth(2);
    setColorRGBA(0, 191, 255, 95);

    glBegin(GL_LINE_LOOP);
    glVertex3d(-1.5, 0.75, 0.3);
    glVertex3d(-1.25, 1, 0.3);
    glVertex3d(1.25, 1, 0.3);
    glVertex3d(1.5, 0.75, 0.3);
    glVertex3d(1.5, -0.75, 0.3);
    glVertex3d(1.25, -1, 0.3);
    glVertex3d(-1.25, -1, 0.3);
    glVertex3d(-1.5, -0.75, 0.3);
    glEnd();

    glDisable(GL_BLEND);

    renderBitmapString(-1.2, 0.15, 0.32, GLUT_BITMAP_HELVETICA_12, textAboutFirstLine, 105, 105, 105);
    renderBitmapString(-1.45, 0.0, 0.32, GLUT_BITMAP_HELVETICA_12, textAboutSecondLine, 105, 105, 105);

}