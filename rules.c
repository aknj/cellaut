#include "rules.h"

int get_number_of_alive_neighbors(neighborhood_t* nbh) {
    /* najpierw trzeba sie dowiedziec, jak wyglada neighborhood_t */
    int i;
    int sum = 0;
    for(i = 0; i < nbh->max; i++)
        if(nbh->neighbors[i] == ALIVE)
            sum++;
    return sum;
}

state_t get_next_state(state_t current_state, neighborhood_t* neighbors) {
    int sum = get_number_of_alive_neighbors(neighbors);
    
    if(current_state == DEAD) {
        if(sum == 3)
            return ALIVE;
        else
            return DEAD;
    }
    else if(current_state == ALIVE) {
        if(sum == 2 || sum == 3)
            return ALIVE;
        else
            return DEAD;
    }
    //else
        /* this situation is interesting from a philosophical point of view */
}
