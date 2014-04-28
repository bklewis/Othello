#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

//Make it three versions, the first one is human vs human, the second version is computer v.s human
//make sure that human does always start first/second. The last version is c v.s c  

int main(){
	srand(time(NULL));
    system("clear");
	
	printf("\n\nWelcome to Othello!\n\nYOOOOOOO!\n\n\n");
	
	initialize();
	int whichmode= getMode();
   	puts("in main");
   	if(whichmode==1)chooseMode(HUMAN, COMPUTER);
   	else if(whichmode==2) chooseMode(HUMAN,HUMAN);
   	else if(whichmode==3) chooseMode (COMPUTER,COMPUTER);
   	else{
   		 	puts("GetMode functions returns wierd stuff. Abort!");
   		 	exit(0);
   		}
	return 0;
}


void human(int turn){
	system("clear");
	print();
	getEntry();
	flipIt(turn,row,col,FLIPONLY);
	puts("\nYou made a move!\n");
	clear();
	print();
}


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
	//somewhere in getMode, it will say bonusmode = BONUSON or BONUSOFF 
	//bonusmode=1;
	if(bonusmode){//bonus_on
			bonus_x=randGen(0,7);
       		bonus_y=randGen(0,7);
       		
	}
	
    char x;
    //while((x = fgetc(stdin)) != EOF && x != '\n'){ ; }//clean up
    system("clear");
    //print();
    for(int i=3; i>=0; i--){
        printf("Game Start in %d\n",i);
        sleep(0.8);
        system("clear");
    }
   
	turn = randGen(0,1);
	//printf("Turn is %d\n",turn);
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
			turn=1;//take turns, the the other guy play.
		}
	}
	puts("Game over");
	printf("p1 scores: %d p2 scores: %d\n",p1score,p2score);
	if(p1score>p2score) puts("Player 1 (X) wins! \n");
	else if(p1score<p2score)  puts("Player 2 (O) wins! \n");
	else puts("You tied!  Boring... \n");
	exit(0);
	
}
