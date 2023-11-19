#ifndef map_H
#define map_H
#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define mapNil 0
#define mapMaxEl 10
#define mapUndefined -999

// typedef int bool;
typedef Word mapkeytype;
typedef Word mapvaluetype;
typedef int mapaddress;

typedef struct {
	mapkeytype Key;
	mapvaluetype Value;
} mapinfotype;

typedef struct {
	mapinfotype Elements[mapMaxEl];
	mapaddress Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void mapCreateEmpty(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean mapIsEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean mapIsFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
mapvaluetype mapValue(Map M, mapkeytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void mapInsert(Map *M, mapkeytype k, mapvaluetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void mapDelete(Map *M, mapkeytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean mapIsMember(Map M, mapkeytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif