#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"
#include "../MESINKATA/mesinkata.h"
// #include "../LIST/list.h"       /*berisi album dari penyanyi*/

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define setNil 0
#define setMaxEl 100

typedef int setinfotype;
typedef int setaddress;

typedef struct {
    setinfotype ke[setMaxEl];
    setaddress Count;
} SetInfoLagu;

// typedef struct {
//     Word NamaAlbum;
//     int jumlahLagu;
//     // modified mapvaluetype Value;
//     SetInfoLagu InfoLagu;
//     // modified mapkeytype Key;
//     mapkeytype KeyAlbum;
// } MapInfoAlbum;

// typedef struct {
//     Word NamaPenyanyi;
//     int jumlahAlbum;
//     //  modified mapvaluetype Value;
//     MapInfoAlbum InfoAlbum;
//     //  modified mapkeytype Key;
//     mapkeytype KeyPenyanyi;
// } MapInfoPenyanyi; //List penyanyi

// typedef struct {
//     int jumlahPenyanyi;
//     MapInfoPenyanyi InfoPenyanyi[setMaxEl];
// } ListPenyanyi; 

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateSet(SetInfoLagu *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(SetInfoLagu S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(SetInfoLagu S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(SetInfoLagu *S, setinfotype Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(SetInfoLagu *S, setinfotype Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(SetInfoLagu S, setinfotype Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif