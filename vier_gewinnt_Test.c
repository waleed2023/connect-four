// Copyright Waleed Rajab
// University Freiburg

/*
    a Program to test the Game VIER GEWINNT
    returns: 0
*/
#include "vier_gewinnt.h"
#include <assert.h>
#include <stdio.h>
#include <wchar.h>

int main() {
  wchar_t x = 'x';
  wchar_t y = 'y';
  wchar_t c = ' ';

  make_matrix(matrix);
  int matrix_items = 0;

  for (int i = 0; i < ZEILE; i++) {
    for (int j = 0; j < SPALTE; j++) {
      matrix_items += 1;
      // check the matrix if it has the correctly value.
      assert(matrix[i][j] == c);
    }
  }

  // check if the matrix has 42 items
  assert(matrix_items == 42);
  drop(x, 1, matrix);
  drop(y, 2, matrix);
  drop(x, 3, matrix);
  drop(y, 4, matrix);
  drop(x, 5, matrix);
  drop(y, 6, matrix);
  drop(x, 7, matrix);
  // more items for test column if has full.
  drop(y, 7, matrix);
  drop(x, 7, matrix);
  drop(y, 7, matrix);
  drop(x, 7, matrix);
  drop(y, 7, matrix);
  drop(x, 7, matrix);
  // check if the column add no more items
  //  ween its full.
  assert(matrix[0][6] == y);

  // check the first row drop the items.
  for (int i = 0; i <= 5; i++) {
    assert(matrix[5][i] == x);
    i += 1;
    assert(matrix[5][i] == y);
  }
  drop(y, 1, matrix);
  drop(y, 1, matrix);
  drop(y, 1, matrix);
  // check if the player has not win.
  assert(win(y, matrix) != 4);
  assert(win(x, matrix) != 4);

  drop(y, 1, matrix);
  // check if the player has win (senkrecht).
  assert(win(y, matrix) == 4);

  // make new game
  make_matrix(matrix);
  drop(y, 1, matrix);
  drop(x, 2, matrix);
  drop(y, 2, matrix);
  drop(y, 3, matrix);
  drop(x, 3, matrix);
  drop(y, 3, matrix);
  drop(y, 4, matrix);
  drop(x, 4, matrix);
  drop(x, 4, matrix);
  assert(win(x, matrix) != 4);
  assert(win(y, matrix) != 4);
  drop(y, 4, matrix);
  // check if the player has win diagonal (/)
  assert(win(y, matrix) == 4);

  make_matrix(matrix);
  drop(y, 1, matrix);
  drop(y, 1, matrix);
  drop(y, 1, matrix);
  drop(x, 1, matrix);
  drop(y, 2, matrix);
  drop(y, 2, matrix);
  drop(x, 2, matrix);
  drop(y, 3, matrix);
  drop(x, 3, matrix);
  assert(win(x, matrix) != 4);
  assert(win(y, matrix) != 4);
  drop(x, 4, matrix);
  // check if the player has win diagonal (\)
  assert(win(x, matrix) == 4);

  // make new game
  make_matrix(matrix);
  drop(y, 1, matrix);
  drop(y, 2, matrix);
  drop(y, 3, matrix);
  assert(win(y, matrix) != 4);
  drop(y, 4, matrix);
  // check if the player has win (waagerecht).
  assert(win(y, matrix) == 4);
}
