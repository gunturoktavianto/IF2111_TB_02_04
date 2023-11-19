#ifndef map_H
#define map_H
// #include <stdio.h>
// #include "boolean.h"
#include "set.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define mapNil 0
#define mapMaxEl 10
#define mapUndefined -999

// typedef int bool;
typedef char* mapkeytype;
typedef int mapvaluetype;
// typedef int mapaddress;

typedef struct {
    Word NamaAlbum;
    int jumlahLagu;
    // modified mapvaluetype Value;
    SetInfoLagu InfoLagu;
    // modified mapkeytype Key;
    mapkeytype KeyAlbum;
} MapInfoAlbum;

typedef struct {
    Word NamaPenyanyi;
    int jumlahAlbum;
    //  modified mapvaluetype Value;
    MapInfoAlbum InfoAlbum;
    //  modified mapkeytype Key;
    mapkeytype KeyPenyanyi;
} MapInfoPenyanyi; //List penyanyi

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator Album*** */
void CreateMapAlbum(MapInfoAlbum *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMapAlbum(MapInfoAlbum M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMapAlbum(MapInfoAlbum M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
mapvaluetype ValueMapAlbum(MapInfoAlbum M, mapkeytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMapAlbum(MapInfoAlbum *M, mapkeytype k, mapvaluetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMapAlbum(MapInfoAlbum *M, mapkeytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMapAlbum(MapInfoAlbum M, mapkeytype k);
/* Mengembalikan true jika k adalah member dari M */


/* *** Konstruktor/Kreator Penyanyi*** */
void CreateMapPenyanyi(MapInfoPenyanyi *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMapPenyanyi(MapInfoPenyanyi M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMapPenyanyi(MapInfoPenyanyi M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
mapvaluetype ValueMapPenyanyi(MapInfoPenyanyi M, mapkeytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMapPenyanyi(MapInfoPenyanyi *M, mapkeytype k, mapvaluetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMapPenyanyi(MapInfoPenyanyi *M, mapkeytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMapPenyanyi(MapInfoPenyanyi M, mapkeytype k);
/* Mengembalikan true jika k adalah member dari M */


#endif