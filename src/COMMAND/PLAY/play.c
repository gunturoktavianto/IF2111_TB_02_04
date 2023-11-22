#include "play.h"

/* MAIN SECTION */
void startPlay()
{
    printf("\n====[ SELAMAT DATANG DI FUNGSI PLAY ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("    1. PLAY SONG -> untuk memainkan lagu berdasarkan masukan detail lagu\n");
    printf("    2. PLAY PLAYLIST -> untuk memainkan lagu berdasarkan id playlist\n");
    printf("    3. PLAY QUIT -> untuk keluar dari fungsi PLAY\n\n");
    printf("> SILAHKAN MASUKAN COMMAND: ");
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
        else printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG: \n");   
    }
}

/* PRIMARY SECTION*/
void PlaySong(){
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
    while(i<l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.Count){
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
    printf("\nMemutar lagu \"%s\" oleh \"%s\".\n", l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1].nama.TabWord, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Key.TabWord);

    /* Final State */
    //Ketika command ini berhasil dieksekusi, queue dan riwayat lagu akan menjadi kosong
    CreateStack(&r);
    CreateQueueLagu(&q);
    // // Update currentsong
    currentsong = l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1];
    printf("%s\n",currentsong.nama.TabWord);
}

void PlayPlaylist(){
    /*Initial State*/
    /*playlist tidak kosong*/
    if(!IsEmptyArrayDin(daftarPlaylist)){
        printf("Daftar Playlist Pengguna :\n");
        DisplayDaftarPlaylist(daftarPlaylist);
        printf("Masukkan ID Playlist: ");
        Word idplaylist = GetInput();
        int IDPlaylist;
        boolean valid = false;
        while(!valid){
            if (IsWordNumber(idplaylist)){
                IDPlaylist = WordtoInt(idplaylist);
                if (IDPlaylist <= LengthArrayDin(daftarPlaylist) && IDPlaylist > 0){valid = true;}
                else{
                    printf("ID Playlist INVALID\n");
                    printf("Masukkan ID Playlist: ");
                    idplaylist = GetInput();
                }
            }
            else{
                printf("ID Playlist INVALID\n");
                printf("Masukkan ID Playlist: ");
                idplaylist = GetInput();
            }
        }
        printf("Memutar playlist \"%s\".\n", daftarPlaylist.A[IDPlaylist-1].NamaPlaylist.TabWord);
    


        /* Final State */
        /*queue berisi semua lagu dalam playlist*/
        CreateQueueLagu(&q);
        // masukin playlist ke queuelagu
        queueKnownPlaylist(daftarPlaylist, &q, IDPlaylist-1);

        /*currentsong menjadi lagu urutan pertama dalam playlist*/
        ReplaceCS(&r, daftarPlaylist.A[IDPlaylist-1].First->infolagu);
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
    else{printf("\nPlaylist Kosong.\n");}
}