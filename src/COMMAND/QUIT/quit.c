#include "quit.h"

void startQuit() {
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
    Word command=GetInput();
    if (command.TabWord[0] == 'Y' || command.TabWord[0] == 'y') {
        startSave();
    }
    stateWayangWave=false;
    
    printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
    exit(0);
}