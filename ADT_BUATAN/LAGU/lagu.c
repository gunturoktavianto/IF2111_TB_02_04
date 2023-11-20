#include "lagu.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySetLagu(SetLagu *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetLagu(SetLagu S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFullSetLagu(SetLagu S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void InsertSetLagu(SetLagu *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMemberSetLagu(*S, Elmt))
    {
        return;
    }
    S->InfoLagu[S->Count] = Elmt;
    S->Count++;
}

void DeleteSetLagu(SetLagu *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMemberSetLagu(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (IsWordEq((*S).InfoLagu[idx].nama, Elmt.nama) && IsWordEq((*S).InfoLagu[idx].album, Elmt.album) && IsWordEq((*S).InfoLagu[idx].penyanyi, Elmt.penyanyi))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->InfoLagu[iterator - 1] = S->InfoLagu[iterator];
    }
    S->Count--;
}

boolean IsMemberSetLagu(SetLagu S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    address idx = 0;
    while (idx < S.Count)
    {
        if (IsWordEq(S.InfoLagu[idx].nama, Elmt.nama) && IsWordEq(S.InfoLagu[idx].album, Elmt.album) && IsWordEq(S.InfoLagu[idx].penyanyi, Elmt.penyanyi))
            return true;
        idx++;
    }
    return false;
}

void PrintLagu(SetLagu S){
/* Mencetak keseluruhan elemen lagu*/
/* Format: [Penyanyi, Album, Nama]*/
    int idx = 0;
    while (idx < S.Count){
        printf("[%s, %s, %s]\n", 
        S.InfoLagu[idx].penyanyi.TabWord, 
        S.InfoLagu[idx].album.TabWord, 
        S.InfoLagu[idx].nama.TabWord);
        idx++;
    }
}

Lagu MakeLagu(Word penyanyi, Word album, Word nama){
/* Mengisi Lagu*/
    Lagu temp;
    temp.nama = nama;
    temp.album = album;
    temp.penyanyi = penyanyi;
    return temp;
}

SetLagu MakeSetLagu(int jumlahlagu){
/* Mengisi Lagu*/
    SetLagu temp;
    int i=0;
    while (i<jumlahlagu){
        char strnama[30], stralbum[30], strpenyanyi[30]; 
        printf("Input penyanyi, album, dan nama lagu ke-%d:\n", i+1);
        scanf(" %[^\n]",strpenyanyi);
        scanf(" %[^\n]",stralbum);
        scanf(" %[^\n]",strnama);
        temp.InfoLagu[i]=MakeLagu(toKata(strpenyanyi),toKata(stralbum),toKata(strnama));
        i++;
    }
    return temp;
}