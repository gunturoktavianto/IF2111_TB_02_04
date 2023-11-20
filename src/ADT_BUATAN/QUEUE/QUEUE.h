#ifndef QUEUE_H
#define QUEUE_H
#include "queuelagu.h"
// Fungsi untuk menambahkan lagu ke dalam queue
void queuePlaylist(ArrayDin L, Queue *Q);
// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(int x, int y, Queue *Q);
// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(int songId, Queue *Q);
// Fungsi untuk mengosongkan queue
void clearQueue(Queue *Q);
#endif