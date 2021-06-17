//Header file for commonly used functions in conio.h in Turbo C
//getch(), getche(), gotoxy()

#ifndef __CONIO_H
  #define __CONIO_H
  //Places cursor at specified coordinates
  extern void gotoxy(int col, int row);

  //Read 1 character without echo
  extern char getch(void);

  //Read 1 character with echo
  extern char getche(void);

  /*Read arrow keys predominantly
    Returns 'A' for up
    Returns 'B' for down
    Returns 'C' for right
    Returns 'D' for left
    Returns getch() for all other keys*/
    extern char getkey(void);
#endif        
//End of conio.h
