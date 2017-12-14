//
// Created by konstantin on 23.11.17.
//

#ifndef COURSEWORK_BASICFIGURES_H
#define COURSEWORK_BASICFIGURES_H

#include "../Structs.h"
#include <iostream>

GLuint loadTexture(std::string fileName);

void setColorRGBA(double red, double green, double blue, double opacity);

void reshapeSize(int w, int h);

void setBackground();

void renderBitmapString(float x, float y, float z, void *font, const char *string,
                        double red, double green, double blue);

bool isGameField(int xCoord, int yCoord);

#endif //COURSEWORK_BASICFIGURES_H
