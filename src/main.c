#include "start.h"
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
