CC=gcc
CFLAGS=-Wall -ansi

default: main.o pair.o
	$(CC) main.o pair.o -o group-selector

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

pair.o: pair.c pair.h
	$(CC) $(CFLAGS) -c pair.c -o pair.o
