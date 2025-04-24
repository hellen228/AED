set: main.o set.o
	gcc main.o set.o -o set
main.o: main.c set.h
	gcc -c main.c
set.o: set.c set.h
	gcc -c set.c