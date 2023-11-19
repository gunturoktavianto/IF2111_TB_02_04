#include "ADT_BUATAN/RIWAYAT/riwayat.h"
#include "ADT_BUATAN/QUEUE/queuelagu.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void songNext(Queue queueLagu, Stack riwayat)
{
    // KAMUS    
    Lagu currentSong, song;
    // ALGORITMA
    if(isEmptyQueue(queueLagu)) // jika queueu kosong
    {
        // Pop(&riwayat, &lagudiputars); // ambil lagu saat ini
        // currentSong
        // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        Push(&riwayat, currentSong);
        printf("Queue kosong, memutar kembali lagu \n %s oleh %s", currentSong.nama.TabWord, currentSong.penyanyi.TabWord);
        // memainkan lagu saat ini
        // Push(&riwayat, lagudiputars);
    }
    else
    {
        dequeue(&queueLagu, &song);
        // lagudiputars = lagudiputarq;
         // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        Push(&riwayat, currentSong);
        printf("Memutar lagu selanjutnya \n %s oleh %s", song.nama.TabWord, song.penyanyi.TabWord);
        currentSong = song;
        // Push(&riwayat, lagudiputars);
    }
}

void songPrevious(Queue queueLagu, Stack riwayat)
{
    // KAMUS    
    Lagu currentSong, song;
    ElTypeQueue val;
    int i;
    // ALGORITMA
    if(IsEmptyStack(riwayat))
    {
        // Push (&riwayat, nowplaying); // tadinya mikir lagu yang bakal diputar di tamabhin ke riwayat
        enqueue(&queueLagu, currentSong); // nambahin lagu yang diputar ke queue
        if(!isEmptyQueue(queueLagu))
        {
            for(i = 0; i < length(queueLagu)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeue(&queueLagu, &val);
                enqueue(&queueLagu, val);
            }
        }
        printf("Riwayat lagu kosong, memutar kembali lagu \n %s oleh %s\n", currentSong.nama.TabWord, currentSong.penyanyi.TabWord); // memainkan lagu
    }   

    else
    {
        Pop(&riwayat, &song); // ambi lagu dari riwayat
        enqueue(&queueLagu, currentSong); // nambahin lagu ke queue
        if(!isEmptyQueue(queueLagu))
        {
            for(i = 0; i < length(queueLagu)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeue(&queueLagu, &val);
                enqueue(&queueLagu, val);
            }
        }
        printf("Memutar lagu sebelumnya \n %s oleh %s", song.nama.TabWord, song.penyanyi.TabWord);
        Push(&riwayat, currentSong);
        currentSong = song;
    }
}

void song()
{
    // KAMUS
    boolean valid = false;
    Queue queueLagu; // sementara
    Stack riwayat;
    // ALGORITMA
    load();
    printf("====[ SELAMAT DATANG DI FUNGSI SONG ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("    1. SONG NEXT \n");
    printf("    2. SONG PREVIOUS \n");
    printf("> SILAHKAN MASUKAN COMMAND: \n");
    GetCommand();
    while(!valid)
    {
        if (IsWordEq(toKata("SONG NEXT"), currentWord))
        {
            songNext(queueLagu, riwayat);
            valid = true;
        } 
        else if(IsWordEq(toKata("SONG PREVIOUS"), currentWord))
        {
            songPrevious(queueLagu, riwayat);
            valid = true;
        } 
        else
        {
            printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG\n");
            GetCommand();
        }
    }
}