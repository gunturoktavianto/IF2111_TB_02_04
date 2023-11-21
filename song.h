#ifndef song_H
#define song_H

#include "ADT_BUATAN/RIWAYAT/riwayat.h"
#include "ADT_BUATAN/QUEUE/queuelagu.h"

void songNext(Queue *queueLagu, Stack *riwayat);
void songPrevious(Queue *queueLagu, Stack *riwayat);
void song(Queue *queueLagu, Stack *riwayat);
#endif