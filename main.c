#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

int main(){

	srand(time(NULL));

	printf("\n\n Welcome to Othello!\n\n");

	initialize();
	
	//these variables are used for the main flow of the game
	//turn is the current player's symbol, pass indicates one player's turn is passed because
	//there is no valid move exist.
    int turn = X;
	
	while(pass<2){
		if(turn){//Player1
			puts("Player1 (X) is playing ...");
			//the following check if moveExist, marks moves
			if(!moveExist(X)) {//No move exist, this means pass.
				turn=0; 
				pass++;
				puts(":) Just passed because there is no move!");
			}else{
			//commit moves here 
			
				//the following is computer move
			    //computerMove(X);
			    // print();
			    
			    //the following is human move 
			    
				print();
				getEntry();
				flipIt(X,O,row,col,FLIPONLY);
				puts("\n You made a move!");
				clear();
				print();
			}
			
			turn=0;//take turn, let the other player play.
			
		}else{//Player2
			puts("Player2 (O) is playing....");
			//the following check if moveExist, marks moves
			if(!moveExist(O)) {//No move exist, this means pass.
				turn=1; 
				pass++;
				puts(":) Just passed because there is no move!");
			}else{
			//commit moves here 
			    //the following is computer move
			    computerMove(O);
			   
			    print();
			    
			    puts("\n Computer just moved. Press ENTER to continue");
			    getchar();
			    
			
			    
			    //the following is human move 
			    
				//print();
				//getEntry();
				//flipIt(O,X,row,col,FLIPONLY);
				//puts("\n You made a move!");
				//clear();
				//print();
			}
			
			turn=1;//take turns, the the other guy play.
			
		}
	}
	puts("Game over");
	
	//SAY WHO WINS THE GAME!!!
	
	
	
    
    
	//printf("Final Score: %d to %d\n", p1score, p2score);
	//if(p1score > p2score) printf("P1 Wins!\n\n");
	//else if (p2score > p1score) printf("P2 Wins!\n\n");
	//else printf("It's a tie!\n\n");


	/*printf("Othello!\n");

	initialize();
	
	scoreKeep();
	printIt();
	moveExist(X);
	scoreKeep();
	print();
	computerMove(X,O);
	scoreKeep();
	printIt();*/

	//flipIt(X,O,6,0,FLIPONLY);
	//clear();
	//print();
	return 0;
}
