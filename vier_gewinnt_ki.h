// Copyright Waleed Rajab
// University Freiburg

#ifndef VIER_GEWINNT_KI_H_
#include <stdbool.h>
#include <stddef.h>
#include "vier_gewinnt.h"

#define VIER_GEWINNT_KI_H_

// a function to make a easy mode for the user.
// drop random
void Easy(wchar_t matrix[ZEILE][SPALTE]);
// a function to check the empty place.
int checkEmpty(wchar_t matrix[ZEILE][SPALTE], int num, int row);
/*
    this function gonna block the Player under some conditions
      as example ween the Player have to Rocks Vertival or Horizontal
        gonna block it and put the PC Shape.
         {Vertical, Horizontal, right, Left.}
 */
void Medium(wchar_t matrix[ZEILE][SPALTE], wchar_t character);
/*
    this function gonna make the PC player intellgent.
    its gonna study all places that they have the Portability to put
    the PC shape !
*/
void ai(wchar_t matrix[ZEILE][SPALTE], wchar_t character);

/*
    this function makes a smart steps
    like build the rocks diagonal
*/
void i_got_smarter(wchar_t matrix[ZEILE][SPALTE], wchar_t character);

#endif  // VIER_GEWINNT_KI_H_
