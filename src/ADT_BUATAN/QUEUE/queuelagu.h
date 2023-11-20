#ifndef queuelagu_H
#define queuelagu_H
#include "../PLAYLIST/playlist.h"

#define IDX_UNDEF -1
#define CAPACITY 20

/* Definisi elemen dan address */
typedef Lagu ElTypeQueue;

typedef struct
{
        ElTypeQueue buffer[CAPACITY];
        int idxHead;
        int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** KREATOR *** */
/* I.S : sembarang */
/* F.S : Sebuah q kosong terbentuk dengan kondisi sbb: */
/* 		- Index head bernilai IDX_UNDEF */
/* 		- Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
void CreateQueueLagu(Queue *q);


/* ********* PROTOTYPE ********* */
/* Fungsi yang mengirim true jika q kosong: lihat definisi di atas */
boolean isEmptyQueueLagu(Queue q);

/* Fungsi yang mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isFullQueueLagu(Queue q);

/* Fungsi yang mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int lengthQueueLagu(Queue q);

/* *** OPERASI OPERASI *** */
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S : q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S : val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueueLagu(Queue *q, ElTypeQueue val);

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S : q tidak mungkin kosong */
/* F.S : val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
		 q mungkin kosong */
void dequeueLagu(Queue *q, ElTypeQueue *val);

/* *** Display Queue *** */
/* Prosedur untuk menampilkan Queue secara transversal*/
/* I.S : Queue terdefinisi */
/* F.S : Queue terlihat dilayar */
void displayQueueLagu(Queue q);

/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S : queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S : queueOutput memiliki isi queue yang sama */
void copyQueueLagu(Queue *queueInput, Queue *queueOutput);

/* Fungsi yang mengembalikan true jika x merupakan elemen dari q */
boolean isInQueueLagu(Queue q, ElTypeQueue x);

void transferReverseQueueLagu(Queue* q1, Queue* q2);
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik

#endif