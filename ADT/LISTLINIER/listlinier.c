#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>


Address newNode(ElType val){
    /* Definisi List : */
    /* List kosong : FIRST(l) = NULL */
    /* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
    /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
    Address p = (Address)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;

}
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */
    return FIRST(l) == NULL;
}


/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    int i;
    i = 0;
    Address temp = l;
    while(i < idx){
        ++i;
        temp = NEXT(temp);
    }
    return INFO(temp);
}

/* Mengirim true jika list kosong */
void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    int i = 0;
    Address temp = *l;

    while( i < idx){
        ++i;
        temp = (temp)->next;
    }
    (temp)->info = val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address temp = l;
    int i = 0;
    boolean isFound = false;
    while(temp != NULL && !isFound){
        if(INFO(temp) == val){
            isFound = true;
        }
        else{
            ++i;
            temp = NEXT(temp);
        }
    }
    if(isFound){
        return i;
    }else{
        return IDX_UNDEF;
    }

}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    if(p != NULL){
        p->next = *l;
        *l = p;
    }

}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    Address temp = *l;
    if(p != NULL){
        if(isEmpty(*l)){
            insertFirst(l, val);
        }
        else{
            while(NEXT(temp) != NULL){
                temp = NEXT(temp);
            }
            NEXT(temp) = p;
        }

    }
}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    Address temp = *l;
    int i = 0;
    if( p != NULL){
        if(idx == 0){
            insertFirst(l, val);
        }else{
            while(i < idx - 1){
                ++i;
                temp = NEXT(temp);
            }
            NEXT(p) = NEXT(temp);
            NEXT(temp) = p;
        }

    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address temp = *l;
    *val = INFO(temp);
    if(NEXT(temp) == NULL){
        *l = NULL;
        free(*l);
    }else{
        *l = NEXT(temp);
        free(temp);
    }
}
void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address p, q;
    if((*l)->next == NULL){
        deleteFirst(l, val);
    }
    else{
        p = *l;
        q = NULL;
        while(p->next != NULL){
            q = p;
            p = p->next;
        }
        if(q == NULL){
            *l = NULL;
        }
        else{
            q->next = NULL;
        }
        *val = p->info;
        free(p);
    }
}

void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    Address p, q;
    int count = 0;
    if((*l)->next == NULL){
        deleteFirst(l, val);
    }
    else{
        if(idx == 0){
            deleteFirst(l, val);
        }
        else{
            p = *l;
            while(count < idx){
                q = p;
                p = p->next;
                ++count;
            }
            *val = p->info;
            q->next = p->next;
            p->next = NULL;
            free(p);
        }
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address temp = l;
    printf("[");
    if(!isEmpty(l)){
        while(NEXT(temp) != NULL){
            printf("%d,", temp->info);
            temp = NEXT(temp);

        }
        printf("%d", INFO(temp));
    }
    printf("]");
}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int sum = 0;
    Address temp;

    temp = l;
    if(isEmpty(l)){
        return sum;
    }else{
        sum = 1;
        while(temp->next!=NULL){
            temp = temp->next;
            sum++;
        }
        return sum;
    }
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    Address temp;
    List l3;
    ElType val;

    CreateList(&l3);
    temp = l1;
    while(temp != NULL){
        insertLast(&l3, temp->info);
        temp = temp->next;
    }

    temp = l2;
    while(temp != NULL){
        insertLast(&l3, temp->info);
        temp = temp->next;

    }
    return l3;
}
