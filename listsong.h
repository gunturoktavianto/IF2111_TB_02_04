#ifndef listsong_H
#define listSong_H

#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void DisplayDaftarPenyanyi(List L);
/*
Menampilkan list penyanyi yang ada
*/

void DisplayDaftarAlbum(Map MPenyanyi, char *album);
// Menampilkan daftar album yang ada


void DisplayDaftarLagu(Set S, Map MLagu, char* lagu, int indeks);
// Menampilkan daftar lagu yang ada

void ListDefault(List Penyanyi, Map Album, Set Lagu);
// Menampilkan list penyanyi, album, dan lagu mereka
#endif