/* *** MODUL INTEGER DYNAMIC LIST *** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocateList(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    BUFFER(*l) = NULL;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return l.nEff;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    if (!isEmpty(l)){
        return IDX_MIN;
    }
}

IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    if (!isEmpty(l)){
        return l.nEff - 1;
    }
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (getFirstIdx(l) <= i && i < l.capacity);
}

boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return (getFirstIdx(l) <= i && i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return l.nEff == 0;
}

/* *** Test list penuh *** */
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return l.nEff == l.capacity;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    int N;
    IdxType i;
    scanf("%d\n", &N);
    while (N < 0 || N > CAPACITY(*l)){
        scanf("%d\n", &N);
    }
    NEFF(*l) = N;
    for (i = IDX_MIN; i < N; i++){
        scanf("%d\n", &ELMT(*l, i));
    }
}

void printList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    IdxType i;
    printf("[");
    if (!isEmpty(l)){
        for (i = IDX_MIN; i < l.nEff; i++){
            if (i != l.nEff - 1){
                printf("%d,", l.buffer[i]);
            }
            else{
                printf("%d", l.buffer[i]);
            }
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    IdxType i;
    if ((l1.nEff == l2.nEff) && (!isEmpty(l1))){
        if (plus){
            for (i = IDX_MIN; i < l1.nEff; i++){
                l1.buffer[i] += l2.buffer[i];
            }
        }
        else{
            for (i = IDX_MIN; i < l1.nEff; i++){
                l1.buffer[i] -= l2.buffer[i];
            }
        }
    }
    return l1;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    IdxType i;
    if (l1.nEff == l2.nEff){
        for (i = IDX_MIN; i < l1.nEff; i++){
            if (l1.buffer[i] != l2.buffer[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    IdxType i;
    if (!isEmpty(l)){
        for (i = IDX_MIN; i < l.nEff; i++){
            if (l.buffer[i] == val){
                return i;
            }
        }
        return IDX_UNDEF;
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    if (!isEmpty(l)){
        IdxType i;
        *max = l.buffer[IDX_MIN];
        *min = l.buffer[IDX_MIN];
        for (i = IDX_MIN + 1; i < l.nEff; i++){
            if (l.buffer[i] > *max){
                *max = l.buffer[i];
            }
            if (l.buffer[i] < *min){
                *min = l.buffer[i];
            }
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    IdxType i;
    CreateListDin(lOut, lIn.capacity);
    NEFF(*lOut) = lIn.nEff;
    for (i = IDX_MIN; i < lIn.nEff; i++){
        ELMT(*lOut, i) = lIn.buffer[i];
    }
}

ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    IdxType i;
    ElType sum = 0;
    for (i = IDX_MIN; i < l.nEff; i++){
        sum += l.buffer[i];
    }
    return sum;
}

int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    IdxType i;
    int countVal = 0;
    for (i = IDX_MIN; i < l.nEff; i++){
        if (l.buffer[i] == val){
            countVal += 1;
        }
    }
    return countVal;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    IdxType i, j;
    ElType a;
    if (asc){
        for (i = IDX_MIN; i < NEFF(*l) - 1; i++){
            for (j = i + 1; j < NEFF(*l); j++){
                if (ELMT(*l, i) > ELMT(*l, j)){
                    a = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = a;
                }
            }
        }
    }
    else{
        for (i = IDX_MIN; i < NEFF(*l) - 1; i++){
            for (j = i + 1; j < NEFF(*l); j++){
                if (ELMT(*l, i) < ELMT(*l, j)){
                    a = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = a;
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (!isFull(*l)){
        NEFF(*l) += 1;
        ELMT(*l, NEFF(*l) - 1) = val;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    if (!isEmpty(*l)){
        *val = ELMT(*l, NEFF(*l) - 1);
        NEFF(*l) -= 1;
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY(*l) += num;
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    CAPACITY(*l) -= num;
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void compressList(ListDin *l){
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}