/*Game consisting of 4x4 grid in which last cell is blank and others
contain numbers from 1 to 15 in a random order. Blank cell is moved
with arrow keys till the numbers are arranged in increasing order.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for time()
#include <stdbool.h>
#include "include/conio.h" /*User defined library containing the functions,
                             getch(), getche() and gotoxy()*/
#include "include/game.h"                             

void arr_random_fill(int *arr)
{
  int n[15], i, index, upper, lower, j;
  lower = 0;
  upper = 14;
  for (i = 0; i < 15; i++)
  {
    n[i] = i + 1;
  }
  srand((unsigned)time(0)); //system time acts as a seed for the PRNG
  for (i = 0; i < 15; i++)
  {
    index = (rand() % (upper - lower + 1)) + lower;
    *arr = n[index];
    for (j = index; j < upper; j++)
    {
      n[j] = n[j + 1];
    }
    arr++;
    upper--;
  }
}                             

bool solvable(int *arr)
{
  int inv_count = 0;
  bool retval = false;
  for (int i = 0; i < 14; i++)
  {
    for (int j = i + 1; j < 15; j++)
    {
      if (arr[i] > arr[j]) //count pairs (a, b) such that a appears before b, but a > b, not counting the blank.
      {
        inv_count++;
      }
    }
  }
  if (inv_count % 2 == 0) //Blank is on the last row which is an odd row. Hence if inv_count is even, it is solvable.
  {
    retval = true;
  }
  return retval;
}

void arr_print(int *arr, int c)
{
  system("clear");
  int i, col, row;
  gotoxy(20, 0);
  printf("Number Game");
  for (i = 0; i <= 15; i++)
  {
    col = ((i % 4) + 1) * 10;
    if(i <= 3)
    row = 0;
    else if(i > 3 && i <= 7)
    row = 5;
    else if(i > 7 && i <= 11)
    row = 10;
    else if(i > 11 && i <= 15)
    row = 15;
    gotoxy(col, row + 5);
    if(*arr == 0)
      printf(" ");
    else
      printf("%d", *arr);     
    arr++;  
  }
  printf("\nUsing the arrow keys move the numbers around the blank to arrange the number in increasing order.\n");
  printf("Press any other key to exit the game.\n");
  printf("Number of moves = %d.", c);
}
//End of game.c