#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>

int randGen( int min,  int max){/*randge is [min,max]. problem with random, the sequence is determinstic... */
	//srand(time)NULL))
	double scaled = (double)rand()/RAND_MAX;
    return (max - min +1)*scaled + min;
}
int main(){
	int i=0; 
	while(i<20){
	printf("%d\n",randGen(0,5));
	i++;
	}
	return 1;
}
