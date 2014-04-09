#ifndef _NEIGHBORHOOD_H_
#define _NEIGHBORHOOD_H_

#include "plansza.h"

typedef struct {
    // ????????
    int max;
    state_t* neighbors;
} neighborhood_t;

neighborhood_t* set_up_nbh();

neighborhood_t* neighbors(board_t* b, unsigned int x, unsigned int y);

#endif
