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
        else if(IsWordEq(AccessCommand(command, 0),toKata("PLAYLIST")), IsWordEq(AccessCommand(command,1),toKata("SWAP"))) {swapPlaylist(command); state=true;}
        else if(IsWordEq(AccessCommand(command,0),toKata("PLAYLIST")) && IsWordEq(AccessCommand(command,1),toKata("REMOVE"))) {removePlaylist(command); state=true;}
        else if (IsWordEq(command,toKata("PLAYLIST DELETE"))) {deletePlaylist(); state=true;}
        else if (IsWordEq(command,toKata("PLAYLIST QUIT"))) {state=false;}
        else printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG!\n");   
    }
}

void startPlaylist()
{
    printf("====[ SELAMAT DATANG DI FUNGSI PLAYLIST ]====\n");
    printf("----TERDAPAT TUJUH FUNGSI YANG BISA DIAKSES---- \n");
    printf("1. PLAYLIST CREATE -> untuk membuat playlist baru\n");
    printf("2. PLAYLIST ADD SONG -> untuk menambah lagu baru ke playlist\n");
    printf("3. PLAYLIST ADD ALBUM -> untuk menambah album ke playlist\n");
    printf("4. PLAYLIST SWAP <id> <x> <y>-> untuk menukar urutan lagu x dan y pada playlist di indeks id\n");
    printf("5. PLAYLIST REMOVE <id> <n>-> untuk menghapus lagu dari playlist di indeks id dengan urutan n\n");
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
    if(LengthArrayDin(daftarPlaylist)==0) printf("Belum ada playlist yang dibuat.\n");
    else{

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
        while(i<l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.Count){
            printf("  %d. %s\n", i+1, l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Value.InfoLagu[i].nama.TabWord);
            i++;
        } i=0;

        // mencari lagu
        printf("\nMasukkan ID Lagu  yang dipilih : ");
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

}

void addPlaylistAlbum()
{
    if(LengthArrayDin(daftarPlaylist)==0) printf("Belum ada playlist yang dibuat.\n");
    else{

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
            printf("Album dengan judul \"%s\" berhasil ditambahkan ke dalam pada playlist pengguna \"%s\".\n",l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Key.TabWord, daftarPlaylist.A[idpl-1].NamaPlaylist.TabWord);
        }
        else{
            printf("Album dengan judul \"%s\" sudah ditambahkan ke dalam pada playlist pengguna \"%s\".\n",l.PenyanyiKe[idxp].InfoPenyanyi[idxp].Value.InfoAlbum[idxa].Key.TabWord, daftarPlaylist.A[idpl-1].NamaPlaylist.TabWord);
        }
    }
}
void swapPlaylist(Word command)
{
    Word idplaylist = AccessCommand(command,2);
    Word idx1=AccessCommand(command,3);
    int idPlaylist=WordtoInt(idplaylist);
    Word idx2=AccessCommand(command,4);
    if (!IsWordNumber(idplaylist) || !IsWordNumber(idx1) || !IsWordNumber(idx2))
    {
        printf("Command invalid.\n");
    }
    else if (idPlaylist<1 ||idPlaylist>LengthArrayDin(daftarPlaylist))
    {
        printf("Tidak ada playlist dengan playlist ID %d\n",idPlaylist);
    }
    else if (alamatIndeksKe(daftarPlaylist.A[idPlaylist-1],WordtoInt(idx1))==Nil)
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"\n",WordtoInt(idx1),daftarPlaylist.A[idPlaylist-1].NamaPlaylist.TabWord);
    }
    else if (alamatIndeksKe(daftarPlaylist.A[idPlaylist-1],WordtoInt(idx2))==Nil)
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"\n",WordtoInt(idx2),daftarPlaylist.A[idPlaylist-1].NamaPlaylist.TabWord);
    }
    else
    {
        Lagu tukarx, tukary;
        alamat adrx,adry;
        int x=WordtoInt(idx1);
        int y=WordtoInt(idx2);
        int id=WordtoInt(idplaylist);
        adrx=alamatIndeksKe(daftarPlaylist.A[id-1], x);
        adry=alamatIndeksKe(daftarPlaylist.A[id-1], y);
        tukarx=Info(adrx);
        tukary=Info(adry);
        Info(adrx)=tukary;
        Info(adry)=tukarx;
        printf("Berhasil menukar lagu dengan nama \"%s\" dengan \"%s\" di playlist \"%s\"\n",Info(adry).nama.TabWord,Info(adrx).nama.TabWord, daftarPlaylist.A[id-1].NamaPlaylist.TabWord);
    }
}

void removePlaylist(Word command)
{
    if(!IsWordNumber(AccessCommand(command,2)) || !IsWordNumber(AccessCommand(command,3))) printf("Command invalid.\n");
    else
    {
        int id=WordtoInt((AccessCommand(command,2)));
        int n=WordtoInt(AccessCommand(command,3));
        alamat Loc=First(daftarPlaylist.A[id-1]);
        if(id<=0 || id>LengthArrayDin(daftarPlaylist)) printf("Tidak ada playlist dengan ID %d.",id);
        else if(Loc==Nil || n>NbElmtPlaylist(daftarPlaylist.A[id-1])) printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n",n,daftarPlaylist.A[id-1].NamaPlaylist.TabWord);
        else if(n==1) DelFirst(&daftarPlaylist.A[id-1],&Loc);
        else 
        {
            alamat Prec,Loc;
            Loc=alamatIndeksKe(daftarPlaylist.A[id-1], n);
            Lagu dihapus=LaguIndeksKe(daftarPlaylist.A[id-1],n);
            Prec=alamatIndeksKe(daftarPlaylist.A[id-1], n-1);
            DelAfter(&daftarPlaylist.A[id-1], &Loc, Prec);
            printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"!\n",dihapus.nama.TabWord,dihapus.penyanyi.TabWord, daftarPlaylist.A[id-1].NamaPlaylist.TabWord);
        }
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
        printf("Playlist ID %d dengan judul '%s' berhasil dihapus.\n",idpl, daftarPlaylist.A[idpl-1].NamaPlaylist.TabWord);
        DeleteAtArrayDin(&daftarPlaylist, idpl-1);
    }
}