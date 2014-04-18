#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

//void initialize();

int main(){

	srand(time(NULL));

	//p1score = 2;

	printf("%d!\n", computeCount[0][0]);

	initialize();

	scoreKeep();
	print();

	//moveExist(X);

	//printIt();

	//getEntry();

	//printf("main: %d\n", p1score);

	printf("Othello!\n");

	initialize();
	
	scoreKeep();
	printIt();
	moveExist(X);
	scoreKeep();
	print();
	computerMove(X,O);
	scoreKeep();
	printIt();
	print();
	//flipIt(X,O,6,0,FLIPONLY);
	//clear();
	//print();
	return 0;
}
