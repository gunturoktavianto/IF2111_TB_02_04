#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void load()
{
    printf("Masukkan nama file yang ingin diload: ");
    Word file=GetInput();
    file.TabWord[file.Length]='.';
    file.TabWord[file.Length+1]='t';
    file.TabWord[file.Length+2]='x';
    file.TabWord[file.Length+3]='t';
    file.Length+=4;
    file.TabWord[file.Length+4]='\0';
    char dir[50] = "../../../save/";
    int i = 0;
    for (i=0; i<file.Length; i++)
    {
        dir[14+i]=file.TabWord[i];
    }
    dir[14 + i] = '\0';
    printf("%s",dir);
    int jumlahLaguQueue, jumlahLaguRiwayat, jumlahPlaylist, jumlahLaguPlaylist ;
    FILE *input =fopen(dir,"r");
    if (input == NULL) printf("File tidak ditemukan. ");
    else
    {
        STARTWORD(input);
        ADVWORD();
        l.Count=WordtoInt(currentWord);
        nextLine();
        for (int i=0; i<l.Count; i++)
        {
            ADVWORD();
            l.PenyanyiKe[i].Count=l.Count;
            l.PenyanyiKe[i].InfoPenyanyi[i].Value.Count=WordtoInt(currentWord);
            l.PenyanyiKe[i].InfoPenyanyi[i].Key =GetWords();
            nextLine();
            for (int j=0; j<l.PenyanyiKe[i].InfoPenyanyi[i].Value.Count; j++)
            {
                ADVWORD();
                l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.Count=WordtoInt(currentWord);//4
                l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Key=GetWords();//BORN PINK
                nextLine();
                int jumlahLagu=l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.Count;
                for(int k=0; k<jumlahLagu; k++)
                {
                    Word w=GetWords();
                    l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].nama=w;
                    l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].album=l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Key;
                    l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].penyanyi=l.PenyanyiKe[i].InfoPenyanyi[i].Key;
                    nextLine();
                }
            }
        }
        nextLine();
        STARTWORDLOAD(input);
        Word penyanyiSekarang, albumSekarang, laguSekarang;
        Word penyanyiQueue, albumQueue, laguQueue;
        Word penyanyiRiwayat, albumRiwayat, laguRiwayat;
        Word penyanyiPlaylist, albumPlaylist, laguPlaylist;
        Word namaPlaylist;
        penyanyiSekarang = currentWord;
        ADVWORDLOAD();
        albumSekarang = currentWord;
        ADVWORDLOAD();
        laguSekarang = currentWord;
        currentsong= MakeLagu(penyanyiSekarang, albumSekarang, laguSekarang);
        ADVWORD();
        jumlahLaguQueue = WordtoInt(currentWord); //Jumlah record lagu dalam queue
        nextLine();
        
        //record lagu dalam queue
        for (int i = 0; i<jumlahLaguQueue; i++){
            ADVWORDLOAD();
            penyanyiQueue = currentWord;
            ADVWORDLOAD();
            albumQueue = currentWord;
            ADVWORDLOAD();
            laguQueue = currentWord;
            enqueueLagu(&q, MakeLagu(penyanyiQueue, albumQueue, laguQueue));
        }

        ADVWORD();
        jumlahLaguRiwayat = WordtoInt(currentWord); //Jumlah record lagu dalam riwayat
        nextLine();

        // record lagu dalam riwayat
        for (int i = 0; i<jumlahLaguRiwayat; i++){
            ADVWORDLOAD();
            penyanyiRiwayat = currentWord;
            
            ADVWORDLOAD();
            albumRiwayat = currentWord;

            ADVWORDLOAD();
            laguRiwayat = currentWord;

            Push(&r, MakeLagu(penyanyiRiwayat, albumRiwayat, laguRiwayat));
        }

        ADVWORD();
        jumlahPlaylist = WordtoInt(currentWord); //Jumlah playlist
        nextLine();
        for (int i=0; i<jumlahPlaylist; i++){
            ADVWORD();
            jumlahLaguPlaylist = WordtoInt(currentWord);
            ADVWORDLOAD();
            namaPlaylist = currentWord;
            List PlaylistRiwayat;
            CreateEmptyPlaylist(namaPlaylist, &PlaylistRiwayat);
            InsertAtArrayDin(&daftarPlaylist, PlaylistRiwayat, LengthArrayDin(daftarPlaylist));
            for (int j=0; j<jumlahLaguPlaylist; j++){
                ADVWORDLOAD();
                penyanyiRiwayat = currentWord;
                ADVWORDLOAD();
                albumRiwayat = currentWord;
                ADVWORDLOAD();
                laguRiwayat = currentWord;
                InsVLast(&daftarPlaylist.A[j], MakeLagu(penyanyiRiwayat, albumRiwayat, laguRiwayat));
            }
        }
    }
}