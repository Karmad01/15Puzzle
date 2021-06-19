//Header for user defined functions used

#ifndef __GAME_H
  #define __GAME_H
  #include <stdbool.h>

  //Fills the array randomly leaving the last value 0
  extern void arr_random_fill(int *arr);
  
  /*Checks if the game is solvable
    Returns true if solvable*/
  extern bool solvable(int *arr);

  /*Checks if the game is solved
    Returns true if solved*/
  extern bool solved(int *arr);  

  //Prints the array as a 4x4 grid
  extern void arr_print(int *arr, int c);
#endif  
//End of game.h