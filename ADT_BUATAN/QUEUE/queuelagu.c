#include "queuelagu.h"
#include <stdio.h>

void CreateQueueLagu(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* PROTOTYPE ********* */
/* Fungsi yang mengirim true jika q kosong: lihat definisi di atas */
boolean isEmptyQueueLagu(Queue q){
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

/* Fungsi yang mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isFullQueueLagu(Queue q){
    return (lengthQueueLagu(q) == CAPACITY);
}

/* Fungsi yang mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int lengthQueueLagu(Queue q){
    if (isEmptyQueueLagu(q))
	{
		return 0;
	}
	else
	{
		int i = IDX_HEAD(q);
		int count = 1;
		while (i != IDX_TAIL(q))
		{
			count++;
			i = (i + 1) % CAPACITY;
		}
		return count;
	}
}

/* *** OPERASI OPERASI *** */
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S : q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S : val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueueLagu(Queue *q, ElTypeQueue val){
    if (isEmptyQueueLagu(*q))
	{
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
	}

	else
	{
		// circular buffer
		IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
	}
	TAIL(*q).lagu.nama.Length = val.lagu.nama.Length;
    TAIL(*q).lagu.album.Length = val.lagu.penyanyi.Length;
    TAIL(*q).lagu.penyanyi.Length = val.lgu.nama.Length;
	int i;
	for (i = 0; i < val.lagu.nama.Length; i++)
	{
		TAIL(*q).lagu.nama.TabWord[i] = val.lagu.nama.TabWord[i];
	}
    for (i = 0; i < val.lagu.album.Length; i++)
	{
		TAIL(*q).lagu.album.TabWord[i] = val.lagu.album.TabWord[i];
	}
    for (i = 0; i < val.lagu.penyanyi.Length; i++)
	{
		TAIL(*q).lagu.penyanyi.TabWord[i] = val.lagu.penyanyi.TabWord[i];
	}
}

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S : q tidak mungkin kosong */
/* F.S : val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
		 q mungkin kosong */
void dequeueLagu(Queue *q, ElTypeQueue *val){
    (*val).lagu.nama.Length = HEAD(*q).lagu.nama.Length;
    (*val).lagu.album.Length = HEAD(*q).lagu.album.Length;
    (*val).lagu.penyanyi.Length = HEAD(*q).lagu.penyanyi.Length;
	int i;
	for (i = 0; i < (*val).lagu.nama.Length; i++)
	{
		(*val).lagu.nama.TabWord[i] = HEAD(*q).lagu.nama.TabWord[i];
	}
    for (i = 0; i < (*val).lagu.album.Length; i++)
	{
		(*val).lagu.album.TabWord[i] = HEAD(*q).lagu.album.TabWord[i];
	}
    for (i = 0; i < (*val).lagu.penyanyi.Length; i++)
	{
		(*val).lagu.penyanyi.TabWord[i] = HEAD(*q).lagu.penyanyi.TabWord[i];
	}

	if (IDX_HEAD(*q) == IDX_TAIL(*q))
	{
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	}

	else
	{
		IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
	}
}

/* *** Display Queue *** */
/* Prosedur untuk menampilkan Queue secara transversal*/
/* I.S : Queue terdefinisi */
/* F.S : Queue terlihat dilayar */
void displayQueueLagu(Queue q){
    int i, temp1, temp2;
	ElTypeQueue val;
	char* valchar,valchar1,valchar2;
	/*ALGORITMA*/
	if (isEmptyQueue(q))
	{
		printf("[]\n");
	}
	else
	{
		temp1 = IDX_HEAD(q);
		temp2 = IDX_TAIL(q);
		while (IDX_HEAD(q) != IDX_UNDEF)
		{
			dequeueLagu(&q, &val);
			valchar = WordToString(val.lagu.nama.Tabword);
            valchar1 = WordToString(val.lagu.album.Tabword);
            valchar2 = WordToString(val.lagu.penyanyi.Tabword);
			printf("[%s,%s, %s]\n", valchar,valchar1,valchar2);
		}
		IDX_HEAD(q) = temp1;
		IDX_TAIL(q) = temp2;
	}
}

/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S : queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S : queueOutput memiliki isi queue yang sama */
void copyQueue(Queue *queueInput, Queue *queueOutput){
    /*KAMUS LOKAL*/
	int i, len;
	Queue q;
	ElTypeQueue val;
	CreateQueueLagu(&q);
	len = lengthQueueLagu(*queueInput);
	/*ALGORITMA*/
	for (i = 0; i < len; i++)
	{
		dequeueLagu(queueInput, &val);
		enqueueLagu(queueOutput, val);
		enqueueLagu(&q, val);
	}
	len = lengthQueueLagu(q);
	for (i = 0; i < len; i++)
	{
		dequeueLagu(&q, &val);
		enqueueLagu(queueInput, val);
	}
}

/* Fungsi yang mengembalikan true jika x merupakan elemen dari q */
boolean isInQueueLagu(Queue q, ElTypeQueue x){
    /*KAMUS LOKAL*/
	ElTypeQueue val;
	char *xchar = WordToString(x.lagu.nama.Tabword);
    char *xchar1 = WordToString(x.lagu.album.Tabword);
    char *xchar2 = WordToString(x.lagu.penyanyi.Tabword);
	boolean notfound = true;
	/*ALGORITMA*/
	while ((IDX_HEAD(q) != IDX_UNDEF) && notfound)
	{
		dequeueLagu(&q, &val);
		if (IsEqual(val.lagu.nama.Tabword, xchar) && IsEqual(val.lagu.album.Tabword, xchar) && IsEqual(val.lagu.penyanyi.Tabword, xchar))
		{
			notfound = false;
		}
	}
	return !notfound;
}

void transferReverse(Queue* q1, Queue* q2){
    int q1length = lengthQueueLagu(*q1);

    IDX_HEAD(*q2) = IDX_HEAD(*q1);
    IDX_TAIL(*q2) = IDX_TAIL(*q1);

    int i;
    for(i = 0; i<q1length; i++){
        int j = q1length - i - 1;
        (*q2).buffer[(j + IDX_HEAD(*q2)) % (CAPACITY)] = (*q1).buffer[(i + IDX_HEAD(*q1)) % (CAPACITY)]; 
    }

    IDX_HEAD(*q1) = IDX_UNDEF;
    IDX_TAIL(*q1) = IDX_UNDEF;
}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik