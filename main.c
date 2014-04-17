#include "main.h"
#include "init.h"
//#include "io.h"
//#include "makeMove.h"

//void initialize();

int main(){

	srand(time(NULL));

	p1score = 2;

	initialize();

	print();

	getEntry();

	printf("main: %d\n", p1score);

	printf("Othello!\n");
	return 0;
}
