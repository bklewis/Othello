#include "io.h"
#include "main.h"
#include "makeMove.h"

//COLORS! to use then, do   printf( RED "whatever you want print" RESET );
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

//prints the board and simultaneously keeps score
void print() {
        int i, j;
        char rows[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	p1score=p2score=0;

	puts("\n	OTHELLO \n" );
	if(turn ==X) puts("Player 1 is playing (X):");
	else puts("Player 2 is playing (O):");
        printf("\n    1 2 3 4 5 6 7 8\n   -----------------\n");
        for (i = 0; i < 8; i++) {
                printf("%c | ", rows[i]);
                for (j = 0; j < 8; j++) {
                        
                        	//do the scorekeeping at the same time
                        	if(board[i][j]==X) p1score++;
							else if(board[i][j]==O) p2score++;
							
							//Board
							if(board[i][j]==X) printf( "%c ", getTokenName(board[i][j])); 
                            else if(board[i][j]==O) printf(RED "%c " RESET, getTokenName(board[i][j])); 
                            else if(board[i][j]==M) printf(BLUE "%c " RESET, getTokenName(board[i][j])); 
                            else printf("%c ", getTokenName(board[i][j])); 
                		   }
                		   
               // }
                printf("| \n");
        }
        printf("   -----------------\n\n");
	printf("Player 1 (X) Score: %d \nPlayer 2 (O) Score: %d\n\n--------------------\n", p1score, p2score);
}

//gets user entry for column and row; 
//checks input and allows user to reenter if input not legal
void getEntry() {
	int flag=1;
	char str[100];
   	int num=0;
	char letter=0;

	printf("Please enter a row (A-H) and a column (1-8): ");
	while(1){
	  	flag=1; //indicator
      		fgets(str, sizeof(str), stdin);//get line
      		sscanf(str, "%c %d", &letter, &num);//parse line

        	//check if input is valid
      		if((num>=1 && num<=8) &&  ((letter>='a' && letter<='h')||(letter>='A' && letter<='H')) ){
        		col = num-1;
      			flag=0;
        		if(letter < 123 && letter > 96){row = letter - 'a' ;}
      			if(letter < 91 && letter > 64){row = letter - 'A' ;}
      			if (board[row][col] == M) break;
        		printf("Input %c %d is not a valid move!\nEnter a move where there is an M: ", letter, num);
        	}//end if((num>=1

		if(flag)printf("Input %c %d is not valid!\nEnter a row (A-H) and a column (1-8): ", letter,num);
	}//end while(1);
}//End of getEntry()

//returns a number from 1-3, indicating which mode is chosen 
//among the three at the frist prompt
int getMode(){
	int flag1=1; //indicators
	int flag2=1;
	char str[100]; //used for storage
   	int num=0;
	char letter=0;
	int res=0; //temp result holder
    
	if(flag1)printf("Please select a mode:\n"
	"    1 -> Human vs. Computer\n"
	"    2 -> Human vs. Human\n"
	"    3 -> Computer vs. Computer\n");
	
	while(flag1){
		//this checks 1-3
     		fgets(str, sizeof(str), stdin);//get line
      		sscanf(str, "%d", &num);
      		printf("Entered: %d\n", num);
      		if (num == 1) {res=1;flag1=0;break;}
		else if (num == 2) {res=2;flag1=0;break;}
		else if (num == 3) {res=3;flag1=0;break;}
		else{
			printf("%d is not valid, choose from 1-3: ", num);
		}
	}

	//Prompt 2
	if(flag2)printf("\nBonus mode runs a special game that involves a hidden 'bonus' tile.\n"
	"When the tile is played upon by one player, it acts as a normal token, but additionally\n"
	"flips one of the opponent's tiles (chosen at random) to the symbol of the player who hit the bonus.\n"
	"\nDo you want to try BONUS MODE? [y/n]: ");

	while(flag2){
		//this checks y/n only
      		fgets(str, sizeof(str), stdin);//get line
		sscanf(str, "%c", &letter);
		printf("Entered: %c\n", letter);
		if (letter == 'y' || letter =='Y') {bonusmode=1;flag2=0; return res;}
		else if (letter == 'n' || letter== 'N') {bonusmode=0;flag2=0;return res;}
		else{
	    		printf("%c is not valid, please enter y or n: ", letter);
		}
	}
	//the res indicates which mode are chosen.
	return res;
}
