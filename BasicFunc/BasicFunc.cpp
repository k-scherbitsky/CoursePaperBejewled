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
#include <SFML/Graphics.hpp>

GLuint bgkTex[3], gameOverTex;
int randBgk;

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

void renderBitmapString(float x, float y, float z, void *font, const char *string,
                        double red, double green, double blue) {
    setColorRGBA(red, green, blue, 100);
    const char *c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

GLuint loadTexture(std::string fileName) {
    sf::Image image;
    image.loadFromFile(fileName);

//    image.flipVertically();

    GLuint texture = 0;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x, image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE,
                      image.getPixelsPtr());

    return texture;

}

void initTex() {
    randBgk = rand() % 3;
    for (int i = 0; i < 3; ++i) {
        bgkTex[i] = loadTexture(TEXTURE_PATH + "bgk_" + std::to_string(i) + ".png");
    }
    gameOverTex = loadTexture(TEXTURE_PATH + "game_over-min.png");
}

void setBackground() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, bgkTex[randBgk]);
    glBegin(GL_POLYGON);
    setColorRGBA(244, 164, 96, 100);
    glTexCoord3d(0, 0, Z_AXIS_BACKGROUND_GAME);
    glVertex3d(0, 0, Z_AXIS_BACKGROUND_GAME);
    glTexCoord3d(1, 0, Z_AXIS_BACKGROUND_GAME);
    glVertex3d(WINDOW_WIDTH / PREF_SCREEN_CROP_FACTOR, 0, Z_AXIS_BACKGROUND_GAME);

    setColorRGBA(192, 192, 192, 100);
    glTexCoord3d(1, 1, Z_AXIS_BACKGROUND_GAME);
    glVertex3d(WINDOW_WIDTH / PREF_SCREEN_CROP_FACTOR, WINDOW_HEIGHT / PREF_SCREEN_CROP_FACTOR,
               Z_AXIS_BACKGROUND_GAME);
    glTexCoord3d(0, 1, Z_AXIS_BACKGROUND_GAME);
    glVertex3d(0, WINDOW_HEIGHT / PREF_SCREEN_CROP_FACTOR, Z_AXIS_BACKGROUND_GAME);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void gameOverTexture(bool isGameOver) {
    if (!isGameOver)
        return;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, gameOverTex);
    glBegin(GL_POLYGON);
    setColorRGBA(244, 164, 96, 100);
    glTexCoord3d(0, 0, Z_AXIS_GAME_OVER);
    glVertex3d(0, 0, Z_AXIS_GAME_OVER);
    glTexCoord3d(1, 0, Z_AXIS_GAME_OVER);
    glVertex3d(WINDOW_WIDTH / PREF_SCREEN_CROP_FACTOR, 0, Z_AXIS_GAME_OVER);

    setColorRGBA(192, 192, 192, 100);
    glTexCoord3d(1, 1, Z_AXIS_GAME_OVER);
    glVertex3d(WINDOW_WIDTH / PREF_SCREEN_CROP_FACTOR, WINDOW_HEIGHT / PREF_SCREEN_CROP_FACTOR,
               Z_AXIS_GAME_OVER);
    glTexCoord3d(0, 1, Z_AXIS_GAME_OVER);
    glVertex3d(0, WINDOW_HEIGHT / PREF_SCREEN_CROP_FACTOR, Z_AXIS_GAME_OVER);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}
