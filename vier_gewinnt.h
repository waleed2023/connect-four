// Copyright Waleed Rajab
// University Freiburg

#ifndef VIER_GEWINNT_H_
#include <stdbool.h>
#include <stddef.h>

#define VIER_GEWINNT_H_
#define SPALTE 7
#define ZEILE 6

// define a Matrix [6*7]
wchar_t matrix[ZEILE][SPALTE];

//  a function to make the matrix
void make_matrix(wchar_t matrix[ZEILE][SPALTE]);
//  a function to print the matrix
void print_matrix(wchar_t matrix[ZEILE][SPALTE]);
// a function to drop the elements in the matrix
int drop(wchar_t player, int spalte, wchar_t matrix[ZEILE][SPALTE]);
// a function to check if the player win.
// return 4 in case the Player has Winning
int win(wchar_t player, wchar_t matrix[ZEILE][SPALTE]);

#endif  // VIER_GEWINNT_H_
