//
// Created by konstantin on 01.12.17.
//

#include <GL/glut.h>
#include "Score.h"
#include "../BasicFunc/BasicFunc.h"
#include "../CONSTANTS.h"

const char *scoreText = "Score: 59";
const char *timeText = "Time: 46:32";
const char *ok = "OK";
const char *records = "RECORD LIST";

void scoreWindow();

void scoreGame(bool isShowScore) {
    if (!isShowScore)
        return;
    // ========= ПРОТОТИП ==========
    renderBitmapString(10, 2, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, scoreText, 240, 230, 140);
    renderBitmapString(10, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, timeText, 240, 230, 140);
    // =============================

}

void menuScoreWindow(bool isShowScoreWindow) {
    if (!isShowScoreWindow)
        return;

    TextColor getColorText = {240, 230, 140};

    // ========= ПРОТОТИП ==========

    glLineWidth(0.1);
    glBegin(GL_LINE_STRIP);
    setColorRGBA(0, 0, 0, 100);
    glVertex3d(8.25, 2.5, Z_AXIS_MENU_ITEM_TEXT);
    glVertex3d(8.25, 7.5, Z_AXIS_MENU_ITEM_TEXT);
    glEnd();

    for (double j = 3.02; j < 8 ; j += 0.5) {
        glLineWidth(0.1);
        glBegin(GL_LINE_STRIP);
        setColorRGBA(0, 0, 0, 100);
        glVertex3d(5, j, Z_AXIS_MENU_ITEM_TEXT);
        glVertex3d(9, j, Z_AXIS_MENU_ITEM_TEXT);
        glEnd();
    }

    renderBitmapString(5.2, 3, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_HELVETICA_18, "First Player", 240, 230, 140);
    renderBitmapString(5.2, 3.5, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_HELVETICA_18, "Second Player", 240, 230, 140);
    renderBitmapString(8.3, 3, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_HELVETICA_18, "69", 240, 230, 140);
    renderBitmapString(8.3, 3.5, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_HELVETICA_18, "105", 240, 230, 140);

    // ============================


    renderBitmapString(5.5, 1.5, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_TIMES_ROMAN_24, records, 240, 230, 140);
    renderBitmapString(6.7, 9.1, Z_AXIS_MENU_BUTTON_TEXT, GLUT_BITMAP_TIMES_ROMAN_24, ok,
                       getColorText.R, getColorText.G, getColorText.B);

    scoreWindow();
}

void scoreWindow() {
    //Window
    setColorRGBA(0, 0, 128, 90);
    glBegin(GL_POLYGON);
    glVertex3d(3, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 9, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(3, 9, Z_AXIS_MENU_ITEM);
    glEnd();

    //Border of Window
    glLineWidth(2.5);
    setColorRGBA(0, 191, 255, 90);
    glBegin(GL_LINE_LOOP);
    glVertex3d(3, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 9, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(3, 9, Z_AXIS_MENU_ITEM);
    glEnd();

    //Button
    setColorRGBA(25, 25, 112, 100);
    glBegin(GL_POLYGON);
    glVertex3d(6, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 9.25, Z_AXIS_MENU_BUTTON);
    glVertex3d(6, 9.25, Z_AXIS_MENU_BUTTON);
    glEnd();

    //Border of Button
    glLineWidth(2.5);
    setColorRGBA(0, 191, 255, 95);
    glBegin(GL_LINE_LOOP);
    glVertex3d(6, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 9.25, Z_AXIS_MENU_BUTTON);
    glVertex3d(6, 9.25, Z_AXIS_MENU_BUTTON);
    glEnd();

}