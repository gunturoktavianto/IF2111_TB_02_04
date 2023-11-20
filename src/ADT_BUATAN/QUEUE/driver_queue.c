#include "QUEUE.h"
int main()
{
    Queue Q;
    Queue q;
    CreateQueueLagu(&Q);
    CreateQueueLagu(&q);
    ArrayDin daftarPlaylist=MakeArrayDin();
    List playlist,p;
    Lagu l,m;
    l=MakeLagu(toKata("BLACKPINK"),toKata("BORN PINK"), toKata("Pink Venom"));
    m=MakeLagu(toKata("BLACKPINK"),toKata("BORN PINK"), toKata("Shut Down"));
    //l.album=toKata("BORN PINK");
    //l.nama=toKata("Shut Down");
    //l.penyanyi=toKata("BLACKPINK");
    CreateEmptyPlaylist(toKata("kpop"),&playlist);
    CreateEmptyPlaylist(toKata("barat"),&p);
    InsertAtArrayDin(&daftarPlaylist, playlist, 0);
    InsertAtArrayDin(&daftarPlaylist, p, 1);

    InsVLast(&daftarPlaylist.A[0], l);
    InsVLast(&daftarPlaylist.A[0], m);
    //printf("%s",daftarPlaylist.A[0].NamaPlaylist.TabWord);
    queuePlaylist(daftarPlaylist, &Q);
    queuePlaylist(daftarPlaylist, &Q);
    displayQueueLagu(Q);
    swapSongs(1,2,&Q);
    displayQueueLagu(Q);
    transferReverseQueueLagu(&Q,&q);
    displayQueueLagu(q);
}