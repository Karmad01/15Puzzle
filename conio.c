//Code for commonly used function in conio.h in Turbo C
//getch(), getche(), gotoxy()
#include <stdio.h>
#include <termios.h>
#include "include/conio.h"

static struct termios old, new;

void gotoxy(int col, int row)
{
  printf("%c[%d;%df", 0x1B, row, col);
}

// Initialize new terminal i/o settings
void initTermios(int echo)
{
  tcgetattr(0, &old); //grab old terminal i/o settings
  new = old; //make new settings same as old settings
  new.c_lflag &= ~ICANON; //disable buffered i/o
  new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}
 
// Restore old terminal i/o settings
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}
 
// Read 1 character - echo defines echo mode
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
char getch(void)
{
  return getch_(0);
}
 
char getche(void)
{
  return getch_(1);
}

char getkey(void)
{
  char ch;
  ch = getch();
  if (ch == '\033')
  {
    ch = getch();
    ch = getch();
    return ch;
  }
  return ch;
}
//End of conio.c