#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

int main(){

	srand(time(NULL));

	printf("\n\nWelcome to Othello!\n\n");
	int turn = X;

	initialize();
	//moveExist(turn);
	//scoreKeep();
	//print();

	int pass = 0;

	do{
		printf("TURN: %d\n", turn);
		moveExist(turn);
		scoreKeep();
		print();
		if(countMs()){
			if(turn){
				//computerMove(X, O);
				getEntry();
				printf("col: %d, row: %d\n", col, row);
				flipIt(X, O, row, col, FLIPONLY);
			}
			else{
				getEntry();
				//computerMove(O, X);
				printf("col: %d, row: %d\n", col, row);
				flipIt(O, X, row, col, FLIPONLY);
			}
		}
		else{
			pass++;
		}
		//scoreKeep();
		//print();
		turn = !turn;
	} while (pass < 2);

	printf("\nGAME OVER!\n");
	printf("Final Score: %d to %d\n", p1score, p2score);
	if(p1score > p2score) printf("P1 Wins!\n\n");
	else if (p2score > p1score) printf("P2 Wins!\n\n");
	else printf("It's a tie!\n\n");
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
