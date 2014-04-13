#include "file_reader.h"
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
