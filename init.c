#include "main.h"
#include "init.h"

void initialize() {
	p1score=0;
	p2score=0;
	bonusmode=0; //default bonusmode is off.
    bonus_x=-1; //default bonus_x and bonus_y are -1
	bonus_y=-1; //out of the board range
	pass=0;
	
		
        int i, j;
        for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                        board[i][j] = '-';
                        computeCount[i][j]=0;
                }
        }
        board[3][3] = X;
        board[3][4] = O;
        board[4][3] = O;
        board[4][4] = X;
}
