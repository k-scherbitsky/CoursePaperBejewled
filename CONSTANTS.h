//
// Created by konstantin on 09.12.17.
//

#ifndef COURSEWORK_CONSTINT_H
#define COURSEWORK_CONSTINT_H
#include <iostream>

const int INTERVAL = 1;
const double MENU_INTERVAL = 0.5;
const std::string MUSIC_PATH = "res/music/";
const std::string SOUND_PATH = "res/sound/";
const std::string TEXTURE_PATH = "res/texture/";
const std::string RECORDS_FILE_NAME = "records.txt";
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
const double Z_AXIS_GAME_OVER = 0.4;

//text
const std::string NEW_GAME = "New Game";
const std::string CONTINUE = "Continue";
const std::string MAIN_MENU = "Main menu";
const std::string SCORE = "Score";
const std::string EXIT_GAME = "Exit";
const std::string ABOUT = "About";
const std::string TEXT_ABOUT_FIRST_LINE = "Invented, painted and wrote the code - ";
const std::string TEXT_ABOUT_SECOND_LINE = "Konstantin Scherbitsky(kostya.em2@gmail.com)";
const std::string SCORE_TEXT = "Score: ";
const std::string TIMER_TEXT = "Time:";
const std::string BUTTON_OK = "OK";
const std::string RECORD_LIST = "RECORD LIST";

#endif //COURSEWORK_CONSTINT_H
