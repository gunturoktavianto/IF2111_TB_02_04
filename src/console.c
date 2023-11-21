#include "console.h"

void ListCommand() {
    printf("> ENTER COMMAND: ");
    Word command=GetInput();
    if (IsWordEq(toKata("LIST"),command)) startList();
    else if(IsWordEq(toKata("PLAY"),command)) startPlay();
    else if(IsWordEq(toKata("QUEUE"),command)) startQueue();
    else if(IsWordEq(toKata("SONG"),command)) startSong(); 
    else if(IsWordEq(toKata("STATUS"),command)) startPlaylist();
    else if(IsWordEq(toKata("SAVE"),command)) startSave();
    else if(IsWordEq(toKata("QUIT"),command)) startQuit();
    else if(IsWordEq(toKata("HELP"),command)) SessionHelp;
    else printf("Command tidak dikenali, silahkan masukkan command yang valid.\nGunakan HELP untuk menunjukan list command.\n\n");
}