//
// Created by konstantin on 23.11.17.
//

#ifndef COURSEWORK_BASICFIGURES_H
#define COURSEWORK_BASICFIGURES_H

void drawLine(double x0, double y0, double z0, double x, double y, double z);

void drawRegtangle(double x0, double y0, double x, double y);
void drawFillRectangle(double x0, double y0, double x, double y, double z);
void createTextureRectangle(double x0, double y0, double x, double y, double z);

void drawEllipse(int slices, double x, double y);
void drawFillEllipse(int slices, double x, double y);

GLuint LoadTexture(char *FileName, int n);

void setColorRGBA(double red, double green, double blue, double opacity);

void reshapeSize(int w, int h);
void createWindow(int args, char **argv, int w, int h);

void setBackground();
void renderBitmapString(float x, float y, float z, void *font, const char *string,
                        double red, double green, double blue);

#endif //COURSEWORK_BASICFIGURES_H
