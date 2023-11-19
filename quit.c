#include <stdio.h>
#include "mesinkata.h"

void QUIT(char command, Word currentWord) {
    if (command == "QUIT;") {
        char response[2];
        printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
        ADVWORD();
        if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y') {
            // memanggil save
            save();
        }

        printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
        exit();
    } else {
        printf("Perintah tidak valid\n");
    }
}
