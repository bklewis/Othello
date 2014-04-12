#include "io.h"
#include "main.h"

void print() {
        char rows[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        int i, j;
        printf("\n    1 2 3 4 5 6 7 8\n   -----------------\n");
        for (i = 0; i < 8; i++) {
                printf("%c | ", rows[i]);
                for (j = 0; j < 8; j++) {
                        if (j != 7) {
                                printf("%c ", board[i][j]);
                        }
                        else {
                                printf("%c |", board[i][j]);
                        }
                }
                printf("\n");
        }
        printf("   -----------------\n\n");

}


void getEntry() { /*there is a bug in getEntry() which I am working on resolving*/
        printf("Please enter a row (A-H): ");
        scanf("%c", &row);
        printf("Please enter a column (1-8): ");
        scanf("%d", &column);
        if (row < 'A' || row > 'H' || column < 1 || column > 8) {
                printf("\nInvalid entry.  Please enter new move.\n\n");
                getEntry();
        }
}
