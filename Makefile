CC = gcc
CFLAGS = -DDEBUG -g -Wall -pedantic -std=c99
LFLAGS = -lgsl -lgslcblas -lm

cellaut: main.o plansza.o plansza.h
	$(CC) -o $@ main.o plansza.o $(LFLAGS)

clean:
	rm -f main.o plansza.o

test1:
	./cellaut dane1.board 16 2 test1
