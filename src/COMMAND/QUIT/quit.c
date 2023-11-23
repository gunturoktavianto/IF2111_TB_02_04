#include "quit.h"

void startQuit() {
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
    Word command=GetInput();
    boolean state = false;
    while (state == false){
        if ((command.Length == 1)&&(command.TabWord[0] == 'Y' || command.TabWord[0] == 'N')){
            if (command.TabWord[0] == 'Y') {
            startSave();
            }
            state = true;
            printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
            exit(0);
        }
        printf("Input Anda salah. Silahkan mencoba kembali.");
        printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
        Word command=GetInput();
    }
    stateWayangWave=false;
    
    printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
    exit(0);
}