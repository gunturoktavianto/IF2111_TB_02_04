#ifndef map_H
#define map_H
#include <stdio.h>
#include "boolean.h"
#include "../SET/set.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
<<<<<<< HEAD
#define MaxMap 10
=======
#define MaxEl 10
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
#define Undefined -999

// typedef int bool;
typedef int keytype;
typedef int valuetype;
typedef int address;

typedef struct {
	keytype Key;		//	nomor album
	valuetype Value;	// 	nama album
	Set* Lagu;	//	LINKED KE SET LAGU
} InfoAlbum;

typedef struct {
<<<<<<< HEAD
	InfoAlbum Elements[MaxMap];	// array of album
=======
	InfoAlbum Elements[MaxEl];	// array of album
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
	address Count;		// jumlah album dari penyanyi
} Map;		// penyanyi

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateMap(Map *M);
/* I.S. Sembarang */
<<<<<<< HEAD
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxMap */
=======
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
<<<<<<< HEAD
/* Ciri Map penuh : count bernilai MaxMap */
=======
/* Ciri Map penuh : count bernilai MaxEl */
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif