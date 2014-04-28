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
	puts("\n	OTHELLO \n");
	if(turn ==X) puts("Player1 is playing (X):");
	else puts("Player2 is playing (O):");
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
	printf("Player 1 (X) Score: %d \nPlayer 2 (O) Score: %d\n\n--------------------\n", p1score, p2score);
}

//get Entry gets entry and it will let the user reenter the input if the input is not legal
void getEntry() {
	int flag=1;
	char str[100];
   	int num=0;
    char letter=0;

	printf("Please enter a row (A-H) and a column (1-8): ");
	while(1){
	  	flag=1; //indicator
      	gets(str);//get line
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

//returns a number from 1-3, indicating which mode is chosen among the three at the frist prompt
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
     	gets(str);
      	sscanf(str, "%d", &num);
      	printf("Entered: %d\n", num);
      	if (num == 1) {res=1;flag1=0;break;}
	    else if (num == 2) {res=2;flag1=0;break;}
	    else if (num == 3) {res=3;flag1=0;break;}
	    else{
	    	printf("%d is not valid, choose from 1-3: ",num);
	    }
	}
	
	//Prompt 2 
	if(flag2)printf("Do you want to try BONUS MODE (= Unfair advantages most of the time)? [y/n]: ");
	
	while(flag2){
		//this check y/n only
     	gets(str);
      	sscanf(str, "%c", &letter);
      	printf("Entered: %c\n", letter);
      	if (letter == 'y' || letter =='Y') {bonusmode=1;flag2=0; return res;}
	    else if (letter == 'n' || letter== 'N') {bonusmode=0;flag2=0;return res;}
	    else{
	    	printf("%c is not valid, type y or n: ",letter);
	    }
	}
	//the res indicates which mode are chosen.
    return res;
}
