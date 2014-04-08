#ifndef _RULES_H_
#define _RULES_H_

#include "state.h"
#include "neighborhood.h"

int get_number_of_alive_neighbors(neighborhood_t* neighbors);

state_t get_next_state(state_t current_state, neighborhood_t* neighbors);

#endif
