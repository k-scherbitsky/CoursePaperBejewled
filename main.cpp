#include <GL/glut.h>
#include <cstdio>
#include "BasicFunc/basicFigures.h"

/**
GLuint textureID[8];
struct {
    int W;
    int H;
    unsigned char *Image;
} getTexture[8];
*/

GLuint textureID;
struct {
    int W;
    int H;
    unsigned char *Image;
} getTexture;

void draw();
void setBackground();
void drawParallelepiped(double x, double y, double zLeft, double zRight, double red, double green, double blue);
bool LoadTexture(char *FileName);
void processNormalKeys(unsigned char key, int x, int y);
/**GLuint LoadTexture(char *FileName, int n) ;*/

int main(int args, char **argv) {

    createWindow(args, argv, 800, 600);
    glutDisplayFunc(draw);
    /**textureID[0] = LoadTexture((char *) "../resources/textures/texture.bmp", 0);
    if (textureID[0] == -1) {
        printf("Не удалось загрузить изображение\n");
    }else{
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &textureID[0]);
        glBindTexture(GL_TEXTURE_2D, textureID[0]);
//        glTexImage2D(GL_TEXTURE_2D, 0, 3, getTexture[0].W, getTexture[0].H, 0, GL_RGB, GL_UNSIGNED_BYTE,
//                     getTexture[0].Image);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, getTexture[0].W, getTexture[0].H, GL_RGB, GL_UNSIGNED_BYTE, getTexture[0].Image);
    }*/
    glutReshapeFunc(reshapeSize);
    glutIdleFunc(draw);
    glutKeyboardFunc(processNormalKeys);
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
    setColorRGB(242,255,156);
    drawFillRectangle(-1, 1, 1, -1);

//    setBackground();

//    drawParallelepiped(0.52, 3, -0.02, 0.52, 1, 1 ,0);


    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y){
    switch(key){
        case 49:{
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, textureID);
            setColorRGB(255,255,0);
            if (LoadTexture((char *) "../resources/textures/Red.bmp") != 1) {
                printf("Не удалось загрузить изображение\n");
            }

            break;
        }
        case 50:{
            glDisable(GL_TEXTURE_2D);
            break;
        }
        case 27:
            exit(1);
        default:break;
    }
}

bool LoadTexture(char *FileName) {
    FILE *F;
//     Открываем файл
    if ((F = fopen(FileName, "rb")) == nullptr)
        return false;
//    Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну
    fseek(F, 18, SEEK_SET);
    fread(&(getTexture.W), 2, 1, F);
    fseek(F, 2, SEEK_CUR);
    fread(&(getTexture.H), 2, 1, F);

    printf("%d x %d\n", getTexture.W, getTexture.H);

//     Выделяем память под изображение. Если память не выделилась, закрываем файл и выходим с ошибкой
    if ((getTexture.Image = (unsigned char *) malloc(sizeof(unsigned char) * 3 * getTexture.W * getTexture.H)) ==
        nullptr) {
        fclose(F);
        return false;
    }
//     Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя
    fseek(F, 30, SEEK_CUR);
    fread(getTexture.Image, 3, getTexture.W * getTexture.H, F);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, getTexture.W, getTexture.H, GL_RGB, GL_UNSIGNED_BYTE, getTexture.Image);
    free(getTexture.Image);
    fclose(F);

    return true;
}

/**
GLuint LoadTexture(char *FileName, int n) {
    bool status = false;
    FILE *F;
//     Открываем файл
    if ((F = fopen(FileName, "rb")) == nullptr)
        return static_cast<GLuint>(-1);
//    Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну
    fseek(F, 18, SEEK_SET);
    fread(&(getTexture[n].W), 2, 1, F);
    fseek(F, 2, SEEK_CUR);
    fread(&(getTexture[n].H), 2, 1, F);

    printf("%d x %d\n", getTexture[n].W, getTexture[n].H);

//     Выделяем память под изображение. Если память не выделилась, закрываем файл и выходим с ошибкой
    if ((getTexture[n].Image = (unsigned char *) malloc(sizeof(unsigned char) * 3 * getTexture[n].W * getTexture[n].H)) ==
        nullptr) {
        fclose(F);
        return static_cast<GLuint>(-1);
    }
//     Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя
    fseek(F, 30, SEEK_CUR);
    fread(getTexture[n].Image, 3, getTexture[n].W * getTexture[n].H, F);

    if (getTexture[n].Image) {
            free(getTexture[n].Image);
    }
    fclose(F);

    return textureID[n];
}
*/
