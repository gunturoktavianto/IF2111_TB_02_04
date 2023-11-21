#ifndef QUEUE_H
#define QUEUE_H
#include "../START/start.h"

// Fungsi untuk menambahkan lagu ke dalam queue
void queuePlaylist(ArrayDin L, Queuelagu *Q);
// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(int x, int y, Queuelagu *Q);
// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(int songId, Queuelagu *Q);
// Fungsi untuk mengosongkan queue
void clearQueue(Queuelagu *Q);
#endif
