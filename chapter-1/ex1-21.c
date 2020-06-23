/* ENTAB program 

| 1 2 3 4 5 6 7 8 | 1 2 3 4 5 6 7 8 |
  h e l l o\t       h e y\t


*/

#include <stdio.h>
#define TABINC 8

int main()
{
int c, nb, nt, pos;

nb = 0;
nt = 0;
for (pos = 1; (c =getchar()) != EOF; ++pos)
    if (c == ' '){
        if (pos % TABINC != 0)
            ++nb;
        else {
            nb = 0;
            ++nt;
        }
    }
    else {
        for ( ; nt > 0; --nt)
            putchar('\t');
        if (c == '\t')
            nb = 0;
        else
            for ( ; nb > 0; --nb)
                putchar(' ');
        putchar(c);
        if ( c == '\n')
            pos = 0;
        else if (c == '\t')
            pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
    }
}