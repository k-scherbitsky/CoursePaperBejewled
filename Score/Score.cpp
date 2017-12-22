//
// Created by konstantin on 01.12.17.
//

#include <GL/glut.h>
#include <zconf.h>
#include <cstring>
#include <fstream>
#include "Score.h"
#include "../BasicFunc/BasicFunc.h"
#include "../CONSTANTS.h"

ObjectVisibility v;

//Именование рекорда и запись в файл

void saveRecordTableToFile(int score) {
    std::ofstream recordFile(RECORDS_FILE_NAME);
    if (recordFile.is_open()) {
        recordFile << score << "\n";
        recordFile.close();
        std::cout << "[INFO] Records file successfully saved" << std::endl;
        return;
    } else {
        std::cout << "[ERR] Unable to create records file" << std::endl;
        return;
    }
}

void scoreGame(bool isShowScore) {
    if (!isShowScore)
        return;

    renderBitmapString(10, 2, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, SCORE_TEXT.c_str(), 240, 230, 140);
    renderBitmapString(10, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, TIMER_TEXT.c_str(), 240, 230, 140);
    renderBitmapString(11.5, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, ":", 240, 230, 140);
    renderBitmapString(12, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, ":", 240, 230, 140);

}

// Таблица рекордов и ее заполнение из файла
void readRecordsTableFromFile() {
    std::ifstream recordFile(RECORDS_FILE_NAME);
    if (recordFile.is_open()) {
        Record record;
        char *buff = (char *) calloc(256, sizeof(char));
        double interval = 0;
        int i = 0;
        int name = 1;
        while (!recordFile.eof() and name != 11) {

            recordFile.getline(buff, 256, '\n');
            record.score = atoi(buff);

            scoreWindow(std::to_string(name++).c_str(), std::to_string(record.score).c_str(), interval);
            interval += 0.5;
            i++;
        }
        free(buff);
        recordFile.close();
    } else {
        std::cout << "[WARN] Record table not found" << std::endl;
    }
}

void drawScoreWindow(bool isShowScoreWindow) {
    if (!isShowScoreWindow)
        return;

    //Window
    setColorRGBA(0, 0, 128, 90);
    glBegin(GL_POLYGON);
    glVertex3d(3, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 9, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(3, 9, Z_AXIS_MENU_ITEM);
    glEnd();

    //Border of Window
    glLineWidth(2.5);
    setColorRGBA(0, 191, 255, 90);
    glBegin(GL_LINE_LOOP);
    glVertex3d(3, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 1, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 2, Z_AXIS_MENU_ITEM);
    glVertex3d(11, 9, Z_AXIS_MENU_ITEM);
    glVertex3d(10, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(4, 10, Z_AXIS_MENU_ITEM);
    glVertex3d(3, 9, Z_AXIS_MENU_ITEM);
    glEnd();

    //Button
    setColorRGBA(25, 25, 112, 100);
    glBegin(GL_POLYGON);
    glVertex3d(6, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 9.25, Z_AXIS_MENU_BUTTON);
    glVertex3d(6, 9.25, Z_AXIS_MENU_BUTTON);
    glEnd();

    //Border of Button
    glLineWidth(2.5);
    setColorRGBA(0, 191, 255, 95);
    glBegin(GL_LINE_LOOP);
    glVertex3d(6, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 8.75, Z_AXIS_MENU_BUTTON);
    glVertex3d(8, 9.25, Z_AXIS_MENU_BUTTON);
    glVertex3d(6, 9.25, Z_AXIS_MENU_BUTTON);
    glEnd();

    //Line of grid
    glLineWidth(0.1);
    glBegin(GL_LINE_STRIP);
    setColorRGBA(0, 0, 0, 100);
    glVertex3d(7.5, 2.5, Z_AXIS_MENU_ITEM_TEXT);
    glVertex3d(7.5, 7.5, Z_AXIS_MENU_ITEM_TEXT);
    glEnd();

    for (double j = 3.02; j < 8; j += 0.5) {
        glLineWidth(0.1);
        glBegin(GL_LINE_STRIP);
        setColorRGBA(0, 0, 0, 100);
        glVertex3d(5, j, Z_AXIS_MENU_ITEM_TEXT);
        glVertex3d(9, j, Z_AXIS_MENU_ITEM_TEXT);
        glEnd();
    }

    renderBitmapString(5.5, 1.5, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_TIMES_ROMAN_24, RECORD_LIST.c_str(), 240, 230,
                       140);
    renderBitmapString(6.7, 9.1, Z_AXIS_MENU_BUTTON_TEXT, GLUT_BITMAP_TIMES_ROMAN_24, BUTTON_OK.c_str(), 240, 230,
                       140);
}

void scoreWindow(const char *name, const char *score, double interval) {
    renderBitmapString(5.2, 3 + interval, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_HELVETICA_18, name, 192, 192, 192);
    renderBitmapString(7.52, 3 + interval, Z_AXIS_MENU_ITEM_TEXT, GLUT_BITMAP_HELVETICA_18, score, 192, 192, 192);
}