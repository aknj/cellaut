CC = gcc
CFLAGS = -DDEBUG -g -Wall -pedantic -std=c99
LFLAGS = -lgsl -lgslcblas -lm

cellaut.out: main.o plansza.o rules.o
	$(CC) -o $@ $^ $(LFLAGS)

plansza.o: plansza.h state.h

rules.o: rules.h state.h neighborhood.h neighborhood.o

# neighborhood.o: plansza.h

clean:
	rm -f *.o cellaut.out

testm: cellaut.out
	./$< mat1

testm2: cellaut.out
	./$< mat2

test1: cellaut.out
	./cellaut.out dane1.board 16 2 test1
