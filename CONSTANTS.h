//
// Created by konstantin on 09.12.17.
//

#ifndef COURSEWORK_CONSTINT_H
#define COURSEWORK_CONSTINT_H
#include <iostream>

const int INTERVAL = 1;
const std::string MUSIC_PATH = "res/music/";
const std::string SOUND_PATH = "res/sound/";

//window
const int PREF_SCREEN_CROP_FACTOR = 60;
const int WINDOW_WIDTH = 845;
const int WINDOW_HEIGHT = 700;

//layers
const double Z_AXIS_BACKGROUND_GAME = 0.0;
const double Z_AXIS_BACKGROUND_MENU = 0.15;
const double Z_AXIS_GEMS = 0.1;
const double Z_AXIS_CURSOR = 0.11;
const double Z_AXIS_MENU = 0.2;
const double Z_AXIS_MENU_TEXT = 0.22;
const double Z_AXIS_MENU_ITEM = 0.3;
const double Z_AXIS_MENU_ITEM_TEXT = 0.32;
const double Z_AXIS_MENU_BUTTON = 0.34;
const double Z_AXIS_MENU_BUTTON_TEXT = 0.36;

//text
const char NEW_GAME[] = "New Game";
const char CONTINUE[] = "Continue";
const char MAIN_MENU[] = "Main menu";
const char SCORE[] = "Score";
const char EXIT_GAME[] = "Exit";
const char ABOUT[] = "About";
const char TEXT_ABOUT_FIRST_LINE[] = "Invented, painted and wrote the code - ";
const char TEXT_ABOUT_SECOND_LINE[] = "Konstantin Scherbitsky(kostya.em2@gmail.com)";

#endif //COURSEWORK_CONSTINT_H
