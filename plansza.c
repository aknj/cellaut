#include "plansza.h"

#include <string.h>

/* funkcja mallocujaca pamiec na zmienna typu board_t */
board_t*    make_board(int n, int m) {
    board_t *new_board = malloc(sizeof *new_board);
    if(new_board == NULL)
        return NULL;
    if((new_board->state = malloc((size_t)n * (size_t)m * sizeof *new_board->state)) == NULL) {
        free(new_board);
        return NULL;
    }
    new_board->n = n;
    new_board->m = m;
    memset(new_board->state, 0, (size_t)(n * (size_t)m * sizeof *new_board->state));
    return new_board;
}

/* wczytaj do planszy dane z pliku */
board_t*    write_to_board(FILE* stream) {
    int n, m;
    int i, j;
    board_t *new_board;
    if(fscanf(stream, "%d %d", &n, &m) != 2)
        return NULL;
    if((new_board = make_board(n, m)) == NULL)
        return NULL;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(fscanf(stream, "%d", &new_board->state[i * m + j]) != 1) {
                return NULL;
            }
    return new_board;
}

//void        set_cell(board_t* b, int x, int y, int state);

//int         get_cell(board_t* b, int x, int y);

/* przeczytaj dane z planszy b na strumien stream */
void        read_board(board_t* b, FILE* stream) {
    int i, j;
    if(b == NULL) {
        fprintf(stream, "Plansza jest pusta\n");
        return;
    }

    fprintf(stream, "%d %d\n", b->n, b->m);
    for(i = 0; i < b->n; i++) {
        for(j = 0; j < b->m; j++)
            fprintf(stream, " %d ", b->state[i * b->m + j]);
        fprintf(stream, "  \n", b->state[i * b->m + j]);
    }
}

