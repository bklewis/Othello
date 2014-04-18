#include "io.h"
#include "main.h"

char getTokenNames(int t){
	switch(t){
		case X: return 'X';
		case O: return 'O';
		case M: return 'M';
		default: return '.';
	}
}

void print() {
        char rows[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        int i, j;
        printf("\n    1 2 3 4 5 6 7 8\n   -----------------\n");
        for (i = 0; i < 8; i++) {
                printf("%c | ", rows[i]);
                for (j = 0; j < 8; j++) {
                        if (j != 7) {
                                printf("%c ", getTokenNames(board[i][j]));
                        }
                        else {
                                printf("%c |",getTokenNames(board[i][j]));
                        }
                }
                printf("\n");
        }
        printf("   -----------------\n\n");
	printf("Player 1 Score: %d\nPlayer 2 Score: %d\n", p1score, p2score);
}


void getEntry() {
	char x, tempRow;
        int tempColumn, i;

	char rows[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

        printf("Please enter a row (A-H): ");
        scanf("%c", &tempRow);
        printf("Please enter a column (1-8): ");
        scanf("%d", &tempColumn);

	while((x = fgetc(stdin)) != EOF && x != '\n'){ ; }
        if (tempRow < 'A' || tempRow > 'H' || tempColumn < 1 || tempColumn > 8) {
                printf("\nInvalid entry.  Please enter new move.\n\n");
                getEntry();
        }

	col = tempColumn - 1;
        for (i = 0; i < 8; i++) {
                if (tempRow == rows[i]) {
                        row = i;
                }
        }
}
