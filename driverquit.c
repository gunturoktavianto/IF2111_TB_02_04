#include "quit.c"

int main() {
    char command[5];
    GetCommand();

    if (IsWordEq(toKata("QUIT;"), currentWord)) {
        QUIT(currentWord);
    }
    return 0;

}
