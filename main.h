#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//#include "initialize.h"

#define N 8

char board[8][8];
int legalMoves[64];
char flip[64];

int p1score;
int p2score;
int row;
int col;

int pass;
bool turn;