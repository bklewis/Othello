#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define N 8

char board[N][N];
int legalMoves[N*N];
//char flip[N*N];  flip is not 

int p1score;
int p2score;
int row;
int col;

int computeCount[N][N] = {0};
int flips;

int pass;
bool turn;

typedef enum {X = 1, O = 2, M = 3} token;
typedef enum {COUNTONLY,FLIPONLY} mode;

#endif
