#include "playlist.c"
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkata/mesinkarakter.c"
#include "../PENYANYI/penyanyi.c"
#include "../LAGU/lagu.c"
int main()
{
    daftarPlaylist=MakeArrayDin();
    List playlist,p;
    Lagu l,m;
    l=MakeLagu(toKata("BLACKPINK"),toKata("BORN PINK"), toKata("Pink Venom"));
    m=MakeLagu(toKata("BLACKPINK"),toKata("BORN PINK"), toKata("Shut Down"));
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