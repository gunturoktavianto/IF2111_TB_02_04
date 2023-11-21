#ifndef song_H
#define song_H

#include "ADT_BUATAN/RIWAYAT/riwayat.h"
#include "ADT_BUATAN/QUEUE/queuelagu.h"
#include "ADT_BUATAN/PENYANYI/penyanyi.h"
#include "ADT_BUATAN/PLAYLIST/playlistcmd.h"
#include "start.h"

void DisplayDaftarPlaylist(ArrayDin Arr);

int SearchIndexAlbum(ListPenyanyi *penyanyi, Word album, int indekspenyanyi);

void DisplayDaftarAlbum(ListPenyanyi *penyanyi, int indekspenyanyi);

void DisplayDaftarLagu(SetLagu lagu, Word namaalbum);

char yesorno ();

void ListLagu();

void list();
#endif
