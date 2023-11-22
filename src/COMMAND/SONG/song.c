#include <stdio.h>
#include "song.h"
#include <stdlib.h>

void songNext()
{
    // KAMUS    
    Lagu song;
    // ALGORITMA
    if(isEmptyQueueLagu(q)) // jika queueu kosong
    {
        if(currentsong.penyanyi.Length == Nil && currentsong.album.Length == Nil && currentsong.nama.Length == Nil)
        {
            printf(">> Queue lagu kamu kosong, dan tidak ada lagu yang dimainkan saat ini. Silahkan masukkan fungsi lain");
            
        }
        else
        {
            // Push(riwayat, currentsong);
            printf("Queue kosong, memutar kembali lagu \n\"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.penyanyi.TabWord);
            // memainkan lagu saat ini
            // Push(&riwayat, lagudiputars);
            printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.album.TabWord, currentsong.penyanyi.TabWord);
            // displayQueueLagu(queueLagu);
            // displayRiwayat(&riwayat);
        }
    }

    else
    {
        dequeueLagu(&q, &song);
        // lagudiputars = lagudiputarq;
         // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        Push(&r, currentsong);
        printf("Memutar lagu selanjutnya\n\"%s\" oleh \"%s\"", song.nama.TabWord, song.penyanyi.TabWord);
        currentsong = song;
        printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.album.TabWord, currentsong.penyanyi.TabWord);
        // displayQueueLagu(queueLagu);
        // displayRiwayat(&riwayat);
    }
}

void songPrevious()
{
    // KAMUS    
    Lagu song;
    ElTypeQueue val;
    int i;
    // ALGORITMA
    if(IsEmptyStack(r))
    {
        if(currentsong.penyanyi.Length == Nil && currentsong.album.Length == Nil && currentsong.nama.Length == Nil)
        {
            printf(">> Riwayat lagu kamu kosong, dan tidak ada lagu yang dimainkan saat ini. Silahkan masukkan fungsi lain");
        }
        else
        {
            // Push (riwayat, currentsong); // tadinya mikir lagu yang bakal diputar di tamabhin ke riwayat
            // enqueueLagu(queueLagu, currentsong); // nambahin lagu yang diputar ke queue
            // if(!isEmptyQueueLagu(*queueLagu))
            // {
            //     for(i = 0; i < lengthQueueLagu(*queueLagu)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            //     {
            //         dequeueLagu(queueLagu, &val);
            //         enqueueLagu(queueLagu, val);
            //     }
            // }
            printf("Riwayat lagu kosong, memutar kembali lagu\n\"%s\" oleh \"%s\"\n", currentsong.nama.TabWord, currentsong.penyanyi.TabWord); // memainkan lagu
            printf("CURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.album.TabWord, currentsong.penyanyi.TabWord);
            // displayQueueLagu(*queueLagu);
            // displayRiwayat(riwayat);
        }
       
    }   
    else
    {
        Pop(&r, &song); // ambi lagu dari riwayat
        enqueueLagu(&q, currentsong); // nambahin lagu ke queue
        if(!isEmptyQueueLagu(q))
        {
            for(i = 0; i < lengthQueueLagu(q)-1; i++) // loop untuk ngubah posisi lagu yang dimainkan ke posisi pertama di queue
            {
                dequeueLagu(&q, &val);
                enqueueLagu(&q, val);
            }
        }
        printf("Memutar lagu sebelumnya \n\"%s\" oleh \"%s\"", song.nama.TabWord, song.penyanyi.TabWord);
        Push(&r, currentsong);
        currentsong = song;
        printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.album.TabWord, currentsong.penyanyi.TabWord);
        // displayQueueLagu(queueLagu);
        // displayRiwayat(&riwayat);
    }
}

void startSong()
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
            songNext();
            valid = true;
        } 
        else if(IsWordEq(toKata("SONG PREVIOUS"), command))
        {
            songPrevious();
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