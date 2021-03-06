Othello: main.o init.o io.o makeMove.o
	gcc main.o init.o io.o makeMove.o -o Othello -std=c99

main.o: main.c
	gcc -c main.c -std=c99

init.o: init.c
	gcc -c init.c -std=c99

makeMove.o: makeMove.c
	gcc -c makeMove.c -std=c99

io.o: io.c
	gcc -c io.c -std=c99

clean:
	rm -rf *.o
