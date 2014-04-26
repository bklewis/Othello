#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define N 8

int computeCount[N][N];
char board[N][N];
int legalMoves[N*N];
//int flips;
//char flip[N*N];  flip is not 

int p1score;
int p2score;
int row;
int col;
int pass;
int turn;


typedef enum {X = 1, O = 2, M = 3} token;
typedef enum {COUNTONLY,FLIPONLY} mode;
typedef enum {HUMAN=1,COMPUTER=2} playmode;

void human(int turn);
void computer(int turn);
void chooseMode(int mode1, int mode2);


#endif
