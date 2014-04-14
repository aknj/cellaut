CC = gcc
CFLAGS = -DDEBUG -g -Wall -pedantic -std=c99
LFLAGS = -lbmp -lm
NAME = life.out

$(NAME): main.o plansza.o rules.o boardio.o automaton.o torus_neighborhood.o
	$(CC) -o $@ $^ $(LFLAGS)

main.o: boardio.h automaton.h

plansza.o: plansza.h state.h

rules.o: rules.h state.h neighborhood.h

# neighborhood.o: plansza.h

.PHONY: clean testnbh

clean:
	rm -f *.o test/*.o *.out

#testm: $(NAME)
#	./$< mat1

#testm2: $(NAME)
#	./$< mat2

#test1: $(NAME)
#	./$< dane1.board 16 2 test1

# testy samego neighborhood

nbhood_test.out: test/nbhood_test.o plansza.o rules.o neighborhood.o boardio.o
	$(CC) -o $@ $^ $(LFLAGS)

testnbh: nbhood_test.out
	./nbhood_test.out test/dane2
