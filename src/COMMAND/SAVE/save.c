#include "save.h"
void startSave(Word filesave) {
    FILE *fpointer;
    Word maindir;
    int jumlahPenyanyi, jumlahAlbum, jumlahLagu, jumlahDiQueue, jumlahDiRiwayat;
    int jumlahPlaylist, jumlahLaguPlaylist;
    char* namaPlaylist;
    maindir=toKata("../save/");
    // ubah variabel maindir jadi word dulu dan assign ke variabel baru
    // misalkan: maindirWord = wordToString(maindir);
    fpointer = fopen(wordToString(concatWord(maindir, AccessCommand(filesave,1))), "w"); 
    jumlahPenyanyi=l.Count;
    Word namaPenyanyi;
    Word namaAlbum;
    Word namaLagu;

    for (int i = 0; i < jumlahPenyanyi; i++)
    { namaPenyanyi=l.PenyanyiKe[i].InfoPenyanyi[i].Key;
        jumlahAlbum = l.PenyanyiKe[i].InfoPenyanyi[i].Value.Count;
        fprintf(fpointer, "%d %s \n", jumlahAlbum, namaPenyanyi.TabWord); 
        for (int j = 0; j < jumlahAlbum; j++)
        {
            namaAlbum=l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Key;
            jumlahLagu = l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.Count;
            fprintf(fpointer, "%d %s \n", jumlahLagu, namaAlbum.TabWord);
            for (int k = 0; k < jumlahLagu; k++)
            {
                namaLagu=l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].nama;
                fprintf(fpointer, "%s \n", namaLagu.TabWord);
            }
        }
    }
    namaPenyanyi=currentsong.penyanyi;
    namaAlbum=currentsong.album;
    namaLagu=currentsong.nama;
    fprintf(fpointer, "%s;%s;%s\n", namaPenyanyi.TabWord, namaAlbum.TabWord, namaLagu.TabWord);

    // jumlah lagu di queue
    jumlahDiQueue=lengthQueueLagu(q);
    fprintf(fpointer, "%d\n", jumlahDiQueue);
    ElTypeQueue lagudiqueue;
    for (int i = 0; i < jumlahDiQueue; i++)
    {
        dequeueLagu(&q, &lagudiqueue);
        fprintf(fpointer, "%s;%s;%s\n", lagudiqueue.penyanyi.TabWord, lagudiqueue.album.TabWord, lagudiqueue.nama.TabWord); 
    }

    // jumlah lagu di riwayat
    jumlahDiRiwayat=NbElmtStack(&r);
    infotypeStack lagudistack;
    fprintf(fpointer, "%d\n", jumlahDiRiwayat);
    for (int i = 0; i < jumlahDiRiwayat; i++)
    { 
        Pop(&r, &lagudistack);
        fprintf(fpointer, "%s;%s;%s\n", lagudistack.penyanyi.TabWord, lagudistack.album.TabWord, lagudistack.nama.TabWord);
    }

    // PLAYLIST
    jumlahPlaylist=LengthArrayDin(daftarPlaylist);
    fprintf(fpointer, "%d\n", jumlahPlaylist);
    Lagu laguPlaylist;
    for (int i = 0; i < jumlahPlaylist; i++)
    {
        namaPlaylist=daftarPlaylist.A[i].NamaPlaylist.TabWord;
        jumlahLaguPlaylist=0;
        alamat p=First(daftarPlaylist.A[i]);
        while(p!=Nil)
        {
            jumlahLaguPlaylist++;
            p=Next(p);
        }
        fprintf(fpointer, "%d %s\n", jumlahLaguPlaylist, namaPlaylist); 
        p=First(daftarPlaylist.A[i]);
        while(p!=Nil)
        {
            laguPlaylist=Info(p);
            p=Next(p);
            fprintf(fpointer, "%s;%s;%s\n", laguPlaylist.penyanyi.TabWord, laguPlaylist.album.TabWord, laguPlaylist.nama.TabWord);
        }
    }
    fclose(fpointer);
    printf("File berhasil disimpan!\n");
}