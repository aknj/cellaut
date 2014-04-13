#include "file_writer.h"

void write_to_file(board_t* b, FILE* stream) {
    int i, j;
    if(b == NULL) {
        fprintf(stream, "Plansza jest pusta\n");
        return;
    }

    fprintf(stream, "%d %d\n", b->rn, b->cn);
    for(i = 0; i < b->rn; i++) {
        for(j = 0; j < b->cn; j++)
            fprintf(stream, " %d ", b->state[i * b->cn + j]);
        fprintf(stream, "  \n");
    }
}

