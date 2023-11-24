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
            command=GetInput();
            startSave(command);
            }
            state = true;
            printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
            exit(0);
        }
        printf("Input Anda salah. Silahkan mencoba kembali.");
    } while (!state);
}