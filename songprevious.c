#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void songPrevious(Queue queueLagu, Stack riwayat)
{
    // KAMUS    
    ElTypeQueue lagudiputarq;
    infotypeStack lagudiputars, nowplaying;
    ElTypeQueue val;
    int i;
    // ALGORITMA
    Pop(&riwayat, &nowplaying); // mengambil lagu saat ini
    if(IsEmptyStack(riwayat))
    {
        // Push (&riwayat, nowplaying); // tadinya mikir lagu yang bakal diputar di tamabhin ke riwayat
        lagudiputarq = nowplaying; 
        enqueue(&queueLagu, lagudiputarq); // nambahin lagu yang diputar ke queue
        if(!isEmptyQueue(queueLagu))
        {
            for(i = 0; i < length(q)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeue(&queueLagu, &val);
                enqueue(&queueLagu, val);
            }
        }
        printf("Riwayat lagu kosong, memutar kembali lagu \n %s\n", nowplaying); // memainkan lagu
        PlaySong();
    }   
    else
    {
        Pop(&riwayat, &lagudiputars); // ambi lagu dari riwayat
        lagudiputarq = lagudiputars;
        enqueue(&q, lagudiputarq); // nambahin lagu ke queue
        if(!isEmptyQueue(queueLagu))
        {
            for(i = 0; i < length(q)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeue(&queueLagu, &val);
                enqueue(&queueLagu, val);
            }
        }
        printf("Memutar lagu sebelumnya \n “%s”", lagudiputars);
        PlaySong();
    }
}