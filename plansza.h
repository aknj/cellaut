#ifndef _PLANSZA_H_
#define _PLANSZA_H_

#include "state.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int rn;
    int cn;
    state_t* state;
} board_t;

board_t*    make_board(int rn, int cn);

board_t*    write_to_board(FILE* stream);

void        set_cell(board_t* b, int x, int y, state_t state);

state_t     get_cell(board_t* b, int x, int y);

void        read_board(board_t* b, FILE* stream);

#endif
