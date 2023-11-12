#include "listplaylist.h"
#include <stdio.h>
#include <stdlib.h>
void DisplayDaftarPlaylist(ListLL L){
/*
Menampilkan daftar playlist yang ada
*/
    // KAMUS
    int i = 1;
    address p;
    // ALGORITMA    
    if(IsEmptyLL(L)) // kalo kosong
    {
        printf("Daftar playlist yang kamu miliki: \n");
        printf("Kamu tidak memiliki playlist.\n");
    }
    else
    {
        printf("Daftar playlist yang kamu miliki: \n");
        p = First(L);
        while(p != Nil) // loop unutk ngeprint playlist
        {
            printf("%d. %s", i, Info(p));
            p = Next(p);
            i++;
        }
    }
}