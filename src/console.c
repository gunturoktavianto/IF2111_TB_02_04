#include "console.h"
#include <time.h>
#include <stdio.h>

void ListCommand() {
    printf("\n> ENTER COMMAND: ");
    Word command=GetInput();
    if (IsWordEq(toKata("LIST"),command)) startList();
    else if(IsWordEq(toKata("PLAY"),command)) startPlay();
    else if(IsWordEq(toKata("QUEUE"),command)) startQueue();
    else if(IsWordEq(toKata("SONG"),command)) startSong(); 
    else if(IsWordEq(toKata("PLAYLIST"),command)) startPlaylist(); 
    else if(IsWordEq(toKata("STATUS"),command)) startStatus();
    else if(IsWordEq(toKata("SAVE"),AccessCommand(command,0))) startSave(command);
    else if(IsWordEq(toKata("QUIT"),command)) startQuit();
    else if(IsWordEq(toKata("HELP"),command)) SessionHelp();
    else printf("Command tidak dikenali, silahkan masukkan command yang valid.\nGunakan HELP untuk menunjukan list command.\n\n");
}

void loading() 

{

    int i, j, delay;
    printf(YEL);


    printf("On the way to WAYANG WAVE ");

    printf("[");

    for(i = 0; i < 20; i++) { 
        for(j = 0; j < 100000000; j++) { 
            delay = j;
        }
        printf("=");
    }
    printf("]");


    printf(" COMPLETED\n\n");

    for(j = 0; j < 100099999 ; j++) { 
        delay = j;
        }
}


void image()
{
    char *filename = "../bin/welcome.txt";
    FILE *fptr = NULL;
    fptr = fopen(filename,"r");
 
    print_image(fptr);
 
    fclose(fptr);
}
 
void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
    printf(CYN);
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
    printf(RESET);
}

void welcome(){
    loading();
    image();
    printf("\n\n");
}