#include <stdio.h>
#include <stdlib.h>
#include "makeMove.h"
//#include "main.h"
#define N 8

//all global variables 
typedef enum  {X=1, O=2, M=3} token;
typedef enum  {COUNTONLY,FLIPONLY} mode;
int board [N][N]={ {0,0,0,0,0,0,0,0},   
                   {0,0,0,0,0,0,0,0},  
                   {0,0,0,X,0,X,0,0},  
                   {0,0,0,O,O,0,0,0},   
                   {0,0,0,0,O,0,0,0},   
                   {0,0,0,0,X,0,0,0},    
                   {0,0,0,0,0,0,0,0},   
                   {0,0,0,0,0,0,0,0} };
                   
int computeCount[N][N] = {0};                   
int flips;


/*
void main(){
	srand(time(0));
	print();
	moveExist(X);
	print();
	computerMove(X,O);
	//flip(X,O,6,0,FLIPONLY);
	//clear();
	print();
}
*/
//Functions

int randGen( int min,  int max){/*randge is [min,max]. problem with random, the sequence is determinstic... */
	//srand(time)NULL))
	double scaled = (double)rand()/RAND_MAX;
    return (max - min +1)*scaled + min;
}

void computerMoveHelper(int t, int nt, int *max, int *count){ //returns max counts 
	int maxy=0;
	int county=0;
	for(int i=0; i<N ;i++){
		for(int j=0; j<N; j++){
			if(board[i][j]==M){
				county++;
				computeCount[i][j]=flip(t,nt,i,j,COUNTONLY);
				if(computeCount[i][j]>maxy) maxy =computeCount[i][j];
			}//end if board
		}//enf for int j
	}//end for i	
	*max=maxy;
	*count=county;
}

void computerMove(int t, int nt){
	
	int max=0,count=0;
	computerMoveHelper(t,nt,&max,&count);
    int number = randGen(1,count);
    int tog=1;
    while(tog && number >=1){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(computeCount[i][j]==max){
					//printf("number is %d\n",number);
					if(number==1){
					    //printf("here\n");
						flip(t,nt,i,j, FLIPONLY);
						tog=0;
						number=0;
						i=N;
						j=N;
					}
					number--;
				}//if
			}//for j
 	    }//for i
	  
	}//end while
	clear();
}//computerMove




int flip(int t,int nt, int x, int y, int mode){
	flips=0;
	if(board[x][y]!=M) {
		printf("Input coordinates for M is not valid!\n");
		return -1; //return -1 is M is not valid coordinates
	}
	
	//now, this M looks at eight directions
	int m,n,step=0;
	
	//UP 
	m=x-1;n=y;step=0;
	while(m>=0 && (board[m][n]==nt)){ //consume all the opposite symbol
		m--;
		step++;
	}
	//step >1 means there are opposite symbol, next I should check if last one is the same symbol as t.
	if(step){
		if(board[m][n]==t){
			//start flip: set board[x][y] to be t; flip all the other until out of bound or there is none 
			if(mode==FLIPONLY)board[x][y]=t;
			m=x-1;n=y;
			while(m>=0 && (board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				m--;
			}
		}
	}//END_UP
	
    //DOWN
	m=x+1;n=y;step=0;
	while(m<N && (board[m][n]==nt)){ 
		m++;
		step++;
	}
	if(step){
		if(board[m][n]==t){
			if(mode==FLIPONLY)board[x][y]=t;
			m=x+1;n=y;
			while(m<N && (board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				m++;
			}
		}
	}//END_DOWN
	
	//LEFT
	m=x;n=y-1;step=0;
	while(n>=0 &&(board[m][n]==nt)){
		n--;
		step++;
	}
	
	if(step){
		if(board[m][n]==t){
			if(mode==FLIPONLY)board[x][y]=t;
			m=x;n=y-1;
			while(n>=0 &&(board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				n--;
			}
		}
	}//END_LEFT
	
	//RIGHT --NOT TESTED
	m=x; n=y+1;step=0;
	while(n<N &&(board[m][n]==nt)){
		n++;
		step++;
	}
	if(step){
		if(board[m][n]==t){
			if(mode==FLIPONLY)board[x][y]=t;
			m=x; n=y+1;
			while(n<N &&(board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				n++;
			}
		}
	}//END_RIGHT
	
	//UPLEFT
	m=x-1;n=y-1;step=0;
	while(m>=0 && n>=0 &&(board[m][n]==nt)){
		n--;
		m--;
		step++;
	}
	if(step){
		if(board[m][n]==t){
			if(mode==FLIPONLY)board[x][y]=t;
			m=x-1;n=y-1;
			while(m>=0 && n>=0 &&(board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				m--;
				n--;
			}
		}
	}//END_UPLEFT
	
	
	//UPRIGHT 
	m=x-1;n=y+1;step=0;
	while(m>=0 && n<N &&(board[m][n]==nt)){
		m--;
	 	n++;
		step++;
	}
	if(step){
		if(board[m][n]==t){
			if(mode==FLIPONLY)board[x][y]=t;
			m=x-1;n=y+1;
			while(m>=0 && n<N &&(board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				m--;
				n++;
			}
		}
	}//END_UPRIGHT
	
	//DOWNLEFT
	m=x+1;n=y-1;step=0;
	while(m<N && n>=0 && (board[m][n]==nt)){
		m++;
		n--;
		step++;	
	}
	if(step){
		if(board[m][n]==t){
			if(mode==FLIPONLY)board[x][y]=t;
			m=x+1;n=y-1;
			while(m<N && n>=0 && (board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				m++;
				n--;
			}
		}
	}//END_DOWNLEFT
	
	//DOWNRIGHT 
	m=x+1;n=y+1;step=0;
	while(m<N && n<N && (board[m][n]==nt)){
		m++;
		n++;
		step++;
	}
	if(step){
		if(board[m][n]==t){
			if(mode==FLIPONLY)board[x][y]=t;
			m=x+1;n=y+1;
			while(m<N && n<N && (board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				m++;
				n++;
			}
		}
	}//END_DOWNRIGHT
	//printf("flips is %d\n",flips);
	return flips;
}
 
                  
char getTokenName(int t){
	switch(t){
		case X: return 'X';
		case O: return 'O';
		case M: return 'M';
		default: return '.';
	}
}

void print(){
printf("0 1 2 3 4 5 6 7 \n");
for(int i = 0; i<N ; i++){

		for( int j =0; j<N; j++){
		printf("%c ",getTokenName( board[i][j] ) );
		
		}
		printf("%d \n", i);
	}
	printf("\n\n");
}	


void clear(){
//printf("0 1 2 3 4 5 6 7 \n");
for(int i = 0; i<N ; i++){
		for( int j =0; j<N; j++){
		if(board[i][j] == 3) board[i][j]=0;
		}
	}
}

//move exist helper
int meCrawler(int t, int step, int m, int n){
    if( (step==1) && ((getTokenName(board[m][n]) == '.')||( getTokenName(board[m][n])  == 'M'))) return 1;
    if(board[m][n]==t) return 1;
    if( (step>1) && ((getTokenName(board[m][n]) == '.')||( getTokenName(board[m][n])  == 'M')) ){
	    board[m][n]=3;
		return 1;
	}
	return 0;
}

int moveExist (int t){//t indicates wethher this is a X or a O
	for(int i = 0; i<N ; i++){
		for( int j =0; j<N; j++){
			if(getTokenName( board[i][j] ) == getTokenName(t)){
				int m,n,step;
				
				//direction up
				m=i-1;
				step=1;
				while(m>=0){
					if(meCrawler(t,step,m,j)) break;
					step++;
					m--;
				}//end diretion up;

				//direction down
				m=i+1;
				step=1;
				while(m<N){
					if(meCrawler(t,step,m,j)) break;
					step++;
					m++;
				}//end diretion down;

               
				//direction left
				m=j-1;
				step=1;
				while(m>=0){
					//printf("token is: %c , step is %d\n",board step);
					if(meCrawler(t,step,i,m)) break;
					step++;
					m--;
				}//end diretion left;

				//direction right
				m=j+1;
				step=1;
				while(m<N){
					if(meCrawler(t,step,i,m)) break;
					step++;
					m++;
				}//end diretion right;
				
				//direction upleft
				m=i-1;
				n=j-1;
				step=1;
				while(m>=0 && n>=0){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m--;
					n--;
				}//end diretion upleft;
				
				//direction downleft
				m=i+1;
				n=j-1;
				step=1;
				while(m<N && n>=0){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m++;
					n--;
				}//end diretion downleft;
				
				//direction downright
				m=i+1;
				n=j+1;
				step=1;
				while(m<N && n<N){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m++;
					n++;
				}//end diretion downright;
				
				//direction upright
				m=i-1;
				n=j+1;
				step=1;
				while(n<N && m>=0){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m--;
					n++;
				}//end diretion upright;
				
			}//End of Eight Direction
		}
		//printf("\n");
	}
} 




	


