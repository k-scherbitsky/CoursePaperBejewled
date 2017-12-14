//
// Created by konstantin on 29.11.17.
//

#include <GL/glut.h>
#include "Menu.h"
#include "../BasicFunc/BasicFunc.h"
#include "../CONSTANTS.h"

TextColor getColorText = {240, 230, 140};

void mainMenu(bool isShowMenu) {
    if (!isShowMenu)
        return;


    drawWindowMenu();
    renderBitmapString(5, 4.75, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, NEW_GAME,
                       getColorText.R, getColorText.G, getColorText.B);
    renderBitmapString(5, 5.25, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, SCORE,
                       getColorText.R, getColorText.G, getColorText.B);
    renderBitmapString(5, 5.75, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, EXIT_GAME,
                       getColorText.R, getColorText.G, getColorText.B);
    renderBitmapString(5, 6.25, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, ABOUT,
                       getColorText.R, getColorText.G, getColorText.B);
}

void pauseMenu(bool isShowPauseMenu) {
    if (!isShowPauseMenu)
        return;

    drawWindowMenu();
    renderBitmapString(5, 4.75, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, CONTINUE,
                       getColorText.R, getColorText.G, getColorText.B);
    renderBitmapString(5, 5.25, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, MAIN_MENU,
                       getColorText.R, getColorText.G, getColorText.B);
    renderBitmapString(5, 5.75, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, SCORE,
                       getColorText.R, getColorText.G, getColorText.B);
    renderBitmapString(5, 6.25, Z_AXIS_MENU_TEXT, GLUT_BITMAP_HELVETICA_18, EXIT_GAME,
                       getColorText.R, getColorText.G, getColorText.B);
}

void drawWindowMenu() {

    setColorRGBA(0, 0, 128, 90);

    glBegin(GL_POLYGON);
    glVertex3d(3, 4, Z_AXIS_MENU);
    glVertex3d(4, 3, Z_AXIS_MENU);
    glVertex3d(10, 3, Z_AXIS_MENU);
    glVertex3d(11, 4, Z_AXIS_MENU);
    glVertex3d(11, 7, Z_AXIS_MENU);
    glVertex3d(10, 8, Z_AXIS_MENU);
    glVertex3d(4, 8, Z_AXIS_MENU);
    glVertex3d(3, 7, Z_AXIS_MENU);
    glEnd();

    //Border
    glLineWidth(2.5);
    setColorRGBA(0, 191, 255, 95);

    glBegin(GL_LINE_LOOP);
    glVertex3d(3, 4, Z_AXIS_MENU);
    glVertex3d(4, 3, Z_AXIS_MENU);
    glVertex3d(10, 3, Z_AXIS_MENU);
    glVertex3d(11, 4, Z_AXIS_MENU);
    glVertex3d(11, 7, Z_AXIS_MENU);
    glVertex3d(10, 8, Z_AXIS_MENU);
    glVertex3d(4, 8, Z_AXIS_MENU);
    glVertex3d(3, 7, Z_AXIS_MENU);
    glEnd();

}

void drawWindowAbout(bool isShowAbout) {
    if (!isShowAbout) {
        return;
    }

    setColorRGBA(176, 224, 230, 97);
    glEnable(GL_BLEND);


    glBegin(GL_POLYGON);
    glVertex3d(4, 4.5, Z_AXIS_MENU_ITEM);
    glVertex3d(4.5, 4, Z_AXIS_MENU_ITEM);
    glVertex3d(9.5, 4, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 4.5, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 6.5, Z_AXIS_MENU_ITEM);
    glVertex3d(9.5, 7, Z_AXIS_MENU_ITEM);
    glVertex3d(4.5, 7, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 6.5, Z_AXIS_MENU_ITEM);
    glEnd();

    //Border
    glLineWidth(2);
    setColorRGBA(0, 191, 255, 95);

    glBegin(GL_LINE_LOOP);
    glVertex3d(4, 4.5, Z_AXIS_MENU_ITEM);
    glVertex3d(4.5, 4, Z_AXIS_MENU_ITEM);
    glVertex3d(9.5, 4, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 4.5, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 6.5, Z_AXIS_MENU_ITEM);
    glVertex3d(9.5, 7, Z_AXIS_MENU_ITEM);
    glVertex3d(4.5, 7, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 6.5, Z_AXIS_MENU_ITEM);
    glEnd();

    glDisable(GL_BLEND);

    renderBitmapString(4.5, 5.25, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_8_BY_13, TEXT_ABOUT_FIRST_LINE, 105, 105, 105);
    renderBitmapString(4.15, 5.5, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_8_BY_13, TEXT_ABOUT_SECOND_LINE, 105, 105, 105);

}

