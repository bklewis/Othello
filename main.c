#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

//void initialize();

int main(){

	srand(time(NULL));

	printf("NEW!\n");

	p1score = 2;
	
	printf("%d!\n", computeCount[0][0]);
    
	initialize();

	print();

	//printIt();

	getEntry();

	printf("main: %d\n", p1score);

	printf("Othello!\n");
	
	
	//printIt();
	//moveExist(X);
//	print();
	//computerMove(X,O);
	//flipIt(X,O,6,0,FLIPONLY);
	//clear();
	//print();
	return 0;
}
