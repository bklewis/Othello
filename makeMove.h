#ifndef MAKEMOVE_H
#define MAKEMOVE_H

int randGen( int min,  int max);
int getOppositeSymbol(int t);
void computerMoveHelper(int t, int nt, int *max, int *count);
void computerMove(int t);
int flipIt(int t, int x, int y,int mode);
char getTokenName(int t);

void clear();
int meCrawler(int t, int step, int m, int n, int *signal);
int moveExist (int t);

#endif
