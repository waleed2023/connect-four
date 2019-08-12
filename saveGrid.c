// Copyright Waleed Rajab
#include "./saveGrid.h"
#include <stdio.h>
#include <string.h>
#include "vier_gewinnt.h"


/*
    function to save the Game coordinate 
    in a new data
*/
void saveGrid(wchar_t matrix[ZEILE][SPALTE], int mode) {
  wchar_t SHAPE1 = L'𐘾';
  wchar_t SHAPE2 = L'𐙝';
  FILE *write = fopen("save", "w");

  if (mode == 1) {
    // in case the Game in ai mode
    fprintf(write, "k");
  }
  if (mode == 2) {
    // in case the Game in player vs player mode
    fprintf(write, "s");
  }
  for (int i = 0; i < ZEILE; i++) {
    for (int j = 0; j < SPALTE; j++) {
      if (matrix[i][j] == SHAPE1) {
        // set 1 to know which game has to rock
        // and set the coordinate the matrix
        fprintf(write, "1%d%d", i, j);
      } else {
        if (matrix[i][j] == SHAPE2) {
          fprintf(write, "2%d%d", i, j);
        }
      }
    }
  }
  fclose(write);
  return;
}
