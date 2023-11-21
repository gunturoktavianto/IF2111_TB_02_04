#include "command_playlist.h"

void getCommandPlaylist()
{
    printf("> SILAHKAN MASUKAN COMMAND: ");
    boolean state=false;
    while(!state)
    {
        Word command=GetInput();
        if(IsWordEq(command, toKata("PLAYLIST CREATE"))) {createPlaylist(); state=true;}
        else if(IsWordEq(command, toKata("PLAYLIST ADD SONG"))) {addPlaylistSong(); state=true;}
        else if(IsWordEq(command,toKata("PLAYLIST ADD ALBUM"))) {addPlaylistAlbum(); state=true;}
        else if(IsWordEq(command,toKata("PLAYLIST SWAP"))) {swapPlaylist(); state=true;}
        else if(IsWordEq(command,toKata("PLAYLIST REMOVE"))) {removePlaylist(); state=true;}
        else if (IsWordEq(command,toKata("PLAYLIST DELETE"))) {deletePlaylist(); state=true;}
        else printf("Invalid command. Silahkan masukkan command kembali.\n> SILAHKAN MASUKAN COMMAND: ");   
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
    getCommandPlaylist();
}
void addPlaylistSong()
{
    // printdaftarPenyanyi(l);
    // printf("Masukkan Nama Penyanyi yang dipilih : ");
    printf("Masukkan nama lagu:");
    Word w=GetInput();
    DisplayDaftarPlaylist();
    printf("Masukkan ID Playlist yang dipilih : ");
    int id=WordtoInt(GetInput());
    Lagu song; song.nama=w;
    InsVLast(&daftarPlaylist.A[id-1], song);
    printf("Lagu dengan judul '%s' berhasil ditambahkan ke playlist 's'.\n",song.nama.TabWord,daftarPlaylist.A[id-1].NamaPlaylist.TabWord);
    getCommandPlaylist();
}

void addPlaylistAlbum()
{
    getCommandPlaylist();
}
void swapPlaylist()
{
    int id,x,y;
    DisplayDaftarPlaylist();
    printf("Masukkan id playlist:");
    id=WordtoInt(GetInput());
    DisplayLaguPlaylist(daftarPlaylist.A[id-1]);
    printf("Masukkan urutan lagu pertama yang mau ditukar:");
    x=WordtoInt(GetInput());
    printf("Masukkan urutan lagu kedua yang mau ditukar:");
    y=WordtoInt(GetInput());
    Lagu tukarx, tukary;
    alamat adrx,adry;
    adrx=alamatIndeksKe(daftarPlaylist.A[id-1], x-1);
    adry=alamatIndeksKe(daftarPlaylist.A[id-1], y-1);
    tukarx=Info(adrx);
    tukary=Info(adry);
    Info(adrx)=tukary;
    Info(adry)=tukarx;
    getCommandPlaylist();
}
void removePlaylist()
{
    int id;
    id=WordtoInt(GetInput());
    if(id>LengthArrayDin(daftarPlaylist)) printf("Tidak ada playlist dengan ID %d.",id);
    int n=WordtoInt(GetWords());
    alamat Prec;
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
    getCommandPlaylist();
}
void deletePlaylist()
{
    if(LengthArrayDin(daftarPlaylist)==0) printf("Belum ada playlist yang dibuat.\n");
    else
    {
        int id; Word w;
        DisplayDaftarPlaylist();
        do
        {
            printf("Masukkan ID Playlist yang dipilih : ");
            id=WordtoInt(GetInput());
            w=daftarPlaylist.A[id-1].NamaPlaylist;
            if(id>LengthArrayDin(daftarPlaylist) || id<0) 
            {
                printf("Tidak ada playlist dengan ID 11 dalam daftar\nplaylist pengguna. Silakan coba lagi.\n");
            }
        } while (id>LengthArrayDin(daftarPlaylist));
        DeleteAtArrayDin(&daftarPlaylist, id-1);
        printf("Playlist ID %d dengan judul '%s' berhasil dihapus.\n",id,w.TabWord);
    }
    getCommandPlaylist();
}