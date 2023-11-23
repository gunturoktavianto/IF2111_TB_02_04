#include "console.h"

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