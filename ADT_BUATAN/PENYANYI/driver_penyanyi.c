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
    // printf("Daftar Penyanyi :\n");
    printPenyanyi(penyanyi);
    // printf("Daftar Penyanyi :\n");
    // for(i = 0; i< penyanyi.Count ; i++)
    // {
    //     printf("    %d. %s\n", i+1, penyanyi.InfoPenyanyi[i].Key.TabWord);
    // }  
    if(IsMemberPenyanyi(&penyanyi, &namapenyanyi2))
    {
        printf("%s ada di penyanyi", namapenyanyi2.TabWord);
    }
    
    i =0;
    // ALGORITMA
    // printf("\nDaftar List Penyanyi :\n");
    // for(i = 0; i< daftarpenyanyi.Count ; i++)
    // {
    //     printf("    %d. %s\n", i+1, daftarpenyanyi.PenyanyiKe[i].InfoPenyanyi[i].Key.TabWord);
    // }  
    if(IsMemberListPenyanyi(&daftarpenyanyi, &elmt1))
    {
        printf("%s ada di list penyanyi", elmt1.Key.TabWord);
    }
    indeks = IdxPenyanyi(penyanyi, namapenyanyi1);
    printf("indeks penyanti = %d", indeks);
    // printdaftarPenyanyi(daftarpenyanyi);
    // address idx = 0, iterator;
    // boolean found = false;
    // // ALGORITMA
    // while (idx < penyanyi.Count && !found) {
    //     if (IsWordEq(penyanyi.InfoPenyanyi[idx].Key,namapenyanyi1)) found = true;
    //     else idx++;
    // }
    // printf("\n %d", idx);
    DeletePenyanyi(&penyanyi, &namapenyanyi2);
    DeleteListPenyanyi(&daftarpenyanyi, &elmt2);

    // printPenyanyi(penyanyi);
}