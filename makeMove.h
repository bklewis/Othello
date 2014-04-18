#ifndef MAKEMOVE_H
#define MAKEMOVE_H

char getTokenName(int t);
void printIt();
void clear();
int meCrawler(int t, int step, int m, int n);
int moveExist (int t);
int flipIt(int t,int nt, int x, int y,int mode);
int randGen( int min,  int max);
void computerMoveHelper(int t, int nt, int *max, int *count);
void computerMove(int t, int nt);

/* this is stuff that we were suppose to have 
void update();
void crawler();
bool moveExist();
void scoreKeep();
void countingFiles();
void computerMove();
*/

#endif
