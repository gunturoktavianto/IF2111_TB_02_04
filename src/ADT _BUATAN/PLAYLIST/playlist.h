#ifndef playlist_H
#define playlist_H

#include "../ADT/MESINKATA/mesinkata.h"
#include "../LAGU/lagu.h"

#define InitialSize 10

typedef int IdxType;
typedef Lagu ElType;

typedef struct {
    Word nama;
    Playlist *DaftarPlaylist;
    int Capacity;
    int Neff;
} DaftarPlaylist;

#define Nil NULL

typedef struct { 
	Lagu infolagu;
	Playlist* next;
} Playlist;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next


/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk DaftarPlaylist kosong dengan ukuran InitialSize
 */
DaftarPlaylist MakeDaftarPlaylist();

/**
 * Destruktor
 * I.S. DaftarPlaylist terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateDaftarPlaylist(DaftarPlaylist *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(DaftarPlaylist array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(DaftarPlaylist array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(DaftarPlaylist array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(DaftarPlaylist array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(DaftarPlaylist *array, ElType el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(DaftarPlaylist *array, ElType el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(DaftarPlaylist *array, ElType el);

/**
 * Fungsi untuk menghapus elemen di index ke-i DaftarPlaylist
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(DaftarPlaylist *array, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir DaftarPlaylist
 * Prekondisi: array tidak kosong
 */
void DeleteLast(DaftarPlaylist *array);

/**
 * Fungsi untuk menghapus elemen pertama DaftarPlaylist
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(DaftarPlaylist *array);

/**
 * Fungsi untuk melakukan print suatu DaftarPlaylist.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintDaftarPlaylist(DaftarPlaylist array);

/**
 * Fungsi untuk melakukan reverse suatu DaftarPlaylist.
 * Prekondisi: array terdefinisi
 */
void ReverseDaftarPlaylist(DaftarPlaylist *array);

/**
 * Fungsi untuk melakukan copy suatu DaftarPlaylist.
 * Prekondisi: array terdefinisi
 */
DaftarPlaylist CopyDaftarPlaylist(DaftarPlaylist array);

/**
 * Fungsi untuk melakukan search suatu DaftarPlaylist.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchDaftarPlaylist(DaftarPlaylist array, ElType el);

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyPlaylist (Playlist L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreatePlaylist (Playlist *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address AlokasiPlaylist (infotypeLL X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiPlaylist (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchPlaylist (Playlist L, infotypeLL X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (Playlist *L, infotypeLL X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (Playlist *L, infotypeLL X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (Playlist *L, infotypeLL *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (Playlist *L, infotypeLL *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstPlaylist (Playlist *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfterPlaylist (Playlist *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastPlaylist (Playlist *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstPlaylistPlaylist (Playlist *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPPlaylistPlaylist (Playlist *L, infotypeLL X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastPlaylistPlaylist (Playlist *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterPlaylistPlaylist (Playlist *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoPlaylistPlaylist (Playlist L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtPlaylistPlaylist (Playlist L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */



/****************** PROSES TERHADAP LIST ******************/

void InversPlaylist (Playlist *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1Playlist (Playlist *L1, Playlist *L2, Playlist *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */


#endif
