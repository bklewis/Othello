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


//print will do score keeping and print at the same time
void print() {
	p1score=0;
	p2score=0;
        char rows[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        int i, j;
        printf("\n    1 2 3 4 5 6 7 8\n   -----------------\n");
        for (i = 0; i < 8; i++) {
                printf("%c | ", rows[i]);
                for (j = 0; j < 8; j++) {
                        if (j != 7) {
                        		//do the scorekeeping at the same time
                        		if(board[i][j]==X) p1score++;
								else if(board[i][j]==O) p2score++;
                                printf("%c ", getTokenNames(board[i][j]));
                        }else {
                                printf("%c |",getTokenNames(board[i][j]));
                        }
                }
                printf("\n");
        }
        printf("   -----------------\n\n");
	printf("Player 1 (X) Score: %d \nPlayer 2 (O) Score: %d\n\n", p1score, p2score);
	
}

//get Entry gets entry and it will let the user reenter the input if the input is not legal
void getEntry() {
	char x, tempRow;
    	int tempColumn, i;

	char rowsUpper[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	char rowsLower[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

        printf("Please enter a row (A-H): ");
        scanf("%c", &tempRow);
        printf("Please enter a column (1-8): ");
        scanf("%d", &tempColumn);

	while((x = fgetc(stdin)) != EOF && x != '\n'){ ; }

	if (tempRow < 'A' || tempRow > 'h' || (tempRow > 'H' && tempRow < 'a') || tempColumn < 1 || tempColumn > 8) {
                printf("\n%c%d is an invalid entry.  Please enter a new move.\n\n", tempRow, tempColumn);
                getEntry();
        }

	col = tempColumn - 1;
        for (i = 0; i < 8; i++) {
                if (tempRow == rowsUpper[i]) {
                        row = i;
                }
		else if (tempRow == rowsLower[i]) {
                        row = i;
                }
        }

	if (board[row][col] != M) {
		printf("%c%d is not a valid move.  Please enter a new move.\n", tempRow, tempColumn);
		getEntry();
	}
}

void getMode(){
	char x;
	printf("Please select a mode:\n"
	"    1 -> Human vs. Computer\n"
	"    2 -> Human vs. Human\n"
	"    3 -> Computer vs. Computer\n");
	scanf("%c", &x);

	if (x == '1') chooseMode(HUMAN, COMPUTER);
	else if (x == '2') chooseMode(HUMAN, HUMAN);
	else if (x == '3') chooseMode(COMPUTER, COMPUTER);
	else{
		printf("That input is not correct.  Please enter 1, 2, or 3\n\n");
		getMode();
	}
	
	while((x = fgetc(stdin)) != EOF && x != '\n'){ ; }//clean up 
}


