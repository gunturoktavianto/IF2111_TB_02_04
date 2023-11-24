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

#define MAX_LEN 128
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void ListCommand();
/* Memilih menu WayangWAve
    I.S. listGame dan queueGame terdefinisi mungkin kosong
    F.S. Menu dijalankan sesuai dengan input user
*/

void loading();
/* Menampilkan loading screen
    I.S. Sembarang
    F.S. Loading screen ditampilkan
*/

void welcome();
/* Menampilkan welcome screen
    I.S. Sembarang
    F.S. Welcome screen ditampilkan
*/

void image();
void image2();

void print_image(FILE *fptr);
/* Menampilkan image
    I.S. Sembarang
    F.S. Image ditampilkan
*/
#endif