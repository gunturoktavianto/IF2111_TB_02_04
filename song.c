#include <stdio.h>
#include "song.h"
#include <stdlib.h>

void songNext(Queue *queueLagu, Stack *riwayat)
{
    // KAMUS    
    Lagu song;
    // ALGORITMA
    if(isEmptyQueueLagu(*queueLagu)) // jika queueu kosong
    {
        if(currentSong.penyanyi.Length == Nil && currentSong.album.Length == Nil && currentSong.nama.Length == Nil)
        {
            printf(">> Queue lagu kamu kosong, dan tidak ada lagu yang dimainkan saat ini. Silahkan masukkan fungsi lain");
            
        }
        else
        {
            Push(riwayat, currentSong);
            printf("Queue kosong, memutar kembali lagu \n\"%s\" oleh \"%s\"", currentSong.nama.TabWord, currentSong.penyanyi.TabWord);
            // memainkan lagu saat ini
            // Push(&riwayat, lagudiputars);
            printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentSong.nama.TabWord, currentSong.album.TabWord, currentSong.penyanyi.TabWord);
            // displayQueueLagu(queueLagu);
            // displayRiwayat(&riwayat);
        }
    }

    else
    {
        dequeueLagu(queueLagu, &song);
        // lagudiputars = lagudiputarq;
         // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        Push(riwayat, currentSong);
        printf("Memutar lagu selanjutnya\n\"%s\" oleh \"%s\"", song.nama.TabWord, song.penyanyi.TabWord);
        currentSong = song;
        printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentSong.nama.TabWord, currentSong.album.TabWord, currentSong.penyanyi.TabWord);
        // displayQueueLagu(queueLagu);
        // displayRiwayat(&riwayat);
    }
}

void songPrevious(Queue *queueLagu, Stack *riwayat)
{
    // KAMUS    
    Lagu song;
    ElTypeQueue val;
    int i;
    // ALGORITMA
    if(IsEmptyStack(*riwayat))
    {
        if(currentSong.penyanyi.Length == Nil && currentSong.album.Length == Nil && currentSong.nama.Length == Nil)
        {
            printf(">> Riwayat lagu kamu kosong, dan tidak ada lagu yang dimainkan saat ini. Silahkan masukkan fungsi lain");
        }
        else
        {
            Push (riwayat, currentSong); // tadinya mikir lagu yang bakal diputar di tamabhin ke riwayat
            enqueueLagu(queueLagu, currentSong); // nambahin lagu yang diputar ke queue
            if(!isEmptyQueueLagu(*queueLagu))
            {
                for(i = 0; i < lengthQueueLagu(*queueLagu)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
                {
                    dequeueLagu(queueLagu, &val);
                    enqueueLagu(queueLagu, val);
                }
            }
            printf("Riwayat lagu kosong, memutar kembali lagu\n\"%s\" oleh \"%s\"\n", currentSong.nama.TabWord, currentSong.penyanyi.TabWord); // memainkan lagu
            printf("CURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentSong.nama.TabWord, currentSong.album.TabWord, currentSong.penyanyi.TabWord);
            // displayQueueLagu(*queueLagu);
            // displayRiwayat(riwayat);
        }
       
    }   
    else
    {
        Pop(riwayat, &song); // ambi lagu dari riwayat
        enqueueLagu(queueLagu, currentSong); // nambahin lagu ke queue
        if(!isEmptyQueueLagu(*queueLagu))
        {
            for(i = 0; i < lengthQueueLagu(*queueLagu)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeueLagu(queueLagu, &val);
                enqueueLagu(queueLagu, val);
            }
        }
        printf("Memutar lagu sebelumnya \n\"%s\" oleh \"%s\"", song.nama.TabWord, song.penyanyi.TabWord);
        Push(riwayat, currentSong);
        currentSong = song;
        printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentSong.nama.TabWord, currentSong.album.TabWord, currentSong.penyanyi.TabWord);
        // displayQueueLagu(queueLagu);
        // displayRiwayat(&riwayat);
    }
}

void song(Queue *queueLagu, Stack *riwayat)
{
    // KAMUS
    boolean valid = false;
    Word command;
   
    // ALGORITMA
    printf("====[ SELAMAT DATANG DI FUNGSI SONG ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("    1. SONG NEXT \n");
    printf("    2. SONG PREVIOUS \n");
    printf("    3. QUIT \n");
    printf("> SILAHKAN MASUKAN COMMAND: \n");
    command = GetInput();
    while(!valid)
    {
        if (IsWordEq(toKata("SONG NEXT"), command))
        {
            songNext(queueLagu, riwayat);
            valid = true;
        } 
        else if(IsWordEq(toKata("SONG PREVIOUS"), command))
        {
            songPrevious(queueLagu, riwayat);
            valid = true;
        } 
        else if(IsWordEq(toKata("QUIT"), command))
        {
            printf("\n>> Keluar dari Fungsi");
            valid = true;
        } 
        else
        {
            printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG\n");
            command = GetInput();
        }
    }
}