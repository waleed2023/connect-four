// Copyright Waleed Rajab
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "continue.h"
#include "saveGrid.h"
#include "vier_gewinnt.h"
#include "vier_gewinnt_ki.h"
#include "vier_gewinnt_ki_main.h"

// this function to make the function readGrid easier
// ween the player choosed the mode (player agains PC) must
// this function called .
// this function called to continue the game
// applies without test
void kiContinue(wchar_t matrix[ZEILE][SPALTE]) {
  wchar_t PLAYER = L'𐘾';
  wchar_t PC = L'𐙝';
  int column;
  // this veritable to change between Player and PC
  int check = 0;
  // for scanf
  char pl[7] = " ";
  char *endPointer;

  while (true) {
    if (check == 0) {
      scanf("%s", pl);
      int check2 = strcmp(pl, "save");
      if (check2 == 0) {
        saveGrid(matrix, 1);
        printf("SAVED IN save  \n");
        return;
      }
      printf("\n");
      // convert to number
      column = strtol(pl, &endPointer, 10);
      // check if the column between 1 - 7
      if (!(column >= 1 && column <= 7)) {
        printf("PLEASE ENTER A NUMBER BETWEEN 1-7:  \n");
        continue;
      }
      drop(PLAYER, column, matrix);
      check = 1;
    } else {
      printf("LAST DROP FOR YOU WAS IN  :  %d \n", column);
      Medium(matrix, PC);

      check = 0;
    }
    // print the Game
    print_matrix(matrix);
    // if the PLAYER win print the winner and exit
    if (win(PLAYER, matrix) == 4) {
      printf("\033[1;37m");
      printf("YOU ARE WINNER !!:   %lc\n", PLAYER);
      return;
    }
    if (win(PC, matrix) == 4) {
      printf("\033[1;37m");
      printf("THE PC PLAYER HAS WINNING !!:   %lc\n", PC);
      return;
    }
  }
}
