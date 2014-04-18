#include "main.h"
#include "init.h"
//#include "io.h"
//#include "makeMove.h"

//void initialize();

int main(){

	srand(time(NULL));

	printf("NEW!\n");

	p1score = 2;

	initialize();

	printIt();

	getEntry();

	printf("main: %d\n", p1score);

	printf("Othello!\n");
	return 0;
}
