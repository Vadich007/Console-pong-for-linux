#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>

#define YMAX 25
#define XMAX 75
#define WINPOINTS 1

struct ball
{
    int x, y, directionX, directionY;
};

struct player
{
    int x, y, points;
};

int  isPlayer(struct player player, int x, int y);
void printField(struct ball ball, struct player player1, struct player player2);
int  isBall (struct ball ball, int x, int y);
int  isEdge (int x, int y);
void startPosition(struct ball *ball, struct player *player1, struct player *player2);
void checkDirection(struct ball *ball, struct player player1, struct player player2);
int control(struct player *player1, struct player *player2, int gameIsRunning);
void moveBall (struct ball *ball);
void setcur (int x, int y);
int plusPoint (struct ball *ball, struct player *player1, struct player *player2, int gameIsRunning);
int checkWin (struct player *player);
void congratulationScreen (int winPlayer);
void printInstruction (struct player player1, struct player player2);

#endif