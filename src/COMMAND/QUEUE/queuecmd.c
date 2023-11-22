#include "queuecmd.h"


// Fungsi untuk menambahkan lagu ke dalam queue
void getCommandQueue()
{
    printf("> SILAHKAN MASUKAN COMMAND: ");
    boolean state=false;
    while(!state)
    {
        Word command=GetInput();
        if(IsWordEq(command, toKata("QUEUE SONG"))) {queueSong(); state=true;}
        else if(IsWordEq(command, toKata("QUEUE PLAYLIST"))) {queuePlaylist(); state=true;}
        else if(IsWordEq(command,toKata("QUEUE SWAP"))) {swapSongs(); state=true;}
        else if(IsWordEq(command,toKata("QUEUE REMOVE"))) {removeSong(); state=true;}
        else if(IsWordEq(command,toKata("QUEUE CLEAR"))) {clearQueue(); state=true;}
        else if (IsWordEq(command,toKata("QUEUE QUIT"))) {state=false;}
        else printf("Invalid command. Silahkan masukkan command kembali.\n> SILAHKAN MASUKAN COMMAND: ");   
    }
}

void startQueue()
{
    printf("====[ SELAMAT DATANG DI FUNGSI PLAYLIST ]====\n");
    printf("----TERDAPAT LIMA FUNGSI YANG BISA DIAKSES---- \n");
    printf("1. QUEUE SONG -> untuk menambahkan lagu ke dalam queue\n");
    printf("2. QUEUE PLAYLIST -> untuk menambahkan lagu yang ada dalam playlist ke dalam queue\n");
    printf("3. QUEUE SWAP -> untuk menukar lagu pada urutan ke x dan juga urutan ke y\n");
    printf("4. QUEUE REMOVE -> untuk menghapus lagu dari queue\n");
    printf("5. QUEUE CLEAR -> untuk mengosongkan queue\n");
    printf("6. QUEUE QUIT -> untuk keluar dari fungsi queue\n");
    getCommandQueue();
}
void queueSong() {
    printf(">> QUEUE SONG;\n");
    // menampilkan penyanyi, disimpan dalam ADT penyanyi, berperan juga sebagai key
    int i=0;
    printf("Daftar Penyanyi :\n");
    while(i<l.Count){
        printf("  %d. %s\n", i+1, l.PenyanyiKe[i].InfoPenyanyi[i].Key.TabWord);
        i++;
    } i=0;

    // mencari penyanyi
    infotypePenyanyi namapenyanyi;
    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    namapenyanyi.Key = GetInput();
    while(!IsMemberListPenyanyi(&l, namapenyanyi)){
        printf("Nama Penyanyi tidak ditemukan.\n");
        printf("\nMasukkan Nama Penyanyi yang dipilih : ");
        namapenyanyi.Key = GetInput();
    }   int idxp = IdxPenyanyi(&l, namapenyanyi.Key);

    // menampilkan album dari penyanyi X, disimpan dalam ADT map
    printf("Daftar Album oleh %s :\n", namapenyanyi.Key.TabWord);
    while(i<l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.Count){
        printf("  %d. %s\n", i+1, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[i].Key.TabWord);
        i++;
    } i=0;

    // mencari album
    infotypeAlbum namaalbum;
    printf("\nMasukkan Nama Album yang dipilih : ");
    namaalbum.Key = GetInput();
    while(!IsMemberAlbum(l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value, namaalbum.Key)){
        printf("Nama Album tidak ditemukan.\n");
        printf("\nMasukkan Nama Album yang dipilih : ");
        namaalbum.Key = GetInput();
    }   int idxa = IdxAlbum(&l, idxp, namaalbum.Key);

    // menampilkan lagu dari album X, disimpan dalam ADT set
    printf("Daftar Lagu Album %s oleh %s :\n", namaalbum.Key.TabWord, namapenyanyi.Key.TabWord);
    while(i<l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.Count){
        printf("  %d. %s\n", i+1, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[i].nama.TabWord);
        i++;
    } i=0;

    // mencari lagu
    printf("\nMasukkan ID Lagu yang dipilih : ");
    int idxl = WordtoInt(GetInput());
    while(idxl > l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.Count && idxl < 0 ){
        printf("Nama ID Lagu tidak ditemukan.\n");
        printf("\nMasukkan ID Lagu  yang dipilih : ");
        idxl = WordtoInt(GetInput());
    }   /*int idxl = IdxLagu(&l, idxp, idxa, namalagu.nama);*/

    enqueueLagu(&q, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl]);

    /* Final State */
    printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl].nama.TabWord, namapenyanyi.Key.TabWord);
}


// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist() {
    printf(">> QUEUE PLAYLIST;\n");
    printf("Masukkan ID Playlist: ");
    Word kata = GetInput();
    int id=WordtoInt(kata);
    while ((id> LengthArrayDin(daftarPlaylist)) && (id < 1)){
        printf("Input Id salah. Silahkan mencoba kembali\n");
        printf("Masukkan ID Playlist: ");
        Word kata = GetInput();
        int id=WordtoInt(kata);
    }
    printf("\n");
    alamat P = First(daftarPlaylist.A[id-1]); //Pake ADT Dilla
    if (P != Nil){
        while (P != Nil) {
            enqueueLagu(&q, P->infolagu);
            P = P->next;
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", daftarPlaylist.A[id-1].NamaPlaylist.TabWord); 
    }
    else{
        printf("Playlist kosong. Tidak ada lagu dari playlist yang ditambahkan ke dalam queue\n");
    }
    getCommandQueue();
}

// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs() {
    printf(">> QUEUE SWAP;\n");
    boolean found = false;
    while (!found){
        printf("Masukkan index lagu pertama yang ingin dihapus dari queue : ");
        Word idx1 = GetInput();
        int x = WordtoInt(idx1);
        printf("Masukkan index lagu kedua yang ingin dihapus dari queue : ");
        Word idx2 = GetInput();
        int y = WordtoInt(idx2);
        if (x >= 1 && x <= lengthQueueLagu(q) && y >= 1 && y <= lengthQueueLagu(q)) {
            ElTypeQueue temp;
            int i;
            temp.nama.Length = q.buffer[x-1].nama.Length;
            temp.album.Length = q.buffer[x-1].album.Length;
            temp.penyanyi.Length = q.buffer[x-1].penyanyi.Length;
            for (i = 0; i < temp.nama.Length; i++)
            {
                temp.nama.TabWord[i] = q.buffer[x-1].nama.TabWord[i];
            }
            temp.nama.TabWord[temp.album.Length]='\0';
            for (i = 0; i < temp.album.Length; i++)
            {
                temp.album.TabWord[i] = q.buffer[x-1].album.TabWord[i];
            }
            temp.album.TabWord[temp.album.Length]='\0';
            for (i = 0; i < temp.penyanyi.Length; i++)
            {
                temp.penyanyi.TabWord[i] = q.buffer[x-1].penyanyi.TabWord[i];
            }
            temp.penyanyi.TabWord[temp.penyanyi.Length]='\0';
            q.buffer[x-1].nama.Length = q.buffer[y-1].nama.Length;
            q.buffer[x-1].album.Length = q.buffer[y-1].album.Length;
            q.buffer[x-1].penyanyi.Length = q.buffer[y-1].penyanyi.Length;
            for (i = 0; i < q.buffer[x-1].nama.Length; i++)
            {
                q.buffer[x-1].nama.TabWord[i] = q.buffer[y-1].nama.TabWord[i];
            }
            q.buffer[x-1].nama.TabWord[q.buffer[x-1].nama.Length]='\0';
            for (i = 0; i < q.buffer[x-1].album.Length; i++)
            {
                q.buffer[x-1].album.TabWord[i] = q.buffer[y-1].album.TabWord[i];
            }
            q.buffer[x-1].album.TabWord[q.buffer[x-1].album.Length]='\0';
            for (i = 0; i < q.buffer[x-1].penyanyi.Length; i++)
            {
                q.buffer[x-1].penyanyi.TabWord[i] = q.buffer[y-1].penyanyi.TabWord[i];
            }
            q.buffer[y-1].nama.Length = temp.nama.Length;
            q.buffer[y-1].album.Length = temp.album.Length;
            q.buffer[y-1].penyanyi.Length = temp.penyanyi.Length;
            for (i = 0; i < q.buffer[y-1].nama.Length; i++)
            {
                q.buffer[y-1].nama.TabWord[i] = temp.nama.TabWord[i];
            }
            q.buffer[y-1].nama.TabWord[q.buffer[y-1].nama.Length]='\0';
            for (i = 0; i < q.buffer[y-1].album.Length; i++)
            {
                q.buffer[y-1].album.TabWord[i] = temp.album.TabWord[i];
            }
            q.buffer[y-1].album.TabWord[q.buffer[y-1].album.Length]='\0';
            for (i = 0; i < q.buffer[y-1].nama.Length; i++)
            {
                q.buffer[y-1].penyanyi.TabWord[i] = temp.penyanyi.TabWord[i];
            }
            q.buffer[y-1].penyanyi.TabWord[q.buffer[y-1].penyanyi.Length]='\0';
            printf("Lagu %s berhasil ditukar dengan %s\n", q.buffer[y-1].nama.TabWord, q.buffer[x-1].nama.TabWord);
            found = true;
        } else {
            if ((x < 1 || x > lengthQueueLagu(q)) && y >= 1 && y <= lengthQueueLagu(q)){
                printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
            }
            else if (x >= 1 && x <= lengthQueueLagu(q) && (y < 1 || y > lengthQueueLagu(q))){
                printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
            }
            else if ((x < 1 || x > lengthQueueLagu(q)) && (y < 1 || y > lengthQueueLagu(q))){
                printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", y, x );
            }
            printf("Input Anda Salah. Silahkan mencoba kembali\n");
        }
    }
}

// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong() {
    printf(">> QUEUE REMOVE;\n");
    boolean found = false;
    while (!found){
        printf("Masukkan id lagu yang ingin dihapus dari queue : ");
        Word id = GetInput();
        int songId = WordtoInt(id);
        printf("\n");
        if (songId >= 1 && songId <= lengthQueueLagu(q)) { //Nanti dibwhnya bikin loop bistu bikin kondisi yang menyakan if q.Tab[songId] == Song.Elements[i].keytype then
            printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", q.buffer[songId-1].nama.TabWord, q.buffer[songId-1].penyanyi.TabWord);
            Queuelagu temp;
            CreateQueueLagu(&temp);
            ElTypeQueue  val;
            dequeueLagu(&q, &val);
            enqueueLagu(&temp, val);
            while (!isInQueueLagu(temp,q.buffer[songId-1])){
                dequeueLagu(&q, &val);
                enqueueLagu(&temp, val);
            }
            dequeueLagu(&temp,&val);
            while (!isEmptyQueueLagu(temp)){
                dequeueLagu(&temp, &val);
                enqueueLagu(&q, val);
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
void clearQueue() {
    printf(">> QUEUE CLEAR;\n");
    CreateQueueLagu(&q);
    printf("Queue berhasil dikosongkan.\n");
}