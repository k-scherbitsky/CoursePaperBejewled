//
// Created by konstantin on 23.11.17.
//

#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include "basicFigures.h"
#include <iostream>

GLuint textureID[8];
struct {
    int W;
    int H;
    unsigned char *Image;
} getTexture[8];

void drawRegtangle(double x0, double y0, double x, double y) {
    glBegin(GL_LINE_LOOP);
    glVertex2d(x0, y0);
    glVertex2d(x, y0);
    glVertex2d(x, y);
    glVertex2d(x0, y);
    glEnd();
}

void drawFillRectangle(double x0, double y0, double x, double y, double z) {
    glBegin(GL_POLYGON);

    glVertex3d(x0, y0, z);
    glVertex3d(x, y0, z);

    glVertex3d(x, y, z);
    glVertex3d(x0, y, z);

    glEnd();
}

void createTextureRectangle(double x0, double y0, double x, double y, double z) {
    glBegin(GL_POLYGON);

    glTexCoord2d(0, 0);
    glVertex3d(x0, y0, z);

    glTexCoord2d(1, 0);
    glVertex3d(x, y0, z);

    glTexCoord2d(1, 1);
    glVertex3d(x, y, z);

    glTexCoord2d(0, 1);
    glVertex3d(x0, y, z);

    glEnd();
}

void drawEllipse(int slices, double x, double y) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= slices; i++) {
        double rad = i * M_PI / 180;
        glVertex2d(cos(rad) * x, sin(rad) * y);
    }
    glEnd();
}

void drawFillEllipse(int slices, double x, double y) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0.0f, 0.0f);
    for (int i = 0; i <= slices; ++i) {
        double rad = i * 2 * M_PI / slices;
        glVertex2d(sin(rad) * x, cos(rad) * y);
    }
    glEnd();
}

void setColorRGBA(double red, double green, double blue, double opacity) {
    double r = red / 255;
    double g = green / 255;
    double b = blue / 255;
    double op = opacity / 100;
    glColor4d(r, g, b, op);
}

void reshapeSize(int w, int h) {
    if (h == 0) {
        h = 1;
    }
    double ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
//    glutReshapeWindow(845, 700);
}

void createWindow(int args, char **argv, int w, int h) {
    glutInit(&args, argv);
    glutInitWindowPosition(100, 0);
    glutInitWindowSize(w, h);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Bejeweled");
    glClearColor(1, 1, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
}

GLuint LoadTexture(char *FileName, int n) {
    FILE *F;
//     Открываем файл
    if ((F = fopen(FileName, "rb")) == nullptr)
        return false;
//    Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну
    fseek(F, 18, SEEK_SET);
    fread(&(getTexture[n].W), 2, 1, F);
    fseek(F, 2, SEEK_CUR);
    fread(&(getTexture[n].H), 2, 1, F);

    printf("%d x %d\n", getTexture[n].W, getTexture[n].H);

//     Выделяем память под изображение. Если память не выделилась, закрываем файл и выходим с ошибкой
    if ((getTexture[n].Image =
                 (unsigned char *) malloc(sizeof(unsigned char) * 3 * getTexture[n].W * getTexture[n].H)) == nullptr) {
        fclose(F);
        return false;
    }
//     Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя
    fseek(F, 30, SEEK_CUR);
    fread(getTexture[n].Image, 3, getTexture[n].W * getTexture[n].H, F);

    glGenTextures(n, &textureID[n]);
    glBindTexture(GL_TEXTURE_2D, textureID[n]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, getTexture[n].W, getTexture[n].H, GL_RGB, GL_UNSIGNED_BYTE,
                      getTexture[n].Image);
    free(getTexture[n].Image);
    fclose(F);

    return true;

}

void setBackground() {
    glBegin(GL_POLYGON);

    setColorRGBA(244, 164, 96, 100);
    glVertex3d(-5, 5, 0);
    glVertex3d(5, 5, 0);

    setColorRGBA(192, 192, 192, 100);
    glVertex3d(5, -5, 0);
    glVertex3d(-5, -5, 0);

    glEnd();
}

void renderBitmapString(float x, float y, float z, void *font, const char *string,
                        double red, double green, double blue) {
    setColorRGBA(red, green, blue, 100);
    const char *c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}



