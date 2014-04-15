#include "boardio.h"
#include "automaton.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <bmpfile.h>
#include <string.h>

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
    char *base = argc > 4 ? argv[4] : "output/life";
    char filename[255];
    char *filenametemp = base;
    strcpy(filename, filenametemp);
    int basenamel = strlen(filename);
#ifdef DEBUG
    printf("basenamel = %d\n", basenamel);
#endif
    char basename[255];
    strcpy(basename, filename);

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
        if(i % step == 0) {
            //memcpy(filename, filename, basenamel);
            /* dodawanie numeru */
            filename[0] = '\0';
            strcat(filename, basename);
            strcat(filename, "_");          // dopisanie do filename znaku _
            char buf[20];
            sprintf(buf, "%d", i);          // zamiana i na const char*
            char* c = buf;
            strcat(filename, c);            // dopisanie do filename numeru generacji
            strcat(filename, ".bmp");       // dopisanie do filename .bmp

            write_to_bmp(b, filename);
        }
        prepare_next_states(b, backb); // to, co w momencie rozpoczecia tej funkcji jest na backb nas nie obchodzi
        swap_boards(&b, &backb);
    }

    printf("Stan planszy %d generacji pozniej:\n", n);
    write_to_file(b, stdout);

    return 0;
}


