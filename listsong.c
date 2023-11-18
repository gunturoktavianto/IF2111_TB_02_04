#include <stdlib.h>
#include "listsong.h"
#include <stdio.h>

void DisplayDaftarPenyanyi(List L)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i;
    // ALGORITMA
    printf("Daftar Penyanyi :\n");
    for(i = 0;i < Length(L); i++)
    {
        printf("    %d. %s", (i+1), L.A[i]);
    }
}

void DisplayDaftarAlbum(Map MPenyanyi, char *album)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i=0,idx = 0;
    // ALGORITMA
    while(i < MPenyanyi.Count)
    {
        if(MPenyanyi.Elements[i].Value == album)
        {
            idx++;  
        }
        i++;
    }
    printf("Daftar Album oleh %s :\n", album);
    // pake hash
    
}

void DisplayDaftarLagu(Set S, Map MLagu, char* lagu, int indeks)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i;
    // ALGORITMA
    printf("Daftar Lagu di %s :\n", lagu);
    for(i = 0;i < S.Count; i++)
    {
        printf("    %d. %s", (i+1), S.Elements[i]);
    }
}

void ListDefault(List Penyanyi, Map Album, Set Lagu)
{
    // menampilkan penyanyi, disimpan dalam ADT list statis
    // KAMUS
    boolean valid = false;
    char input;
    int i=0, j=1;
    // ALGORTIMA
    printf("Daftar Penyanyi :\n");
    while(Penyanyi.A[i]!=Mark){
        printf("  %d. %d\n", j, Penyanyi.A[i]);
        i++; j++;
    }
    // mencari penyanyi
    char namapenyanyi[100];
    printf("Ingin melihat album yang ada?(Y/N): ");
    scanf("%c", &input);
    if(input == 'Y')
    {
        printf("\nPilih penyanyi untuk melihat album mereka:  ");
        while(valid == false){
            scanf("%s", &namapenyanyi); /*cuma baca sampai sebelum spasi*/
            if(Search(Penyanyi, namapenyanyi)){valid = true;}
            else{printf("Nama Penyanyi tidak ditemukan.\n");}
        }

        // menampilkan album dari penyanyi X, disimpan dalam ADT map
        printf("Daftar Album oleh %s :\n", namapenyanyi);
        PrintMap(Album);

        // mencari album
        char namaalbum[100];
        printf("\nMasukkan Nama Album yang dipilih : ");
        valid = false;
        while(valid == false){
            scanf("%s", &namaalbum); /*cuma baca sampai sebelum spasi*/
            if(IsMemberMap(Album, namaalbum)){valid = true;}
            else{printf("Nama Album tidak ditemukan.\n");}
        }
        printf("Ingin melihat lagu yang ada?(Y/N): ");
        scanf("%c", &input);
        if(input == 'Y')
        {
            // menampilkan lagu dari album X, disimpan dalam ADT set
            printf("Daftar Lagu Album %s oleh %s :\n", namaalbum, namapenyanyi);
            PrintMap(Album);
        }
    } 
}