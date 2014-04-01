#include "plansza.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

char *usage =
    "Opcje: %s -f plik -n gen_n [-s krok] [-o prefix]\n"
    "       plik -  sciezka do pliku, z danymi poczatkowymi\n"
    "       gen_n - liczba kolejnych generacji\n"
    "       krok -  co ile iteracji jest wykonywany zapis generacji\n"
    "               do pliku png (domyslnie 5)\n"
    "       prefix - napis, od ktorego beda zaczynaly sie nazwy\n"
    "               plikow png z zapisywanymi generacjami\n";

int
main(int argc, char **argv)
{
    int n, m;
    FILE *in = argc > 1 ? fopen(argv[1], "r") : NULL;

    if(in == NULL) {
        if(argc > 1)
            fprintf(stderr, "%s: problem z otwarciem pliku %s.\n", argv[0], argv[1]);
        else
            fprintf(stderr, "%s: prosze podac plik z danymi.\n", argv[0]);
        return 1;
    }

    fscanf(in, "%d %d", &n, &m);
    board_t *b = make_board(n, m);
    b = write_to_board(in);

    read_board(b, stdout);

    return 0;
}
