#include <stdio.h>

int main(void)
{
	int c = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
        }
        else putchar(c);
	}
    return 0;
}
