/* 
NIM             : 18220048
Nama            : Rayhan Naufal Luthfi
Tanggal         : 27 Oktober 2021
Topik praktikum : ADT Linked Linear List
Deskripsi       : Pra Praktikum
*/

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLL (ListLL L){
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateLL (ListLL *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}


/****************** Manajemen Memori ******************/
address AlokasiLL (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    ElmtList *Elmt = (ElmtList *)malloc(sizeof(ElmtList));
    
    if (Elmt != Nil){
        Info(Elmt) = X;
        Next(Elmt) = Nil;
        return Elmt;
    }
    else{
        return Nil;
    }
}

void DealokasiLL (address *P){
    free(*P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchLL (ListLL L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    boolean Found = false;
    address Idx = First(L);

    if (!IsEmptyLL(L))
    {
        while ((!Found) && (Idx != Nil))
        {
            if (Info(Idx) == X)
            {
                Found = true;
            }
            else
            {
                Idx = Next(Idx);
            }
        }
    }
    return Idx;
}


/****************** PRIMITIF BERDASARKAN NilAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListLL *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = AlokasiLL(X);
    if (P != Nil){
        InsertFirstLL(L, P);
    }
}
void InsVLast (ListLL *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = AlokasiLL(X);
    if (P != Nil)
    {
        InsertLastLL(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListLL *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirstLL(L, &P);
    *X = Info(P);
    DealokasiLL(&P);
}

void DelVLast (ListLL *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLastLL(L, &P);
    *X = Info(P);
    DealokasiLL(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLL (ListLL *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterLL (ListLL *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastLL (ListLL *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmptyLL(*L)){
        InsertFirstLL(L, P);
    }
    else{
        address Last = First(*L);
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfterLL(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLL (ListLL *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    address X = First(*L);
    if (Next(X) == Nil){
        CreateLL(L);
    }
    else{
        First(*L) = Next(X);
    }
    *P = X;
}

void DelP (ListLL *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P = SearchLL(*L, X);
    if (P != Nil){
        address prev = First(*L);

        if (prev == P){
            DelFirstLL(L, &P);
        }
        else{
            while (Next(prev) != P)
            {
                prev = Next(prev);
            }
            DelAfterLL(L, &P, prev);
        }
    }
    DealokasiLL(&P);
}

void DelLastLL (ListLL *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    *P = First(*L);
    if (Next(*P) == Nil){
        CreateLL(L);
    }
    else{
        address prev = *P;
        while (Next(Next(prev)) != Nil)
            prev = Next(prev);

        DelAfterLL(L, P, prev);
    }
}

void DelAfterLL (ListLL *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (*Pdel != Nil)
        Next(Prec) = Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (ListLL L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (!IsEmptyLL(L)){
        address P = First(L);
        while (P != Nil){
            printf("%d", Info(P));
            P = Next(P);
            if (P != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}

int NbElmtLL (ListLL L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count = 0;
    if (!IsEmptyLL(L)){
        address P = First(L);
        while (Next(P) != Nil)
        {
            count++;
            P = Next(P);
        }
        count++;
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype MaxLL (ListLL L){
/* Mengirimkan nilai Info(P) yang maksimum */
    address P = First(L);
    infotype maks = Info(P);

    while (Next(P) != Nil){
        P = Next(P);
        if (Info(P) > maks){
            maks = Info(P);
        }
    }
    return maks;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1LL (ListLL *L1, ListLL *L2, ListLL *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

    CreateLL(L3);
    if (!IsEmptyLL(*L1)){
        address P = First(*L1);
        First(*L3) = P;
        while (Next(P) != Nil)
        {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }
    CreateLL(L1);
    CreateLL(L2);
}

address AdrMaxLL (ListLL L){
/*	Mengirimkan address P, dengan Info(P) yang bernilai maksimum */
    return SearchLL(L, MaxLL(L));
}

infotype MinLL (ListLL L){
/* Mengirimkan nilai info(P) yang minimum */
    address P = First(L);
    infotype min = Info(P);

    while (Next(P) != Nil){
        P = Next(P);
        if (Info(P) < min){
            min = Info(P);
        }
    }
    return min;
}

address AdrMinLL (ListLL L){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    return SearchLL(L, MinLL(L));
}

float AverageLL (ListLL L){
/* Mengirimkan nilai rata-rata info(P) */
    address P = First(L);
    int count = NbElmtLL(L);
    double sum = 0;
    while (P != Nil){
        sum += Info(P);
        P = Next(P);
    }

    return sum/count;
}

/****************** PROSES TERHADAP LIST ******************/

void InversListLL(ListLL *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    address P, Prec, Last;

    P = First((*L));
    Prec = Nil;

    while (P != Nil) {
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    First(*L) = Last;
}