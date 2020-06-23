#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0
#define BAR '|'

int main(void)
{
    int c, wlength, nwords, state;
    int lhisto[10];

    for (int i = 0; i < 10; i++) 
        lhisto[i] = 0;

    state = OUT;
    c = wlength = nwords = 0;
    printf("Disclaimer: This program can only take up to 10 words.\n");
    while ((c = getchar()) != EOF) {
        /* Handle word state (IN or OUT) */
        if (c == '\n' || c == ' ' || c == '\t') {
            state = OUT;
            putchar('\n');
            lhisto[nwords] = wlength;
            ++nwords;
            wlength = 0;
        }
        else if (state == OUT) {
            state = IN;
        } 

        if (state == IN) {
            ++wlength;
        }
    }
    
    printf("Histogram of word lengths: \n");
    for (int i = 0; i < nwords; i++)
    {
        printf("word no. %d: ", i);
        for (int j = 0; j < lhisto[i]; j++)
            putchar(BAR);
        printf("\n");
    }
    return 0;
}