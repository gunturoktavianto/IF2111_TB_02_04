#include "save.h"
void startSave() { //isi parameter sesuai variabel yang ada di bawah
    printf("Masukkan nama file save :");
    Word filesave=GetInput();
    FILE *fpointer;
    Word maindir;
    Word format;
    int jumlahPenyanyi, jumlahAlbum, jumlahLagu, jumlahDiQueue, jumlahDiRiwayat;
    int jumlahPlaylist, jumlahLaguPlaylist;
    Word namaPenyanyi;
    Word namaAlbum;
    Word namaLagu;

    char* namaPlaylist="BLACKPINK My Top Three";
    char* namaPenyanyiPlaylist="BLACKPINK";
    char* namaAlbumPlaylist="THE ALBUM";
    char* namaLaguPlaylist="How You Like That";

    jumlahDiQueue = 5;
    jumlahDiRiwayat = 2;
    jumlahPlaylist = 3;
    jumlahLaguPlaylist = 3;

    // ubah variabel maindir jadi word dulu dan assign ke variabel baru
    // misalkan: maindirWord = wordToString(maindir);
    maindir=toKata("../../../save/");
    

    // seharusnya yang bener adalah:
    // fpointer = fopen(wordToString(concatWord(maindirWord, inputanNamaFile)), "w");
    // concatWord dan wordToString udah gue bikin di mesinkata
    fpointer = fopen("../../../save/save.txt", "w"); 
    fprintf(fpointer, "%d\n", jumlahPenyanyi);

    jumlahPenyanyi=l.Count;
    for (int i = 0; i < jumlahPenyanyi; i++)
    {
        jumlahAlbum = l.PenyanyiKe[i].InfoPenyanyi[i].Value.Count;
        fprintf(fpointer, "%d %s \n", jumlahAlbum, namaPenyanyi); 
        for (int j = 0; j < jumlahAlbum; j++)
        {
            jumlahLagu = l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.Count;
            fprintf(fpointer, "%d %s \n", jumlahLagu, namaAlbum);
            for (int k = 0; k < jumlahLagu; k++)
            {
                namaLagu=l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].nama;
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