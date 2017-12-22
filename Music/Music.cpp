//
// Created by konstantin on 13.12.17.
//

#include <iostream>
#include "Music.h"
#include "SFML/Audio.hpp"
#include "../CONSTANTS.h"
#include "../Structs.h"

/**
 *
 * https://soundcloud.com/fakhry1995/sets/the-witcher-3-wild-hunt-official-soundtrack
 *
 * start window: 102 Geralt of Rivia, 205 Aen Seidhe, 308 Spikeroog, 427 After The Storm;
 * Game: 110 Silver For Monsters, 212 The Nightingale, 315 Window-Maker, 426 Drink Up There's Morel, 530 TheSong Of The Sword - Dancer;
 * Pause winsow: 101 The Trail, 219 Steel for Humans, 321 The Vagabond.
 *
 */

sf::Music playListGameWindow[5];
sf::Music playListPauseWindow[3];
sf::Music playListStartWindow[4];
const std::string startWindowState = "start_window_";
const std::string pauseWindowState = "pause_window_";
const std::string gameState = "game_";

SW_Sound choose;
SW_Sound match;
SW_Sound clickLeftButton;
SW_Sound clickRightButton;

// Background music
void musicState(sf::Music &playList, MusicState state) {
    switch (state) {
        case PLAY:
            playList.play();
            break;
        case PAUSE:
            playList.pause();
            break;
        case STOP:
            playList.stop();
            break;
        default:
            break;
    }
}

bool loadMusic(sf::Music &music, const std::string &filename) {
    if (!music.openFromFile(MUSIC_PATH + filename)) {
        std::cout << "Error! Music file not found!" << std::endl;
        return false;
    } else
        return true;
}

void musicStartWindow(MusicState state) {

    int randStartWindow = rand() % 4;
    for (int i = 0; i < 4; ++i) {
        loadMusic(playListStartWindow[i], startWindowState + std::to_string(i) + ".ogg");
    }
    playListStartWindow[randStartWindow].setVolume(10);
    musicState(playListStartWindow[randStartWindow], state);
    playListStartWindow[randStartWindow].setLoop(true);
}

void musicPauseWindow(MusicState state) {
    int randPauseWindow = rand() % 3;

    for (int i = 0; i < 3; ++i) {
        loadMusic(playListPauseWindow[i], pauseWindowState + std::to_string(i) + ".ogg");
    }
    playListPauseWindow[randPauseWindow].setVolume(10);
    musicState(playListStartWindow[randPauseWindow], state);
    playListPauseWindow[randPauseWindow].setLoop(true);
}

void musicGameField(MusicState state) {
    int randGameField = rand() % 5;

    for (int i = 0; i < 5; ++i) {
        loadMusic(playListGameWindow[i], gameState + std::to_string(i) + ".ogg");
    }
    playListGameWindow[randGameField].setVolume(10);
    musicState(playListStartWindow[randGameField], state);
    playListGameWindow[randGameField].setLoop(true);
}

// Sounds
bool loadSound(sf::SoundBuffer &buffer, sf::Sound &sound, const std::string &filename) {
    if (!buffer.loadFromFile(SOUND_PATH + filename)) {
        std::cout << "[ERR] Sound file not found: " << filename << std::endl;
        return false;
    } else {
        sound.setBuffer(buffer);
        return true;
    }
}

void sndInit() {
    bool success = true;

    success = loadSound(choose.buffer, choose.sound, "select.wav") ? success : false;
    success = loadSound(match.buffer, match.sound, "match.wav") ? success : false;
    success = loadSound(clickLeftButton.buffer, clickLeftButton.sound, "leftBtn.wav") ? success : false;
    success = loadSound(clickRightButton.buffer, clickRightButton.sound, "rightBtn.wav") ? success : false;

    if (!success) {
        throw std::invalid_argument("could not open some sound files");
    }
}

void sndMatch() {
    match.sound.setVolume(30);
    match.sound.setPitch(1);
    match.sound.play();
}

void sndLeftBtn() {
    clickLeftButton.sound.setVolume(100);
    clickLeftButton.sound.setPitch(1);
    clickLeftButton.sound.play();
}

void sndRightBtn() {
    clickRightButton.sound.setVolume(100);
    clickRightButton.sound.setPitch(1);
    clickRightButton.sound.play();
}
