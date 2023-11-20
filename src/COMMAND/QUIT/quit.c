#include "quit.h"

void QUIT(Word command) {
    char response[2];
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
    GetCommand();
    if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y') {
        // memanggil save
        //save();
    }

    printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
    exit(0);
}