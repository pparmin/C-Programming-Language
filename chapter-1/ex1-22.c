/* Write a program to ``fold'' long input lines into two or more shorter lines after 
the last non-blank character that occurs before the n-th column of input. Make sure 
your program does something intelligent with very long lines, and if there are no blanks
or tabs before the specified column. */

#include <stdio.h>
#define LINEBREAK 40

int main()
{
  int ch, lastch;
  int column = 0;
  int NEWLINE = 0;      /* If SPLIT_STATE equals 1, don't add a blank/tab to the new line */

  while ((ch = getchar()) != EOF)
  {
    if (ch == '\n') {
      putchar(ch);
      column = 0;
    }

    if (column == LINEBREAK - 1) {

      putchar('\n');
      NEWLINE = 1;
      column = 0;

    }
    if (NEWLINE) 
    {
      if (ch == ' ' || ch == '\t') {
        continue;
      } else if (ch != ' ' || ch == '\t') 
        NEWLINE = 0;
    }
    putchar(ch);
    column++;
   }
   return 0;
}