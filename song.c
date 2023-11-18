#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void songNext(Queue queueLagu, Stack riwayat)
{
    // KAMUS    
    List temp;
    char* currentSong, penyanyi;
    infotypeStack lagudiputars;
    ElTypeQueue lagudiputarq;
    ElTypeQueue val;
    // ALGORITMA
    if(isEmptyQueue(queueLagu)) // jika queueu kosong
    {
        // Pop(&riwayat, &lagudiputars); // ambil lagu saat ini
        // currentSong
        // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        lagudiputars = currentSong;
        Push(&riwayat, lagudiputars);
        printf("Queue kosong, memutar kembali lagu \n %s oleh %s", currentSong, penyanyi);
        // memainkan lagu saat ini
        // Push(&riwayat, lagudiputars);
    }
    else
    {
        dequeue(&queueLagu, lagudiputarq);
        // lagudiputars = lagudiputarq;
         // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        lagudiputars = currentSong;
        Push(&riwayat, lagudiputars);
        printf("Memutar lagu selanjutnya \n %s oleh %s", lagudiputarq, penyanyi);
        currentSong = lagudiputarq;
        // Push(&riwayat, lagudiputars);
    }
}

void songPrevious(Queue queueLagu, Stack riwayat)
{
    // KAMUS    
    ElTypeQueue lagudiputarq;
    char* currentSong, penyanyi;
    infotypeStack lagudiputars;
    ElTypeQueue val;
    int i;
    // ALGORITMA
    if(IsEmptyStack(riwayat))
    {
        // Push (&riwayat, nowplaying); // tadinya mikir lagu yang bakal diputar di tamabhin ke riwayat
        lagudiputarq = currentSong; 
        enqueue(&queueLagu, lagudiputarq); // nambahin lagu yang diputar ke queue
        if(!isEmptyQueue(queueLagu))
        {
            for(i = 0; i < length(queueLagu)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeue(&queueLagu, &val);
                enqueue(&queueLagu, val);
            }
        }
        printf("Riwayat lagu kosong, memutar kembali lagu \n %s oleh %s\n", currentSong, penyanyi); // memainkan lagu
    }   

    else
    {
        Pop(&riwayat, &lagudiputars); // ambi lagu dari riwayat
        lagudiputarq = lagudiputars;
        enqueue(&queueLagu, lagudiputarq); // nambahin lagu ke queue
        if(!isEmptyQueue(queueLagu))
        {
            for(i = 0; i < length(queueLagu)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeue(&queueLagu, &val);
                enqueue(&queueLagu, val);
            }
        }
        printf("Memutar lagu sebelumnya \n %s oleh %s", lagudiputars, penyanyi);
        Push(&riwayat, currentSong);
        currentSong = lagudiputars;
    }
}

void song()
{
    // KAMUS
    boolean valid = false;
    // ALGORITMA
    printf("====[ SELAMAT DATANG DI FUNGSI SONG ]====\n");
    printf("TERDAPAT DUA FUNGSI YANG BISA DIAKSES \n");
    printf("    1. SONG NEXT \n");
    printf("    2. SONG PREVIOUS \n");
    printf("SILAHKAN MASUKAN COMMAND: \n");
    GetCommand();
    while(!valid)
    {
        if (IsWordEq(toKata("SONG NEXT"), currentWord))
        {
            songNext();
            valid = true;
        } 
        else if(IsWordEq(toKata("SONG PREVIOUS"), currentWord))
        {
            songPrevious();
            valid = true;
        } 
        else
        {
            printf("COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG\n");
            GetCommand();
        }
    }
}