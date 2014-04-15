#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//#define N 8

char board[8][8];
int legalMoves[64];
char flip[64];

int p1score;
int p2score;
int row;
int col;

int pass;
bool turn;

#endif
