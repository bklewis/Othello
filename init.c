#include "main.h"
#include "init.h"

//creates the original board and fills it appropriately
void initialize() {
	p1score = p2score = 0;
	bonusmode = 0; //default bonusmode is off.
	bonus_x = bonus_y = -1; //default bonus_x and bonus_y are -1
	pass = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = '-';
			computeCount[i][j]=0;
		}
	}
        board[3][3] = X;
        board[3][4] = O;
        board[4][3] = O;
        board[4][4] = X;
}
