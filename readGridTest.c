// Copyright 2019 Waleed Rajab
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "./readGrid.h"
#include "./saveGrid.h"
#include "vier_gewinnt.h"
int main() {
  wchar_t x = L'𐘾';
  wchar_t y = L'𐙝';
  setlocale(LC_ALL, "en_US.UTF-8");

  make_matrix(matrix);

  matrix[1][1] = x;
  matrix[1][3] = y;
  matrix[2][2] = y;
  matrix[3][1] = x;
  // the result
  saveGrid(matrix, 1);
  // i gust maked 0 because i don't want
  // to continue the game
  readGrid(matrix, 0);
  // check if all value sets
  assert(matrix[1][1] == x);
  assert(matrix[1][3] == y);
  assert(matrix[2][2] == y);
  assert(matrix[3][1] == x);
}
