#include "ADT_BUATAN/PLAYLIST/playlist.h"
#include "start.h"
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

// int SearchIndexPenyanyi(Penyanyi Penyanyi, Word namapenyanyi)
// {
//     // KAMUS
//     int i=0;
//     boolean found;
//     // ALGORITMA
//     while(i < Penyanyi.Count && !found)
//     {   
//         if(IsWordEq(Penyanyi.InfoPenyanyi[i].Key,namapenyanyi))
//         {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return i;
// }

int SearchIndexAlbum(ListPenyanyi penyanyi, Word album, int indekspenyanyi)
// cari album yang ada di miliki penyanyi
{
    // KAMUS
    int idx = 0;
    boolean found;
    // ALGORITMA
    while(idx < penyanyi.PenyanyiKe[indekspenyanyi].InfoPenyanyi[indekspenyanyi].Value.Count && !found)
    {   
        if(IsWordEq(penyanyi.PenyanyiKe[indekspenyanyi].InfoPenyanyi[indekspenyanyi].Value.InfoAlbum[idx].Key,album))
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

void DisplayDaftarAlbum(ListPenyanyi penyanyi, Word namapenyanyi, int indekspenyanyi) 
// print daftar album berdasarkan masukan nama penyanyi dan indeks penyanyi yang ada di function list
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i=0,idx = 0;
    boolean found;
    // ALGORITMA
    printf("Daftar Album oleh %s :\n", namapenyanyi.TabWord);
    
    if(found)
    {
        for(idx = 0; idx<penyanyi.PenyanyiKe[indekspenyanyi].InfoPenyanyi[indekspenyanyi].Value.Count; i++)
        {
            printf("    %d. %s\n", idx+1, penyanyi.PenyanyiKe[indekspenyanyi].InfoPenyanyi[indekspenyanyi].Value.InfoAlbum[idx].Key.TabWord);
        }
    }
}

void DisplayDaftarLagu(SetLagu lagu, Word namaalbum) // untuk print daftar lagu berdasarkan album masukan 
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
    Word command;
    char input;
    boolean valid = false;
    // ALGORITMA
    command = GetInput(); // udah nerima input
    while(!valid)
    {
        if(currentWord.Length > 1) command = GetInput();
        else
        {
            input = command.TabWord[0];
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
                command = GetInput();
            }
        } 
    }
    return input;
}


void ListLagu()
{
    printf("jalan");

    // KAMUS
    boolean valid = false;
    char inputyn;
    int i=0, j=1,indekspenyanyi, indeksalbum;
    Word command;
    // ALGORTIMA
    printdaftarPenyanyi(&l);
    // mencari penyanyi
    printf("Ingin melihat album yang ada?(Y/N): ");
    inputyn = yesorno();
    if(inputyn == 'Y' || inputyn == 'y')
    {
        printf("\nPilih penyanyi untuk melihat album mereka:  ");
        while(valid == false)
        {
            command = GetInput(); /*cuma baca sampai sebelum spasi*/
            if(AnggotaListPenyanyi(&l, &command)){valid = true;}
            else{printf("Nama Penyanyi tidak ditemukan.\n");}
        }
        Word namapenyanyi = command;
        indekspenyanyi = IdxDaftarPenyanyi(&l, namapenyanyi);
        DisplayDaftarAlbum(l, namapenyanyi, indekspenyanyi); // menampilkan album dari penyanyi X, disimpan dalam ADT map

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
                command = GetInput();  /*cuma baca sampai sebelum spasi*/
                if(IsMemberAlbum(l.PenyanyiKe[indekspenyanyi].InfoPenyanyi[indekspenyanyi].Value, currentWord)){valid = true;}
                else{printf("Nama Album tidak ditemukan.\n");}
            }
            Word namaalbum = command;
            indeksalbum = SearchIndexAlbum(l, namaalbum, indekspenyanyi);
            DisplayDaftarLagu(l.PenyanyiKe[indekspenyanyi].InfoPenyanyi[indekspenyanyi].Value.InfoAlbum[indeksalbum].Value, namaalbum);
        }
    }
}

void list() // yang dipanggil
{
    // KAMUS
    Word command;
    boolean valid = false;
    printf("====[ SELAMAT DATANG DI FUNGSI LIST ]====\n");
    printf("----TERDAPAT DUA FUNGSI YANG BISA DIAKSES---- \n");
    printf("        1. LIST DEFAULT\n");
    printf("        2. LIST PLAYLIST \n");
    printf("        3. QUIT \n");
    printf("> SILAHKAN MASUKAN COMMAND: \n");\

    command = GetInput();
    while(!valid)
    {
        if (IsWordEq(toKata("LIST DEFAULT"), command))
        {
            ListLagu();
            valid = true;
        } 
        else if(IsWordEq(toKata("LIST PLAYLIST"), command))
        {
            printf("\nlist playlist jalan");
            // DisplayDaftarPlaylist(playlist);
            valid = true;
        } 
        else if(IsWordEq(toKata("QUIT"), command))
        {
            printf("\n>> Keluar dari Fungsi");
            valid = true;
        } 
        else
        {
            printf("> COMMAND TIDAK VALID SILAHKAN MASUKAN ULANG\n");
            command = GetInput();
        }
    }
}

int main()
{
    startconfig();
    list();
}