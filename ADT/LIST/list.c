/*
Nama        : Hartanto Luwis
NIM         : 18222064
Topik       : Pra Praktikum 4
Tanggal     : 27 September 2023
Deskripsi   :
*/

#include <stdlib.h>
#include "list.h"
#include <stdio.h>

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */

List MakeList(){
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */

    // KAMUS
    List L;

    // ALGORITMA    
    L.A[MaxEl];
    L.A[0] = Mark;
    return L;
}

boolean IsEmpty(List L){
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */

    // KAMUS
    // ALGORITMA
    return L.A[0] == Mark;
}

ElType Get(List L, IdxType i){
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */

    // KAMUS

    // ALGORITMA
    return L.A[i];
}

void Set(List *L, IdxType i, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */

    // KAMUS

    // ALGORITMA
    if(i > Length(*L) - 1)
    {
        L->A[Length(*L) + 1] = Mark;
    }
    L->A[i] = v;
}

int Length(List L){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */

    // KAMUS
    int i,count;
    // ALGORITMA
    i = 0;
    count = 0;

    while(L.A[i] != Mark && i < MaxEl-1)
    {
        count++;
        i++;
    }
    if(L.A[i]!= Mark)
    {
        count ++;
    }

    return count;
}

IdxType FirstIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

    // KAMUS
    // ALGORITMA
    return 0;
}

IdxType LastIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */

   // KAMUS
    int i, indeks, cek = 0;
    // ALGORITMA
    return Length(L) - 1;
}

boolean IsIdxValid (List L, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

    // KAMUS

    // ALGORITMA
    return i>=0 && i<=MaxEl;
}

boolean IsIdxEff (List L, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */

    // KAMUS

    // ALGORITMA
    return i >= 0 && i < Length(L);
}

boolean Search(List L, ElType X){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

    // KAMUS
    int i = 0;
    boolean cek = false;
    // ALGORITMA
    while(i <= LastIdx(L) && !cek)
    {
        if(L.A[i] == X)
        {
            cek = true;
        }
        i++;
    }
   return cek;
}

void InsertFirst(List *L, ElType X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

    // KAMUS

    // ALGORITMA
    InsertAt(L, X, 0);
}

void InsertAt(List *L, ElType X, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

    // KAMUS
    int j;
    // ALGORITMA
    L->A[Length(*L) + 1] = Mark;
    for(j = Length(*L); j> i; j--)
    {
        L->A[j] = L->A[j-1];  
    }
    L->A[i] = X;
}

void InsertLast(List *L, ElType X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

    // KAMUS

    // ALGORITMA
    InsertAt(L, X, Length(*L));
}

void DeleteFirst(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

    // KAMUS

    // ALGORITMA
    DeleteAt(L, 0);
}

void DeleteAt(List *L, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

    // KAMUS
    int j;
    // ALGORITMA
    for(j = i; j < Length(*L) - 1; j++)
    {
        L->A[j] = L->A[j+1];
    }
    L->A[j] = Mark;
}

void DeleteLast(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

    // KAMUS

    // ALGORITMA
    DeleteAt(L, Length(*L) - 1);
}

List Concat(List L1, List L2){
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

    // KAMUS
    List L3;
    int i,j;
    // ALGORITMA
    for(i = 0; i<Length(L1);i++)
    {
        L3.A[i] = L1.A[i];
    }
    for(j = 0; j < Length(L2); j++)
    {
        L3.A[i+j] = L2.A[j];
    }
    L3.A[i+j] = Mark;
    return L3;
}