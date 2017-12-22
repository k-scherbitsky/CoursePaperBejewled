#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/BasicFunc.h"
#include "Figures/Figures.h"
#include "Menu/Menu.h"
#include "Score/Score.h"
#include "CONSTANTS.h"
#include "Structs.h"
#include "Music/Music.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

Piece grid[10][10];
Cursor gemCursor = {1, 1};
Cursor gemSwapCursor;
Cursor menuCursor = {0, 0, 4.6, 4.52};
ObjectVisibility object;
bool isMoving = false;
int score = 0;
int i = 1;
int gMsec = 0, gSec = 0, gMin = 0;
bool stopTimer;
int pauseMin, pauseSec, pauseMsec;

void drawGrid();

void draw();

void cellFilling();

void matchFinding();

void swap(Piece p1, Piece p2);

void drawCell(int x, int y);

int setTimer();

void drawTimer(int min, int sec, int msec);

void processNormalKeys(unsigned char key, int x, int y);

void processSpecialKeys(int key, int xx, int yy);

int main(int args, char **argv) {
    srand(time(0));

    sndInit();
    musicStartWindow(PLAY);

    glutInit(&args, argv);

    int posX = (glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2;
    int posY = (glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2;

    glutInitWindowPosition(posX, posY);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Bejeweled");
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    glClearColor(1, 1, 1, 0);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH / PREF_SCREEN_CROP_FACTOR, WINDOW_HEIGHT / PREF_SCREEN_CROP_FACTOR, 0, -50, 50);
    glMatrixMode(GL_MODELVIEW);

    // инициализация текстур
    initTex();

    // прорисовка
    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeSize);
    glutIdleFunc(draw);

    // регистрация клавиатуры и мыши
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    glutMainLoop();

    return 0;
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(
            0, 0, 10,
            0, 0, 0,
            0, 1, 0);

    setBackground();

    drawGrid();
    matchFinding();

    mainMenu(object.isShowMenu);
    drawCursorMenu(menuCursor.xCursord, menuCursor.yCursord, object.isShowMenu || object.isShowPauseMenu);
    drawWindowAbout(object.isShowAbout);
    drawScoreWindow(object.isShowScoreWindow);
    pauseMenu(object.isShowPauseMenu);
    gameOverTexture(object.isGameOver);

    scoreGame(object.isGameField);

    if (object.isGameField) {
        if (setTimer() < 1) {
            drawTimer(gMin, gSec, gMsec);
        } else {
            object.isGameOver = true;
            object.isGameField = false;
            object.isMoveCursor = false;
            object.isShowScore = false;
            saveRecordTableToFile(score);
        }
    }

    if (object.isShowPauseMenu) {
        pauseMin = gMin;
        pauseSec = gSec;
        pauseMsec = gMsec;
        stopTimer = true;
        drawTimer(pauseMin, pauseSec, pauseMsec);
    }

    if (object.isShowScoreWindow) {
        readRecordsTableFromFile();
    }

    if ((object.isShowPauseMenu && object.isGameField) || object.isShowScoreWindow)
        drawCursorGem(gemCursor.xCursor, gemCursor.yCursor, false);
    else if (object.isGameField)
        drawCursorGem(gemCursor.xCursor, gemCursor.yCursor, true);

    glutSwapBuffers();
}

void cellFilling() {
    if (!object.isGameField)
        return;

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            grid[i][j].pos = rand() % 6;
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].x = i * INTERVAL;
            grid[i][j].y = j * INTERVAL;
        }
    }
}

void matchFinding() {
    if (!object.isGameField)
        return;

    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            drawCell(i, j);
        }
    }

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (grid[i][j].cell == grid[i + 1][j].cell and grid[i][j].cell == grid[i - 1][j].cell and
                grid[i][j].x != -1)
                for (int n = -1; n <= 1; n++) {
                    grid[i + n][j].match++;
                    score += grid[i][j].match / 1;
                }

            if (grid[i][j].cell == grid[i][j + 1].cell and grid[i][j].cell == grid[i][j - 1].cell and
                grid[i][j].x != -1)
                for (int n = -1; n <= 1; n++) {
                    grid[i][j + n].match++;
                    score += grid[i][j].match / 1;
                }
        }
    }

    isMoving = false;
    for (int i = 8; i > 0; i--) {
        for (int j = 8; j > 0; j--) {
            Piece &p = grid[i][j];
            int dx = 0, dy = 0;
            for (int n = 0; n < 10000; n++) {
                dx = p.x - p.row * INTERVAL;
                dy = p.y - p.col * INTERVAL;
                if (dx) p.x -= abs(dx) / dx;
                if (dy) p.y -= abs(dy) / dy;
            }
            if (dx || dy) isMoving = true;
        }
    }

    if (!isMoving)
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (grid[i][j].match)
                    if (grid[i][j].alpha > 10) {
                        grid[i][j].alpha -= 10;
                        sndMatch();
                        isMoving = true;
                    }
            }
        }

    //Обновление сетки
    if (!isMoving) {
        for (int i = 8; i > 0; i--)
            for (int j = 1; j < 9; j++)
                if (grid[i][j].match)
                    for (int n = i; n > 0; n--)
                        if (!grid[n][j].match) {
                            swap(grid[n][j], grid[i][j]);
                            break;
                        };

        for (int j = 1; j < 9; j++)
            for (int i = 8, n = 0; i > 0; i--)
                if (grid[i][j].match) {
                    grid[i][j].pos = rand() % 6;
                    grid[i][j].row = i;
                    grid[i][j].col = j;
                    grid[i][j].x = -i * n++;
                    grid[i][j].y = j * INTERVAL;
                    grid[i][j].match = 0;
                    grid[i][j].alpha = 255;
                }
    }
    renderBitmapString(11.2, 2, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(score).c_str(), 240, 230, 140);

}

void swap(Piece p1, Piece p2) {
    std::swap(p1.col, p2.col);
    std::swap(p1.row, p2.row);

    grid[p1.row][p1.col] = p1;
    grid[p2.row][p2.col] = p2;
}

void drawGrid() {
    if (!object.isDrawGrid)
        return;

    for (double i = 0; i < WINDOW_WIDTH; i += 1) {
        for (double j = 0; j < WINDOW_HEIGHT; j += 1) {
            glBegin(GL_LINE_STRIP);
            glLineWidth(1);
            setColorRGBA(0, 0, 0, 100);
            glVertex3d(i, j, 0.01);
            glVertex3d(i, -j, 0.01);
            glEnd();
        }
    }

    for (double i = 0; i < WINDOW_WIDTH; i += 1) {
        for (double j = 0; j < WINDOW_HEIGHT; j += 1) {
            glBegin(GL_LINE_STRIP);
            glLineWidth(1);
            setColorRGBA(0, 0, 0, 100);
            glVertex3d(i, j, 0.01);
            glVertex3d(-i, j, 0.01);
            glEnd();
        }
    }
}

void drawCell(int x, int y) {
    switch (grid[x][y].pos) {
        case 0:
            glPushMatrix();
            grid[x][y].cell = drawBlueGem(grid[x][y].x, grid[x][y].y, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 1:
            glPushMatrix();
            grid[x][y].cell = drawGreenGem(grid[x][y].x, grid[x][y].y, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
            grid[x][y].cell = drawOrangeGem(grid[x][y].x, grid[x][y].y, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 3:
            glPushMatrix();
            grid[x][y].cell = drawPurpleGem(grid[x][y].x, grid[x][y].y, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 4:
            glPushMatrix();
            grid[x][y].cell = drawRedGem(grid[x][y].x, grid[x][y].y, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 5:
            glPushMatrix();
            grid[x][y].cell = drawYellowGem(grid[x][y].x, grid[x][y].y, grid[x][y].alpha);
            glPopMatrix();
            break;
        default:
            break;
    }
}

void stateGame(MenuItems points) {
    switch (points) {
        case FIRST_ITEM: {
            if (object.isShowMenu) {
                gMsec = 0;
                gSec = 0;
                gMin = 0;
                score = 0;
                object.isGameOver = false;
                object.isShowMenu = false;
                object.isGameField = true;
                cellFilling();
                object.isMoveCursor = true;
                object.isShowScore = true;
            }
            if (object.isShowPauseMenu) {
                object.isShowPauseMenu = false;
                object.isMoveCursor = true;
                gMin = pauseMin;
                gSec = pauseSec;
                gMsec = pauseMsec;
                stopTimer = false;
            }
            break;
        }
        case SECOND_ITEM: {
            if (object.isShowMenu) {
                object.isShowMenu = false;
                object.isShowScoreWindow = true;
            }
            if (object.isShowPauseMenu) {
                musicStartWindow(PLAY);
                object.isShowPauseMenu = false;
                object.isShowScore = false;
                object.isGameField = false;
                object.isMoveCursor = false;
                object.isShowScoreWindow = false;
                object.isShowMenu = true;
            }
            break;
        }
        case THIRD_ITEM: {
            if (object.isShowMenu) {
                exit(1);
            }
            if (object.isShowPauseMenu) {
                object.isShowPauseMenu = false;
                object.isMoveCursor = false;
                object.isShowScoreWindow = true;
            }
            break;
        }
        case FOURTH_ITEM: {
            if (object.isShowMenu) {
                object.isShowAbout = true;
            }
            if (object.isShowPauseMenu) {
                exit(1);
            }
            break;
        }
    }
}

void processNormalKeys(unsigned char key, int x, int y) {

    switch (key) {
        case 13: {
            if (object.isShowScoreWindow) {
                object.isShowScoreWindow = false;
                object.isShowMenu = true;
            }

            if (menuCursor.yCursord == 4.52) {
                stateGame(FIRST_ITEM);
                i++;
            }
            if (menuCursor.yCursord == 5.02)
                stateGame(SECOND_ITEM);
            if (menuCursor.yCursord == 5.52)
                stateGame(THIRD_ITEM);
            if (menuCursor.yCursord == 6.02)
                stateGame(FOURTH_ITEM);

            break;
        }
        case 27: { // ESC
            if (object.isGameOver) {
                object.isGameOver = false;
                object.isShowMenu = true;
            }

            if (object.isShowScoreWindow && !object.isGameField) {
                object.isShowScoreWindow = false;
                object.isShowMenu = true;
            } else if (object.isShowScoreWindow && object.isGameField) {
                object.isShowScoreWindow = false;
                object.isShowPauseMenu = true;
            }

            if (!object.isShowMenu) {
                object.isShowPauseMenu = true;
                object.isMoveCursor = false;
            }

            if (object.isShowAbout) {
                object.isShowMenu = true;
                object.isShowAbout = false;
                object.isMoveCursor = false;
            }
            break;
        }
        case 32: { // space
            if (!object.isShowMenu) {
                object.isSwap = !object.isSwap;
                gemSwapCursor.xCursor = gemCursor.xCursor;
                gemSwapCursor.yCursor = gemCursor.yCursor;
                cout << "isSwap: " << object.isSwap << endl << endl;
            }
            break;
        }
        default:
            break;
    }
}

void processSpecialKeys(int key, int xx, int yy) {
    if (key)
        sndLeftBtn();

    switch (key) {
        case GLUT_KEY_F1:
            object.isDrawGrid = !object.isDrawGrid;
            break;
        case GLUT_KEY_UP: {
            if (!object.isShowMenu) {
                gemCursor.yCursor -= INTERVAL;
                if (gemCursor.yCursor < 1)
                    gemCursor.yCursor = 8;
            }

            if (object.isShowMenu || object.isShowPauseMenu) {
                menuCursor.yCursord -= MENU_INTERVAL;
                if (menuCursor.yCursord < 4.52)
                    menuCursor.yCursord = 6.02;
            }

            if (object.isSwap) {
                std::swap(grid[gemCursor.xCursor][gemCursor.yCursor].pos,
                          grid[gemSwapCursor.xCursor][gemSwapCursor.yCursor].pos);
                sndRightBtn();
                object.isSwap = false;
            }
            break;
        }
        case GLUT_KEY_DOWN: {
            if (!object.isShowMenu) {
                gemCursor.yCursor += INTERVAL;
                if (gemCursor.yCursor > 8)
                    gemCursor.yCursor = 1;
            }

            if (object.isShowMenu || object.isShowPauseMenu) {
                menuCursor.yCursord += MENU_INTERVAL;
                if (menuCursor.yCursord > 6.02)
                    menuCursor.yCursord = 4.52;
            }

            if (object.isSwap) {
                std::swap(grid[gemCursor.xCursor][gemCursor.yCursor].pos,
                          grid[gemSwapCursor.xCursor][gemSwapCursor.yCursor].pos);
                sndRightBtn();
                object.isSwap = false;
            }
            break;
        }
        case GLUT_KEY_LEFT: {
            if (!object.isShowMenu) {
                gemCursor.xCursor -= INTERVAL;
                if (gemCursor.xCursor < 1)
                    gemCursor.xCursor = 8;
            }
            if (object.isSwap) {
                std::swap(grid[gemCursor.xCursor][gemCursor.yCursor].pos,
                          grid[gemSwapCursor.xCursor][gemSwapCursor.yCursor].pos);
                sndRightBtn();
                object.isSwap = false;
            }
            break;
        }
        case GLUT_KEY_RIGHT: {
            if (!object.isShowMenu) {
                gemCursor.xCursor += INTERVAL;
                if (gemCursor.xCursor > 8)
                    gemCursor.xCursor = 1;
            }
            if (object.isSwap) {
                std::swap(grid[gemCursor.xCursor][gemCursor.yCursor].pos,
                          grid[gemSwapCursor.xCursor][gemSwapCursor.yCursor].pos);
                sndRightBtn();
                object.isSwap = false;
            }
            break;
        }
        default:
            break;
    }
}

int setTimer() {
    if (stopTimer) {
        return -1;
    } else {
        if (gMsec == 60) {
            gSec++;
            gMsec = 0;
        }
        if (gSec == 60) {
            gMin++;
            gSec = 0;
        }
        gMsec++;
        return gMin;
    }
}

void drawTimer(int min, int sec, int msec) {
    renderBitmapString(12.1, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(msec).c_str(), 240, 230, 140);
    renderBitmapString(11.6, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(sec).c_str(), 240, 230, 140);
    renderBitmapString(11.25, 3, 0.02, GLUT_BITMAP_TIMES_ROMAN_24, std::to_string(min).c_str(), 240, 230, 140);
}