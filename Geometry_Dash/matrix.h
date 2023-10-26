#ifndef MATRIX_H
#define MATRIX_H

typedef struct m{
    short int point[100][150];
}GameMatrix;

void startSetUpMatrix(GameMatrix *m);
int rectJumpUp(GameMatrix *m,int startX,int startY);
void printMatrix(GameMatrix *m);
int rectJumpDown(GameMatrix *m,int startX,int startY);
void buildObstacleMatrix(GameMatrix *m,int x,int y,int w,int h);
int slideObstacleMatrix(GameMatrix *m,int x,int y,int w,int h);
int checkDown(GameMatrix *m,int startX,int startY);
int checkSX(GameMatrix *m,int startX,int startY,int h);

#endif