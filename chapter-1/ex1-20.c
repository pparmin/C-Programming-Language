/* DETAB program */

#include <stdio.h>
#define TABINC 8

int main(void)
{
  int ch;
  int position = 1;
  int spaces = 0;

  printf("|      |       |       |       |\n");
  while ((ch = getchar()) != EOF) {
    if (ch == '\t') {

        // calculate the amount of spaces based on the current position of the word-end
        spaces = TABINC - (position % TABINC);
        while (spaces > 0) {
          putchar(' ');
          spaces--;
          ++position;
      }

    }
    // reset position when a new line is started
    else if (ch == '\n') 
    {
      putchar(ch);
      position = 1;
    }
    // advance a position and write character to output if it's not a whitespace
    else 
    {
    putchar(ch);
    ++position;
    }
  }
}