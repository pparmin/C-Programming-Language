#include <stdio.h>
#define MAXLINE 1000
#define CAP 80

int get_line(char line[], int maxsize);
void copy(char to[], char from[]);
void rmblanks(char source[], char target[], int length);
void reverse(char source[], char target[], int len);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char line_brm[MAXLINE]; /* placeholder array for lines without whitespace */
    char line_rev[MAXLINE];
    char overCAP[MAXLINE];
    
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
        }

        /* print line only if cap has been passed */
        if (len > CAP) {
            rmblanks(line, line_brm, len);
            reverse(line_brm, line_rev, len);
            copy(overCAP, line_brm);
            printf("%s", overCAP);
        }
    } 
    return 0;
}

/* gtline:  read a line into s, return length  */
int get_line(char line[], int maxsize) 
{
    int c, len;

    for (len = 0; len < maxsize-1 && (c = getchar()) != EOF && c != '\n'; ++len) 
        line[len] = c;
    if (c == '\n') {
        line[len] = c;
        ++len;
    }
    line[len] = '\0';
    return len;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void rmblanks(char[] line, char[] newLine, int end_of_array)
    char lastch;
    for (int i = end_of_array; i >= 0; i--) 
    {

        if (lastch == '\t' || last == ' ')
            continue;
            
        lastch = line[i];
        newLine[i] == line[i];
    }
}

void reverse(char[] line, char[] target, int len)
{
    for (int i = len; i >= 0; i--) {
    }
}