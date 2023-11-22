#ifndef QUEUE_H
#define QUEUE_H
#include "../../ADT_BUATAN/RIWAYAT/riwayat.h"

void getCommandQueue();
void startQueue();
void queueSong();
// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist();
// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs();
// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong();

// Fungsi untuk mengosongkan queue
void clearQueue();

#endif