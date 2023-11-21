#include "riwayat.h"

int main(){
    // KAMUS
    Lagu song;
    Stack riwayat, temp;
    // ALGORITMA
    CreateStack(&riwayat);
    song.nama = toKata("Namaku Favian");
    song.penyanyi = toKata("Favian Izza");
    song.album = toKata("Perjalan favian menguasai dunia kelinci");
    Push(&riwayat, song);
    while(!IsEmptyStack(riwayat))
    {
        Pop(&riwayat, &song);
        printf("lagu yang ada di playlist : %s\n", song.nama.TabWord);
        printf("Penyanyinya : %s\n", song.penyanyi.TabWord);
        printf("Albumnya : %s\n", song.album.TabWord);
    }
    return 0;
}