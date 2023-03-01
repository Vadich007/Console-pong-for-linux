#include "main.h"

int isPlayer(struct player player, int x, int y) {
    int flag = 0;
    if (x == player.x && (y == player.y || y == player.y + 1 || y == player.y - 1)) {
        flag = 1;
    }
    return flag;
}

int isBall(struct ball ball, int x, int y) {
    int flag = 0;
    if (y == ball.y && x == ball.x) {
        flag = 1;
    } 
    return flag;
}

int isEdge (int x, int y) {
    int flag = 0;
    if (y == 0 || x == 0 || y == YMAX - 1 || x == XMAX - 1) {
        flag = 1;
    } 
    return flag;
}

void startPosition(struct ball *ball, struct player *player1, struct player *player2) {
    ball->x = XMAX / 2 + 1;
    ball->y = YMAX / 2 + 1;
    ball->directionY = 1;
    ball->directionX = 1;
    player1->x = 4;
    player1->y = YMAX / 2 + 1;
    player2->x = XMAX - 5;
    player2->y = YMAX / 2 + 1;
}

void printField(struct ball ball, struct player player1, struct player player2) {
    for (int y = 0; y < YMAX; y++) {
        for (int x = 0; x < XMAX; x++) {
            if (isBall(ball, x, y) == 1) {
                printf("*");
            } else if (isEdge(x, y) == 1) {
                printf("#");
            } else if (isPlayer(player1, x, y) == 1 || isPlayer(player2, x, y) == 1 || x == XMAX / 2 + 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void checkDirection(struct ball *ball, struct player player1, struct player player2) {
    if (ball->y == 1 || ball->y == YMAX - 2) {
        ball->directionY *= -1;
    } else if(isPlayer(player1, ball->x - 1, ball->y) || isPlayer(player2, ball->x + 1, ball->y)){
        ball->directionX *= -1;
    }
}

int control(struct player *player1, struct player *player2, int gameIsRunning) {
    if (GetKeyState('A') < 0 && player1->y != 2) 
        player1->y--;
    if (GetKeyState('Z') < 0 && player1->y != YMAX - 3)
        player1->y++;
    if (GetKeyState('K') < 0 && player2->y != 2) 
        player2->y--;
    if (GetKeyState('M') < 0 && player2->y != YMAX - 3)
        player2->y++;
    if (GetKeyState('Q') < 0)
        gameIsRunning--;
    return gameIsRunning;
}

void setcur (int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void moveBall (struct ball *ball) {
    ball->x += ball->directionX;
    ball->y += ball->directionY;
}

void congratulationScreen (int winPlayer) {
    system("cls");
    printf("               PLAYER %d WON!!!\n", winPlayer);
    FILE *file = fopen("cat.txt", "r");
    char line[255];
    while (fgets(line, 255, file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

int checkWin (struct player *player) {
    int win = 0;
    if (player->points == WINPOINTS)
        win++;
    return win;
}

void printInstruction (struct player player1, struct player player2) {
    printf("                            player 1     player 2\n");
    printf("                               %d           %d\n", player1.points, player2.points);
    printf("                             UP - A        UP - K\n");
    printf("                            DOWN - Z     DOWN - M\n");
    printf("                                  QUIT - Q");
}

int plusPoint (struct ball *ball, struct player *player1, struct player *player2, int gameIsRunning) {
    if (ball->x < player1->x) {
        player2->points++;
        startPosition(ball, player1, player2);
        if (checkWin(player2) == 1) {
        gameIsRunning--;
        congratulationScreen(gameIsRunning + 2);
        }
    } else if(ball ->x > player2->x) {
        player1->points++;
        startPosition(ball, player1, player2);
        if (checkWin(player1) == 1) {
        gameIsRunning--;
        congratulationScreen(gameIsRunning + 1); 
        }
    }
    return gameIsRunning;
}