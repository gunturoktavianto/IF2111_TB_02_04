#include "adtplus.h"

int main()
{
    Map InfoPenyanyi[NMax];
    FILE *input=fopen("config.txt","r");
    STARTWORD(input);
    int JumlahPenyanyi=WordtoInt(currentWord);
    for (int i=0; i<JumlahPenyanyi; i++)
    {
        ADVWORD;
        int jumlahAlbum;
        GetWords();
    }
}