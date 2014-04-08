#include "plansza.h"
#include "state.h"

#include <string.h>

/* funkcja mallocujaca pamiec na zmienna typu board_t */
board_t*    make_board(int rn, int cn) {
    board_t *new_board = malloc(sizeof *new_board);
    if(new_board == NULL)
        return NULL;
    if((new_board->state = malloc((size_t)rn * (size_t)cn * sizeof *new_board->state)) == NULL) {
        free(new_board);
        return NULL;
    }
    new_board->rn = rn;
    new_board->cn = cn;
    memset(new_board->state, 0, (size_t)(rn * (size_t)cn * sizeof *new_board->state));
    return new_board;
}

void free_board(board_t* b) {
    free(b->state);
    free(b);
}

/* wczytaj do planszy dane z pliku */
board_t*    write_to_board(FILE* stream) {
    int rn, cn;
    int i, j;
    board_t *new_board;
    if(fscanf(stream, "%d %d", &rn, &cn) != 2)
        return NULL;
    if((new_board = make_board(rn, cn)) == NULL)
        return NULL;
    for(i = 0; i < rn; i++)
        for(j = 0; j < cn; j++)
            if(fscanf(stream, "%c", &new_board->state[i * cn + j]) != 1) {
                free_board(new_board);
                return NULL;
            }
    return new_board;
}

void        set_cell(board_t* b, int x, int y, state_t state) {
    if(x >= 0 && x <= b->rn && y >= 0 && y <= b->cn)
        b->state[x * b->cn + y] = state;
}

state_t     get_cell(board_t* b, int x, int y) {
    if(x >= 0 && x <= b->rn && y >= 0 && y <= b->cn)
        return b->state[x * b->cn + y];
    else
        return 0;                                // co ma sie dziac z obszarem poza brzegami?
}

/* przeczytaj dane z planszy b na strumien stream */
void        read_board(board_t* b, FILE* stream) {
    int i, j;
    if(b == NULL) {
        fprintf(stream, "Plansza jest pusta\n");
        return;
    }

    fprintf(stream, "%d %d\n", b->rn, b->cn);
    for(i = 0; i < b->rn; i++) {
        for(j = 0; j < b->cn; j++)
            fprintf(stream, " %c ", b->state[i * b->cn + j]);
        fprintf(stream, "  \n");
    }
}

