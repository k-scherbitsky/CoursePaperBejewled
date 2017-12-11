#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFunc.h"
#include "Figures/figures.h"
#include "Menu/menu.h"
#include "Score/score.h"
#include "CONSTANTS.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

struct piece {
    int pos;
    int cell;
    int x;
    int y;
    int col;
    int row;
    int match;
    double alpha = 100;
} grid[10][10];

double interval = 1;
double zGem = 0.0;
int xCursor = 1;
int yCursor = 1;
int xSwap;
int ySwap;
sf::Music music;

bool isShowMenu = true;
bool isShowAbout = false;
bool isMoveCursor = false;
bool isDrawGrid = false;
bool isSwap = false;
bool isMoving = false;

void drawGrid();

void draw();

void drawCell();

void cellFilling();

void matchFinding();

void swap(piece p1, piece p2);

void drawCell(int x, int y);

void processNormalKeys(unsigned char key, int x, int y);

void processSpecialKeys(int key, int xx, int yy);

void mouseButton(int button, int state, int x, int y);

int main(int args, char **argv) {
    if (!music.openFromFile("../resources/music/background_music.ogg"))
        return -1;
    music.setVolume(100);
//    music.play();
    music.setLoop(true);

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

    // прорисовка
    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeSize);
    glutIdleFunc(draw);

    cellFilling();

    // регистрация клавиатуры и мыши
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutMouseFunc(mouseButton);

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
    drawCell();
    drawCursorGem(xCursor, yCursor, isMoveCursor);
    menu(isShowMenu);
    scoreGame();
    matchFinding();
    drawWindowAbout(isShowAbout);
    glutSwapBuffers();
}

void cellFilling() {
    srand(time(0));
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            grid[i][j].pos = rand() % 6;
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].x = i * interval;
            grid[i][j].y = j * interval;
        }
    }
}

void drawCell() {
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            drawCell(i, j);
        }
    }
}

void matchFinding() {
    //Match finding
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (grid[i][j].pos == grid[i + 1][j].pos and grid[i][j].pos == grid[i - 1][j].pos)
                for (int n = -1; n <= 1; n++) grid[i + n][j].match++;

            if (grid[i][j].pos == grid[i][j + 1].pos and grid[i][j].pos == grid[i][j - 1].pos)
                for (int n = -1; n <= 1; n++) grid[i][j + n].match++;
        }
    }

    isMoving = false;
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            piece &p = grid[i][j];
            int dx, dy;
            dx = p.x - p.row * interval;
            dy = p.y - p.col * interval;
            if (dx) p.x -= dx / abs(dx);
            if (dy) p.y -= dy / abs(dy);

            if (dx || dy) isMoving = 1;
        }
    }

    if (!isMoving)
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (grid[i][j].match)
                    if (grid[i][j].alpha > 10) {
                        grid[i][j].alpha -= 10;
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
                    grid[i][j].x = i * interval;
                    grid[i][j].y = j * interval;
                    grid[i][j].match = 0;
                    grid[i][j].alpha = 255;
                }
    }

}

void swap(piece p1, piece p2) {
    std::swap(p1.col, p2.col);
    std::swap(p1.row, p2.row);

    std::swap(p1.x, p2.x);
    std::swap(p1.y, p2.y);

    grid[p1.row][p1.col] = p1;
    grid[p2.row][p2.col] = p2;

    grid[p1.x][p1.y].pos = p1.pos;
    grid[p2.x][p2.y].pos = p2.pos;
}

void drawGrid() {
    if (!isDrawGrid)
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
            grid[x][y].cell = drawBlueGem(grid[x][y].x, grid[x][y].y, zGem, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 1:
            glPushMatrix();
            grid[x][y].cell = drawGreenGem(grid[x][y].x, grid[x][y].y, zGem, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
            grid[x][y].cell = drawOrangeGem(grid[x][y].x, grid[x][y].y, zGem, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 3:
            glPushMatrix();
            grid[x][y].cell = drawPurpleGem(grid[x][y].x, grid[x][y].y, zGem, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 4:
            glPushMatrix();
            grid[x][y].cell = drawRedGem(grid[x][y].x, grid[x][y].y, zGem, grid[x][y].alpha);
            glPopMatrix();
            break;
        case 5:
            glPushMatrix();
            grid[x][y].cell = drawYellowGem(grid[x][y].x, grid[x][y].y, zGem, grid[x][y].alpha);
            glPopMatrix();
            break;
        default:
            break;
    }
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 27: { // ESC
            if (!isShowMenu) {
                isShowMenu = true;
                isMoveCursor = false;
            } else {
                isShowMenu = false;
                isMoveCursor = true;
            }

            if (isShowAbout) {
                isShowMenu = true;
                isShowAbout = false;
                isMoveCursor = false;
            }
            break;
        }
        case 32: { // space
            if (!isShowMenu) {
                isSwap = !isSwap;
                xSwap = xCursor;
                ySwap = yCursor;
                cout << "isSwap: " << isSwap << endl << endl;
            }
            break;
        }
        case 51: { // 3
            if (!isShowMenu)
                break;
            else
                exit(0);
        }
        case 52: { // 4
            if (isShowMenu) {
                if (!isShowAbout) {
                    isShowAbout = true;
                    isMoveCursor = false;
                } else {
                    isShowAbout = false;
                    isMoveCursor = false;
                }
            }
            break;
        }
        case 71: // G(g)
        case 103:
            isDrawGrid = !isDrawGrid;
            break;
        case 77: // m
        case 109:
            music.play();
            break;
        case 78: // n
        case 110:
            cellFilling();
            break;
        default:
            break;
    }
}

void processSpecialKeys(int key, int xx, int yy) {
    switch (key) {
        case GLUT_KEY_UP: {
            if (!isShowMenu) {
                yCursor -= interval;
                if (yCursor < 1)
                    yCursor = 8;
            }
            if (isSwap) {
                std::swap(grid[xCursor][yCursor].pos, grid[xSwap][ySwap].pos);
                isSwap = false;
            }
            break;
        }
        case GLUT_KEY_DOWN: {
            if (!isShowMenu) {
                yCursor += interval;
                if (yCursor > 8)
                    yCursor = 1;
            }
            if (isSwap) {
                std::swap(grid[xCursor][yCursor].pos, grid[xSwap][ySwap].pos);
                isSwap = false;
            }
            break;
        }
        case GLUT_KEY_LEFT: {
            if (!isShowMenu) {
                xCursor -= interval;
                if (xCursor < 1)
                    xCursor = 8;
            }
            if (isSwap) {
                std::swap(grid[xCursor][yCursor].pos, grid[xSwap][ySwap].pos);
                isSwap = false;
            }
            break;
        }
        case GLUT_KEY_RIGHT: {
            if (!isShowMenu) {
                xCursor += interval;
                if (xCursor > 8)
                    xCursor = 1;
            }
            if (isSwap) {
                std::swap(grid[xCursor][yCursor].pos, grid[xSwap][ySwap].pos);
                isSwap = false;
            }
            break;
        }
        default:
            break;
    }

}

void mouseButton(int button, int state, int x, int y) {
    y = y / PREF_SCREEN_CROP_FACTOR;
    x = x / PREF_SCREEN_CROP_FACTOR;
    bool isMenuField = (2 < x && x < 11) && (2 < y && y < 9);
    bool isGameField = (0 < x && x < 9) && (0 < y && y < 9);
    switch (button) {
        case GLUT_LEFT_BUTTON:
//            cout << x << " " << y << endl << xCursor << " " << yCursor << endl << endl;;
            if (!isShowMenu && isGameField) {
                xSwap = xCursor = x;
                ySwap = yCursor = y;
                isSwap = true;
                cout << "isSwap " << isSwap << endl;
            }
            if (isShowMenu && !isMenuField) {
                isShowMenu = false;
                isShowAbout = false;
                isMoveCursor = true;
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (!isShowMenu && isGameField && isSwap) {
                swap(grid[xSwap][ySwap], grid[x][y]);
                xCursor = x;
                yCursor = y;
                isSwap = false;
            }
            break;
        default:
            break;
    }

}
