//
// Created by konstantin on 01.12.17.
//

#ifndef COURSEWORK_SCORE_H
#define COURSEWORK_SCORE_H

void scoreGame(bool isShowScore);
void saveRecordTableToFile(int score);
void scoreWindow(const char *name, const char *score, double interval);
void readRecordsTableFromFile();
void drawScoreWindow(bool isShowScoreWindow);

#endif //COURSEWORK_SCORE_H
