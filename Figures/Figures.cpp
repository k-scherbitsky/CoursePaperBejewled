//
// Created by konstantin on 26.11.17.
//

#include <GL/glut.h>
#include <cmath>
#include "Figures.h"
#include "../BasicFunc/BasicFunc.h"
#include "../CONSTANTS.h"

void partOfCursor(double x1, double x2, double y1, double y2);

int drawBlueGem(double x, double y, double alpha) {
    glTranslated(x, y, 0);

    glBegin(GL_POLYGON);
    setColorRGBA(176, 224, 230, alpha);
    glVertex3d(0.125, 0.25, Z_AXIS_GEMS);
    glVertex3d(0.375, 0.125, Z_AXIS_GEMS);

    setColorRGBA(0, 191, 255, alpha);
    glVertex3d(0.625, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.25, Z_AXIS_GEMS);

    setColorRGBA(0, 0, 128, alpha);
    glVertex3d(0.5, 0.875, Z_AXIS_GEMS);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, alpha);
    glBegin(GL_LINE_LOOP);

    glVertex3d(0.125, 0.25, Z_AXIS_GEMS);
    glVertex3d(0.375, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.625, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.25, Z_AXIS_GEMS);
    glVertex3d(0.5, 0.875, Z_AXIS_GEMS);

    glEnd();

    return 0;
}

int drawGreenGem(double x, double y, double alpha) {
    glTranslated(x, y, 0);

    glEnable(GL_BLEND);


    glBegin(GL_POLYGON);

    setColorRGBA(0, 100, 0, alpha);
    glVertex3d(0.125, 0.25, Z_AXIS_GEMS);
    glVertex3d(0.25, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.75, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.25, Z_AXIS_GEMS);

    setColorRGBA(144, 238, 144, alpha);
    glVertex3d(0.875, 0.75, Z_AXIS_GEMS);
    glVertex3d(0.75, 0.875, Z_AXIS_GEMS);

    setColorRGBA(0, 255, 127, alpha);
    glVertex3d(0.25, 0.875, Z_AXIS_GEMS);
    glVertex3d(0.125, 0.75, Z_AXIS_GEMS);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, alpha);
    glBegin(GL_LINE_LOOP);

    glVertex3d(0.125, 0.25, Z_AXIS_GEMS);
    glVertex3d(0.25, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.75, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.25, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.75, Z_AXIS_GEMS);
    glVertex3d(0.75, 0.875, Z_AXIS_GEMS);
    glVertex3d(0.25, 0.875, Z_AXIS_GEMS);
    glVertex3d(0.125, 0.75, Z_AXIS_GEMS);

    glEnd();
    glDisable(GL_BLEND);
    return 1;
}

int drawOrangeGem(double x, double y, double alpha) {
    glTranslated(x, y, 0);

    glTranslated(0.5, 0.5, 0);
    setColorRGBA(254, 224, 0, alpha);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 6; ++i) {
        double rad = i * 2 * M_PI / 6;
        setColorRGBA(245, 125, 0, 100);
        glVertex3d(cos(rad) * 0.375, sin(rad) * 0.375, Z_AXIS_GEMS);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, alpha);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 3;
        glVertex3d(cos(rad) * 0.375, sin(rad) * 0.375, Z_AXIS_GEMS);
    }
    glEnd();
    glTranslated(0, 0, 0);

    glDisable(GL_BLEND);
    return 2;
}

int drawPurpleGem(double x, double y, double alpha) {
    glTranslated(x, y, 0);

    glEnable(GL_BLEND);


    glTranslated(0.5, 0.5, 0);
    setColorRGBA(236, 183, 225, alpha);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 3; ++i) {
        double rad = i * 2 * M_PI / 3;
        setColorRGBA(128, 0, 128, alpha);
        glVertex3d(cos(rad) * 0.375, sin(rad) * 0.375, Z_AXIS_GEMS);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, alpha);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 1.5;
        glVertex3d(cos(rad) * 0.375, sin(rad) * 0.375, Z_AXIS_GEMS);
    }
    glEnd();
    glTranslated(0, 0, 0);
    glDisable(GL_BLEND);
    return 3;
}

int drawRedGem(double x, double y, double alpha) {
    glTranslated(x, y, 0);

    glEnable(GL_BLEND);


    glBegin(GL_POLYGON);

    setColorRGBA(255, 0, 0, alpha);
    glVertex3d(0.125, 0.1875, Z_AXIS_GEMS);
    glVertex3d(0.1875, 0.125, Z_AXIS_GEMS);

//    setColorRGBA(32,178,170);
    glVertex3d(0.8125, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.1875, Z_AXIS_GEMS);

    setColorRGBA(255, 228, 225, alpha);
    glVertex3d(0.875, 0.8125, Z_AXIS_GEMS);
    glVertex3d(0.8125, 0.875, Z_AXIS_GEMS);

    setColorRGBA(240, 128, 128, alpha);
    glVertex3d(0.1875, 0.875, Z_AXIS_GEMS);
    glVertex3d(0.125, 0.8125, Z_AXIS_GEMS);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, alpha);
    glBegin(GL_LINE_LOOP);

    glVertex3d(0.125, 0.1875, Z_AXIS_GEMS);
    glVertex3d(0.1875, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.8125, 0.125, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.1875, Z_AXIS_GEMS);
    glVertex3d(0.875, 0.8125, Z_AXIS_GEMS);
    glVertex3d(0.8125, 0.875, Z_AXIS_GEMS);
    glVertex3d(0.1875, 0.875, Z_AXIS_GEMS);

    glEnd();
    glDisable(GL_BLEND);
    return 4;
}

int drawYellowGem(double x, double y, double alpha) {
    glTranslated(x, y, 0);

    glEnable(GL_BLEND);

    glTranslated(0.5, 0.5, 0);

    setColorRGBA(254, 254, 162, alpha);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 4; ++i) {
        double rad = i * 2 * M_PI / 4;
        setColorRGBA(255, 255, 0, alpha);
        glVertex3d(cos(rad) * 0.375, sin(rad) * 0.375, Z_AXIS_GEMS);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, alpha);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 2;
        glVertex3d(cos(rad) * 0.375, sin(rad) * 0.375, Z_AXIS_GEMS);
    }
    glEnd();
    glTranslated(0, 0, 0);
    glDisable(GL_BLEND);
    return 5;
}

int drawCursorGem(double x, double y, bool isMoveCursorGem) {
    if (!isMoveCursorGem)
        return -1;

    glTranslated(x, y, 0);

    /*

     2________1
     |      /
     |     /
     |    /
     |   /
     |  /
     | /
     |/
     3

      */

    partOfCursor(0.25, 0, 0, 0.25);
    partOfCursor(0.75, 1, 0, 0.25);
    partOfCursor(0.75, 1, 1, 0.75);
    partOfCursor(0.25, 0, 1, 0.75);

    glTranslated(-x, -y, 0);
    return 6;
}

int drawCursorMenu(double x, double y, bool isMoveCursorMenu) {
    if (!isMoveCursorMenu)
        return -1;

    glTranslated(x, y, 0);
    setColorRGBA(192, 192, 192, 100);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0, 0, Z_AXIS_MENU_TEXT);
    glVertex3d(0.2, 0.1, Z_AXIS_MENU_TEXT);
    glVertex3d(0.0, 0.2, Z_AXIS_MENU_TEXT);
    glEnd();

    glTranslated(-x, -y, 0);
    return 7;

}

void partOfCursor(double x1, double x2, double y1, double y2) {
    setColorRGBA(176, 224, 230, 100);
    glBegin(GL_POLYGON);
    glVertex3d(x1, y1, Z_AXIS_CURSOR);
    glVertex3d(x2, y1, Z_AXIS_CURSOR);
    glVertex3d(x2, y2, Z_AXIS_CURSOR);
    glEnd();
}
