#include <stdlib.h>
#include "listsong.h"
#include <stdio.h>

#include "listplaylist.h"
#include "listsong.h"
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
}

void DisplayDaftarPenyanyi(List Penyanyi)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i;
    // ALGORITMA
    printf("Daftar Penyanyi :\n");
    while(Penyanyi.A[i]!=Mark){
        printf("  %d. %d\n", i+1, Penyanyi.A[i]);
        i++;
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

char yesorno ()
{
    // KAMUS
    char input;
    boolean valid = false;
    // ALGORITMA
    GetCommand();
    while(!valid)
    {
        if(currentWord.Length > 1) GetCommand();
        else
        {
            input = currentWord.TabWord[0];
            if(input == 'Y' || input == 'y')
            {
                valid = true;
            }
            else if(input == 'N' || input == 'n')
            {
                valid = true;
            }
            else
            {
                GetCommand();
            }
        } 
    }
    return input;
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

void ListLagu(List Penyanyi, Map Album, Set Lagu)
{
    // menampilkan penyanyi, disimpan dalam ADT list statis
    // KAMUS
    boolean valid = false;
    char inputyn;
    int i=0, j=1;
    // ALGORTIMA
    DisplayDaftarPenyanyi(Penyanyi);
    // mencari penyanyi
    char namapenyanyi[100];
    printf("Ingin melihat album yang ada?(Y/N): ");
    inputyn = yesorno();
    if(inputyn == 'Y' || inputyn == 'y')
    {
        printf("\nPilih penyanyi untuk melihat album mereka:  ");
        while(valid == false)
        {
            GetCommand(); /*cuma baca sampai sebelum spasi*/
            if(Search(Penyanyi, currentWord)){valid = true;}
            else{printf("Nama Penyanyi tidak ditemukan.\n");}
        }
        DisplayDaftarAlbum(); // menampilkan album dari penyanyi X, disimpan dalam ADT map

        // mencari album
        char namaalbum[100];
        printf("\nMasukkan Nama Album yang dipilih : ");
        valid = false;
        while(valid == false)
        {
            GetCommand();  /*cuma baca sampai sebelum spasi*/
            if(IsMemberMap(Album, currentWord)){valid = true;}
            else{printf("Nama Album tidak ditemukan.\n");}
        }

        printf("Ingin melihat lagu yang ada?(Y/N): ");
        inputyn = yesorno();
        if(inputyn == 'Y' || inputyn == 'y')
        {
            // menampilkan lagu dari album X, disimpan dalam ADT set
            DisplayDaftarLagu();
        }
    }
}

void list()
{
    // KAMUS
    boolean valid = false;
    // ALGORITMA
    printf("====[ SELAMAT DATANG DI FUNGSI LIST ]====\n");
    printf("TERDAPAT DUA FUNGSI YANG BISA DIAKSES \n");
    printf("    1. LIST DEFAULT\n");
    printf("    2. LIST PLAYLIST \n");
    printf("SILAHKAN MASUKAN COMMAND: \n");
    GetCommand();
    while(!valid)
    {
        if (IsWordEq(toKata("LIST DEFAULT"), currentWord))
        {
            ListDefault();
            valid = true;
        } 
        else if(IsWordEq(toKata("LIST PLAYLIST"), currentWord))
        {
            DisplayDaftarPlaylist();
            valid = true;
        } 
        else
        {
            printf("COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG\n");
            GetCommand();
        }
    }
}