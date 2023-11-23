#include "mesinkata.c"
#include "mesinkarakter.c"
int main()
{
    START(stdin);
    while(currentChar!=';') {
        printf("%c", currentChar);
        ADV();
    }
    START(stdin);
    while(currentChar!=';') {
        printf("%c", currentChar);
        ADV();
    }
}