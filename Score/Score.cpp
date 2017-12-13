//
// Created by konstantin on 01.12.17.
//

#include <GL/glut.h>
#include "Score.h"
#include "../BasicFunc/BasicFunc.h"

const char *scoreText = "Score: 0";
const char *timeText = "Time: 00:00";

void scoreGame(){
    renderBitmapString(10, 2, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, scoreText, 240, 230, 140);
    renderBitmapString(10, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, timeText, 240, 230, 140);

}