Othello: main.o init.o
	gcc main.o init.o -o Othello

main.o: main.c
	gcc -c main.c -std=c99

init.o: init.c
	gcc -c init.c -std=c99

clean:
	rm -rf *o Othello
