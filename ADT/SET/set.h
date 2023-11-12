#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"
#include "../LIST/list.h"       /*berisi album dari penyanyi*/

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 100

// typedef int bool;
typedef int infotypeSet;
typedef int addressSet;

typedef struct 
{
        int* lagu;
} InfoLagu;     // lagu

typedef struct
{
    InfoLagu Elements[MaxEl];   // array of lagu
    addressSet Count;              // jumlah lagu dari album
} Set;          // album

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateSet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, InfoLagu Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, InfoLagu Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, InfoLagu Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2);
Set SetIntersection(Set s1, Set s2);
Set SetSymmetricDifference(Set s1, Set s2);
Set SetSubtract(Set s1, Set s2);

#endif