// Copyright 2019 Waleed Rajab
#include "./readGrid.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "continue.h"
#include "ki_continue.h"
#include "vier_gewinnt.h"

/*
    function to read the save file and to continue the Game
*/
void readGrid(wchar_t matrix[ZEILE][SPALTE], int check) {
  wchar_t player;
  wchar_t pc;
  player = L'𐘾';
  pc = L'𐙝';
  // important for the Wchar_t convert !
  setlocale(LC_ALL, "en_US.UTF-8");
  // make the matrix
  make_matrix(matrix);
  int kind_of_game;
  int first;
  int second;
  int last;
  // open the file as read
  FILE *read = fopen("save", "r");
  if (!read) {
    return;
  }
  // to know the kind of the game
  kind_of_game = fgetc(read);
  while (true) {
    first = fgetc(read);
    // break if end of file
    if (first == EOF) break;
    // the row
    second = fgetc(read);
    // the column
    last = fgetc(read);
    // check if the first one is Player
    if (strcmp("1", &first) == 0) {
      // convert from char to intger
      matrix[(int)second - 48][(int)last - 48] = player;
    } else {
      // check if the first one is PC
      if (strcmp("2", &first) == 0) {
        matrix[(int)second - 48][(int)last - 48] = pc;
      }
    }
  }
  if (check)
  // print the matrix
  print_matrix(matrix);
  // start the game in case the mode of Game is
  // player vs player
  if (strcmp("s", &kind_of_game) == 0 && check) {
    printf("HELLO AGAIN\n");
    // continue in the mode (Player agains Player)
    continueM(matrix, first);
    return;
  }
  // start the game in case the mode of Game is
  // pc vs player
  if (strcmp("k", &kind_of_game) == 0 && check) {
    printf("HELLO AGAIN\n");
    printf("YOUR TURN %lc   ", player);
    // continue in mode (Pc agains Player)
    kiContinue(matrix);
    return;
  }
  fclose(read);
}
