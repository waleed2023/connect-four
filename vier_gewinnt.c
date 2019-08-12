// Copyright Waleed Rajab
// University Freiburg

#include <stddef.h>
#include <stdio.h>
#include "vier_gewinnt.h"

/*
   sets Matrix to a ' '
*/

wchar_t c = ' ';
void make_matrix(wchar_t matrix[ZEILE][SPALTE]) {
  for (int i = 0; i < ZEILE; i++) {
    for (int j = 0; j < SPALTE; j++) {
      matrix[i][j] = c;
    }
  }
  return;
}

/*
    a function to drop the elements in the matrix
*/
int drop(wchar_t player, int spalte, wchar_t matrix[ZEILE][SPALTE]) {
  int row = ZEILE - 1;
  if (spalte > 7 || spalte == 0) {
    printf("CHOSE ANOTHER PLACE !!\n");
    printf("\n");
    return 0;
  }
  while (matrix[row][spalte - 1] != c) {
    if (row == 0) {
      printf("CHOSE ANOTHER PLACE !!\n");
      return 0;
    }
    row -= 1;
  }

  if (matrix[row][spalte - 1] == c) {
    matrix[row][spalte - 1] = player;
    if (win(player, matrix) == 4) {
      printf("\033[5;38m");
      return 0;
    } else {
      return 0;
    }
  }
  return 0;
}

/*
    a function to check if the player win
*/
int win(wchar_t player, wchar_t matrix[ZEILE][SPALTE]) {
  int count = 0;

  // check the right side right (waagerecht) *----> left, left *----> right.
  for (int i = 0; i < ZEILE; i++) {
    for (int j = 0; j < SPALTE - 3; j++) {
      if (matrix[i][j] == player) {
        if (matrix[i][j + 1] == player) {
          if (matrix[i][j + 2] == player) {
            if (matrix[i][j + 3] == player) {
              count += 4;
              return count;
            }
          }
        }
      }
    }
  }
  // check the column senkrecht up *----> down, down *----> up
  for (int i = 0; i < SPALTE; i++) {
    for (int j = 0; j < ZEILE - 3; j++) {
      if (matrix[j][i] == player) {
        if (matrix[j + 1][i] == player) {
          if (matrix[j + 2][i] == player) {
            if (matrix[j + 3][i] == player) {
              count += 4;
              return count;
            }
          }
        }
      }
    }
  }

  // check the column diagonal  (\)
  for (int i = 0; i < ZEILE - 3; i++) {
    for (int j = 0; j < SPALTE - 3; j++) {
      if (matrix[i][j] == player) {
        if (matrix[i + 1][j + 1] == player) {
          if (matrix[i + 2][j + 2] == player) {
            if (matrix[i + 3][j + 3] == player) {
              count += 4;
              return count;
            }
          }
        }
      }
    }
  }

  // check the column diagonal  (/)
  for (int i = 0; i < ZEILE - 3; i++) {
    for (int j = SPALTE - 4; j < SPALTE; j++) {
      if (matrix[i][j] == player) {
        if (matrix[i + 1][j - 1] == player) {
          if (matrix[i + 2][j - 2] == player) {
            if (matrix[i + 3][j - 3] == player) {
              count += 4;
              return count;
            }
          }
        }
      }
    }
  }

  return count;
}

/*
  a function to print the Grid
  returns:

           vier gewinnt
     [1] [2] [3] [4] [5] [6] [7]
  [1] 0   0   0   0   0   0   0
  [2] 0   0   0   0   0   0   0
  [3] 0   0   0   0   0   0   0
  [4] 0   0   0   0   0   0   0
  [5] 0   0   0   0   0   0   0
  [6] 0   0   0   0   0   0   0
*/
void print_matrix(wchar_t matrix[ZEILE][SPALTE]) {
  int i, j;
  printf("    ");
  printf("%s   ", "\n");
  printf("\033[1;31m");
  printf("\n");
  printf("                                  VIER GEWINNT\n");
  printf("\n");
  for (i = 1; i <= SPALTE; i++) {
    printf("        [%d] ", i);
  }
  printf("\n");
  for (j = 0; j < ZEILE; j++) {
    printf("\033[1;31m[%d]", j + 1);
    printf("\n");
    // change color and make illuminated
    printf("\033[4;37m");
    for (i = 0; i < SPALTE; i++) {
      printf("         %lc  ", matrix[j][i]);
      printf("\033[1;37m");
    }
    printf("\n");
    printf("\n");
  }
  printf("\033[0m");
  printf("\033[0m");
  return;
}
