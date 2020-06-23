#include <stdio.h>
#define IN 1
#define OUT 0

int main(void)
{
	int c, state;
    state = OUT;

	
	while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar('\n');
        }
        if (c == '\n' || c == ' ' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
        } 
        
        if (state == IN) {
            putchar(c);
        }
	}
    return 0;
}
