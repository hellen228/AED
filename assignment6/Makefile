class: main.o class.o
	gcc main.o class.o -o class
main.o: main.c class.h
	gcc -c main.c
class.o: class.c class.h
	gcc -c class.c