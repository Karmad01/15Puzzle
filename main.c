/*Game consisting of 4x4 grid in which last cell is blank and others
contain numbers from 1 to 15 in a random order. Blank cell is moved
with arrow keys till the numbers are arranged in increasing order.*/
#include <stdio.h>
#include "include/conio.h" /*User defined library containing the functions,
                             getch(), getche() and gotoxy()*/
#include "include/game.h"  

int main(int argc, char const *argv[])
{
  int num[16] = {0}; //Stores the grid as a 1D array
  int count = 0; //Stores the number of moves
  int blank = 15;//Tracks where the blank (i.e., the 0) in num 
  int check = 1; //Checks if the game is solved (0 - solved, 1 - unsolved)
  int i; //Loop, swap variable
  char key; //Stores the value of pressed key
  arr_random_fill(num);
  arr_print(num, count);
  key = getkey();
  while (key == 'A' || key == 'B' || key == 'C' || key == 'D')
  {
    if (key == 'B')
    {
      if (blank <= 3)
      {
        printf("\nNo number above");
        key = getkey();
        continue;
      }
      else
      {
        i = num[blank - 4];
        num[blank - 4] = 0;
        num[blank] = i;
        blank = blank - 4;
      }
    }
    else if (key == 'C')
    {
      if (blank % 4 == 0)
      {
        printf("\nNo number to the left");
        key = getkey();
        continue;
      }
      else
      {
        i = num[blank - 1];
        num[blank - 1] = 0;
        num[blank] = i;
        blank = blank - 1;
      }
    }
    else if (key == 'D')
    {
      if (blank % 4 == 3)
      {
        printf("\nNo number to the right");
        key = getkey();
        continue;
      }
      else
      {
        i = num[blank + 1];
        num[blank + 1] = 0;
        num[blank] = i;
        blank = blank + 1;
      }
    }
    else
    {
      if (blank >= 12)
      {
        printf("\nNo number below");
        key = getkey();
        continue;
      }
      else
      {
        i = num[blank + 4];
        num[blank + 4] = 0;
        num[blank] = i;
        blank = blank + 4;
      }
    }
    count++;
    arr_print(num, count);
    check = 0;
    for (i = 0; i <= 14; i++)
    {
      if(num[i] != i + 1)
      {
        check = 1;
        break;
      }
    }
    if (check == 0)
    {
      printf("\nYou have completed the game in %d moves.\n", count);
      break;
    }
    else
    {
      key = getkey();
    }
  }
  if (check == 1)
  {
    printf("\nYou have exited the game without completing it.\n");
  }
  return 0;
}
//End of main.c