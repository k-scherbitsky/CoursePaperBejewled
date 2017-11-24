//
// Created by konstantin on 23.11.17.
//

#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include "basicFigures.h"



void drawLine(double x0, double y0, double x, double y){
    glBegin(GL_LINE_STIPPLE);
    glVertex2d(x0, y0);
    glVertex2d(x, y);
    glEnd();
}

void drawRegtangle(double x0, double y0, double x, double y){
    glBegin(GL_LINE_LOOP);
    glVertex2d(x0, y0);
    glVertex2d(x, y0);
    glVertex2d(x, y);
    glVertex2d(x0, y);
    glEnd();
}

void drawFillRectangle(double x0, double y0, double x, double y){
    glBegin(GL_POLYGON);

    glTexCoord2d(0, 0);
    glVertex2d(x0, y0);

    glTexCoord2d(1, 0);
    glVertex2d(x, y0);

    glTexCoord2d(1, 1);
    glVertex2d(x, y);

    glTexCoord2d(0, 1);
    glVertex2d(x0, y);

    glEnd();
}

void createTextureRectangle(double x0, double y0, double x, double y){
    glBegin(GL_POLYGON);
    glTexCoord2d(x0, y0);
    glTexCoord2d(x, y0);
    glTexCoord2d(x, y);
    glTexCoord2d(x0, y);
    glEnd();
}

void drawTriangle(double x0, double y0, double x1, double y1, double x2, double y2){
    glBegin(GL_LINE_LOOP);
    glVertex2d(x0, y0);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
}

void drawFillTriangle(double x0, double y0, double x1, double y1, double x2, double y2){
    glBegin(GL_TRIANGLES);
    glTexCoord2d(0, 0);
    glVertex2d(x0, y0);
    glTexCoord2d(0, 1);
    glVertex2d(x1, y1);
    glTexCoord2d(1, 0);
    glVertex2d(x2, y2);
    glEnd();
}

void createTextureTriangle(double x0, double y0, double x1, double y1, double x2, double y2){
    glBegin(GL_TRIANGLES);
    glTexCoord2d(x0, y0);
    glTexCoord2d(x1, y1);
    glTexCoord2d(x2, y2);
    glEnd();
}

void drawEllipse(int slices, double x, double y){
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= slices; i++) {
        double rad = i * M_PI / 180;
        glVertex2d(cos(rad) * x, sin(rad) * y);
    }
    glEnd();
}

void drawFillEllipse(int slices, double x, double y){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= slices; ++i) {
        double rad = i * 2 * M_PI / slices;
        glVertex2d(sin(rad) * x, cos(rad) * y);
    }
    glEnd();
}

void createTextureEllipse(int slices, double x, double y);


void setColorRGB(double red, double green, double blue){
    double r = red / 255;
    double g = green / 255;
    double b = blue / 255;
    glColor3d(r, g, b);
}

void reshapeSize(int w, int h){
    if (h == 0) {
        h = 1;
    }
    double ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void createWindow(int args, char **argv, int w, int h){
    glutInit(&args, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(w, h);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Bejeweled");
    glClearColor(1, 1, 1, 0);
    glEnable(GL_DEPTH_TEST);
}



