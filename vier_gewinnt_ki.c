// Copyright Waleed Rajab

/*
                                *************************************************
                                This Game created to simulation a normal Pepole
                                  the functions are not to Perfect to defat a
                                  smart one.
                                 All you Have to do is run the Makefile and its*
                                 gonna show you the Game.
                                 I could not Commenting all the Program because
                                   its gonna be so long.
                                 I tried to explain them in the Test how they
                                  work!

                                *************************************************

*/
#include "vier_gewinnt_ki.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vier_gewinnt.h"
wchar_t PLAYER = L'𐘾';
wchar_t PC = L'𐙝';

/*
    this function gonna block the Player under some conditions
      as example ween the Player have to the Rocks ertival or Horizontal
         so gonna block them and put the PC rock.
         {Vertical, Horizontal, right, Left.}

 */
void ai(wchar_t matrix[ZEILE][SPALTE], wchar_t character) {
  int i, j;
  wchar_t xc = ' ';

  for (i = ZEILE - 1; i >= 2; i--) {
    for (j = 0; j < SPALTE; j++) {
      if (matrix[i][j] == character && matrix[i - 1][j] == character &&
          matrix[i - 2][j] == character && matrix[i - 3][j] == xc) {
        matrix[i - 3][j] = PC;
        printf("IM GONNA BLOCK YOOOOU !!!");
        return;
      }
    }
  }
  for (i = 0; i < ZEILE; i++) {
    for (j = 0; j < (SPALTE - 2); j++) {
      if (matrix[i][j] == character && matrix[i][j + 1] == character &&
          checkEmpty(matrix, j + 2, i)) {
        printf("IM GONNA BLOCK YOOOOU !!!");
        matrix[i][j + 2] = PC;
        return;
      }
      if (matrix[i][j + 1] == character && matrix[i][j + 2] == character &&
          checkEmpty(matrix, j, i)) {
        printf("IM GONNA BLOCK YOOOOU !!!");
        matrix[i][j] = PC;
        return;
      }
    }
  }
  for (i = ZEILE - 1; i >= 2; i--) {
    for (j = 0; j < (SPALTE - 2); j++) {
      if (matrix[i][j] == character && matrix[i - 1][j + 1] == character &&
          checkEmpty(matrix, j + 2, i - 2)) {
        printf("IM GONNA BLOCK YOOOOU !!!!");
        matrix[i - 2][j + 2] = PC;
        return;
      }
      if (matrix[i - 1][j + 1] == character &&
          matrix[i - 2][j + 2] == character && checkEmpty(matrix, j, i)) {
        printf("IM GONNA BLOCK YOOOOU !!!!");
        matrix[i][j] = PC;
        return;
      }
    }
  }
  for (i = ZEILE - 1; i >= 2; i--) {
    for (j = SPALTE - 1; j >= 2; j--) {
      if (matrix[i][j] == character && matrix[i - 1][j - 1] == character &&
          checkEmpty(matrix, j - 2, i - 2)) {
        printf("IM GONNA BLOCK YOOOOU !!!!");
        matrix[i - 2][j - 2] = PC;

        return;
      }
      if (matrix[i - 1][j - 1] == character &&
          matrix[i - 2][j - 2] == character && checkEmpty(matrix, j, i)) {
        printf("IM GONNA BLOCK YOOOOU !!!!");
        matrix[i][j] = PC;
        return;
      }
    }
  }

  // check if they are tow Pice or three or even four to put
  for (i = ZEILE - 1; i >= 3; i--) {
    for (j = 0; j < SPALTE; j++) {
      if (matrix[i][j] == character && matrix[i - 1][j] == character &&
          matrix[i - 2][j] == xc && matrix[i - 3][j] == xc &&
          matrix[i - 4][j] == xc) {
        printf("IM GONNA BLOCK YOOOOU !!!!");
        matrix[i - 2][j] = PC;
        return;
        if (matrix[i][j] == character && matrix[i - 1][j] == character &&
            matrix[i - 2][j] == PLAYER && matrix[i - 3][j] == PLAYER &&
            matrix[i - 4][j] == xc) {
          printf("IM GONNA BLOCK YOOOOU !!");
          matrix[i - 4][j] = PC;
          return;
          if (matrix[i][j] == character && matrix[i - 1][j] == character &&
              matrix[i - 2][j] == character && matrix[i - 3][j] == xc &&
              matrix[i - 4][j] == xc) {
            printf("IM GONNA BLOCK YOOOOU !!!!");
            matrix[i - 3][j] = PC;
            return;
          }
        }
      }
    }
  }
  // ween they are nothing to block go and
  // play some smart steps
  i_got_smarter(matrix, character);
}

/*
    this function make a so smart moves
    as example try to build a diagonal rocks
    the character take in this case the PC rock
*/
void i_got_smarter(wchar_t matrix[ZEILE][SPALTE], wchar_t character) {
  int i, j;
  wchar_t xc = ' ';
  for (i = 0; i < ZEILE; i++) {
    for (j = 0; j < (SPALTE - 3); j++) {
      if (matrix[i][j] == character && matrix[i][j + 1] == character &&
          matrix[i][j + 3] == xc && checkEmpty(matrix, j + 2, i)) {
        matrix[i][j + 2] = PC;
        printf("I GOT SMARTER !");

        return;
      }
    }
    if (matrix[i][j + 1] == character && matrix[i][j + 2] == character &&
        checkEmpty(matrix, j, i)) {
      printf("I GOT SMARTER !");
      matrix[i][j] = PC;
      return;
    }
    if (matrix[i][j] == character && matrix[i][j + 2] == character &&
        checkEmpty(matrix, j, i)) {
      printf("I GOT SMARTER !");
      matrix[i][j + 1] = PC;
      return;
    }
    if (matrix[i][j] == character && matrix[i][j + 1] == character &&
        checkEmpty(matrix, j + 2, i)) {
      printf("I GOT SMARTER !");
      matrix[i][j + 2] = PC;
      return;
    }
  }

  for (i = ZEILE - 1; i >= 3; i--) {
    for (j = 0; j < (SPALTE - 3); j++) {
      if (matrix[i][j] == character && matrix[i - 1][j + 1] == character &&
          checkEmpty(matrix, j + 2, i - 2)) {
        printf("I GOT SMARTER !");
        matrix[i - 2][j + 2] = PC;
        return;
      }
      if (matrix[i - 1][j + 1] == character &&
          matrix[i - 2][j + 2] == character && checkEmpty(matrix, j, i)) {
        printf("I GOT SMARTER !");
        matrix[i][j] = PC;
        return;
      }
      if (matrix[i][j] == character && matrix[i - 2][j + 2] == character &&
          checkEmpty(matrix, j + 1, i - 1)) {
        printf("I GOT SMARTER !");
        matrix[i - 1][j + 1] = PC;
        return;
      }
      if (matrix[i][j] == character && matrix[i - 1][j + 1] == character &&
          checkEmpty(matrix, j + 2, i - 2)) {
        printf("I GOT SMARTER !");
        matrix[i - 2][j + 2] = PC;
        return;
      }
    }
  }
  for (i = ZEILE - 1; i >= 3; i--) {
    for (j = SPALTE - 1; j >= 3; j--) {
      if (matrix[i][j] == character && matrix[i - 1][j - 1] == character &&
          checkEmpty(matrix, j - 2, i - 2)) {
        printf("I GOT SMARTER !");
        matrix[i - 2][j - 2] = PC;
        return;
      }
      if (matrix[i - 1][j - 1] == character &&
          matrix[i - 2][j - 2] == character && checkEmpty(matrix, j, i)) {
        printf("I GOT SMARTER !");
        matrix[i][j] = PC;
        return;
      }
      if (matrix[i][j] == character && matrix[i - 2][j - 2] == character &&
          checkEmpty(matrix, j - 1, i - 1)) {
        printf("I GOT SMARTER !");
        matrix[i - 1][j - 1] = PC;
        return;
      }

      if (matrix[i][j] == character && matrix[i - 1][j - 1] == character &&
          checkEmpty(matrix, j - 2, i - 2)) {
        printf("I GOT SMARTER !");
        matrix[i - 2][j - 2] = PC;
        return;
      }
    }
  }

  // make the Rocks diagonal  (/)
  for (i = ZEILE - 1; i >= 3; i--) {
    for (j = SPALTE - 1; j >= 3; j--) {
      if (matrix[i][j] == character && matrix[i - 1][j - 1] == xc &&
          checkEmpty(matrix, j - 3, i - 3)) {
        printf("I GOT SMARTER !");
        matrix[i - 3][j - 3] = PC;
        return;
      }
      // make the Rocks diagonal  (/)
      if (matrix[i - 1][j - 1] == character && matrix[i - 2][j - 2] == xc &&
          matrix[i - 3][j - 3] == xc && checkEmpty(matrix, j, i)) {
        printf(" THE NEW ONE 2!!!!   ");
        matrix[i][j] = PC;
        return;
      }
      // make the Rocks diagonal  (/)
      if (matrix[i][j] == character && matrix[i - 2][j - 2] == xc &&
          checkEmpty(matrix, j - 1, i - 1)) {
        printf("I GOT SMARTER !");
        matrix[i - 1][j - 1] = PC;
        return;
      }
      // make the Rocks diagonal  (/)
      if (matrix[i][j] == character && matrix[i - 1][j - 1] == xc &&
          checkEmpty(matrix, j - 2, i - 2)) {
        printf("I GOT SMARTER !");
        matrix[i - 2][j - 2] = PC;
        return;
      }
      // make the Rocks diagonal  (/)
      if (matrix[i][j] == character && matrix[i - 1][j - 1] == xc &&
          checkEmpty(matrix, j - 3, i - 3)) {
        printf("I GOT SMARTER !");
        matrix[i - 3][j - 3] = PC;
        return;
      }
    }
  }
  // ween the PC has nothing to Play
  // go the Function an
  Easy(matrix);
}

// a function to make a easy mode for the user.
// drop random
void Easy(wchar_t matrix[ZEILE][SPALTE]) {
  wchar_t xc = ' ';
  int i, j, flag, l;
  printf("IM TOO EASY NOW !!");
  l = rand() % SPALTE;
  for (i = (ZEILE - 1); i >= 0; i--) {
    if (matrix[i][l] == xc) {
      matrix[i][l] = PC;
      return;
    }
    flag = 0;
    while (i == 0 && matrix[i][l] != xc) {
      l = rand() % SPALTE;
      flag = 1;
    }
    for (j = (ZEILE - 1); flag == 1; j--) {
      if (matrix[j][l] == xc) {
        matrix[j][l] = PC;
        return;
      }
    }
  }
}
// a function to check if the place is a empty place !
int checkEmpty(wchar_t matrix[ZEILE][SPALTE], int num, int row) {
  // empty place
  wchar_t xc = ' ';
  if (row == (ZEILE - 1) && matrix[row][num] == xc) {
    return 1;
  } else if (matrix[row + 1][num] != xc && matrix[row][num] == xc) {
    return 1;
  }
  return 0;
}

/*
    this function gonna make the PC player intellgent.
    its gonna study all places that they have the Portability to put
    the PC shape !
*/
void Medium(wchar_t matrix[ZEILE][SPALTE], wchar_t character) {
  int i, j;
  wchar_t xc = ' ';
  // check senkrecht
  for (i = ZEILE - 1; i >= 3; i--) {
    for (j = 0; j < SPALTE; j++) {
      if (matrix[i][j] == character && matrix[i - 1][j] == character &&
          matrix[i - 2][j] == character && matrix[i - 3][j] == xc) {
        // put it in the empty place
        matrix[i - 3][j] = PC;
        printf(" YOU GONNA LOSE  !!!!   ");
        return;
      }
    }
  }
  // check on the sids
  for (i = 0; i < ZEILE; i++) {
    for (j = 0; j < (SPALTE - 3); j++) {
      if (matrix[i][j] == character && matrix[i][j + 1] == character &&
          matrix[i][j + 2] == character && checkEmpty(matrix, j + 3, i)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        // put it in the empty place
        matrix[i][j + 3] = PC;
        return;
      }
      if (matrix[i][j + 1] == character && matrix[i][j + 2] == character &&
          matrix[i][j + 3] == character && checkEmpty(matrix, j, i)) {
        // put it in the empty place
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i][j] = PC;
        return;
      }
      if (matrix[i][j] == character && matrix[i][j + 2] == character &&
          matrix[i][j + 3] == character && checkEmpty(matrix, j + 1, i)) {
        matrix[i][j + 1] = PC;
        printf(" YOU GONNA LOSE  !!!!   ");
        return;
      }
      if (matrix[i][j] == character && matrix[i][j + 1] == character &&
          matrix[i][j + 3] == character && checkEmpty(matrix, j + 2, i)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i][j + 2] = PC;
        return;
      }
    }
  }
  for (i = ZEILE - 1; i >= 3; i--) {
    for (j = 0; j < (SPALTE - 3); j++) {
      if (matrix[i][j] == character && matrix[i - 1][j + 1] == character &&
          matrix[i - 2][j + 2] == character &&
          checkEmpty(matrix, j + 3, i - 3)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i - 3][j + 3] = PC;
        return;
      }
      if (matrix[i - 1][j + 1] == character &&
          matrix[i - 2][j + 2] == character &&
          matrix[i - 3][j + 3] == character && checkEmpty(matrix, j, i)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i][j] = PC;
        return;
      }
      if (matrix[i][j] == character && matrix[i - 2][j + 2] == character &&
          matrix[i - 3][j + 3] == character &&
          checkEmpty(matrix, j + 1, i - 1)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i - 1][j + 1] = PC;
        return;
      }
      if (matrix[i][j] == character && matrix[i - 1][j + 1] == character &&
          matrix[i - 3][j + 3] == character &&
          checkEmpty(matrix, j + 2, i - 2)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i - 2][j + 2] = PC;
        return;
      }
    }
  }
  for (i = ZEILE - 1; i >= 3; i--) {
    for (j = SPALTE - 1; j >= 3; j--) {
      if (matrix[i][j] == character && matrix[i - 1][j - 1] == character &&
          matrix[i - 2][j - 2] == character &&
          checkEmpty(matrix, j - 3, i - 3)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i - 3][j - 3] = PC;
        return;
      }
      if (matrix[i - 1][j - 1] == character &&
          matrix[i - 2][j - 2] == character &&
          matrix[i - 3][j - 3] == character && checkEmpty(matrix, j, i)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i][j] = PC;
        return;
      }
      if (matrix[i][j] == character && matrix[i - 2][j - 2] == character &&
          matrix[i - 3][j - 3] == character &&
          checkEmpty(matrix, j - 1, i - 1)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i - 1][j - 1] = PC;
        return;
      }

      if (matrix[i][j] == character && matrix[i - 1][j - 1] == character &&
          matrix[i - 3][j - 3] == character &&
          checkEmpty(matrix, j - 2, i - 2)) {
        printf(" YOU GONNA LOSE  !!!!   ");
        matrix[i - 2][j - 2] = PC;
        return;
      }
    }
  }
  // ween the PC has nothing to Play it
  // go to ai and chose a place to Block the Player
  ai(matrix, PLAYER);
}
