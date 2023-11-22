#ifndef status_H
#define status_H

#include "../../ADT_BUATAN/RIWAYAT/riwayat.h"

boolean IsPlaylistinQueue(Queuelagu ql);
/* I.S. queue terdefinisi
   F.S. mengirimkan true jika isi queue, beserta currentsong, sama dengan salah satu playlist dalam daftarplaylist
*/

void startStatus();
/* I.S. currentsong, queueLagu, daftarPlaylist
   F.S. menampilkan pesan lagu yang sedang diputar beserta isi queue dan playlist (jika ada)
*/

#endif