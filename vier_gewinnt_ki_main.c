// Copyright Waleed Rajab
#include "vier_gewinnt_ki_main.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saveGrid.h"
#include "vier_gewinnt_ki.h"

/*
    function to run the Game in ai mode and to print it
*/
void kiMain() {
  wchar_t PLAYER = L'𐘾';
  wchar_t PC = L'𐙝';
  make_matrix(matrix);
  int column;
  // this veritable to change between Player and PC
  int check = 0;
  // for scanf
  char pl[7] = " ";
  char *endPointer;
  setlocale(LC_ALL, "en_US.UTF-8");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("*************  CONNECT FOUR  *************");
  printf("\n");
  printf("\n");
  printf("           YOU: 𐘾       PC: 𑀞            ");
  printf("\n");
  printf("\n");
  printf("******************************************");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");

  printf("YOU ARE PLAYER   : %lc \n\n", PLAYER);
  printf("THE PC PLAYER    : %lc\n\n", PC);
  printf("ENTER A NUMBER BETWEEN 1-7:  %lc \n", PLAYER);

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
  return;
}
