//Ini masih blm lengkap semuanya dan ga tau apakah akan eror klo di jalanin ato ga (blm sempet bikin main.c)
#include "queue.h"
// Fungsi untuk menambahkan lagu ke dalam queue
/*
void queueSong(Queue *Q, ListPenyanyi P) {
    printf("Daftar Penyanyi :\n");
    int i = 0;
    while(P.PenyanyiKe[i].InfoPenyanyi[i].Key != Mark){
        printf("  %d. %d\n", i+1, P.PenyanyiKe[i].InfoPenyanyi[i].Key);
        i++;
    }
    printf("Masukkan nama penyanyi : ");
    STARTWORD(stdin);
    printf("\n");
    boolean found = false;
    if (IsEqual(currentChar, ))
    while(P.PenyanyiKe[i].InfoPenyanyi[i].Key != Mark){
        printf("  %d. %d\n", i+1, P.PenyanyiKe[i].InfoPenyanyi[i].Key);
        i++;
    }
    for(int i = FirstIdxList(Song); i <= LastIdxList(Song); i++){
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
    STARTWORD(stdin);
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
    STARTWORD(stdin);;
    printf("\n");
    for(int i = 0; i < Song[idx].Elements[idx1].Lagu.Count; i++){
        if ((char(Song[idx].Elements[idx1].Lagu.Elements[i].lagu)) == char(Song[idx].Elements[idx1].Lagu.Elements[int(currentWord)].lagu)){
            enqueueQueue(Q,Song[idx].Elements[idx1].Lagu.Elements[i].lagu);
            printf("Berhasil menambahkan lagu “%s” oleh “%s” ke queue.", Song[idx].Elements[idx1].Lagu.Elements[i].lagu, Song[i]);
        }
    }
}
*/

// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist(ArrayDin L, Queue *Q) {
    //soal input id dll itu masih blm kebayang
    printf("Masukkan ID Playlist: ");
    GetInput();
    int id=WordtoInt(currentWord);
    printf("\n");
    alamat P = First(L.A[id-1]); //Pake ADT Dilla
    while (P != Nil) {
        enqueueLagu(Q, P->infolagu);
        P = P->next;
    }
    printf("Berhasil menambahkan playlist “%s” ke queue.\n", L.A[id-1].NamaPlaylist.TabWord);
}

// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(int x, int y, Queue *Q) {
    if (x >= 1 && x <= lengthQueueLagu(*Q) && y >= 1 && y <= lengthQueueLagu(*Q)) {
        ElTypeQueue temp = Q->buffer[x-1];
        Q->buffer[x-1] = Q->buffer[y-1];
        Q->buffer[y-1] = temp;
        printf("Lagu %s berhasil ditukar dengan %s\n", Q->buffer[y].nama.TabWord, Q->buffer[x].nama.TabWord);
    } else {
        if ((x < 1 || x > lengthQueueLagu(*Q)) && y >= 1 && y <= lengthQueueLagu(*Q)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        }
        else if (x >= 1 && x <= lengthQueueLagu(*Q) && (y < 1 || y > lengthQueueLagu(*Q))){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        }
        else if ((x < 1 || x > lengthQueueLagu(*Q)) && (y < 1 || y > lengthQueueLagu(*Q))){
            printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", y, x );
        }
    }
}

// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(int songId, Queue *Q) {
    if (songId >= 1 && songId <= lengthQueueLagu(*Q)) { //Nanti dibwhnya bikin loop bistu bikin kondisi yang menyakan if Q->Tab[songId] == Song.Elements[i].keytype then
        printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", Q->buffer[songId-1].nama.TabWord, Q->buffer[songId-1].penyanyi.TabWord);
        Queue temp;
        CreateQueueLagu(&temp);
        ElTypeQueue  val;
        dequeueLagu(Q, &val);
        enqueueLagu(&temp, val);
        while (!isInQueueLagu(temp,Q->buffer[songId-1])){
            dequeueLagu(Q, &val);
            enqueueLagu(&temp, val);
        }
        dequeueLagu(&temp,&val);
        while (!isEmptyQueueLagu(temp)){
            dequeueLagu(&temp, &val);
            enqueueLagu(Q, val);
        }
        
    }
    else{
        printf("Lagu dengan urutan ke %d tidak ada.\n", songId);
    }
}

// Fungsi untuk mengosongkan queue
void clearQueue(Queue *Q) {
    CreateQueueLagu(Q);
    printf("Queue berhasil dikosongkan.\n");
}