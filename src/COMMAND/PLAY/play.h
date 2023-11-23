#ifndef play_H
#define play_H

#include "../../ADT_BUATAN/RIWAYAT/riwayat.h"
#include "../LIST/listlagu.h"
#include "../SONG/song.h"

void PlaySong();
/* I.S. listpenyanyi terdefinisi dan tidak kosong
   F.S. queue dan riwayat lagu akan menjadi kosong
        currentsong diperbaharui 
*/

void PlayPlaylist();
/* I.S. playlist tidak kosong
   F.S. queue berisi semua lagu dalam playlist
        currentsong menjadi lagu urutan pertama dalam playlist
        isi riwayat lagu (keseluruhan) sama dengan queue, tetapi dengan urutan yang di-reverse.
*/

void startPlay();

void getCommandPlay();

#endif