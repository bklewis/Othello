#include "main.h"
#include "init.h"

/*int main(){
	initialize();
	return 0;
}*/

void initialize() {
		flips=0;
		//printf("flips is init : %d", flips);
        int i, j;
        for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                        board[i][j] = '-';
                        computeCount[i][j]=0;
                }
        }
        board[3][3] = 'X';
        board[3][4] = 'O';
        board[4][3] = 'O';
        board[4][4] = 'X';
	printf("initialize!\n");
}

