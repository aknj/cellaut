#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include "neighborhood.h"
#include "rules.h"

board_t*    prepare_backstage_board(board_t* init_b);

void        prepare_next_states(board_t* b, board_t* bback);

void        swap_boards(board_t** b, board_t** bback);

#endif
