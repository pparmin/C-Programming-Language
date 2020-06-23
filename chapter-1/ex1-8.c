#include <stdio.h>

void main()
{
	int c = 0;
	int tabs = 0;
	int blanks = 0;
	int nl = 0; 
	
	while ((c = getchar()) != EOF) {
		if (c == '\n') { nl++; }
		if (c == '\t') { tabs++; } 
		if (c == ' ') { blanks++; } 
	}
	printf("new lines: %d, blanks: %d, tabs: %d\n", nl, blanks, tabs);
}
