//
// Created by konstantin on 23.11.17.
//

#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include "BasicFunc.h"
#include "../CONSTANTS.h"
#include "../Structs.h"
#include <iostream>

GLuint textureID[8];
Texture getTexture[8];

void setColorRGBA(double red, double green, double blue, double opacity) {
    double r = red / 255;
    double g = green / 255;
    double b = blue / 255;
    double op = opacity / 100;
    glColor4d(r, g, b, op);
}

void reshapeSize(int w, int h) {
    glutReshapeWindow(845, 700);
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
    glVertex3d(0, 0, Z_AXIS_BACKGROUND);
    glVertex3d(WINDOW_WIDTH / PREF_SCREEN_CROP_FACTOR, 0, Z_AXIS_BACKGROUND);

    setColorRGBA(192, 192, 192, 100);
    glVertex3d(WINDOW_WIDTH / PREF_SCREEN_CROP_FACTOR, WINDOW_HEIGHT / PREF_SCREEN_CROP_FACTOR, Z_AXIS_BACKGROUND);
    glVertex3d(0, WINDOW_HEIGHT / PREF_SCREEN_CROP_FACTOR, Z_AXIS_BACKGROUND);

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

bool isGameField(int xCoord, int yCoord){
    return (0 < xCoord && xCoord < 9) && (0 < yCoord && yCoord < 9);
}