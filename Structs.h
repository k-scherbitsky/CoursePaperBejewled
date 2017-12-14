//
// Created by konstantin on 12.12.17.
//

#ifndef COURSEWORK_STRUCTS_H
#define COURSEWORK_STRUCTS_H
#include <GL/glut.h>


enum StateGame {
    START_WINDOW, GAME_FIELD, PAUSE_WINDOW
};

enum MusicState {
    PLAY, PAUSE, STOP
};

struct Texture{
    GLuint textureGem[6];
    GLuint textureBgk[3];
} ;

struct Piece {
    int pos;
    int cell;
    int x;
    int y;
    int col;
    int row;
    int match;
    double alpha = 100;
};

struct Cursor {
    int xCursor = 1;
    int yCursor = 1;
};

struct TextColor{
    int R;
    int G;
    int B;
};

struct ObjectVisibility {
    bool isShowMenu = true;
    bool isShowAbout = false;
    bool isMoveCursor = false;
    bool isDrawGrid = false;
    bool isSwap = false;
    bool isMoving = false;
    bool isGameField = false;
    bool isShowScore = false;
    bool isShowPauseMenu = false;
    bool isShowScoreWindow = false;
};

#endif //COURSEWORK_STRUCTS_H
