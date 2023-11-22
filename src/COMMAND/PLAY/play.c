#include "play.h"

/* MAIN SECTION */
void startPlay()
{
    printf("====[ SELAMAT DATANG DI FUNGSI PLAY ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("1. PLAY SONG -> untuk memainkan lagu berdasarkan masukan detail lagu\n");
    printf("2. PLAY PLAYLIST -> untuk memainkan lagu berdasarkan id playlist\n");
    printf("3. PLAY QUIT -> untuk keluar dari fungsi PLAY\n\n");
    getCommandPlay();
}

void getCommandPlay()
{
    boolean state=true;
    while(state)
    {
        printf("> SILAHKAN MASUKAN COMMAND: ");
        Word command=GetInput();
        if(IsWordEq(command, toKata("PLAY SONG"))) {PlaySong(); state=true;}
        else if(IsWordEq(command, toKata("PLAY PLAYLIST"))) {PlayPlaylist(); state=true;}
        else if(IsWordEq(command,toKata("PLAY QUIT"))) { state=false;}
        else printf("Invalid command. Silahkan masukkan command kembali.\n> SILAHKAN MASUKAN COMMAND: ");   
    }
}

/* PRIMARY SECTION*/
void PlaySong(){
    printf("playsong bisa\n");
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
    printf("\nMemutar lagu \"%s\" oleh \"%s\".\n", l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl].nama.TabWord, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Key.TabWord);

    /* Final State */
    //Ketika command ini berhasil dieksekusi, queue dan riwayat lagu akan menjadi kosong
    CreateStack(&r);
    CreateQueueLagu(&q);
    // // Update currentsong
    currentsong = l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl];
}

void PlayPlaylist(){
    /*Initial State*/
    /*playlist tidak kosong*/
    if(!IsEmptyArrayDin(daftarPlaylist)){
        int IDPlaylist;
        printf("Masukkan ID Playlist: ");
        scanf("%d",IDPlaylist);
        while(IDPlaylist > LengthArrayDin(daftarPlaylist) && IDPlaylist < 0){
            printf("ID Playlist INVALID\n");
            printf("Masukkan ID Playlist: ");
            scanf("%d",IDPlaylist);
        }
        printf("Memutar playlist \"%s\".\n", daftarPlaylist.A[IDPlaylist].NamaPlaylist.TabWord);
    


        /* Final State */
        /*queue berisi semua lagu dalam playlist*/
        clearQueue();
        // masukin playlist ke queuelagu
        queueKnownPlaylist(daftarPlaylist, &q, IDPlaylist);

        /*currentsong menjadi lagu urutan pertama dalam playlist*/
        ReplaceCS(&r, daftarPlaylist.A[IDPlaylist].First->infolagu);
        // hapus el pertama queueLagu untuk menempati currentsong 
        dequeueLagu(&q, &currentsong);


        /* isi riwayat lagu (keseluruhan) sama dengan queue, tetapi dengan urutan yang di-reverse. */
        // Pembuatan queue sementara yang sudah di-reverse
        Queuelagu reversedPlaylist, temp;
        CreateQueueLagu(&reversedPlaylist);
        CreateQueueLagu(&temp);
        copyQueueLagu(&q, &temp);
        transferReverseQueueLagu(&temp, &reversedPlaylist);

        // mengisi riwayat lagu dengan queue yang sudah di-reverse
        while(!isEmptyQueueLagu(reversedPlaylist)){
            ElTypeQueue val;
            dequeueLagu(&reversedPlaylist, &val);
            Push(&r,val);
        }
    }
    
}