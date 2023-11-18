<<<<<<< HEAD
#include "listplaylist.h"
#include <stdio.h>
#include <stdlib.h>
void DisplayDaftarPlaylist(ArrayDin Arr){
/*
Menampilkan daftar playlist yang ada
*/
    // KAMUS
    int i = 0;
    // ALGORITMA    
    if(IsEmptyArray(Arr)) // kalo kosong
    {
        printf("Daftar playlist yang kamu miliki: \n");
        printf("Kamu tidak memiliki playlist.\n");
    }
    else
    {
        printf("Daftar playlist yang kamu miliki: \n");
        while(i < Lengtharrdin(Arr)) // loop unutk ngeprint playlist
        {
            printf("    %d. %s", i+1, Arr.A[i]);
            i++;
        }
    }
=======
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
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
}