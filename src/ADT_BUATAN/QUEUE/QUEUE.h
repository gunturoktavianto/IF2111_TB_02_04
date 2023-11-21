#ifndef QUEUE_H
#define QUEUE_H
#include "queuelagu.h"
#include "../PENYANYI/penyanyi.h"
void getCommandQueue(Queue *Q, ListPenyanyi P, ArrayDin L);
void startQueue(Queue *Q, ListPenyanyi P, ArrayDin L);
void queueSong(Queue *Q, ListPenyanyi P, ArrayDin L);
// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist(Queue *Q, ListPenyanyi P, ArrayDin L);
// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(Queue *Q, ListPenyanyi P, ArrayDin L);
// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(Queue *Q, ListPenyanyi P, ArrayDin L);

// Fungsi untuk mengosongkan queue
void clearQueue(Queue *Q, ListPenyanyi P, ArrayDin L);

#endif