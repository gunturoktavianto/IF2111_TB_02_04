#include <stdio.h>
#include <stdlib.h>
#include "riwayat.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    // KAMUS

    // ALGORTIMA
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    // KAMUS

    // ALGORTIMA
    return (Top(S)==Nil);
}

boolean IsFullStack(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    // KAMUS

    // ALGORTIMA
    return (Top(S)==MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotypeStack X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    // KAMUS

    // ALGORTIMA
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotypeStack* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    // KAMUS

    // ALGORTIMA
    *X = InfoTop(*S);
    Top(*S) -= 1;
}
