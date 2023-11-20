#ifndef lagu_H
#define lagu_H

#include "../../ADT/mesinkata/mesinkata.h"

/* MODUL SetLagu
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/


#define Nil 0
#define MaxEl 100

typedef struct {
    Word nama;
    Word album;
    Word penyanyi;
} Lagu;

typedef Lagu infotype;
typedef int address;

typedef struct
{
    infotype InfoLagu[MaxEl];
    int Count;
} SetLagu;

/* Definisi SetLagu S kosong : S.Count = Nil */
/* S.Count = jumlah element SetLagu */
/* S.Elements = tempat penyimpanan element SetLagu */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySetLagu(SetLagu *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah SetLagu S kosong berkapasitas MaxEl */
/* Ciri SetLagu kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetLagu(SetLagu S);
/* Mengirim true jika SetLagu S kosong*/
/* Ciri SetLagu kosong : count bernilai Nil */

boolean IsFullSetLagu(SetLagu S);
/* Mengirim true jika SetLagu S penuh */
/* Ciri SetLagu penuh : count bernilai MaxEl */

/* ********** Operator Dasar SetLagu ********* */
void InsertSetLagu(SetLagu *S, infotype Elmt);
/* Menambahkan Elmt sebagai elemen SetLagu S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetLagu(SetLagu *S, infotype Elmt);
/* Menghapus Elmt dari SetLagu S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSetLagu(SetLagu S, infotype Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void PrintLagu(SetLagu S);
/* Mencetak keseluruhan lagu yang dimiliki suatu album*/
/* Format: [Penyanyi, Album, Nama]*/

Lagu MakeLagu(Word nama, Word album, Word penyanyi);
/* Mengisi Lagu*/

SetLagu MakeSetLagu(int jumlahlagu);
/* Mengisi SetLagu*/
#endif