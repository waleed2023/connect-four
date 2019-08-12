// Copyright Waleed Rajab
// University Freiburg

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "readGrid.h"
#include "saveGrid.h"
#include "vier_gewinnt.h"
#include "vier_gewinnt_ki.h"
#include "vier_gewinnt_ki_main.h"
#include "vier_gewinnt_main.h"

int main(int argc, char *argv[]) {
  if (argc == 2) {
    int check = strcmp(argv[1], "--load");
    if (check == 0) {
      // load the game and continue it
      readGrid(matrix, 1);
      return 0;
    }
  }

  if (argc == 2) {
    int check = strcmp(argv[1], "--help");
    if (check == 0) {
      printf(
          "********************************************************************"
          "*********"
          "\n");
      printf("                    CONNECT FOUR              \n");
      printf("\n");
      printf("CONNECT-FOUR IS A TIC-TAC-TOE-LIKE TOW-PLAYER GAME\n");
      printf("IN WHICH PLAYERS ALTERNATELY PLACE CHECKERS ON A VERTICAL\n");
      printf("BOARD. THE PLAY BOARD IS 7 COLUMNS ACROSS AND 6 ROWS HIGH.\n");
      printf("EACH PLAYER PLAYS EACH TIME WITH A PARTICULAR ROCK\n");
      printf(
          "THE PLAYER HAS WINING WEEN HE GET FOUR ROCKS VERTICAL OR HORIZONTAL "
          "OR "
          "EVEN DIAGONAL\n\n");
      printf("TO PLAY SINGLE AGAINST THE PC PRESS ./4 --ai \n");
      printf("TO PLAY PLAYER AGAINST PLAYER PRESS ./4 \n");
      printf("TO SAVE THE GAME TIP save DURING THE GAME \n");
      printf("TO LOAD THE GAME TIP ./4 --load ");
      printf("\n");

      return 0;
    }
  }

  if (argc == 2) {
    int check = strcmp(argv[1], "--ai");
    if (check == 0) {
      // call the main-ai
      kiMain();
      return 0;
    }
  }
  // run the normal mode in case (player agains player) the user give
  // ./4
  vierGewinnt();
  return 0;
}
