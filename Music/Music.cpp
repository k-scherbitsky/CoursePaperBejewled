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
std::string startWindowState = "start_window_";
std::string pauseWindowState = "pause_window_";
std::string gameState = "game_";

struct SW_Sound {
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

void musicState(sf::Music &playList, MusicState state);

SW_Sound choose;
SW_Sound match;

bool loadMusic(sf::Music &music, const std::string &filename) {
    if (!music.openFromFile(MUSIC_PATH + filename)) {
        std::cout << "Error! Music file not found!" << std::endl;
        return false;
    } else
        return true;
}
void musicStartWindow(MusicState state){
    srand(time(0));
    int randStartWindow = rand() % 4;
    int nameMusic = 1;
    for (int i = 0; i < 4; ++i) {
        loadMusic(playListStartWindow[i], startWindowState + std::to_string(nameMusic++) + ".ogg");
    }
    playListStartWindow[randStartWindow].setVolume(10);
    musicState(playListStartWindow[randStartWindow], state);
    playListStartWindow[randStartWindow].setLoop(true);
}

void musicPauseWindow(MusicState state){
    srand(time(0));
    int nameMusic = 1;
    int randPauseWindow = rand() % 3;

    for (int i = 0; i < 3; ++i) {
        loadMusic(playListPauseWindow[i], pauseWindowState + std::to_string(nameMusic++) + ".ogg");
    }
    playListPauseWindow[randPauseWindow].setVolume(10);
    musicState(playListStartWindow[randPauseWindow], state);
    playListPauseWindow[randPauseWindow].setLoop(true);
}

void musicGameField(MusicState state){
    srand(time(0));
    int nameMusic = 1;
    int randGameField = rand() % 5;

    for (int i = 0; i < 5; ++i) {
        loadMusic(playListGameWindow[i], gameState + std::to_string(nameMusic++) + ".ogg");
    }
    playListGameWindow[randGameField].setVolume(10);
    musicState(playListStartWindow[randGameField], state);
    playListGameWindow[randGameField].setLoop(true);
}

void musicState(sf::Music &playList, MusicState state) {
    switch (state){
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

    if (!success) {
        throw std::invalid_argument("could not open some sound files");
    }
}

void sndSelect() {
    choose.sound.setVolume(30);
    choose.sound.setPitch(1);
    choose.sound.play();
}

void sndMatch() {
    match.sound.setVolume(30);
    match.sound.setPitch(1);
    match.sound.play();
}
