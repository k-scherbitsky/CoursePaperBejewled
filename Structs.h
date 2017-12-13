//
// Created by konstantin on 12.12.17.
//

#ifndef COURSEWORK_STRUCTS_H
#define COURSEWORK_STRUCTS_H

enum StateGame {
    START_WINDOW, GAME_WINDOW, PAUSE_WINDOW
};

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

struct Texture {
    int W;
    int H;
    unsigned char *Image;
};

struct Cursor {
    int xCursor = 1;
    int yCursor = 1;
};

struct Visibility {
    bool isShowMenu = true;
    bool isShowAbout = false;
    bool isMoveCursor = false;
    bool isDrawGrid = false;
    bool isSwap = false;
    bool isMoving = false;
};

#endif //COURSEWORK_STRUCTS_H
