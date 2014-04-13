CC = gcc
CFLAGS = -DDEBUG -g -Wall -pedantic -std=c99
LFLAGS = -lgsl -lgslcblas -lm
NAME = life.out

$(NAME): main.o plansza.o rules.o textfile_reader.o textfile_writer.o
	$(CC) -o $@ $^ $(LFLAGS)

main.o: file_reader.h file_writer.h

plansza.o: plansza.h state.h

rules.o: rules.h state.h neighborhood.h neighborhood.o

# neighborhood.o: plansza.h

clean:
	rm -f *.o *.out

testm: $(NAME)
	./$< mat1

testm2: $(NAME)
	./$< mat2

test1: $(NAME)
	./$< dane1.board 16 2 test1

# testy samego neighborhood

nbhood_test.out: nbhood_test.o plansza.o rules.o neighborhood.o
	$(CC) -o $@ $^ $(LFLAGS)

testnbh: nbhood_test.out
	./nbhood_test.out dane2
