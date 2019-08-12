// Copyright 2019 Waleed Rajab
#include "continue.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saveGrid.h"
#include "vier_gewinnt.h"
#include "vier_gewinnt_main.h"

/*
this function to make the function readGrid easier
ween the player choosed the mode (player agains player) must
this function called to continue the game
 applies without test
*/
void continueM(wchar_t matrix[ZEILE][SPALTE], wchar_t ply) {
  wchar_t player1;
  wchar_t player2;
  int column;
  player1 = L'𐘾';
  player2 = L'𐙝';
  wchar_t player;
  char pl[7] = " ";
  char *endPointer;
  setlocale(LC_ALL, "en_US.UTF-8");
  // which player has to play
  if (ply == "1") {
    player = player1;
  } else {
    player = player2;
  }

  while (true) {
    printf("ENTER A NUMBER BETWEEN 1-7:  %lc \n", player);
    scanf("%s", pl);
    int check2 = strcmp(pl, "save");
    if (check2 == 0) {
      saveGrid(matrix, 2);
      printf("SAVED IN save  \n");
      return;
    }
    // convert the value
    column = strtol(pl, &endPointer, 10);
    printf("LAST DROP FOR THE PLAYER %lc   WAS IN:  %d \n", player, column);
    // check if the column between 1 - 7
    if (!(column >= 1 && column <= 7)) {
      printf("PLEASE ENTER A NUMBER BETWEEN 1-7:  \n");
      continue;
    }
    drop(player, column, matrix);
    print_matrix(matrix);
    // if the player win print the winner and exit
    if (win(player, matrix) == 4) {
      printf("\033[1;37m");
      printf("YOU ARE WINNER:   %lc\n", player);
      break;
    }
    // change from player1 to player2 or opposite.
    if (player == player1) {
      player = player2;
    } else {
      player = player1;
    }
  }
  return;
}
