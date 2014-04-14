#include "boardio.h"
#include "plansza.h"

board_t* read_from_file(FILE* stream) {
    int rn, cn;
    int i, j;
    int temp;
    board_t *new_board;
    if(fscanf(stream, "%d %d", &rn, &cn) != 2)
        return NULL;
    if((new_board = make_board(rn, cn)) == NULL)
        return NULL;
    for(i = 0; i < rn; i++)
        for(j = 0; j < cn; j++) {
            if(fscanf(stream, "%d", &temp) != 1) {
                free_board(new_board);
                return NULL;
            }
            new_board->state[i * cn + j] = temp;
        }
    return new_board;
}

void write_to_file(board_t* b, FILE* stream) {
    int i, j;
    if(b == NULL) {
        fprintf(stream, "Plansza jest pusta\n");
        return;
    }

    fprintf(stream, "%d %d\n", b->rn, b->cn);
    for(i = 0; i < b->rn; i++) {
        for(j = 0; j < b->cn; j++)
            fprintf(stream, " %d", b->state[i * b->cn + j]);
        fprintf(stream, "  \n");
    }
}

