#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

int main(){
	srand(time(NULL));
	system("clear");

	//create board
	printf("\n\nWelcome to Othello!\n\n");
	initialize();

	//get mode of game and run
	int whichmode= getMode();
   	puts("in main");
   	if(whichmode==1)chooseMode(HUMAN,COMPUTER);
   	else if(whichmode==2) chooseMode(HUMAN,HUMAN);
   	else if(whichmode==3) chooseMode(COMPUTER,COMPUTER);
   	else{
		puts("GetMode functions return errors. Abort!");
		exit(0);
   	}
	return 0;
}

//the human turn
void human(int turn){
	system("clear");
	print();
	getEntry();
	flipIt(turn,row,col,FLIPONLY);
	puts("\nYou made a move!\n");
	clear();
	print();
}

//the computer turn
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

void chooseMode(int mode1, int mode2){
	//getMode specifies whether bonusmode is BONUSON or BONUSOFF 
	if(bonusmode){//bonus_on
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
			//puts("Player1 (X) is playing ...");
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
			turn=0;//take turn, let the other player play.

		}else{//Player2
			//puts("Player2 (O) is playing....");
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
	printf("Final Score:\nPlayer 1: %d, Player 2: %d\n",p1score,p2score);
	if(p1score>p2score) puts("Player 1 (X) wins! \n");
	else if(p1score<p2score)  puts("Player 2 (O) wins! \n");
	else puts("You tied!  Boring... \n");
	exit(0);
}
