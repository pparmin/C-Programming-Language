#include <stdio.h>
 #define MAXLINE 1000 /* maximum input line length */

int getline(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int main()
{
  int len;
  int max;
  char line [MAXLINE];
  char longest[MAXLINE];
}