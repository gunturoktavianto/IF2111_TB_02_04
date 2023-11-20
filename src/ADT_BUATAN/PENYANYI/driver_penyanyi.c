#include "penyanyi.h"

void DisplayDaftarPenyanyi(Penyanyi Penyanyi)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i;
    // ALGORITMA
    printf("Daftar Penyanyi :\n");
    for(i = 0; i< Penyanyi.Count ; i++)
    {
        printf("    %d. %s\n", i+1, Penyanyi.InfoPenyanyi[i].Key.TabWord);
    }   
}

int main()
{
    printf("1. \n");
    // KAMUS
    Penyanyi penyanyi;
    Word namapenyanyi1,namapenyanyi2;
    Album albumRamadhan, FavianRuleTheWorld;
    
    // ALGORITMA
    CreateEmptyPenyanyi(&penyanyi);
    namapenyanyi1 = toKata("Ramadhan Bintang");
    namapenyanyi2 = toKata("Favian Ganz");
    InsertPenyanyi(&penyanyi, namapenyanyi1, albumRamadhan);
    InsertPenyanyi(&penyanyi, namapenyanyi2, FavianRuleTheWorld);
    
    //DisplayDaftarPenyanyi(penyanyi);
    printf("2. \n");
}