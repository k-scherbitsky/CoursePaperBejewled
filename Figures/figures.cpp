//
// Created by konstantin on 26.11.17.
//

#include <GL/glut.h>
#include <cmath>
#include "figures.h"
#include "../BasicFunc/basicFigures.h"

void partOfCursor(double x1, double x2, double y1, double y2);

int drawBlueGem(double x, double y) {
    glTranslated(x, y, 0);

    glBegin(GL_POLYGON);

    setColorRGBA(176, 224, 230, 100);
    glVertex3d(-0.25, 0.2, 0.1);
    glVertex3d(-0.2, 0.25, 0.1);
    setColorRGBA(0, 191, 255, 100);
    glVertex3d(0.2, 0.25, 0.1);
    glVertex3d(0.25, 0.2, 0.1);
    setColorRGBA(0, 0, 128, 100);
    glVertex3d(0, -0.2, 0.1);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, 100);
    glBegin(GL_LINE_LOOP);

    glVertex3d(-0.25, 0.2, 0.1);
    glVertex3d(-0.2, 0.25, 0.1);
    glVertex3d(0.2, 0.25, 0.1);
    glVertex3d(0.25, 0.2, 0.1);
    glVertex3d(0, -0.2, 0.1);

    glEnd();
    return 0;
}

int drawGreenGem(double x, double y) {
    glTranslated(x, y, 0);

    glBegin(GL_POLYGON);

    setColorRGBA(0, 100, 0, 100);
    glVertex3d(-0.25, 0.2, 0.1);
    glVertex3d(-0.2, 0.25, 0.1);
    glVertex3d(0.2, 0.25, 0.1);
    glVertex3d(0.25, 0.2, 0.1);

    setColorRGBA(144, 238, 144, 100);
    glVertex3d(0.25, -0.2, 0.1);
    glVertex3d(0.2, -0.25, 0.1);

    setColorRGBA(0, 255, 127, 100);
    glVertex3d(-0.2, -0.25, 0.1);
    glVertex3d(-0.25, -0.2, 0.1);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, 100);
    glBegin(GL_LINE_LOOP);

    glVertex3d(-0.25, 0.2, 0.1);
    glVertex3d(-0.2, 0.25, 0.1);
    glVertex3d(0.2, 0.25, 0.1);
    glVertex3d(0.25, 0.2, 0.1);
    glVertex3d(0.25, -0.2, 0.1);
    glVertex3d(0.2, -0.25, 0.1);
    glVertex3d(-0.2, -0.25, 0.1);
    glVertex3d(-0.25, -0.2, 0.1);

    glEnd();
    return 1;
}

int drawOrangeGem(double x, double y) {
    glTranslated(x, y, 0);

    setColorRGBA(254, 224, 0, 100);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 6; ++i) {
        double rad = i * 2 * M_PI / 6;
        setColorRGBA(245, 125, 0, 100);
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, 100);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 3;
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();
    return 2;
}

int drawPurpleGem(double x, double y) {
    glTranslated(x, y, 0);

    setColorRGBA(236, 183, 225, 100);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 3; ++i) {
        double rad = i * 2 * M_PI / 3;
        setColorRGBA(128, 0, 128, 100);
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, 100);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 1.5;
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();
    return 3;
}

int drawRedGem(double x, double y) {
    glTranslated(x, y, 0);

    glBegin(GL_POLYGON);

    setColorRGBA(255, 0, 0, 100);
    glVertex3d(-0.25, 0.225, 0.1);
    glVertex3d(-0.225, 0.25, 0.1);

//    setColorRGBA(32,178,170);
    glVertex3d(0.225, 0.25, 0.1);
    glVertex3d(0.25, 0.225, 0.1);

    setColorRGBA(255, 228, 225, 100);
    glVertex3d(0.25, -0.225, 0.1);
    glVertex3d(0.225, -0.25, 0.1);

    setColorRGBA(240, 128, 128, 100);
    glVertex3d(-0.225, -0.25, 0.1);
    glVertex3d(-0.25, -0.225, 0.1);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, 100);
    glBegin(GL_LINE_LOOP);

    glVertex3d(-0.25, 0.225, 0.1);
    glVertex3d(-0.225, 0.25, 0.1);
    glVertex3d(0.225, 0.25, 0.1);
    glVertex3d(0.25, 0.225, 0.1);
    glVertex3d(0.25, -0.225, 0.1);
    glVertex3d(0.225, -0.25, 0.1);
    glVertex3d(-0.225, -0.25, 0.1);
    glVertex3d(-0.25, -0.225, 0.1);

    glEnd();
    return 4;
}

int drawYellowGem(double x, double y) {
    glTranslated(x, y, 0);

    setColorRGBA(254, 254, 162, 100);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 4; ++i) {
        double rad = i * 2 * M_PI / 4;
        setColorRGBA(255, 255, 0, 100);
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGBA(0, 0, 0, 100);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 2;
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();
    return 5;
}

int drawCursor(double x, double y) {
    glTranslated(x, y, 0);

    partOfCursor(-0.15, -0.35, 0.35, 0.15);
    partOfCursor(0.15, 0.35, 0.35, 0.15);
    partOfCursor(0.15, 0.35, -0.35, -0.15);
    partOfCursor(-0.15, -0.35, -0.35, -0.15);

    glTranslated(-x, -y, 0);
    return 6;
}

void partOfCursor(double x1, double x2, double y1, double y2) {
    setColorRGBA(176, 224, 230, 100);
    glBegin(GL_POLYGON);
    glVertex3d(x1, y1, 0.11);
    glVertex3d(x2, y1, 0.11);
    glVertex3d(x2, y2, 0.11);
    glEnd();
}