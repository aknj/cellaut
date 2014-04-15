#ifndef _BOARDIO_H_
#define _BOARDIO_H_

#include "plansza.h"

board_t*    read_from_file(FILE* stream);

void        write_to_file(board_t* b, FILE* stream);

void        write_to_bmp(board_t* b, const char* filename);

#endif
