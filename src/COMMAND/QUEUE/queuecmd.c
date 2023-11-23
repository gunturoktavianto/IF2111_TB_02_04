#include "queuecmd.h"


// Fungsi untuk menambahkan lagu ke dalam queue
void getCommandQueue()
{
    boolean state=true;
    while(state)
    {
        printf("> SILAHKAN MASUKAN COMMAND: ");
        Word command=GetInput();
        if(IsWordEq(command, toKata("QUEUE SONG"))) {queueSong(); state=true;}
        else if(IsWordEq(command, toKata("QUEUE PLAYLIST"))) {queuePlaylist(); state=true;}
        else if(IsWordEq(AccessCommand(command,0),toKata("QUEUE")) && IsWordEq(AccessCommand(command,1),toKata("SWAP"))) {swapSongs(command); state=true;}
        else if(IsWordEq(command,toKata("QUEUE REMOVE"))) {removeSong(); state=true;}
        else if(IsWordEq(command,toKata("QUEUE CLEAR"))) {clearQueue(); state=true;}
        else if (IsWordEq(command,toKata("QUEUE QUIT"))) {state=false;}
        else printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG!\n");   
    }
}

void startQueue()
{
    printf("====[ SELAMAT DATANG DI FUNGSI QUEUE ]====\n");
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
    // menampilkan penyanyi, disimpan dalam ADT penyanyi, berperan juga sebagai key
    int i=0;
    printf("\nDaftar Penyanyi :\n");
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
    Word idlagu = GetInput();
    int idxl;
    boolean valid = false;
    while(!valid){
        if (IsWordNumber(idlagu)){
            idxl = WordtoInt(idlagu);
            if (idxl>0 && idxl<=l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.Count){valid = true;}
            else{
                printf("Nama ID Lagu tidak ditemukan.\n");
                printf("\nMasukkan ID Lagu  yang dipilih : ");
                idlagu = GetInput();
            }
        }
        else{
            printf("Nama ID Lagu tidak ditemukan.\n");
            printf("\nMasukkan ID Lagu  yang dipilih : ");
            idlagu = GetInput();
        }
    }

    enqueueLagu(&q, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1]);

    /* Final State */
    printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1].nama.TabWord, namapenyanyi.Key.TabWord);
}


// Fungsi untuk menambahkan playlist ke dalam queue
void queuePlaylist() {
    printf("\nDaftar Playlist Pengguna :\n");
    DisplayDaftarPlaylist(daftarPlaylist);
    printf("Masukkan ID Playlist: ");
    Word kata = GetInput();
    int idxpl;
    boolean valid = false; 
    while(!valid){
        if (IsWordNumber(kata)){
            idxpl = WordtoInt(kata);
            if (idxpl>0 && idxpl <= LengthArrayDin(daftarPlaylist)){valid = true;}
            else{
                printf("Input Id salah. Silahkan mencoba kembali\n");
            printf("Masukkan ID Playlist: ");
                kata = GetInput();
            }
        }
        else{
            printf("Input Id salah. Silahkan mencoba kembali\n");
            printf("Masukkan ID Playlist: ");
            kata = GetInput();
        }
    }
    printf("\n");
    alamat P = First(daftarPlaylist.A[idxpl-1]); //Pake ADT Dilla
    if (P != Nil){
        while (P != Nil) {
            enqueueLagu(&q, P->infolagu);
            P = P->next;
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", daftarPlaylist.A[idxpl-1].NamaPlaylist.TabWord); 
    }
    else{
        printf("Playlist kosong. Tidak ada lagu dari playlist yang ditambahkan ke dalam queue\n");
    }
    getCommandQueue();
}

// Fungsi untuk menukar lagu pada urutan x dan y dalam queue
void swapSongs(Word command) {
    int x, y;
    Word idx1, idx2;
    idx1 = AccessCommand(command,2);
    idx2 = AccessCommand(command,3);
    boolean valid = false;
    while(!valid){
        if(IsWordNumber(idx1)){
            x = WordtoInt(idx1);
            if(x > 0 && x <= lengthQueueLagu(q)){
                if(IsWordNumber(idx2)){
                    y = WordtoInt(idx2);
                    if((y > 0 && y <= lengthQueueLagu(q)) && y != x){
                        valid = true;
                        break;
                    }
                    else{
                    printf("index invalid.\n");
                    printf("Masukkan index lagu kedua yang ingin dihapus dari queue : ");
                    idx2 = GetInput();
                    }
                }
                else{
                    printf("index invalid.\n");
                    printf("Masukkan index lagu kedua yang ingin dihapus dari queue : ");
                    idx2 = GetInput();
                }
            }
            else{
                printf("index invalid.\n");
                printf("Masukkan index lagu pertama yang ingin dihapus dari queue : ");
                idx1 = GetInput();
            }
        }
        else{
            printf("index invalid.\n");
            printf("Masukkan index lagu pertama yang ingin dihapus dari queue : ");
            idx1 = GetInput();
        }
    }
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
}

// Fungsi untuk menghapus lagu dari queue berdasarkan ID
void removeSong() {
    printf("\nMasukkan urutan lagu yang ingin dihapus dari queue : ");
    Word idlagu = GetInput();
    int idxl;
    boolean valid = false;
    while(!valid){
        if (IsWordNumber(idlagu)){
            idxl = WordtoInt(idlagu);
            if (idxl > 0 && idxl <= lengthQueueLagu(q)){valid = true;}
            else{
                printf("Urutan lagu invalid");
                printf("Masukkan urutan lagu yang ingin dihapus dari queue : \n");
                idlagu = GetInput();
            }
        }
        else{
            printf("Urutan lagu invalid\n");
            printf("Masukkan urutan lagu yang ingin dihapus dari queue : \n");
            idlagu = GetInput();
        }
    }
        printf("\n");
        printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", q.buffer[idxl-1].nama.TabWord, q.buffer[idxl-1].penyanyi.TabWord);
        Queuelagu temp;
        CreateQueueLagu(&temp);
        ElTypeQueue  val;
        dequeueLagu(&q, &val);
        enqueueLagu(&temp, val);
        while (!isInQueueLagu(temp,q.buffer[idxl-1])){
            dequeueLagu(&q, &val);
            enqueueLagu(&temp, val);
        }
        dequeueLagu(&temp,&val);
        while (!isEmptyQueueLagu(temp)){
            dequeueLagu(&temp, &val);
            enqueueLagu(&q, val);
        }
}


// Fungsi untuk mengosongkan queue
void clearQueue() {
    CreateQueueLagu(&q);
    printf("\nQueue berhasil dikosongkan.\n");
}