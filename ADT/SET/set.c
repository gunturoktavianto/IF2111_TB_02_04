#include "set.h"

/* *** Konstruktor/Kreator *** */
// Membuat album baru
void CreateSet(SetInfoLagu *S){
    /* I.S. Sembarang */
    /* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
    /* Ciri Set kosong : count bernilai setNil */
    (*S).Count = setNil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
// Apakah album kosong
boolean IsEmptySet(SetInfoLagu S){
    /* Mengirim true jika Set S kosong*/
    /* Ciri Set kosong : count bernilai setNil */
    return (S.Count == setNil);
}

// Apakah album penuh
boolean IsFullSet(SetInfoLagu S){
    /* Mengirim true jika Set S penuh */
    /* Ciri Set penuh : count bernilai MaxEl */
    return (S.Count == setMaxEl);
}

/* ********** Operator Dasar Set ********* */
// Memasukkan lagu pada album
void InsertSet(SetInfoLagu *S, setinfotype Elmt){
    /* Menambahkan Elmt sebagai elemen Set S. */
    /* I.S. S mungkin kosong, S tidak penuh
            S mungkin sudah beranggotakan Elmt */
    /* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
    if (!IsMemberSet(*S,Elmt)){
        (*S).ke[(*S).Count] = Elmt;
        (*S).Count++;
    }
}

// Menghapus lagu pada album
void DeleteSet(SetInfoLagu *S, setinfotype Elmt){
    /* Menghapus Elmt dari Set S. */
    /* I.S. S tidak kosong
            Elmt mungkin anggota / bukan anggota dari S */
    /* F.S. Elmt bukan anggota dari S */
    if(IsMemberSet(*S, Elmt)){
        int i = 0;
        while (S->ke[i] != Elmt){
            i++;
        }
        i--;
        while (i < S->Count){
            S->ke[i] = S->ke[i+1];
            i++;
        }
        S->Count--;
    }
}

// Apakah lagu terdapat pada album tersebut
boolean IsMemberSet(SetInfoLagu S, setinfotype Elmt){
    /* Mengembalikan true jika Elmt adalah member dari S */
    int i = 0;
    boolean found = false;
    while (i < S.Count && !found){
        if (S.ke[i] == Elmt){
            found = true;
        }
        i++;
    }
    return found;
}