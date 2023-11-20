#include <stdio.h>
#include <stdlib.h>
#include "load.h"



void displayWord(Word W)
{
    for(int i=0;i<W.Length;i++)
    {
        printf("%c",W.TabWord[i]);
    };
}

//file: load.txt
void load()
{
    int jumlahLaguQueue, jumlahLaguRiwayat, jumlahPlaylist, jumlahLaguPlaylist ;
    FILE *input =fopen("load.txt","r");
    STARTWORDLOAD(input);
    Word penyanyiSekarang, albumSekarang, laguSekarang;
    Word penyanyiQueue, albumQueue, laguQueue;
    Word penyanyiRiwayat, albumRiwayat, laguRiwayat;
    Word penyanyiPlaylist, albumPlaylist, laguPlaylist;
    Word namaPlaylist;

    penyanyiSekarang = currentWord;
    displayWord(penyanyiSekarang);
    printf("\n");
    ADVWORDLOAD();
    albumSekarang = currentWord;
    displayWord(albumSekarang);
    printf("\n");
    ADVWORDLOAD();
    laguSekarang = currentWord;
    displayWord(laguSekarang);
    printf("\n");
    ADVWORD();
    jumlahLaguQueue = WordtoInt(currentWord); //Jumlah record lagu dalam queue
    printf("%d", jumlahLaguQueue);
    printf("\n");
    nextLine();
    
    //record lagu dalam queue
    for (int i = 0; i<jumlahLaguQueue; i++){
        printf("Record queue ke %d", i+1);
        printf("\n");
        ADVWORDLOAD();
        penyanyiQueue = currentWord;
        displayWord(penyanyiQueue);
        printf("\n");
        ADVWORDLOAD();
        albumQueue = currentWord;
        displayWord(albumQueue);
        printf("\n");
        ADVWORDLOAD();
        laguQueue = currentWord;
        displayWord(laguQueue);
        printf("\n");
        printf("\n");
    }

    ADVWORD();
    jumlahLaguRiwayat = WordtoInt(currentWord); //Jumlah record lagu dalam riwayat
    printf("%d\n", jumlahLaguRiwayat);
    nextLine();

    // record lagu dalam riwayat
    for (int i = 0; i<jumlahLaguRiwayat; i++){
        printf("Record queue ke %d", i+1);
        printf("\n");
        ADVWORDLOAD();
        penyanyiRiwayat = currentWord;
        displayWord(penyanyiRiwayat);
        printf("\n");
        ADVWORDLOAD();
        albumRiwayat = currentWord;
        displayWord(albumRiwayat);
        printf("\n");
        ADVWORDLOAD();
        laguRiwayat = currentWord;
        displayWord(laguRiwayat);
        printf("\n");
        printf("\n");
    }

    ADVWORD();
    jumlahPlaylist = WordtoInt(currentWord); //Jumlah playlist
    printf("%d\n", jumlahPlaylist);
    nextLine();
    for (int i=0; i<jumlahPlaylist; i++){
        ADVWORD();
        jumlahLaguPlaylist = WordtoInt(currentWord);
        printf("%d\n", jumlahLaguPlaylist);
        ADVWORDLOAD();
        namaPlaylist = currentWord;
        displayWord(namaPlaylist);
        printf("\n");

        for (int j=0; j<jumlahLaguPlaylist; j++){
            printf("Playlist ke %d record ke %d", i+1, j+1);
            printf("\n");
            ADVWORDLOAD();
            penyanyiRiwayat = currentWord;
            displayWord(penyanyiRiwayat);
            printf("\n");
            ADVWORDLOAD();
            albumRiwayat = currentWord;
            displayWord(albumRiwayat);
            printf("\n");
            ADVWORDLOAD();
            laguRiwayat = currentWord;
            displayWord(laguRiwayat);
            printf("\n");
            printf("\n");       
        }
    
    }
    



}


int main(){
    load();
    return 0;
}