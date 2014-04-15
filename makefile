Othello: main.o initialize.o
	gcc main.o initialize.o -o Othello

main.o: main.c
	gcc -c main.c -std=c99

initialize.o: initialize.c
	gcc -c initialize.c -std=c99

clean:
	rm -rf *o Othello
