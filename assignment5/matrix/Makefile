matriz: main.o matrix.o
	gcc main.o matrix.o -o matriz
main.o: main.c matrix.h
	gcc -c main.c
matrix.o: matrix.c matrix.h
	gcc -c matrix.c