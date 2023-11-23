#ifndef list_H
#define list_H

#include "../../ADT_BUATAN/RIWAYAT/riwayat.h"

int SearchIndexAlbum(Word album, int indekspenyanyi);

void DisplayDaftarPlaylist(ArrayDin Arr);

void DisplayDaftarAlbum(ListPenyanyi *penyanyi, int indekspenyanyi);

void DisplayDaftarLagu(SetLagu lagu, Word namaalbum);

char yesorno ();

void ListLagu();

void startList();

#endif