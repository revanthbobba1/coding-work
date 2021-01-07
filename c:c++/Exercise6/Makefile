main: main.o print.o
	gcc main.o print.o -lm -o main
print.o: print.c print.h
	gcc -Wall -std=c99 -g -c print.c -o print.o
main.o: main.c
	gcc -Wall -std=c99 -g -c main.c -o main.o