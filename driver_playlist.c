#include "playlist.c"
#include "../LAGU/lagu.c"
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkata/mesinkarakter.c"
int main()
{
    ArrayDin daftarPlaylist=MakeArrayDin();
    List playlist,p;
    Lagu l,m;
    l=MakeLagu(toKata("Pink Venom"),toKata("BORN PINK"), toKata("BLACKPINK"));
    m=MakeLagu(toKata("Shut Down"),toKata("BORN PINK"), toKata("BLACKPINK"));
    //l.album=toKata("BORN PINK");
    //l.nama=toKata("Shut Down");
    //l.penyanyi=toKata("BLACKPINK");
    CreateEmptyPlaylist(toKata("kpop"),&playlist);
    CreateEmptyPlaylist(toKata("barat"),&p);
    InsertAtArrayDin(&daftarPlaylist, playlist, LengthArrayDin(daftarPlaylist));
    InsertAtArrayDin(&daftarPlaylist, p, LengthArrayDin(daftarPlaylist));

    InsVLast(&daftarPlaylist.A[0], l);
    InsVLast(&daftarPlaylist.A[0], m);
    //printf("%s",daftarPlaylist.A[0].NamaPlaylist.TabWord);
    DisplayLaguPlaylist(daftarPlaylist.A[0]);
}