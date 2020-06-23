#include <stdio.h>
#define MAXLINE 1000
#define CAP 80

int get_line(char line[], int maxsize);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char overCAP[MAXLINE];
    
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
        }
        printf("length: %d\n", len);
        if (len > CAP) {
            copy(overCAP, line);
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