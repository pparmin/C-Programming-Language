#include <stdio.h>

#define PROGRAM 0
#define CHECK_COMMENT_TYPE 1
#define IN_SL_COMMENT 2
#define IN_ML_COMMENT 3
#define END_ML_COMMENT 4
#define IN_COMMENT 5

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

/*        else if (state == IN_ML_COMMENT) {
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
        }*/
    }
    return 0;
}



/*
int main()
{
  int current_ch, last_ch;
  int state;

  state = PROGRAM;

  while ((current_ch = getchar()) != EOF) {
    if (state == PROGRAM) {
      if (current_ch == '/') {
        state = BEGIN_COMMENT;
      }
      else if (current_ch == 'n' && last_ch == '\\') {
          putchar(last_ch);
          putchar(current_ch);
      }
      else if (last_ch == '\\' && current_ch != 'n') {
          state = IN_COMMENT;
      }
      else {
        putchar(current_ch);
      }
    }
    else if (state == BEGIN_COMMENT) {
        if (current_ch == '/' || current_ch == '*') {
            state = IN_COMMENT;
        }
        else {
            putchar('/');
            state = PROGRAM;
        }
    }
    else if (state == IN_COMMENT) {
        if (current_ch == '*' || current_ch == '/') {
            state = END_COMMENT;
        }
        // Handle line feed (LF or '\n') character
        // PROBLEM: In multi-line comments this presents an issue: How do I handle multi-line comments
        // but also handle comments that come after a valid expression (like int len; // length\n int end;)

        else if (current_ch == '\n') {
            state = PROGRAM;
        }

    }
    else if (state == END_COMMENT) {
        if (current_ch == '/') {
            state = PROGRAM;
        }
        */
/*else if (current_ch == '\\') {
            last_ch = current_ch;
            state = PROGRAM;
        }*//*

        else {
            state = IN_COMMENT;
        }
    }
  }
  return 0;
}*/
