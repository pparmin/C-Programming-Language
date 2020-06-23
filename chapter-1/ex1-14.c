#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0
#define BAR '|'

int main(void)
{
    int ch, nwords, state;
    
    char letters[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z'
    };
    int frequency[26];

    for (int i = 0; i < 26; i++) 
        frequency[i] = 0;

    state = OUT;
    ch = nwords = 0;

    printf("Disclaimer: This program can only take up to 10 words.\n");
    while ((ch = getchar()) != EOF) {
        /* Handle word state (IN or OUT) */
        if (ch == '\n' || ch == ' ' || ch == '\t') {
            state = OUT;
            ++nwords;
            putchar('\n');
        }
        else if (state == OUT) {
            state = IN;
        } 

        if (state == IN) {
            for (int i = 0; i < 26; i++) {
                if (ch == letters[i]) 
                    frequency[i] += 1;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d\n", frequency[i]);
    }
    
    printf("Histogram of the frequencies of letters in the input: \n");
    for (int i = 0; i < 26; i++) {
        printf("letter %c: ", letters[i]);
        for (int j = 0; j < frequency[i]; j++) 
            putchar(BAR);
        printf("\n");
    }
    return 0;
}