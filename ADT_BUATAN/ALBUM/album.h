#ifndef album_H
#define album_H

#include "../LAGU/lagu.h"


/* MODUL Album
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1

// typedef int bool;
typedef Word keytype;
typedef SetLagu valuetypeAlbum;
typedef int address;

typedef struct {
	keytype Key;//NamaAlbum
	valuetypeAlbum Value;//SetLagu
} infotypeAlbum;

typedef struct {
	infotypeAlbum InfoAlbum[MaxEl];
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
valuetypeAlbum ValueAlbum(Album M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertAlbum(Album *M, keytype k, valuetypeAlbum v);
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

void PrintAlbum(Album M);
/* Mencetak keseluruhan album yang dimiliki suatu penyanyi*/
/* Format: 
[Penyanyi, Album, Nama]
[Penyanyi, Album, Nama]*/

#endif