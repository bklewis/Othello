#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define N 8

char board[N][N];
int computeCount[N][N];
int legalMoves[N*N];

int p1score;	//player scores
int p2score;
int row;
int col;
int pass;	//number of passes
int turn;	//tracks turn
int bonusmode;	//is bonusmode on?
int bonus_x;
int bonus_y;

typedef enum {X = 1, O = 2, M = 3} token;
typedef enum {COUNTONLY,FLIPONLY} mode;
typedef enum {HUMAN=1,COMPUTER=2} playmode;
typedef enum {BONUSON=1,BONUSOFF=0} bonus;

void human(int turn);
void computer(int turn);
void chooseMode(int mode1, int mode2);

#endif
