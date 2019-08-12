// Copyright Waleed Rajab
// University Freiburg

/*
    a Program to test the Game VIER GEWINNT
    returns: 0
*/
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "./saveGrid.h"
#include "vier_gewinnt.h"

int main() {
  wchar_t x = L'𐘾';
  wchar_t y = L'𐙝';
  int kind_of_game;
  int first;
  int second;
  int last;
  int array[50];
  setlocale(LC_ALL, "en_US.UTF-8");

  make_matrix(matrix);

  matrix[1][1] = x;
  matrix[1][3] = y;
  matrix[2][2] = y;
  matrix[3][1] = x;
  // the result
  int myArray[] = {1, 1, 1, 2, 1, 3, 2, 2, 2, 1, 3, 1};
  saveGrid(matrix, 1);

  FILE *read = fopen("save", "r");
  // check that the saveGrid make a file
  assert(read);
  if (!read) {
    return 0;
  }
  kind_of_game = fgetc(read);
  int count = 0;
  while (true) {
    first = fgetc(read);
    // break if end of file
    if (first == EOF) break;
    array[count] += first;
    count += 1;
    // the row
    second = fgetc(read);
    array[count] += second;
    count += 1;
    // the column
    last = fgetc(read);
    array[count] += last;
    count += 1;
  }
  // check kind of the Game
  assert(strcmp(&kind_of_game, "k") == 0);
  for (int i = 0; i < count - 3; i++) {
    // check if all the items are correctly
    // -48 to convert the value to int
    assert(((int)array[i] - 48) == myArray[i]);
  }
}
