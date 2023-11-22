#include "song.h"

void songNext()
{
    // KAMUS    
    Lagu song;
    // ALGORITMA
    if(isEmptyQueueLagu(q)) // jika queue kosong
    {
        if(currentsong.penyanyi.Length == 0 && currentsong.album.Length == 0 && currentsong.nama.Length == 0)
        {
            printf(">> Queue lagu kamu kosong, dan tidak ada lagu yang dimainkan saat ini. Silahkan masukkan fungsi lain");
            
        }
        else
        {
            // Push(riwayat, currentsong);
            printf("Queue kosong, memutar kembali lagu \n\"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.penyanyi.TabWord);
            printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.album.TabWord, currentsong.penyanyi.TabWord);
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
        // displayRiwayat(&r);
    }
}

void songPrevious()
{
    // KAMUS    
    infotypeStack song;
    ElTypeQueue val;
    int i;
    // ALGORITMA
    if(IsEmptyStack(r))
    {
        if(currentsong.penyanyi.Length == 0 && currentsong.album.Length == 0 && currentsong.nama.Length == 0)
        {
            printf(">> Riwayat lagu kamu kosong, dan tidak ada lagu yang dimainkan saat ini. Silahkan masukkan fungsi lain");
        }
        else
        {
            printf("Riwayat lagu kosong, memutar kembali lagu\n\"%s\" oleh \"%s\"\n", currentsong.nama.TabWord, currentsong.penyanyi.TabWord); // memainkan lagu
            printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"", currentsong.nama.TabWord, currentsong.album.TabWord, currentsong.penyanyi.TabWord);
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
        if(currentsong.penyanyi.Length != 0 && currentsong.album.Length != 0 && currentsong.nama.Length != 0) Push(&r, currentsong);
        currentsong = song;
        printf("\nCURRENT SONG : \"%s\" di album \"%s\" oleh \"%s\"\n", currentsong.nama.TabWord, currentsong.album.TabWord, currentsong.penyanyi.TabWord);
        // displayQueueLagu(queueLagu);
        // displayRiwayat(&riwayat);
    }
}

void startSong()
{
    printf("====[ SELAMAT DATANG DI FUNGSI SONG ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("    1. SONG NEXT \n");
    printf("    2. SONG PREVIOUS \n");
    printf("    3. QUIT SONG \n");
    getCommandSong();
}
void getCommandSong()
{
    // KAMUS
    boolean state = true;
    while(state)
    {
        printf("> SILAHKAN MASUKAN COMMAND: ");
        Word command = GetInput();
        if (IsWordEq(toKata("SONG NEXT"), command))
        {
            songNext();
            state = true;
        } 
        else if(IsWordEq(toKata("SONG PREVIOUS"), command))
        {
            songPrevious();
            state = true;
        } 
        else if(IsWordEq(toKata("QUIT SONG"), command))
        {
            printf("\n>> Keluar dari Fungsi");
            state = false;
        } 
        else
        {
            printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG! \n");
        }
    }
}