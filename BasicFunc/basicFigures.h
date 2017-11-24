//
// Created by konstantin on 23.11.17.
//

#ifndef COURSEWORK_BASICFIGURES_H
#define COURSEWORK_BASICFIGURES_H

void drawLine(double x0, double y0, double x, double y);

void drawRegtangle(double x0, double y0, double x, double y);
void drawFillRectangle(double x0, double y0, double x, double y);
void createTextureRectangle(double x0, double y0, double x, double y);

void drawTriangle(double x0, double y0, double x1, double y1, double x2, double y2);
void drawFillTriangle(double x0, double y0, double x1, double y1, double x2, double y2);
void createTextureTriangle(double x0, double y0, double x1, double y1, double x2, double y2);

void drawEllipse(int slices, double x, double y);
void drawFillEllipse(int slices, double x, double y);
void createTextureTriangle(int slices, double x, double y);

//GLuint LoadTexture(char *FileName);

void setColorRGB(double red, double green, double blue);

void reshapeSize(int w, int h);
void createWindow(int args, char **argv, int w, int h);

#endif //COURSEWORK_BASICFIGURES_H
