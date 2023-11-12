#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void songNext(Queue queueLagu, Stack riwayat)
{
    // KAMUS    
    List temp;
    infotypeStack lagudiputars;
    ElType lagudiputarq;
    ElType val;
    // ALGORITMA
    if(isEmptyQueue(queueLagu)) // jika queueu kosong
    {
        Pop(&riwayat, &lagudiputars); // ambil lagu saat ini
        // Push(&riwayat, lagudiputars); // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        printf("Queue kosong, memutar kembali lagu \n %s",lagudiputars);
        PlaySong(); // memainkan lagu saat ini
    }
    else
    {
        dequeue(&queueLagu, lagudiputarq);
        // lagudiputars = lagudiputarq;
        // Push(&riwayat, lagudiputars); // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        printf("Memutar lagu selanjutnya \n %s", lagudiputarq);
        PlaySong(); 
    }
}   