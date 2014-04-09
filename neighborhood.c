#include "neighborhood.h"

neighborhood_t* set_up_nbh() {
    neighborhood_t *n = malloc(sizeof *n);
    n->neighbors = malloc((size_t)n->max * sizeof *n->neighbors);
    n->max = 4;
    return n;
}

/* funkcja wsadzajaca do struktury neighborhood_t kolejnych sasiadow (dla danej komorki)
 * (idziemy zgodnie z kierunkiem wskazowek zegara)
 **/
neighborhood_t* neighbors(board_t* b, unsigned int x, unsigned int y) {
    neighborhood_t *n = set_up_nbh();
    // pierwszy sasiad (gora)
    n->neighbors[0] = get_cell(b, x-1, y);
    // prawy
    n->neighbors[1] = get_cell(b, x, y+1);
    // dol
    n->neighbors[2] = get_cell(b, x+1, y);
    // lewy
    n->neighbors[3] = get_cell(b, x, y-1);

    return n;
}
