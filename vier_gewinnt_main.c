// Copyright 2019 Waleed Rajab

#include "vier_gewinnt_main.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saveGrid.h"
#include "vier_gewinnt.h"

void vierGewinnt() {
  wchar_t matrix[ZEILE][SPALTE];
  wchar_t player1;
  wchar_t player2;
  int column;
  player1 = L'𐘾';
  player2 = L'𐙝';
  char pl[7] = " ";
  char *endPointer;
  int player;
  setlocale(LC_ALL, "en_US.UTF-8");
  while (player != 1 && player != 2) {
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("*************  CHIOS A ROCK  *************");
    printf("\n");
    printf("\n");
    printf("             1: 𐘾       2: 𑀞             ");
    printf("\n");
    printf("\n");
    printf("******************************************");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    scanf("%s", pl);
    // convert to intger
    player = strtol(pl, &endPointer, 3);
  }
  printf("YOU ARE PLAYER  : %d \n", player);
  // assign the player which character
  if (player == 1) {
    player = player1;
  } else {
    player = player2;
  }
  make_matrix(matrix);
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
