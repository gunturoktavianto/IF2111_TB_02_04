#include <stdio.h>
#include "mesinkata.c"
#include "mesinkarakter.c"
#include "set.c"
#include "map.c"
int main()
{
    FILE *input=fopen("config.txt","r");
    STARTWORD(input);
    nextLine();
    ADVWORD();
    Word w=GetWords();
    nextLine();
    ADVWORD();
    w=GetWords();
    printf("%s",w.TabWord);
}