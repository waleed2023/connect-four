// Copyright Waleed Rajab

/*
    a Program to test the Game VIER GEWINNT_KI
    returns: 0
    Hints: i just left the print_matrix(matrix); Commented
    that you could it print and see how the Test Work !.
*/
#include "vier_gewinnt_ki.h"
#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include "vier_gewinnt.h"

int main() {
  wchar_t player;
  wchar_t pc;
  player = L'𐘾';
  pc = L'𐙝';
  // important for the Wchar_t convert !
  setlocale(LC_ALL, "en_US.UTF-8");

  // wchar_t matrix[ZEILE][SPALTE];

  //***************** Tests the Blocks from the PC Player *********************

  // make a new matrix
  make_matrix(matrix);
  drop(player, 1, matrix);
  drop(player, 1, matrix);
  Medium(matrix, pc);
  // check after two playing that the PC Player gonna block the other Player !
  assert(matrix[3][0] == pc);
  // print_matrix(matrix);

  // make a new matrix
  make_matrix(matrix);
  drop(player, 7, matrix);
  drop(player, 6, matrix);
  drop(player, 6, matrix);
  drop(player, 5, matrix);
  drop(player, 5, matrix);
  drop(player, 5, matrix);
  drop(player, 4, matrix);
  drop(player, 4, matrix);
  drop(player, 4, matrix);
  ai(matrix, player);
  // print_matrix(matrix);

  // Check PC Player gonna Block the other Player diagonal ( \ )
  assert(matrix[2][3] == pc);

  // make a new matrix
  make_matrix(matrix);
  drop(player, 4, matrix);
  drop(player, 5, matrix);
  drop(player, 5, matrix);
  drop(pc, 6, matrix);
  drop(pc, 6, matrix);
  drop(player, 6, matrix);
  drop(player, 7, matrix);
  drop(player, 7, matrix);
  drop(player, 7, matrix);
  ai(matrix, player);
  // Check PC Player gonna Block the other Player diagonal ( / )
  assert(matrix[2][6] == pc);
  // print_matrix(matrix);

  // make a new matrix
  make_matrix(matrix);
  drop(player, 1, matrix);
  drop(player, 1, matrix);
  drop(player, 1, matrix);
  ai(matrix, player);
  // Block the Player (vertical | )
  assert(matrix[2][0] == pc);
  // print_matrix(matrix);

  // make a new matrix
  make_matrix(matrix);
  drop(player, 7, matrix);
  drop(player, 6, matrix);
  drop(player, 5, matrix);
  ai(matrix, player);
  // check PC Player gonna block after three drops.
  // in the column 4 (horizontal  ------ )
  assert(matrix[5][3] == pc);
  // print_matrix(matrix);

  //***************** Tests How Smart the PC Player is *********************

  make_matrix(matrix);
  // check the PC Player has winning after four drops
  Medium(matrix, pc);
  Medium(matrix, pc);
  Medium(matrix, pc);
  Medium(matrix, pc);
  assert(win(pc, matrix) == 4);
  // print_matrix(matrix);

  // in this case the PC Player gonna try to drop the rocks diagonal (/)
  // to try to win
  make_matrix(matrix);
  drop(player, 2, matrix);
  drop(player, 3, matrix);
  Medium(matrix, pc);
  drop(pc, 2, matrix);
  drop(player, 4, matrix);
  drop(player, 4, matrix);
  drop(player, 4, matrix);
  drop(player, 3, matrix);
  Medium(matrix, pc);
  Medium(matrix, pc);
  assert(win(pc, matrix) == 4);
  // print_matrix(matrix);

  // in this case the PC Player try to drop the rocks (vertical | )
  // to try to win.
  make_matrix(matrix);
  drop(player, 7, matrix);
  drop(player, 7, matrix);
  drop(pc, 6, matrix);
  Medium(matrix, pc);
  Medium(matrix, pc);
  Medium(matrix, pc);
  Medium(matrix, pc);
  assert(win(pc, matrix) == 4);
  // print_matrix(matrix);

  // test the easy mode
  // drop random
  make_matrix(matrix);
  Easy(matrix);
  Easy(matrix);
  Easy(matrix);
  Easy(matrix);
  // print_matrix(matrix);
  assert(win(pc, matrix) != 4);

  // test for got smarter
  // gonna win after 4 drops horizontal
  make_matrix(matrix);
  i_got_smarter(matrix, pc);
  i_got_smarter(matrix, pc);
  i_got_smarter(matrix, pc);
  i_got_smarter(matrix, pc);
  assert(win(pc, matrix) == 4);
  // print_matrix(matrix);

  make_matrix(matrix);
  drop(player, 3, matrix);
  drop(player, 3, matrix);
  // her start the PC to make a diagonal
  // rocks
  i_got_smarter(matrix, pc);
  i_got_smarter(matrix, pc);
  i_got_smarter(matrix, pc);
  i_got_smarter(matrix, pc);
  // her build a way for PC
  // to win
  drop(player, 6, matrix);
  drop(player, 2, matrix);
  drop(player, 2, matrix);
  drop(player, 2, matrix);
  i_got_smarter(matrix, pc);
  assert(win(pc, matrix) == 4);
  // print_matrix(matrix);
}
