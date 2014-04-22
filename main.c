#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

int main(){

	srand(time(NULL));

	printf("\n\nWelcome to Othello!\n\n");

	int turn = X;
	int pass = 0;
	initialize();


	do{
		printf("TURN: %d\n", turn);
		clear();
		moveExist(turn);
		scoreKeep();
		if(countMs()){
			if(turn){
				printf("moveExist: X\n");
				clear();
				moveExist(X);
				printf("Internal print: X\n");
				print();
				//computerMove(X, O);
				getEntry();
				printf("col: %d, row: %d\n", col, row);
				flipIt(X, O, row, col, FLIPONLY);
				clear();
				pass = 0;
			}
			else{
				printf("moveExist: O\n");
				clear();
				moveExist(O);
				printf("Internal print: O\n");
				print();
				getEntry();
				//computerMove(O, X);
				printf("col: %d, row: %d\n", col, row);
				flipIt(O, X, row, col, FLIPONLY);
				clear();
				pass = 0;
			}
		}
		else{
			printf("\nNo Move Exists for %d.  You pass!\n\n", turn);
			pass++;
			clear();
		}
		scoreKeep();
		clear();
		printf("SECOND PRINT\n");
		print();
		turn = !turn;
	} while (pass < 2);
    
    
	printf("\nGAME OVER!\n");
	printf("Final Score: %d to %d\n", p1score, p2score);
	if(p1score > p2score) printf("P1 Wins!\n\n");
	else if (p2score > p1score) printf("P2 Wins!\n\n");
	else printf("It's a tie!\n\n");


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
