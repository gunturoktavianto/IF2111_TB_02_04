#include "quit.h"
#include "../save/save.h"

void startQuit() {
    Word command;
    boolean state = false;
    do
    {
        printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
        command=GetInput();
        if ((command.Length == 1)&&(command.TabWord[0] == 'Y' || command.TabWord[0] == 'N')){
            if (command.TabWord[0] == 'Y') {
            printf("Masukkan nama file penyimpanan: ");
            command=GetInput();
            startSave(command);
            }
            state = true;
            printf(MAG);
            printf("Kamu keluar dari WayangWave.\n");
            printf(RESET);
            goodbye();
            exit(0);
            
        }
        printf("Input Anda salah. Silahkan mencoba kembali.");
    } while (!state);
}

void loading_quit() 

{

    int i, j, delay;
    printf(MAG);

    printf("[");

    for(i = 0; i < 20; i++) { 
        for(j = 0; j < 100000000; j++) { 
            delay = j;
        }
        printf("=");
    }
    printf("]\n");


    for(j = 0; j < 100099999 ; j++) { 
        delay = j;
        }
}

void print_image_quit(FILE *fptr)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
    printf(RESET);
}

void image_quit()
{
    char *filename = "../bin/goodbye.txt";
    FILE *fptr = NULL;
    fptr = fopen(filename,"r");
    printf(CYN);
    print_image_quit(fptr);

    fclose(fptr);
    printf(RESET);

}

void goodbye() {
    image_quit();
    loading_quit();
    printf(RESET);
}