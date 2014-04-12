include "main.h"
include "initialize.h"

void initialize() {
        int i, j;
        for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                        board[i][j] = '-';
                }
        }
        board[3][3] = 'X';
        board[3][4] = 'O';
        board[4][3] = 'O';
        board[4][4] = 'X';
}

