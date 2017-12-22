//
// Created by konstantin on 13.12.17.
//

#ifndef COURSEWORK_MUSIC_H
#define COURSEWORK_MUSIC_H

#include <SFML/Audio/Music.hpp>
#include "../Structs.h"

void sndInit();
void sndSelect();
void sndMatch();
void sndLeftBtn();
void sndRightBtn();

void musicStartWindow(MusicState state);
void musicPauseWindow(MusicState state);
void musicGameField(MusicState state);

#endif //COURSEWORK_MUSIC_H
