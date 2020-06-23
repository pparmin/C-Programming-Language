#include <stdio.h>

#define PROGRAM 0
#define CHECK_COMMENT_TYPE 1
#define IN_SL_COMMENT 2
#define IN_ML_COMMENT 3
#define END_ML_COMMENT 4


int main()
{
    int current_ch, last_ch;
    int state;
    state = PROGRAM;

    while ((current_ch = getchar()) != EOF) {
        if (state == PROGRAM) {
            if (current_ch == '/') {
                state = CHECK_COMMENT_TYPE;
            }
            else {
                putchar(current_ch);
            }
        }

        else if (state == CHECK_COMMENT_TYPE) {
            if (current_ch == '/') {
                state = IN_SL_COMMENT;
            } else if (current_ch == '*') {
                state = IN_ML_COMMENT;
            } else {
                putchar('/');
                state = PROGRAM;
            }
        }

        else if (state == IN_SL_COMMENT) {
            if (current_ch == '\n') {
                putchar('\n');
                state = PROGRAM;
            }
        }

        else if (state == IN_ML_COMMENT) {
            if (current_ch == '*') {
                state = END_ML_COMMENT;
            }
        }

        else if (state == END_ML_COMMENT) {
            if (current_ch == '/') {
                state = PROGRAM;
            } else {
                state = IN_ML_COMMENT;
            }
        }
    }
    return 0;
}