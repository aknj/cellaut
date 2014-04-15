CC = gcc
LDIR = /home/user/lib
CFLAGS = -DDEBUG -g -Wall -pedantic -std=c99 -I$(LDIR)/include
LFLAGS = -L$(LDIR)/lib -lbmp -lm
NAME = life.out
NBHOOD_TYPE = 

$(NAME): main.o plansza.o rules.o boardio.o automaton.o $(NBHOOD_TYPE)neighborhood.o
	$(CC) -o $@ $^ $(LFLAGS)

main.o: boardio.h automaton.h

plansza.o: plansza.h state.h

rules.o: rules.h state.h neighborhood.h

# neighborhood.o: plansza.h

.PHONY: clean cleanbmps testnbh

clean:
	rm -f *.o test/*.o *.out

cleanbmps:
	rm -f *.bmp

#testm: $(NAME)
#	./$< mat1

#testm2: $(NAME)
#	./$< mat2

test1: $(NAME)
	./$< test/diehard 20 1 output/diehard

# testy samego neighborhood

nbhood_test.out: test/nbhood_test.o plansza.o rules.o neighborhood.o boardio.o
	$(CC) -o $@ $^ $(LFLAGS)

testnbh: nbhood_test.out
	./nbhood_test.out test/dane2
