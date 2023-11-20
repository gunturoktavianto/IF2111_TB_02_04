#include <stdlib.h>
#include <stdio.h>
#include "penyanyi.h"

// void DisplayDaftarPenyanyi(Penyanyi Penyanyi)
// {
//     // Menampilkan list penyanyi yang ada
//     // KAMUS
//     int i;
//     // ALGORITMA
//     printf("Daftar Penyanyi :\n");
//     for(i = 0; i< Penyanyi.Count ; i++)
//     {
//         printf("    %d. %s\n", i+1, Penyanyi.InfoPenyanyi[i].Key.TabWord);
//     }   
// }

Penyanyi penyanyi;
ListPenyanyi daftarpenyanyi;
Album albumRamadhan, FavianRuleTheWorld;
infotypePenyanyi elmt1, elmt2;

int main()
{
    // KAMUS
    Word namapenyanyi1,namapenyanyi2;
    Lagu lagu, lagu2;
   
    
    int indeks;
    int i =0;
    // ALGORITMA
    CreateEmptyPenyanyi(&penyanyi);
    namapenyanyi1 = toKata("Ramadhan Bintang");
    namapenyanyi2 = toKata("Favian Ganz");
    elmt1.Key = namapenyanyi1;
    elmt2.Key = namapenyanyi2;
    elmt1.Value = albumRamadhan;
    elmt2.Value = FavianRuleTheWorld;
    InsertPenyanyi(&penyanyi, &namapenyanyi1, &albumRamadhan);
    InsertPenyanyi(&penyanyi, &namapenyanyi2, &FavianRuleTheWorld);
    InsertListPenyanyi(&daftarpenyanyi, &elmt1);
    InsertListPenyanyi(&daftarpenyanyi, &elmt2);
    // Menampilkan list singer yang ada
    printPenyanyi(&penyanyi);
    if(IsMemberPenyanyi(&penyanyi, &namapenyanyi2))
    {
        printf("%s ada di penyanyi\n", namapenyanyi2.TabWord);
    }

    indeks = IdxPenyanyi(&penyanyi, namapenyanyi1);
    printf("\nindeks penyanyi = %d\n", indeks);
    printdaftarPenyanyi(&daftarpenyanyi);
    i =0;
    if(AnggotaListPenyanyi(&daftarpenyanyi, &namapenyanyi1))
    {
        printf("%s ada di list penyanyi\n", elmt1.Key.TabWord);
    }
    DeletePenyanyi(&penyanyi, &namapenyanyi2);
    DeleteListPenyanyi(&daftarpenyanyi, &elmt1);
    printPenyanyi(&penyanyi);
    printdaftarPenyanyi(&daftarpenyanyi);
}