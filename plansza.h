#ifndef PLANSZA_H
#define PLANSZA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int n;
    int m;
    int* state;
} board_t;

board_t*    make_board(int n, int m);

board_t*    write_to_board(FILE* stream);

void        set_cell(board_t* b, int x, int y, int state);

int         get_cell(board_t* b, int x, int y);

void        read_board(board_t* b, FILE* stream);

#endif
