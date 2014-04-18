#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

int main(){

	srand(time(NULL));

	printf("\n\nWelcome to Othello!\n\n");
	int turn = X;

	initialize();
	moveExist(turn);
	scoreKeep();
	print();

	int pass = 0;

	do{
		moveExist(turn);
		if(countMs()){
			if(turn){
				getEntry();
				printf("col: %d, row: %d\n", col, row);
				flipIt(X, O, col, row, FLIPONLY);
			}
			else{
				getEntry();
				//computerMove(O, X);
				printf("col: %d, row: %d\n", col, row);
				flipIt(O, X, col, row, FLIPONLY);
			}
		}
		else{
			pass++;
		}
		scoreKeep();
		print();
	} while (pass < 2);

	printf("GAME OVER!\n\n");
	//scoreKeep();
	//print();

	//moveExist(X);

	//printIt();

	//getEntry();

	//printf("main: %d\n", p1score);

/*	printf("Othello!\n");

	initialize();
	
	scoreKeep();
	printIt();
	moveExist(X);
	scoreKeep();
	print();
	computerMove(X,O);
	scoreKeep();
	printIt();
	print();*/
	//flipIt(X,O,6,0,FLIPONLY);
	//clear();
	//print();
	return 0;
}
