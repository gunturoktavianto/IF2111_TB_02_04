#ifndef penyanyi_H
#define penyanyi_H

#include "../ALBUM/album.h"

/* MODUL Penyanyi
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

typedef Word keytype;
typedef Album valuetypePenyanyi;
typedef int address;    

typedef struct {
    keytype Key;
        valuetypePenyanyi Value;
} infotypePenyanyi;

typedef struct {
	infotypePenyanyi InfoPenyanyi[10];
	address Count;
} Penyanyi;

typedef struct
{
    Penyanyi PenyanyiKe[10];
    int Count;
} ListPenyanyi;

extern ListPenyanyi l;
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
valuetypePenyanyi ValuePenyanyi(Penyanyi *M, keytype *k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertPenyanyi(Penyanyi *M, keytype *k, valuetypePenyanyi *v);
/* Menambahkan Elmt sebagai elemen Penyanyi M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeletePenyanyi(Penyanyi *M, keytype *k);
/* Menghapus Elmt dari Penyanyi M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberPenyanyi(Penyanyi *M, keytype *k);
/* Mengembalikan true jika k adalah member dari M */

/* *** Konstruktor/Kreator *** */
void CreateEmptyListPenyanyi(ListPenyanyi*S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah List S kosong berkapasitas MaxEl */
/* Ciri List kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyListPenyanyi(ListPenyanyi S);
/* Mengirim true jika List S kosong*/
/* Ciri List kosong : count bernilai Nil */

boolean IsFullListPenyanyi(ListPenyanyi S);
/* Mengirim true jika List S penuh */
/* Ciri List penuh : count bernilai MaxEl */

/* ********** Operator Dasar List ********* */
void InsertListPenyanyi(ListPenyanyi *S, infotypePenyanyi *Elmt);
/* Menambahkan Elmt sebagai elemen List S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteListPenyanyi(ListPenyanyi *S, infotypePenyanyi *Elmt);
/* Menghapus Elmt dari List S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberListPenyanyi(ListPenyanyi *S, infotypePenyanyi Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

int IdxPenyanyi(ListPenyanyi *S, keytype kp);
/* I.S. ListPenyanyi tidak kosong, Nama Penyanyi terdefinisi
   F.S. index penyanyi*/

int IdxAlbum(ListPenyanyi *S, int idxp, keytype ka);
/* I.S. ListPenyanyi tidak kosong, index penyanyi dan Nama Album terdefinisi
   F.S. index album*/

int IdxLagu(ListPenyanyi *S, int idxp, int idxa, Word kl);
/* I.S. ListPenyanyi tidak kosong, index penyanyi dan Nama Album terdefinisi
   F.S. index album*/
void printdaftarPenyanyi(ListPenyanyi *S);
/* Mencetak keseluruhan isi daftar penyanyi */
#endif