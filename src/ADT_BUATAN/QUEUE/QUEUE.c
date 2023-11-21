//Ini masih blm lengkap semuanya dan ga tau apakah akan eror klo di jalanin ato ga (blm sempet bikin main.c)
#include "QUEUE.h"
#include <stdio.h>
// Fungsi untuk menambahkan lagu ke dalam queue

void startQueue(Queue *QueueLagu, ListPenyanyi P, ArrayDin L){
    printf("====[ SELAMAT DATANG DI FUNGSI QUEUE ]====\n");
    printf("----TERDAPAT 5 FUNGSI YANG BISA DIAKSES---- \n");
    printf("    1. QUEUE SONG \n");
    printf("    2. QUEUE PLAYLIST \n");
    printf("    3. QUEUE SWAP \n");
    printf("    4. QUEUE REMOVE \n");
    printf("    5. QUEUE CLEAR \n");
    printf("> SILAHKAN MASUKAN COMMAND: \n");
    Word input = GetInput();
    boolean state = false;
    while(!state){
        if (IsWordEq(input, toKata("QUEUE SONG"))){
            queueSong(QueueLagu,P);
            state = true;
        }
        else if (IsWordEq(input, toKata("QUEUE PLAYLIST"))){
            queuePlaylist(L, QueueLagu);
            state = true;
        }
        else if (IsWordEq(input, toKata("QUEUE SWAP"))){
            swapSongs(QueueLagu);
            state = true;
        }
        else if (IsWordEq(input, toKata("QUEUE REMOVE"))){
            removeSong(QueueLagu);
            state = true;
        }
        else if (IsWordEq(input, toKata("QUEUE CLEAR"))){
            clearQueue(QueueLagu);
            state = true;
        }
        else{
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    }

}
void queueSong(Queue *Q, ListPenyanyi P) {
    printf(">> QUEUE SONG;\n");
    int idx1,idx2;
    boolean found = false;
    Word penyanyi, album, lagu;
    Lagu lagu1;
    while(!found){
        printdaftarPenyanyi(&P);
        printf("Masukkan nama penyanyi : ");
        penyanyi = GetInput();
        printf("\n");
        address idx = 0;
        while ((idx < P.Count)&&(!found)) {
            if (IsWordEq(P.PenyanyiKe[idx].InfoPenyanyi[idx].Key, penyanyi )){
                idx1 = idx;
                found = true;
            }
            idx++;
        }
        if (!found){
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    }
    boolean found1 = false;
    while (!found1){
        PrintAlbum(P.PenyanyiKe[idx1].InfoPenyanyi[idx1].Value);
        printf("Masukkan Nama Album yang dipilih : ");
        album = GetInput();
        printf("\n");
        if (IsMemberAlbum(P.PenyanyiKe[idx1].InfoPenyanyi[idx1].Value, album)){
            found1 = true;
        }
        else{
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    }
    SetLagu setlagu = ValueAlbum(P.PenyanyiKe[idx1].InfoPenyanyi[idx1].Value, album);
    boolean found2 = false;
    while (!found2){
        PrintLagu(setlagu);
        printf("Masukkan index lagu yang dipilih : ");
        lagu = GetInput();
        int idxlagu = WordtoInt(lagu);
        if ((idxlagu < setlagu.Count) && (idxlagu> 0)){
            lagu1 = MakeLagu(lagu,album,penyanyi);
            printf("\n");
            if (IsMemberSetLagu(setlagu,lagu1)){
                enqueueLagu(Q, lagu1);
                found2 = true;
            }
            else{
                printf("Input Anda Salah. Silahkan mencoba kembali\n");
            }
        }
        else{
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    
    }
    printf("Berhasil menambahkan lagu “%s” oleh “%s” ke queue.\n", lagu1.nama.TabWord, lagu1.penyanyi.TabWord);

}


// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist(ArrayDin L, Queue *Q) {
    //soal input id dll itu masih blm kebayang
    printf(">> QUEUE PLAYLIST;\n");
    boolean found = false;
    while (!found){
        printf("Masukkan ID Playlist: ");
        Word kata = GetInput();
        int id=WordtoInt(kata);
        printf("\n");
        alamat P = First(L.A[id-1]); //Pake ADT Dilla
        if (P != Nil){
            while (P != Nil) {
                enqueueLagu(Q, P->infolagu);
                P = P->next;
            }
            printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", L.A[id-1].NamaPlaylist.TabWord); //ini msh aneh outputnya
            found = true;
        }
        else{
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    }
}

// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(Queue *Q) {
    printf(">> QUEUE SWAP;\n");
    boolean found = false;
    while (!found){
        printf("Masukkan index lagu pertama yang ingin dihapus dari queue : ");
        Word idx1 = GetInput();
        int x = WordtoInt(idx1);
        printf("Masukkan index lagu kedua yang ingin dihapus dari queue : ");
        Word idx2 = GetInput();
        int y = WordtoInt(idx2);
        if (x >= 1 && x <= lengthQueueLagu(*Q) && y >= 1 && y <= lengthQueueLagu(*Q)) {
            ElTypeQueue temp;
            int i;
            temp.nama.Length = Q->buffer[x-1].nama.Length;
            temp.album.Length = Q->buffer[x-1].album.Length;
            temp.penyanyi.Length = Q->buffer[x-1].penyanyi.Length;
            for (i = 0; i < temp.nama.Length; i++)
            {
                temp.nama.TabWord[i] = Q->buffer[x-1].nama.TabWord[i];
            }
            temp.nama.TabWord[temp.album.Length]='\0';
            for (i = 0; i < temp.album.Length; i++)
            {
                temp.album.TabWord[i] = Q->buffer[x-1].album.TabWord[i];
            }
            temp.album.TabWord[temp.album.Length]='\0';
            for (i = 0; i < temp.penyanyi.Length; i++)
            {
                temp.penyanyi.TabWord[i] = Q->buffer[x-1].penyanyi.TabWord[i];
            }
            temp.penyanyi.TabWord[temp.penyanyi.Length]='\0';
            Q->buffer[x-1].nama.Length = Q->buffer[y-1].nama.Length;
            Q->buffer[x-1].album.Length = Q->buffer[y-1].album.Length;
            Q->buffer[x-1].penyanyi.Length = Q->buffer[y-1].penyanyi.Length;
            for (i = 0; i < Q->buffer[x-1].nama.Length; i++)
            {
                Q->buffer[x-1].nama.TabWord[i] = Q->buffer[y-1].nama.TabWord[i];
            }
            Q->buffer[x-1].nama.TabWord[Q->buffer[x-1].nama.Length]='\0';
            for (i = 0; i < Q->buffer[x-1].album.Length; i++)
            {
                Q->buffer[x-1].album.TabWord[i] = Q->buffer[y-1].album.TabWord[i];
            }
            Q->buffer[x-1].album.TabWord[Q->buffer[x-1].album.Length]='\0';
            for (i = 0; i < Q->buffer[x-1].penyanyi.Length; i++)
            {
                Q->buffer[x-1].penyanyi.TabWord[i] = Q->buffer[y-1].penyanyi.TabWord[i];
            }
            Q->buffer[y-1].nama.Length = temp.nama.Length;
            Q->buffer[y-1].album.Length = temp.album.Length;
            Q->buffer[y-1].penyanyi.Length = temp.penyanyi.Length;
            for (i = 0; i < Q->buffer[y-1].nama.Length; i++)
            {
                Q->buffer[y-1].nama.TabWord[i] = temp.nama.TabWord[i];
            }
            Q->buffer[y-1].nama.TabWord[Q->buffer[y-1].nama.Length]='\0';
            for (i = 0; i < Q->buffer[y-1].album.Length; i++)
            {
                Q->buffer[y-1].album.TabWord[i] = temp.album.TabWord[i];
            }
            Q->buffer[y-1].album.TabWord[Q->buffer[y-1].album.Length]='\0';
            for (i = 0; i < Q->buffer[y-1].nama.Length; i++)
            {
                Q->buffer[y-1].penyanyi.TabWord[i] = temp.penyanyi.TabWord[i];
            }
            Q->buffer[y-1].penyanyi.TabWord[Q->buffer[y-1].penyanyi.Length]='\0';
            printf("Lagu %s berhasil ditukar dengan %s\n", Q->buffer[y-1].nama.TabWord, Q->buffer[x-1].nama.TabWord);
            found = true;
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
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    }
}

// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong(Queue *Q) {
    printf(">> QUEUE REMOVE;\n");
    boolean found = false;
    while (!found){
        printf("Masukkan id lagu yang ingin dihapus dari queue : ");
        Word id = GetInput();
        int songId = WordtoInt(id);
        printf("\n");
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
            found = true;
        }
        else{
            printf("Lagu dengan urutan ke %d tidak ada.\n", songId);
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    }
}

// Fungsi untuk mengosongkan queue
void clearQueue(Queue *Q) {
    printf(">> QUEUE CLEAR;\n");
    CreateQueueLagu(Q);
    printf("Queue berhasil dikosongkan.\n");
}
