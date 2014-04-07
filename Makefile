CC = gcc
CFLAGS = -DDEBUG -g -Wall -pedantic -std=c99
LFLAGS = -lgsl -lgslcblas -lm

cellaut.out: main.o plansza.o plansza.h
	$(CC) -o $@ main.o plansza.o $(LFLAGS)

clean:
	rm -f main.o plansza.o cellaut.out

test: cellaut.out
	./$< test1

test1: cellaut.out
	./cellaut.out dane1.board 16 2 test1
