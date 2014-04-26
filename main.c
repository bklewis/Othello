#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

//Make it three versions, the first one is human vs human, the second version is computer v.s human
//make sure that human does always start first/second. The last version is c v.s c  

int main(){

	srand(time(NULL));

	printf("\n\n Welcome to Othello!\n\n");

	initialize();
	getMode();
    //chooseMode(HUMAN,HUMAN);
	return 0;
}


void human(int turn){
	print();
	getEntry();
	flipIt(turn,row,col,FLIPONLY);
	puts("\n You made a move!");
	clear();
	print();
}


void computer(int turn){
     computerMove(turn);
     print();
     puts("\n Computer just moved. Press ENTER to continue");
     getchar();
     fflush(stdin);
}

void chooseMode(int mode1, int mode2){
    print();
	turn = randGen(0,1);
	printf("Turn is %d\n",turn);
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
				if(mode1==HUMAN) human(X);
				if(mode1==COMPUTER) computer(X);
				
				
				//the following is computer move
			    //computerMove(X);
			    //print();
			    
			    //the following is human move 
			    //print();
			    //getEntry();
				//flipIt(X,row,col,FLIPONLY);
				//puts("\n You made a move!");
				//clear();
				//print();
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
				if(mode2==HUMAN) human(O);
				if(mode2==COMPUTER) computer(O);
			    //the following is computer move
			    //computerMove(O);
			    //print();
			    //puts("\n Computer just moved. Press ENTER to continue");
			    //getchar();
			    

			    //the following is human move 
			    
				//print();
				//getEntry();
				//flipIt(O,row,col,FLIPONLY);
				//puts("\n You made a move!");
				//clear();
				//print();
			}
			turn=1;//take turns, the the other guy play.
		}
	}
	puts("Game over");
	printf("p1s: %d p2s: %d\n",p1score,p2score);
	if(p1score>p2score) puts("Player1 (X) wins! ");
	else if(p1score<p2score)  puts("Player2 (O) wins! ");
	else puts("Tied! Boring... ");
	
}



