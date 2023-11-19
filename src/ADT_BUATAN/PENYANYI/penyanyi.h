#ifndef penyanyi_H
#define penyanyi_H
#include <stdio.h>
#include "boolean.h"
#include "../ADT/MESINKATA/mesinkata.h"
#include "../ALBUM/album.h"

/* MODUL Penyanyi
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 10
#define Undefined -999

// typedef int bool;
typedef Word keytype;
typedef Album valuetype;
typedef int address;

typedef struct {
        keytype Key;//NamaPenyanyi
	valuetype Value;//SetAlbum
} infotype;

typedef struct {
	infotype InfoPenyanyi[MaxEl];
	address Count;
} Penyanyi;

typedef struct
{
    Penyanyi PenyanyiKe[MaxEl];
    int Count;
} ListPenyanyi;

/* Definisi Penyanyi M kosong : M.Count = Nil */
/* M.Count = jumlah element Penyanyi */
/* M.Elements = tempat penyimpanan element Penyanyi */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyPenyanyi(Penyanyi *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Penyanyi M kosong berkapasitas MaxEl */
/* Ciri Penyanyi kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyPenyanyi(Penyanyi M);
/* Mengirim true jika Penyanyi M kosong*/
/* Ciri Penyanyi kosong : count bernilai Nil */

boolean IsFullPenyanyi(Penyanyi M);
/* Mengirim true jika Penyanyi M penuh */
/* Ciri Penyanyi penuh : count bernilai MaxEl */

/* ********** Operator Dasar Penyanyi ********* */
valuetype ValuePenyanyi(Penyanyi M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertPenyanyi(Penyanyi *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Penyanyi M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeletePenyanyi(Penyanyi *M, keytype k);
/* Menghapus Elmt dari Penyanyi M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberPenyanyi(Penyanyi M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif