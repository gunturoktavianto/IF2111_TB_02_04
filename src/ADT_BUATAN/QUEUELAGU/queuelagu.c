#include "queuelagu.h"

Queuelagu q;

void CreateQueueLagu(Queuelagu *q){
    IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* PROTOTYPE ********* */
/* Fungsi yang mengirim true jika q kosong: lihat definisi di atas */
boolean isEmptyQueueLagu(Queuelagu q){
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

/* Fungsi yang mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isFullQueueLagu(Queuelagu q){
    return (lengthQueueLagu(q) == CAPACITY);
}

/* Fungsi yang mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int lengthQueueLagu(Queuelagu q){
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
void enqueueLagu(Queuelagu *q, ElTypeQueue val){
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
	TAIL(*q).nama.Length = val.nama.Length;
    TAIL(*q).album.Length = val.album.Length;
    TAIL(*q).penyanyi.Length = val.penyanyi.Length;
	int i;
	for (i = 0; i < val.nama.Length; i++)
	{
		TAIL(*q).nama.TabWord[i] = val.nama.TabWord[i];
	}
	TAIL(*q).nama.TabWord[TAIL(*q).nama.Length]='\0';
    for (i = 0; i < val.album.Length; i++)
	{
		TAIL(*q).album.TabWord[i] = val.album.TabWord[i];
	}
	TAIL(*q).album.TabWord[TAIL(*q).album.Length]='\0';
    for (i = 0; i < val.penyanyi.Length; i++)
	{
		TAIL(*q).penyanyi.TabWord[i] = val.penyanyi.TabWord[i];
	}
	TAIL(*q).penyanyi.TabWord[TAIL(*q).penyanyi.Length]='\0';
}

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S : q tidak mungkin kosong */
/* F.S : val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
		 q mungkin kosong */
void dequeueLagu(Queuelagu *q, ElTypeQueue *val){
    (*val).nama.Length = HEAD(*q).nama.Length;
    (*val).album.Length = HEAD(*q).album.Length;
    (*val).penyanyi.Length = HEAD(*q).penyanyi.Length;
	int i;
	for (i = 0; i < (*val).nama.Length; i++)
	{
		(*val).nama.TabWord[i] = HEAD(*q).nama.TabWord[i];
	}
	(*val).nama.TabWord[(*val).nama.Length]='\0';
    for (i = 0; i < (*val).album.Length; i++)
	{
		(*val).album.TabWord[i] = HEAD(*q).album.TabWord[i];
	}
	(*val).album.TabWord[(*val).album.Length]='\0';
    for (i = 0; i < (*val).penyanyi.Length; i++)
	{
		(*val).penyanyi.TabWord[i] = HEAD(*q).penyanyi.TabWord[i];
	}
	(*val).penyanyi.TabWord[(*val).penyanyi.Length]='\0';

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
void displayQueueLagu(Queuelagu q){
	int i, temp1, temp2;
	ElTypeQueue val;
	Queuelagu q1;
	/*ALGORITMA*/
	if (isEmptyQueueLagu(q))
	{
	printf("[]\n");
	printf("Queue kosong\n");
	}
	else
	{
	temp1 = IDX_HEAD(q);
	temp2 = IDX_TAIL(q);
	int i = 1;
	while (IDX_HEAD(q) != IDX_UNDEF)
	{
	dequeueLagu(&q, &val);
	enqueueLagu(&q1, val);
	printf("%d. %s - %s - %s\n", i, val.penyanyi.TabWord,val.nama.TabWord,val.album.TabWord);
	i++;
	}
	while (IDX_HEAD(q1) != IDX_UNDEF){
	dequeueLagu(&q1, &val);
	enqueueLagu(&q, val);
	}
	IDX_HEAD(q) = temp1;
	IDX_TAIL(q) = temp2;
	}
}

/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S : queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S : queueOutput memiliki isi queue yang sama */
void copyQueueLagu(Queuelagu *queueInput, Queuelagu *queueOutput){
    /*KAMUS LOKAL*/
	int i, len;
	Queuelagu q;
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
boolean isInQueueLagu(Queuelagu q, ElTypeQueue x){
    /*KAMUS LOKAL*/
	ElTypeQueue val;
	boolean notfound = true;
	/*ALGORITMA*/
	while ((IDX_HEAD(q) != IDX_UNDEF) && notfound)
	{
		dequeueLagu(&q, &val);
		if (IsWordEq(val.nama, x.nama) && IsWordEq(val.album, x.album) && IsWordEq(val.penyanyi, x.penyanyi))
		{
			notfound = false;
		}
	}
	return !notfound;
}

void transferReverseQueueLagu(Queuelagu* q1, Queuelagu* q2){
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

void queueKnownPlaylist(ArrayDin L, Queuelagu *Q, int id) {
/* Fungsi untuk menambahkan playlist ke dalam queue tanpa menampilkan input dan output */
    alamat P = First(L.A[id-1]); //Pake ADT Dilla
    while (P != Nil) {
        enqueueLagu(Q, P->infolagu);
        P = P->next;
    }
}