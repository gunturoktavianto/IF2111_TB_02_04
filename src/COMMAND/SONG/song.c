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
        }
    }

    else
    {
        dequeueLagu(&q, &song);
        // lagudiputars = lagudiputarq;
         // tadinya mikir lagu yang bakal diputar di tambahin ke riwayat
        if(currentsong.penyanyi.Length != 0 && currentsong.album.Length != 0 && currentsong.nama.Length != 0) Push(&r, currentsong);
        printf("Memutar lagu selanjutnya\n\"%s\" oleh \"%s\"\n", song.nama.TabWord, song.penyanyi.TabWord);
        currentsong = song;
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
        // printf("\ncurrent song length: %d\n",currentsong.penyanyi.Length );
        if(currentsong.penyanyi.Length == 0 && currentsong.album.Length == 0 && currentsong.nama.Length == 0)
        {
            printf(">> Riwayat lagu kamu kosong, dan tidak ada lagu yang dimainkan saat ini. Silahkan masukkan fungsi lain");
        }
        else
        {
            printf("Riwayat lagu kosong, memutar kembali lagu\n\"%s\" oleh \"%s\"\n", currentsong.nama.TabWord, currentsong.penyanyi.TabWord); // memainkan lagu
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
        // printf("%d\n",currentsong.nama.Length);
        // if(currentsong.penyanyi.Length != 0 && currentsong.album.Length != 0 && currentsong.nama.Length != 0){
        //     Push(&r, currentsong);}
        currentsong = song;
    }
}

void startSong()
{
    printf("====[ SELAMAT DATANG DI FUNGSI SONG ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("    1. SONG NEXT \n");
    printf("    2. SONG PREVIOUS \n");
    printf("    3. SONG QUIT \n");
    getCommandSong();
}
void getCommandSong()
{
    // KAMUS
    boolean state = true;
    while(state)
    {
        printf("\n> SILAHKAN MASUKAN COMMAND: ");
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
        else if(IsWordEq(toKata("SONG QUIT"), command))
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