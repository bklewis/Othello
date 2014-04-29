#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

int main(){
	srand(time(NULL));
	system("clear");

	//create the board
	printf("\n\nWelcome to Othello!\n\n");
	initialize();

	//get the mode from the user
	int whichmode= getMode();
   	puts("in main");
	//and run the game!
   	if(whichmode==1)chooseMode(HUMAN,COMPUTER);
   	else if(whichmode==2) chooseMode(HUMAN,HUMAN);
   	else if(whichmode==3) chooseMode(COMPUTER,COMPUTER);
   	//something is wrong
	else{
		puts("GetMode functions return errors. Abort!");
		exit(0);
   	}
	return 0;
}

//run the human turn (get input from user)
void human(int turn){
	system("clear");
	print();
	getEntry();
	flipIt(turn,row,col,FLIPONLY);
	puts("\nYou made a move!\n");
	clear();
	print();
}

//run the computer turn (automatically generate a move)
void computer(int turn){
     system("clear");
     print();
     computerMove(turn); //it will say computer is thinking
     sleep(1);
     system("clear");
     print();
     puts("\nComputer just moved!\n");
     sleep(1);
}

//Chooses mode based on user input and runs both players' turns
//until game is complete
void chooseMode(int mode1, int mode2){
	//getMode specifies whether bonusmode is BONUSON or BONUSOFF 
	if(bonusmode){
		bonus_x=randGen(0,7);
       		bonus_y=randGen(0,7);
	}

	char x;
	system("clear");
	for(int i=3; i>=0; i--){
	        printf("Game Start in %d\n",i);
	        sleep(0.8);
	        system("clear");
	}

	turn = randGen(0,1);
	while(pass<2){
		if(turn){//Player1
			//the following check if moveExist, marks moves
			if(!moveExist(X)) {//No move exist, this means pass.
				turn=0;
				pass++;
				puts("Turn is passed: no move available!\n");
			}else{
			//commit moves here
				if(mode1==HUMAN) human(X);
				if(mode1==COMPUTER) computer(X);
			}
			turn=0;//next player's turn

		}else{//Player2
			//the following check if moveExist, marks moves
			if(!moveExist(O)) {//No move exist, this means pass.
				turn=1;
				pass++;
				puts("Turn is passed: no move available!\n");
			}else{
			//commit moves here
				if(mode2==HUMAN) human(O);
				if(mode2==COMPUTER) computer(O);
			}
			turn=1;//next player's turn
		}
	}
	puts("GAME OVER\n");
	printf("Final Score:  %d to %d\n\n",p1score,p2score);
	if(p1score>p2score) puts("Player 1 (X) wins! \n");
	else if(p1score<p2score)  puts("Player 2 (O) wins! \n");
	else puts("You tied!  Boring... \n");
	exit(0);
}
