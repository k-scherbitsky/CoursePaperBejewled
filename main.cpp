#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFigures.h"

GLuint textureID[8];
struct {
    int W;
    int H;
    unsigned char *Image;
} getTexture[8];

void draw();
GLuint LoadTexture(char *FileName);

int main(int args, char **argv) {
    createWindow(args, argv, 800, 600);

    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeSize);
    glutIdleFunc(draw);

    textureID[0] = LoadTexture((char *) "../resources/textures/Background.bmp");
//    if (LoadTexture((char *) "../resources/textures/Red.bmp") != 1) {
//        printf("Не удалось загрузить изображение\n");
//    }

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
    glRotatef(180, 0.0f, 0.0f, 1.0f);

    glTranslated(0, 0, 5);
//    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    setColorRGB(242,255,156);
    drawFillRectangle(-1, 1, 1, -1);

    glutSwapBuffers();
}

GLuint LoadTexture(char *FileName) {
    FILE *F;
//     Открываем файл
    if ((F = fopen(FileName, "rb")) == nullptr)
        return false;
//    Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну
    fseek(F, 18, SEEK_SET);
    fread(&(getTexture[0].W), 2, 1, F);
    fseek(F, 2, SEEK_CUR);
    fread(&(getTexture[0].H), 2, 1, F);

    printf("%d x %d\n", getTexture[0].W, getTexture[0].H);

//     Выделяем память под изображение. Если память не выделилась, закрываем файл и выходим с ошибкой
    if ((getTexture[0].Image = (unsigned char *) malloc(sizeof(unsigned char) * 3 * getTexture[0].W * getTexture[0].H)) ==
        nullptr) {
        fclose(F);
        return false;
    }
//     Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя
    fseek(F, 30, SEEK_CUR);
    fread(getTexture[0].Image, 3, getTexture[0].W * getTexture[0].H, F);

    glGenTextures(1, &textureID[0]);
    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, getTexture[0].W, getTexture[0].H, GL_RGB, GL_UNSIGNED_BYTE, getTexture[0].Image);
    free(getTexture[0].Image);
    fclose(F);

    return true;
}
