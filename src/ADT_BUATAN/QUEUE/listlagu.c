#include "../PLAYLIST/playlist.h"
#include "../PENYANYI/penyanyi.h"
#include "../ALBUM/album.h"
#include "../mesinkata/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayDaftarPlaylist(ArrayDin Arr){
/*
Menampilkan daftar playlist yang ada
*/
    // KAMUS
    int i = 0;
    // ALGORITMA    
    if(IsEmptyArrayDin(Arr)) // kalo kosong
    {
        printf("Daftar playlist yang kamu miliki: \n");
        printf("Kamu tidak memiliki playlist.\n");
    }
    else
    {   
        printf("Daftar playlist yang kamu miliki: \n");
        while(i < LengthArrayDin(Arr)) // loop unutk ngeprint playlist
        {
            printf("    %d. %s", i+1, Arr.A[i].NamaPlaylist.TabWord);
            i++;
        }
    }
}

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

int SearchIndexPenyanyi(Penyanyi Penyanyi, Word namapenyanyi)
{
    // KAMUS
    int i=0;
    boolean found;
    // ALGORITMA
    while(i < Penyanyi.Count && !found)
    {   
        if(IsWordEq(Penyanyi.InfoPenyanyi[i].Key,namapenyanyi))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return i;
}

int SearchIndexAlbum(Penyanyi Penyanyi, Word album, int indekspenyanyi)
{
    // KAMUS
    int idx = 0;
    boolean found;
    // ALGORITMA
    while(idx < Penyanyi.InfoPenyanyi[indekspenyanyi].Value.Count && !found)
    {   
        if(IsWordEq(Penyanyi.InfoPenyanyi[indekspenyanyi].Value.InfoAlbum[idx].Key,album))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return idx;
}

void DisplayDaftarAlbum(Penyanyi Penyanyi, Word namapenyanyi, int indekspenyanyi)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i=0,idx = 0;
    boolean found;
    // ALGORITMA
    printf("Daftar Album oleh %s :\n", namapenyanyi.TabWord);
    
    if(found)
    {
        for(idx = 0; idx<Penyanyi.InfoPenyanyi[i].Value.Count; i++)
        {
            printf("    %d. %s\n", idx+1, Penyanyi.InfoPenyanyi[i].Value.InfoAlbum[idx].Key.TabWord);
        }
    }
}

void DisplayDaftarLagu(SetLagu lagu, Word namaalbum)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i = 0, idx =1;
    // ALGORITMA
    printf("Daftar Lagu di %s :\n", namaalbum.TabWord);
    for(i = 0;i < lagu.Count; i++)
    {
        if(IsWordEq(lagu.InfoLagu[i].album, namaalbum))
        {
            printf("    %d. %s", idx, lagu.InfoLagu[i].album.TabWord);
            idx++;
        }
    }
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

void ListLagu(Penyanyi Penyanyi, Album Album, SetLagu Lagu)
{
    // menampilkan penyanyi, disimpan dalam ADT list statis
    // KAMUS
    boolean valid = false;
    char inputyn;
    int i=0, j=1,indekspenyanyi, indeksalbum;
    // ALGORTIMA
    DisplayDaftarPenyanyi(Penyanyi);

    // mencari penyanyi
    printf("Ingin melihat album yang ada?(Y/N): ");
    inputyn = yesorno();
    if(inputyn == 'Y' || inputyn == 'y')
    {
        printf("\nPilih penyanyi untuk melihat album mereka:  ");
        while(valid == false)
        {
            GetCommand(); /*cuma baca sampai sebelum spasi*/
            if(IsMemberPenyanyi(&Penyanyi, &currentWord)){valid = true;}
            else{printf("Nama Penyanyi tidak ditemukan.\n");}
        }
        Word namapenyanyi = currentWord;
        indekspenyanyi = SearchIndexPenyanyi(Penyanyi, namapenyanyi);
        DisplayDaftarAlbum(Penyanyi, namapenyanyi, indekspenyanyi); // menampilkan album dari penyanyi X, disimpan dalam ADT map

        // mencari album
        printf("Ingin melihat lagu yang ada?(Y/N): ");
        inputyn = yesorno();
        if(inputyn == 'Y' || inputyn == 'y')
        {
            // menampilkan lagu dari album X, disimpan dalam ADT set
            printf("\nMasukkan Nama Album yang dipilih : ");
            valid = false;
            while(valid == false)
            {
                GetCommand();  /*cuma baca sampai sebelum spasi*/
                if(IsMemberAlbum(Penyanyi.InfoPenyanyi[indekspenyanyi].Value, currentWord)){valid = true;}
                else{printf("Nama Album tidak ditemukan.\n");}
            }
            Word namaalbum = currentWord;
            indeksalbum = SearchIndexAlbum(Penyanyi, namaalbum, indekspenyanyi);
            DisplayDaftarLagu(Lagu, namaalbum);
        }
    }
}

void list()
{
    // KAMUS
    boolean valid = false;
    // ArrayDin playlist;
    Penyanyi Penyanyi;
    // Album Album;
    // SetLagu Lagu;
    // ALGORITMA
    printf("====[ SELAMAT DATANG DI FUNGSI LIST ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("        1. LIST DEFAULT\n");
    printf("        2. LIST PLAYLIST \n");
    printf("> SILAHKAN MASUKAN COMMAND: \n");\

    GetCommand();
    while(!valid)
    {
        if (IsWordEq(toKata("LIST DEFAULT"), currentWord))
        {
            printf("\nlist default jalan");
            // ListLagu(Penyanyi,Album,Lagu);
            valid = true;
        } 
        else if(IsWordEq(toKata("LIST PLAYLIST"), currentWord))
        {
            printf("\nlist default jalan");
            // DisplayDaftarPlaylist(playlist);
            valid = true;
        } 
        else
        {
            printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG\n");
            GetCommand();
        }
    }
}

int main()
{
    list();
}