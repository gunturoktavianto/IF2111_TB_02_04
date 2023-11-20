#include "ADT/mesinkata/mesinkata.h"

char yesorno ()
{
    // KAMUS
    Word command;
    char input;
    boolean valid = false;
    // ALGORITMA
    command = GetInput();
    while(!valid)
    {
        if(currentWord.Length > 1) command = GetInput();
        else
        {
            input = command.TabWord[0];
            if(input == 'Y' || input == 'y')
            {
                valid = true;
            }
            else if(input == 'N' || input == 'n')
            {
                valid = true;
            }
            else
            {
                command = GetInput();
            }
        } 
    }
    return input;
}

int main()
{
    // Word kalimat, command;
    // boolean valid = false;
    // printf("masukkan command :\n");
    // command = GetInput();
    // while(!valid)
    // {
        
    //     if(IsWordEq(toKata("PAK ARMIEN"), command))
    //     {
    //         printf("\n jalan");
    //         kalimat = command;
    //         printf("\n kalimat yng muncul adalah : %s", kalimat.TabWord);
    //         valid = true;
    //     }
    //     else
    //     {
    //         printf("\n> INPUT COMMAND LAGI\n");;
    //     }
    //     command = GetInput();
    // }
    printf("masukkan input : ");
    char input = yesorno();
    printf("output adalah %c", input);
}