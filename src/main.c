#include <stdlib.h>
#include <stdio.h>

#include "console.h"

int main() {
    stateWayangWave = false;
    CreateEmptyListPenyanyi(&l);
    CreateQueueLagu(&q);
    CreateStack(&r);
    Word command;
    while (!stateWayangWave) {
        do {
            printf("=====[ Selamat datang di WayangWave ]=====\n");
            InitialHelp();
            printf("> ENTER COMMAND: ");
            command=GetInput();

            if (!IsWordEq(toKata("START"), command) && !IsWordEq(toKata("LOAD"), command)) {
                printf("Command tidak valid. Mesin WayangWave belum dijalankan!\nGunakan command START / LOAD untuk memulai\n\n");
            }
        } while (!IsWordEq(toKata("START"), command) && !IsWordEq(toKata("LOAD"), command));

        if (IsWordEq(toKata("START"), command)) {startconfig(); stateWayangWave=true;}
        else {load(); stateWayangWave=true;};
    }
    printf("%d\n",l.Count);
    if (stateWayangWave) {
        SessionHelp();
        while (stateWayangWave) {
            ListCommand();
        }
    } else {
        printf("WayangWave gagal dijalankan.\n");
    }
}