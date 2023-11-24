#include "COMMAND/START/start.h"
#include "COMMAND/LOAD/load.h"
#include "console.h"



int main() {
    welcome();
    stateWayangWave = false;
    CreateEmptyListPenyanyi(&l);
    CreateQueueLagu(&q);
    CreateStack(&r);
    Word command;
    
    while (!stateWayangWave) {
        do {
            printf("> ENTER COMMAND: ");
            command=GetInput();
            if (IsWordEq(toKata("HELP"), command)){
                InitialHelp();
            }
            else if (!IsWordEq(toKata("START"), command) && !IsWordEq(toKata("LOAD"), AccessCommand(command,0))) {
                printf("Command tidak valid. Mesin WayangWave belum dijalankan!\nGunakan command START/LOAD/HELP untuk memulai\n\n");
            }
        } while (!IsWordEq(toKata("START"), command) && !IsWordEq(toKata("LOAD"), AccessCommand(command,0)));

        if (IsWordEq(toKata("START"), command)) {startconfig(); stateWayangWave=true;}
        else {load(command); stateWayangWave=true;};
    }
    if (stateWayangWave) {
        SessionHelp();
        while (stateWayangWave) {
            ListCommand();
        }
    } else {
        printf("WayangWave gagal dijalankan.\n");
    }
}