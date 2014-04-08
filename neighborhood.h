#ifndef _NEIGHBORHOOD_H_
#define _NEIGHBORHOOD_H_

#include "plansza.h"

typedef struct {
    // ????????
    int i;
    int max;
    state_t* neighbors;
} neighborhood_t;

neighborhood_t* neighbors(unsigned int x, unsigned int y);

#endif
