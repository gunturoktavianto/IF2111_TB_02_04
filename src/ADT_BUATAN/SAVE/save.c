#include "stdio.h"
#include "save.h"
#include "../../ADT/MESINKATA/mesinkata.h"


void save() { //isi parameter sesuai variabel yang ada di bawah
    FILE *fpointer;
    char* maindir;
    Word format;
    int jumlahPenyanyi, jumlahAlbum, jumlahLagu, jumlahDiQueue, jumlahDiRiwayat;
    int jumlahPlaylist, jumlahLaguPlaylist;
    char* namaPenyanyi="BLACKPINK";
    char* namaAlbum="BORN PINK";
    char* namaLagu="Pink Venom";

    char* namaPlaylist="BLACKPINK My Top Three";
    char* namaPenyanyiPlaylist="BLACKPINK";
    char* namaAlbumPlaylist="THE ALBUM";
    char* namaLaguPlaylist="How You Like That";


    jumlahPenyanyi = 2;
    jumlahAlbum = 2;
    jumlahLagu = 4;
    jumlahDiQueue = 5;
    jumlahDiRiwayat = 2;
    jumlahPlaylist = 3;
    jumlahLaguPlaylist = 3;

    // ubah variabel maindir jadi word dulu dan assign ke variabel baru
    // misalkan: maindirWord = wordToString(maindir);
    maindir = "../../../save/";


    // seharusnya yang bener adalah:
    // fpointer = fopen(wordToString(concatWord(maindirWord, inputanNamaFile)), "w");
    // concatWord dan wordToString udah gue bikin di mesinkata
    fpointer = fopen("../../../save/save.txt", "w"); 
    fprintf(fpointer, "%d\n", jumlahPenyanyi);

    for (int i = 0; i < jumlahPenyanyi; i++)
    {
        fprintf(fpointer, "%d %s \n", jumlahAlbum, namaPenyanyi); 
        for (int j = 0; j < jumlahAlbum; j++)
        {
            fprintf(fpointer, "%d %s \n", jumlahLagu, namaAlbum);
            for (int k = 0; k < jumlahLagu; k++)
            {
                fprintf(fpointer, "%s \n", namaLagu);
            }
        }

    }
    // lagu yg sedang diputar
    fprintf(fpointer, "%s;%s;%s\n", namaPenyanyi, namaAlbum, namaLagu);

    // jumlah lagu di queue
    fprintf(fpointer, "%d\n", jumlahDiQueue);
    for (int i = 0; i < jumlahDiQueue; i++)
    {
        fprintf(fpointer, "%s;%s;%s\n", namaPenyanyi, namaAlbum, namaLagu); 
    }

    // jumlah lagu di riwayat
    fprintf(fpointer, "%d\n", jumlahDiRiwayat);
    for (int i = 0; i < jumlahDiRiwayat; i++)
    {
        fprintf(fpointer, "%s;%s;%s\n", namaPenyanyi, namaAlbum, namaLagu);
    }

    // PLAYLIST
    fprintf(fpointer, "%d\n", jumlahPlaylist);
    for (int i = 0; i < jumlahPlaylist; i++)
    {
        fprintf(fpointer, "%d %s\n", jumlahLaguPlaylist, namaPlaylist); 
        for (int j = 0; j < jumlahLaguPlaylist; j++)
        {
            fprintf(fpointer, "%s;%s;%s\n", namaPenyanyiPlaylist, namaAlbumPlaylist, namaLaguPlaylist);
        }
    }

    fclose(fpointer);
    
}

int main() {
    save();
    return 0;
}