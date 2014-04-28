#include "makeMove.h"
#include "main.h"

int randGen( int min,  int max){/*randge is [min,max]. Have to called srand(time(0)) in main for randomness*/
	double scaled = (double)rand()/RAND_MAX;
    return (max - min +1)*scaled + min;
}

int getOppositeSymbol(int t){//given t == X, it returns O, and vice versa.
	if(t==X) return O;
	if(t==O) return X;
	else return 0;
}


//computerMoveHelper: it looks at the board, for every M, store the number of token each M can flip.
//It also updates variable count (number of M on the board currently.) and max: the max number of tokens
//that the "most capable" M can filp
void computerMoveHelper(int t, int nt, int *max, int *count){ 
	int maxy=0;
	int county=0;
	int i=0,j=0;
	//go through the board
	for(i=0; i<N ;i++){
		for(j=0; j<N; j++){
			if(board[i][j]==M){//for every M
				county++; //county is same as count
				computeCount[i][j]=flipIt(t,i,j,COUNTONLY);
				//the max number of tokens that the "most capable" M can filp
				if(computeCount[i][j]>maxy) maxy =computeCount[i][j]; 
			}//end if board
		}//enf for int j
	}//end for i	
	*max=maxy;
	*count=county;
	//printf("        max is : %d, count is: %d \n", maxy, county);
}


//ConputerMove will determine where to move given the current player's symbol t
void computerMove(int t){
	puts("Computer is thinking ... like very hard ");
	//sleep(2);
	int i,j; // index used in double for loops 
	int max=0,count=0;
	int nt =getOppositeSymbol(t);
	
	if(nt==0){
		printf("Computer Move helper input symbol is wrong, abort!\n");
		exit(0);
	}
	
	computerMoveHelper(t,nt,&max,&count);
	
	//next the computer will pick the best M to flip
    //number is random, of range[1,count].
    int number = randGen(1,count);
   // printf("        in function computerMove the number is: %d \n",number );
    int tog=1;
    //assume there are 3 'M's on the board that can flip the most token. 
    //the following will loops through the board, pick the M only if number ==1
    //number is always some random number >= 1
    while(tog && number >=1){
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(computeCount[i][j]==max){
					if(number==1){
					    //printf("\nThe computer decides to move i(verti): %d, j(Hori): %d \n", i, j);
						flipIt(t,i,j,FLIPONLY);
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


//it goes to eight direction. Depending on the mode, it will flip or count flips in each direction. It returns 
//number of flips in a certain direction.
int flipIt(int t, int x, int y, int mode){
	//for a certain position, flips remembers the total number of flips in eight direction.
	int nt= getOppositeSymbol(t);
	int flips=0;
	if(board[x][y]!=M) {
		printf("Input coordinates for M are not valid!\n");
		return -1; //return -1 is M is not valid coordinates
	}
	
	//now, this M looks at eight directions
	int m,n,step=0;
	
	//UP-Direction
	m=x-1;n=y;step=0;/*m and n differ for each direction,because it's the 1st step towards that direction */ 
	while(m>=0 && (board[m][n]==nt)){//consume all the opposite symbols
		m--;
		step++;
	}
	//step >1 means there are opposite symbol, next I should check if last one is the same symbol as t.
	if(step){
		if(board[m][n]==t){
			//start flipIt: set board[x][y] to be t; flipIt all the other until out of bound or there is none 
			if(mode==FLIPONLY)board[x][y]=t;
			m=x-1;n=y;
			while(m>=0 && (board[m][n]==nt)){
				if(mode==FLIPONLY)board[m][n]=t;
				flips++;
				m--;
			}
		}
	}//END_UP
	
	
	//All the other direction are analogous.so no comments for them, the boundary condition
	//and starting m and b differ in each case, as discussed above.
    
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
}//end flipIt
 
                  
//some helper function for printing                  
char getTokenName(int t){
	switch(t){
		case X: return 'X';
		case O: return 'O';
		case M: return 'M';
		default: return '.';
	}
}


//clear() will clean up all the M's later on.
void clear(){
//printf("0 1 2 3 4 5 6 7 \n");
for(int i = 0; i<N ; i++){
		for( int j =0; j<N; j++){
		if(board[i][j] == 3) board[i][j]=0;
		    computeCount[i][j]=0;
		}
	}
}

//move exist helper return one means quit this direction
int meCrawler(int t, int step, int m, int n, int *signal){
	//below: means these is a blank adjacent to t at this direction. which means this is a bad direction, return 1 so that we can quit in move exist for this particular direction.
    if( (step==1) && ((getTokenName(board[m][n]) == '.')||( board[m][n] == M))) return 1;
    //the below means that the there is a same symbol in this direction.
    if(board[m][n]==t) return 1;
    //after the first two if statement, the adjacent cell must be opposite to t. as desiired.
    if( (step>1) && ((getTokenName(board[m][n]) == '.')|| ( board[m][n] == M)) ){
	    board[m][n]=M;
	    (*signal)=1;
		return 1;
	}
	return 0;
}

//MoveExist returns 1 if there are moves Available for the current player(X or O). It returns 0 otherwise. 
int moveExist (int t){
	int signal=0; //it will become 1 if there are move exist.
	
	//going through eight directions 
	for(int i = 0; i<N ; i++){
		for( int j =0; j<N; j++){
			if(board[i][j]  == t){//proceeds only if symbol t. (t is either X or O. Bad variable name, I know..)
				//m,n are index. 
				int m,n,step;
				
				//direction up
				m=i-1;
				step=1; //step always starts from 1. step indicates steps from current cell to the original cell
				while(m>=0){ // <--this condition test for boundary
					if(meCrawler(t,step,m,j,&signal)) break;
					step++;
					m--;
				}//end diretion up;

				//direction down
				m=i+1;
				step=1;
				while(m<N){
					if(meCrawler(t,step,m,j,&signal)) break;
					step++;
					m++;
				}//end diretion down;

               
				//direction left
				m=j-1;
				step=1;
				while(m>=0){
					//printf("token is: %c , step is %d\n",board step);
					if(meCrawler(t,step,i,m,&signal)) break;
					step++;
					m--;
				}//end diretion left;

				//direction right
				m=j+1;
				step=1;
				while(m<N){
					if(meCrawler(t,step,i,m,&signal)) break;
					step++;
					m++;
				}//end diretion right;
				
				//direction upleft
				m=i-1;
				n=j-1;
				step=1;
				while(m>=0 && n>=0){
					if(meCrawler(t,step,m,n,&signal)) break;
					step++;
					m--;
					n--;
				}//end diretion upleft;
				
				//direction downleft
				m=i+1;
				n=j-1;
				step=1;
				while(m<N && n>=0){
					if(meCrawler(t,step,m,n,&signal)) break;
					step++;
					m++;
					n--;
				}//end diretion downleft;
				
				//direction downright
				m=i+1;
				n=j+1;
				step=1;
				while(m<N && n<N){
					if(meCrawler(t,step,m,n,&signal)) break;
					step++;
					m++;
					n++;
				}//end diretion downright;
				
				//direction upright
				m=i-1;
				n=j+1;
				step=1;
				while(n<N && m>=0){
					if(meCrawler(t,step,m,n,&signal)) break;
					step++;
					m--;
					n++;
				}//end diretion upright;
				
			}//End of Eight Direction
		}
		//printf("signal is: %d\n");
	}
	//printf("signal is: %d  ", signal);	
	return signal;
}//End moveExist
