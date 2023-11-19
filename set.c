#include "set.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void setCreateEmpty(Set *S){
    (*S).Count = setNil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean setIsEmpty(Set S){
    return (S.Count == setNil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean setIsFull(Set S){
    return (S.Count == setMaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void setInsert(Set *S, setinfotype Elmt){
    if (!setIsMember(*S, Elmt)){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

boolean setIsMember(Set S, setinfotype Elmt){
    int i = 0;
    boolean found = false;
    while (i < S.Count && !found){
        if (S.Elements[i].TabWord == Elmt.TabWord && S.Elements[i].Length==Elmt.Length){
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */