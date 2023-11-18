#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/*
Nama        : Hartanto Luwis
NIM         : 18222064
Tanggal     : 21 September 2023
Topik       : Pra Praktikum 3
Deskripsi   :
*/

ArrayDin MakeArrayDin()
{
/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */ 
    // KAMUS
    ArrayDin array;
    // ALGORITMA
    array.A = (ElTypeArrDin *)malloc(InitialSize * sizeof(ElTypeArrDin));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}


void DeallocateArrayDin(ArrayDin *array)
{
/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
    // KAMUS

    // ALGORITMA
    return free(array->A);
    array->Capacity = 0;
    array->Neff = 0;
}

boolean IsEmptyArray(ArrayDin array)
{
/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */    
    // KAMUS

    // ALGORITMA
    return (array.Neff == 0);
}


int Lengtharrdin(ArrayDin array)
{
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */    
    // KAMUS

    // ALGORITMA
    return array.Neff;
}


ElTypeArrDin Getarrdin(ArrayDin array, IdxTypeArrDin i)
{
/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */    
    // KAMUS
    
    // ALGORITMA
    return array.A[i];
}


int GetCapacityarrdin(ArrayDin array)
{
/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */    
    // KAMUS

    // ALGORITMA
    return array.Capacity;
}


void InsertAtarrdin(ArrayDin *array, ElTypeArrDin el, IdxTypeArrDin i)
{
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */    
    // KAMUS
    int j;
    // ALGORITMA
    array->Neff += 1;
    for(j = array->Neff; j > i ; j--)
    {
        array->A[j] = array->A[j-1];  
    }
    array->A[i] = el;
}


void DeleteAtarrdin(ArrayDin *array, IdxTypeArrDin i)
{
/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */    
    // KAMUS
    int j;
    // ALGORITMA
    array->Neff -= 1;
    for(j = i; j <= array->Neff; j++)
    {
        array->A[j] = array->A[j+1];  
    }
}
