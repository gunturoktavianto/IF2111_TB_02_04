#ifndef list_H
#define list_H

#include "../START/start.h"

void DisplayDaftarPlaylist(ArrayDin Arr);

int SearchIndexAlbum(ListPenyanyi penyanyi, Word album, int indekspenyanyi);

void DisplayDaftarAlbum(ListPenyanyi penyanyi, Word namapenyanyi, int indekspenyanyi);

void DisplayDaftarLagu(SetLagu lagu, Word namaalbum); // untuk print daftar lagu berdasarkan album masukan 

char yesorno ();

void ListLagu();

void list();

#endif