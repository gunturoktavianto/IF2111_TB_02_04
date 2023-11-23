#include "playlistcmd.h"

void getCommandPlaylist()
{
    boolean state=true;
    while(state)
    {
        printf("> SILAHKAN MASUKAN COMMAND: ");
        Word command=GetInput();
        if(IsWordEq(command, toKata("PLAYLIST CREATE"))) {createPlaylist(); state=true;}
        else if(IsWordEq(command, toKata("PLAYLIST ADD SONG"))) {addPlaylistSong(); state=true;}
        else if(IsWordEq(command,toKata("PLAYLIST ADD ALBUM"))) {addPlaylistAlbum(); state=true;}
        else if(IsWordEq(command,toKata("PLAYLIST SWAP"))) {swapPlaylist(); state=true;}
        else if(IsWordEq(command,toKata("PLAYLIST REMOVE"))) {removePlaylist(); state=true;}
        else if (IsWordEq(command,toKata("PLAYLIST DELETE"))) {deletePlaylist(); state=true;}
        else if (IsWordEq(command,toKata("PLAYLIST QUIT"))) {state=false;}
        else printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG: ");   
    }
}

void startPlaylist()
{
    printf("====[ SELAMAT DATANG DI FUNGSI PLAYLIST ]====\n");
    printf("----TERDAPAT TUJUH FUNGSI YANG BISA DIAKSES---- \n");
    printf("1. PLAYLIST CREATE -> untuk membuat playlist baru\n");
    printf("2. PLAYLIST ADD SONG -> untuk menambah lagu baru ke playlist\n");
    printf("3. PLAYLIST ADD ALBUM -> untuk menambah album ke playlist\n");
    printf("4. PLAYLIST SWAP -> untuk menukar urutan lagu pada playlist\n");
    printf("5. PLAYLIST REMOVE -> untuk menghapus lagu dari playlist\n");
    printf("6. PLAYLIST DELETE -> untuk menghapus playlist\n");
    printf("7. PLAYLIST QUIT -> untuk keluar dari fungsi playlist\n\n");
    getCommandPlaylist();
}
void createPlaylist()
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    int cnt=0;
    Word x;
    do
    {
        x=GetInput();
        for(int i=0; i<x.Length; i++)
        {
            if(x.TabWord[i]!=' ') cnt++;
        }
        if (cnt<3)
        {
            printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            printf("Masukkan nama playlist yang ingin dibuat:");
        }
    } while (cnt<3);
    List l;
    CreateEmptyPlaylist(x, &l);
    InsertAtArrayDin(&daftarPlaylist, l, LengthArrayDin(daftarPlaylist));
    printf("Playlist %s berhasil dibuat!\nSilakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", x.TabWord);
}
void addPlaylistSong()
{
    // printdaftarPenyanyi(l);
    // printf("Masukkan Nama Penyanyi yang dipilih : ");
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
        printf("Penyanyi \"%s\" tidak ada dalam daftar. Silakan coba lagi.\n", namapenyanyi.Key.TabWord);
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
    printf("\nMasukkan Judul Album yang dipilih : ");
    namaalbum.Key = GetInput();
    while(!IsMemberAlbum(l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value, namaalbum.Key)){
        printf("Album \"%s\" tidak ada dalam daftar. Silakan coba lagi.\n", namaalbum.Key.TabWord);
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
    printf("Daftar Playlist Pengguna :\n");
    DisplayDaftarPlaylist(daftarPlaylist);
    printf("\nMasukkan ID Playlist yang dipilih : ");
    Word idplaylist = GetInput();
    int idpl;
    valid = false;
    while(!valid){
        if (IsWordNumber(idplaylist)){
            idpl = WordtoInt(idplaylist);
            if (idpl <= LengthArrayDin(daftarPlaylist) && idpl > 0){valid = true;}
            else{
                printf("ID Playlist tidak ditemukan.\n");
                printf("\nMasukkan ID Playlist yang dipilih : ");
                idplaylist = GetInput();
            }
        }
        else{
            printf("ID Playlist tidak ditemukan.\n");
            printf("\nMasukkan ID Playlist  yang dipilih : ");
            idplaylist = GetInput();
        }
    }
    alamat P = SearchPlaylist(daftarPlaylist.A[idpl-1], l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl]);
    if (P == Nil){
        InsVLast (&daftarPlaylist.A[idpl-1], l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl]);
        printf("Lagu dengan judul \"%s\" pada album \"%s\" oleh penyanyi \"%s\" berhasil ditambahkan ke dalam playlist \"%s\".",l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1].nama.TabWord, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Key.TabWord, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1].nama.TabWord, daftarPlaylist.A[idpl-1].NamaPlaylist.TabWord);
    }
    else{
        printf("Lagu dengan judul \"%s\" pada album \"%s\" oleh penyanyi \"%s\" sudah ditambahkan ke dalam playlist \"%s\".",l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1].nama.TabWord, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Key.TabWord, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[idxl-1].nama.TabWord, daftarPlaylist.A[idpl-1].NamaPlaylist.TabWord);
    }
}

void addPlaylistAlbum()
{
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
        printf("Penyanyi \"%s\" tidak ada dalam daftar. Silakan coba lagi.\n", namapenyanyi.Key.TabWord);
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
        printf("Album \"%s\" tidak ada dalam daftar. Silakan coba lagi.\n", namaalbum.Key.TabWord);
        printf("\nMasukkan Nama Album yang dipilih : ");
        namaalbum.Key = GetInput();
    }   int idxa = IdxAlbum(&l, idxp, namaalbum.Key);

    // menampilkan lagu dari album X, disimpan dalam ADT set
    printf("Daftar Lagu Album %s oleh %s :\n", namaalbum.Key.TabWord, namapenyanyi.Key.TabWord);
    while(i<l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.Count){
        printf("  %d. %s\n", i+1, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[i].nama.TabWord);
        i++;
    } i=0;

    printf("Daftar Playlist Pengguna :\n");
    DisplayDaftarPlaylist(daftarPlaylist);
    printf("\nMasukkan ID Playlist yang dipilih : ");
    Word idplaylist = GetInput();
    int idpl;
    boolean valid = false;
    while(!valid){
        if (IsWordNumber(idplaylist)){
            idpl = WordtoInt(idplaylist);
            if (idpl <= LengthArrayDin(daftarPlaylist) && idpl > 0){valid = true;}
            else{
                printf("ID Playlist tidak ditemukan.\n");
                printf("\nMasukkan ID Playlist yang dipilih : ");
                idplaylist = GetInput();
            }
        }
        else{
            printf("ID Playlist tidak ditemukan.\n");
            printf("\nMasukkan ID Playlist  yang dipilih : ");
            idplaylist = GetInput();
        }
    }
    boolean found = false;
    for (i = 0;i<l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.Count;i++ ){
        alamat P = SearchPlaylist(daftarPlaylist.A[idpl-1], l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[i]);
        if (P == Nil){
            InsVLast (&daftarPlaylist.A[idpl-1], l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[i]);
            found =  true;
        }
    }
    if (found){
        printf("Album dengan judul \"%s\" berhasil ditambahkan ke dalam pada playlist pengguna \"%s\".",l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Key.TabWord, daftarPlaylist.A[idpl-1].NamaPlaylist.TabWord);
    }
    else{
        printf("Album dengan judul \"%s\" sudah ditambahkan ke dalam pada playlist pengguna \"%s\".",l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Key.TabWord, daftarPlaylist.A[idpl-1].NamaPlaylist.TabWord);
    }
}
void swapPlaylist()
{
    printf("Daftar Playlist Pengguna :\n");
    DisplayDaftarPlaylist(daftarPlaylist);
    printf("Masukkan id playlist:");
    Word idplaylist = GetInput();
    int id;
    boolean valid = false;
    while(!valid){
        if (IsWordNumber(idplaylist)){
            id = WordtoInt(idplaylist);
            if (id <= LengthArrayDin(daftarPlaylist) && id > 0){valid = true;}
            else{
                printf("ID Playlist tidak ditemukan.\n");
                printf("\nMasukkan ID Playlist yang dipilih : ");
                idplaylist = GetInput();
            }
        }
        else{
            printf("ID Playlist tidak ditemukan.\n");
            printf("\nMasukkan ID Playlist  yang dipilih : ");
            idplaylist = GetInput();
        }
    }
    DisplayLaguPlaylist(daftarPlaylist.A[id-1]);
    printf("Masukkan urutan lagu pertama yang mau ditukar: ");
    int x, y;
    Word idx1, idx2;
    idx1 = GetInput();
    valid = false;
    while(!valid){
        if(IsWordNumber(idx1)){
            x = WordtoInt(idx1);
            if(x > 0 && x <= NbElmtPlaylist(daftarPlaylist.A[id-1])){
                printf("Masukkan urutan lagu kedua yang mau ditukar: ");
                idx2 = GetInput();
                if(IsWordNumber(idx2)){
                    y = WordtoInt(idx2);
                    if((y > 0 && y <= NbElmtPlaylist(daftarPlaylist.A[id-1])) && y != x){
                        valid = true;
                        break;
                    }
                    else{
                    printf("urutan kedua invalid.\n");
                    printf("Masukkan urutan lagu kedua yang mau ditukar: ");
                    idx2 = GetInput();
                    }
                }
                else{
                    printf("urutan kedua invalid.\n");
                    printf("Masukkan urutan lagu kedua yang mau ditukar: ");
                    idx2 = GetInput();
                }
            }
            else{
                printf("urutan pertama invalid.\n");
                printf("Masukkan urutan lagu pertama yang mau ditukar: ");
                idx1 = GetInput();
            }
        }
        else{
            printf("urutan pertama invalid.\n");
            printf("Masukkan urutan lagu pertama yang mau ditukar: ");
            idx1 = GetInput();
        }
    }
    Lagu tukarx, tukary;
    alamat adrx,adry;
    adrx=alamatIndeksKe(daftarPlaylist.A[id-1], x-1);
    adry=alamatIndeksKe(daftarPlaylist.A[id-1], y-1);
    tukarx=Info(adrx);
    tukary=Info(adry);
    Info(adrx)=tukary;
    Info(adry)=tukarx;
}

void removePlaylist()
{
    int id;
    id=WordtoInt(GetInput());
    if(id>LengthArrayDin(daftarPlaylist)) printf("Tidak ada playlist dengan ID %d.",id);
    int n=WordtoInt(GetWords());
    alamat Loc=First(daftarPlaylist.A[id]);
    if(Loc==Nil) printf("Tidak ada lagu dengan urutan %d di playlist “%s”!",n,daftarPlaylist.A[id].NamaPlaylist.TabWord);
    if(n==1) DelFirst(&daftarPlaylist.A[id],&Loc);
    else 
    {
        alamat Prec,Loc;
        Loc=alamatIndeksKe(daftarPlaylist.A[id], n);
        Prec=alamatIndeksKe(daftarPlaylist.A[id], n-1);
        DelAfter(&daftarPlaylist.A[id], &Loc, Prec);
    }
}

void deletePlaylist()
{
    if(LengthArrayDin(daftarPlaylist)==0) printf("Belum ada playlist yang dibuat.\n");
    else
    {
        int id=0; 
        printf("Daftar Playlist Pengguna :\n");
        DisplayDaftarPlaylist(daftarPlaylist);
        printf("\nMasukkan ID Playlist yang dipilih : ");
        Word idplaylist = GetInput();
        int idpl;
        boolean valid = false;
        while(!valid){
            if (IsWordNumber(idplaylist)){
                idpl = WordtoInt(idplaylist);
                if (idpl <= LengthArrayDin(daftarPlaylist) && idpl > 0){valid = true;}
                else{
                    printf("Tidak ada playlist dengan ID %d dalam daftar\nplaylist pengguna. Silakan coba lagi.\n",idpl);
                    printf("\nMasukkan ID Playlist yang dipilih : ");
                    idplaylist = GetInput();
                }
            }
            else{
                printf("Tidak ada playlist dengan ID %d dalam daftar\nplaylist pengguna. Silakan coba lagi.\n",idpl);
                printf("\nMasukkan ID Playlist  yang dipilih : ");
                idplaylist = GetInput();
            }
        }
        DeleteAtArrayDin(&daftarPlaylist, idpl-1);
        printf("Playlist ID %d dengan judul '%s' berhasil dihapus.\n",idpl, daftarPlaylist.A[id-1].NamaPlaylist.TabWord);
    }
}