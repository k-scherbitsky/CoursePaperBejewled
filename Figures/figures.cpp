//
// Created by konstantin on 26.11.17.
//

#include <GL/glut.h>
#include <cmath>
#include "figures.h"
#include "../BasicFunc/basicFigures.h"

void drawBlueGem() {
    glBegin(GL_POLYGON);

    setColorRGB(176,224,230);
    glVertex3d(-0.25, 0.2, 0.1);
    glVertex3d(-0.2, 0.25, 0.1);
    setColorRGB(0,191,255);
    glVertex3d(0.2, 0.25, 0.1);
    glVertex3d(0.25, 0.2, 0.1);
    setColorRGB(0,0,128);
    glVertex3d(0, -0.2, 0.1);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGB(0, 0, 0);
    glBegin(GL_LINE_LOOP);

    glVertex3d(-0.25, 0.2, 0.1);
    glVertex3d(-0.2, 0.25, 0.1);
    glVertex3d(0.2, 0.25, 0.1);
    glVertex3d(0.25, 0.2, 0.1);
    glVertex3d(0, -0.2, 0.1);

    glEnd();
}

void drawGreenGem() {

    glBegin(GL_POLYGON);

    setColorRGB(0,100,0);
    glVertex3d(-0.25, 0.2, 0.1);
    glVertex3d(-0.2, 0.25, 0.1);
    glVertex3d(0.2, 0.25, 0.1);
    glVertex3d(0.25, 0.2, 0.1);

    setColorRGB(144,238,144);
    glVertex3d(0.25, -0.2, 0.1);
    glVertex3d(0.2, -0.25, 0.1);

    setColorRGB(0,255,127);
    glVertex3d(-0.2, -0.25, 0.1);
    glVertex3d(-0.25, -0.2, 0.1);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGB(0, 0, 0);
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

}

void drawOrangeGem() {
    setColorRGB(254,224,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 6; ++i) {
        double rad = i * 2 * M_PI / 6;
        setColorRGB(245,125,0);
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGB(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 3;
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();
}

void drawPurple(double x0, double y0, double x1, double y1, double x2, double y2, double z) {

    setColorRGB(236,183,225);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 3; ++i) {
        double rad = i * 2 * M_PI / 3;
        setColorRGB(128,0,128);
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGB(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 1.5;
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

}

void drawRedGem() {

    glBegin(GL_POLYGON);

    setColorRGB(255,0,0);
    glVertex3d(-0.25, 0.225, 0.1);
    glVertex3d(-0.225, 0.25, 0.1);

//    setColorRGB(32,178,170);
    glVertex3d(0.225, 0.25, 0.1);
    glVertex3d(0.25, 0.225, 0.1);

    setColorRGB(255,228,225);
    glVertex3d(0.25, -0.225, 0.1);
    glVertex3d(0.225, -0.25, 0.1);

    setColorRGB(240,128,128);
    glVertex3d(-0.225, -0.25, 0.1);
    glVertex3d(-0.25, -0.225, 0.1);

    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGB(0, 0, 0);
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

}

void drawYellowGem() {

    setColorRGB(254,254,162);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= 4; ++i) {
        double rad = i * 2 * M_PI / 4;
        setColorRGB(255,255,0);
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

    //Border
    glLineWidth(1.5);
    setColorRGB(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        double rad = i * M_PI / 2;
        glVertex3d(cos(rad) * 0.25, sin(rad) * 0.25, 0.1);
    }
    glEnd();

}

