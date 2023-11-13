#include <stdio.h>
#include "queue.h"
#include "map.h"
#include "list.h"
#include "boolean.h"
#include "listlinier.h"


// Fungsi untuk menambahkan lagu ke dalam queue
void queueSong(Queue *Q, List Song) {
    printf("Daftar Penyanyi :\n");
    for(int i = FirstIdx(Song); i <= LastIdx(Song); i++){
        printf("%d. %s\n", i+1, char(Song[i]));
    }
    printf("Masukkan nama penyanyi : ");
    ADVWORD();
    printf("\n");
    boolean found = false;
    for(int i = FirstIdx(Song); i <= LastIdx(Song); i++){
        if (char(Song[i]) == currentWord){
            int idx = i;
            found = true;
        }
        //belum kepikiran mo bikin kondisi elsenya mo gimana
    }
    if (found){
        printf("Daftar Album oleh %s :\n", char(Song[idx]));
        for(int i = 0; i < Song[idx].Count; i++){
            printf("    %d. %s\n", Song[idx].Elements[i].Key, char(Song[idx].Elements[i].Value));
        }
    }
    printf("Masukkan Nama Album yang dipilih : ");
    ADVWORD();
    printf("\n");
    boolean found1 = false;
    for(int i = 0; i < Song[idx].Count; i++){
        if (Song[idx].Elements[i].Value == currentWord){
            int idx1 = i;
            found1 = true;
        }
        //belum kepikiran mo bikin kondisi elsenya mo gimana
    }
    if (found1){
        printf("Daftar Lagu Album %s oleh %s :\n", Song[idx].Elements[idx1].Value, char(Song[idx]));
        for(int i = 0; i < Song[idx].Elements[idx1].Lagu.Count; i++){
            printf("    %d. %s\n", i+1, char(Song[idx].Elements[idx1].Lagu.Elements[i].lagu));
        }
    }
    printf("Masukkan ID Lagu yang dipilih: ");
    ADVWORD();
    printf("\n");
    for(int i = 0; i < Song[idx].Elements[idx1].Lagu.Count; i++){
        if ((char(Song[idx].Elements[idx1].Lagu.Elements[i].lagu)) == char(Song[idx].Elements[idx1].Lagu.Elements[int(currentWord)].lagu)){
            enqueue(Q,Song[idx].Elements[idx1].Lagu.Elements[i].lagu);
            printf("Berhasil menambahkan lagu “%s” oleh “%s” ke queue.", Song[idx].Elements[idx1].Lagu.Elements[i].lagu, Song[i]);
        }
    }
}

// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist(ListLL Playlist, Queue *Q) {
    //soal input id dll itu masih blm kebayang
    address P = First(*Playlist);
    boolean found = false;
    while (P != Nil) && (!found){
        enqueue(Q, P->info);
        P = P->next;
    }
    printf("Berhasil menambahkan playlist “%s” ke queue.", char(Playlist));
}

// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(int x, int y, Queue *Q) {
    if (x >= 1 && x <= Length(*Q) && y >= 1 && y <= Length(*Q)) {
        char temp[] = Q->Tab[x];
        Q->Tab[x] = Q->Tab[y];
        Q->Tab[y] = temp;
        printf("Lagu %s berhasil ditukar dengan %s\n", Q->Tab[y], Q->Tab[x]);
    } else {
        if ((x < 1 || x > Length(*Q)) && y >= 1 && y <= Length(*Q)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        }
        else if (x >= 1 && x <= Length(*Q) && (y < 1 || y > Length(*Q))){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        }
        else if ((x < 1 || x > Length(*Q)) && (y < 1 || y > Length(*Q))){
            printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", y, x );
        }
    }
}

// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(int songId, Queue *Q, Map Song) {
    if (songId >= 1 && songId <= Length(*Q)) { //Nanti dibwhnya bikin loop bistu bikin kondisi yang menyakan if Q->Tab[songId] == Song.Elements[i].keytype then
        for (int i = 0; i<MaxElMap;i++){
            for(int j = 0; j<Song.Count;j++){
                for(int k = 0; k<MaxEl;k++){
                    if ((Song[i].Elements[j].Lagu.Elements[k].lagu) == queue.buffer[songId]){
                        printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", queue.Tab[songId], char(Song[i]));
                        Queue temp;
                        CreateQueue(*temp);
                        ElTypeQueue  val;
                        dequeue(*Q, *val);
                        enqueue(*temp, val);
                        while (val != queue.Tab[songId]){
                            dequeue(*Q, *val);
                            enqueue(*temp, val);
                        }
                        dequeue(*Q, *val);
                        enqueue(*temp, val);
                        dequeue(*temp,val);
                        while (!isEmptyQueue(temp)){
                            dequeue(*temp, *val);
                            enqueue(*Q, val);
                        }
                        return;
                    }
                }
            }
        }
    }
    printf("Lagu dengan urutan ke %d tidak ada.\n", songId);
}

// Fungsi untuk mengosongkan queue
void clearQueue(Queue *Q) {
    CreateQueue(Q);
    printf("Queue berhasil dikosongkan.\n");
}
