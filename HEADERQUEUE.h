#ifndef HEADERQUEUE_H
#define HEADERQUEUE_H

#include <stdio.h>
#include "queue.h"
#include "map.h"
#include "list.h"
#include "boolean.h"
#include "arraydin.h"

// Fungsi untuk menambahkan lagu ke dalam queue
void queueSong(Queue *Q, List Song);
// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist(ArrayDin L, Queue *Q);
// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(int x, int y, Queue *Q);
// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(int songId, Queue *Q, Map Song);
// Fungsi untuk mengosongkan queue
void clearQueue(Queue *Q);

#endif