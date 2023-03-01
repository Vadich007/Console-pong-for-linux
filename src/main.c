#include "main.h"

int main() {
    struct ball ball;
    struct player player1;
    struct player player2;
    int gameIsRunning = 1;
    player1.points = 0;
    player2.points = 0;
    startPosition(&ball, &player1, &player2);
    while(gameIsRunning == 1) {
        setcur(0, 0);
        printField(ball, player1, player2);
        printInstruction (player1, player2);
        gameIsRunning = control(&player1, &player2, gameIsRunning);
        moveBall(&ball);
        gameIsRunning = plusPoint(&ball, &player1, &player2, gameIsRunning);
        checkDirection(&ball, player1, player2);
        Sleep(10);
    }
    return 0;
}