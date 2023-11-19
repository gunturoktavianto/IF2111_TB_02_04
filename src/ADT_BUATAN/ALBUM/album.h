#ifndef album_H
#define album_H
#include <stdio.h>
#include "boolean.h"
#include "../ADT/MESINKATA/mesinkata.h"
#include "../LAGU/lagu.h"


/* MODUL Album
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 10
#define Undefined -999

// typedef int bool;
typedef Word keytype;
typedef SetLagu valuetype;
typedef int address;

typedef struct {
	keytype Key;//NamaAlbum
	valuetype Value;//SetLagu
} infotype;

typedef struct {
	infotype InfoAlbum[MaxEl];
	address Count;
} Album;
/*
typedef struct
{
    Album Elements[MaxEl];
    int Count;
} SetAlbum;*/

/* Definisi Album M kosong : M.Count = Nil */
/* M.Count = jumlah element Album */
/* M.Elements = tempat penyimpanan element Album */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyAlbum(Album *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Album M kosong berkapasitas MaxEl */
/* Ciri Album kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyAlbum(Album M);
/* Mengirim true jika Album M kosong*/
/* Ciri Album kosong : count bernilai Nil */

boolean IsFullAlbum(Album M);
/* Mengirim true jika Album M penuh */
/* Ciri Album penuh : count bernilai MaxEl */

/* ********** Operator Dasar Album ********* */
valuetype ValueAlbum(Album M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertAlbum(Album *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Album M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteAlbum(Album *M, keytype k);
/* Menghapus Elmt dari Album M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberAlbum(Album M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

/* *** Konstruktor/Kreator *** */
void CreateEmptySetAlbum(SetAlbum*S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetAlbum(SetAlbum S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSetAlbum(SetAlbum S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSetAlbum(SetAlbum *S, infotype Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetAlbum(SetAlbum *S, infotype Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSetAlbum(SetAlbum S, infotype Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif