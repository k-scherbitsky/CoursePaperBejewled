//
// Created by konstantin on 12.12.17.
//

#ifndef COURSEWORK_STRUCTS_H
#define COURSEWORK_STRUCTS_H

#include <GL/glut.h>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

struct Record {
    int score;
};
enum MenuItems {
    FIRST_ITEM, SECOND_ITEM, THIRD_ITEM, FOURTH_ITEM
};

enum MusicState {
    PLAY, PAUSE, STOP
};


struct SW_Sound {
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

struct Piece {
    int pos;
    int cell;
    int x = 0;
    int y = 0;
    int col = 0;
    int row = 0;
    int match = 0;
    int score = 0;
    double alpha = 100;
};

struct Cursor {
    int xCursor = 1;
    int yCursor = 1;
    double xCursord;
    double yCursord;
};

struct TextColor {
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
    bool isGameField = false;
    bool isShowScore = false;
    bool isShowPauseMenu = false;
    bool isShowScoreWindow = false;
    bool isMoveCursorMenu = true;
    bool isGameOver = false;
};

#endif //COURSEWORK_STRUCTS_H
