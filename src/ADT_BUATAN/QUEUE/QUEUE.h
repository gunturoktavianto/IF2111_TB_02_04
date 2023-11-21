#ifndef QUEUE_H
#define QUEUE_H
#include "queuelagu.h"
#include "../PENYANYI/penyanyi.h"
void startQueue(Queue *Q, ListPenyanyi P, ArrayDin L);
/* Menampilkan halaman utama dari . */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
void queueSong(Queue *Q, ListPenyanyi P);
// Fungsi untuk menambahkan lagu ke dalam queue
void queuePlaylist(ArrayDin L, Queue *Q);
// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(Queue *Q);
// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(Queue *Q);
// Fungsi untuk mengosongkan queue
void clearQueue(Queue *Q);
#endif