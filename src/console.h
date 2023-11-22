#ifndef CONSOLE_H
#define CONSOLE_H

#include "COMMAND/HELP/help.h"
#include "COMMAND/LIST/listlagu.h"
#include "COMMAND/LOAD/load.h"
#include "COMMAND/PLAY/play.h"
#include "COMMAND/PLAYLIST/playlistcmd.h"
#include "COMMAND/QUEUE/queuecmd.h"
#include "COMMAND/QUIT/quit.h"
#include "COMMAND/SAVE/save.h"
#include "COMMAND/SONG/song.h"
#include "COMMAND/STATUS/status.h"

void ListCommand();
/* Memilih menu WayangWAve
    I.S. listGame dan queueGame terdefinisi mungkin kosong
    F.S. Menu dijalankan sesuai dengan input user
*/
#endif