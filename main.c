#include "boardio.h"
#include "automaton.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <bmpfile.h>

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
    FILE *in = argc > 1 ? fopen(argv[1], "r") : NULL;
    int n = argc > 2 ? atoi(argv[2]) : 20;
    int step = argc > 3 ? atoi(argv[3]) : 1;
    int i;

    if(in == NULL) {
        if(argc > 1)
            fprintf(stderr, "%s: problem z otwarciem pliku %s.\n", argv[0], argv[1]);
        else
            fprintf(stderr, "%s: prosze podac plik z danymi.\n", argv[0]);
        return 1;
    }

    board_t *b = read_from_file(in);

    write_to_file(b, stdout);

    board_t *backb = prepare_backstage_board(b);
    for(i = 0; i < n; i++) {
        prepare_next_states(b, backb); // to, co w momencie rozpoczecia tej funkcji jest na backb nas nie obchodzi
        swap_boards(&b, &backb);
    }

    printf("Stan planszy %d generacji pozniej:\n", n);
    write_to_file(b, stdout);

    return 0;
}
