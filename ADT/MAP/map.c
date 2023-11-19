#include "map.h"

/* *** Konstruktor/Kreator Penyanyi*** */
void CreateMapAlbum(MapInfoAlbum *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    (*M).jumlahLagu = mapNil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMapAlbum(MapInfoAlbum M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.jumlahLagu == mapNil;
}

boolean IsFullMapAlbum(MapInfoAlbum M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.jumlahLagu == mapMaxEl;
}

/* ********** Operator Dasar Map ********* */
mapvaluetype ValueMapAlbum(MapInfoAlbum M, mapkeytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    int idx = 0, iterator;

    while (idx < M.Count) {
        if (M.Elements[idx].Key == k) return M.Elements[idx].Value;
        idx++;
    }

    return mapUndefined;
}

void InsertMapAlbum(MapInfoAlbum *M, mapkeytype k, mapvaluetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMemberMap(*M, k)) return;

    M->Elements[M->Count].Key = k;
    M->Elements[M->Count].Value = v;
    M->Count++;
}

void DeleteMapAlbum(MapInfoAlbum *M, mapkeytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    if (!IsMemberMapAlbum(*M, k)) return;

    boolean found = false;
    int idx = 0, iterator;

    while (idx < M->Count) {
        if (M->Elements[idx].Key == k) break;
        idx++;
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->Elements[iterator - 1].Key = M->Elements[iterator].Key;
        M->Elements[iterator - 1].Value = M->Elements[iterator].Value;
    }

    M->Count--;
}

boolean IsMemberMapAlbum(MapInfoAlbum M, mapkeytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int idx = 0, iterator;
    
    while (idx < M.Count) {
        if (M.Elements[idx].Key == k) return true;
        idx++;
    }
    
    return false;
}

/* *** Konstruktor/Kreator Penyanyi*** */
void CreateMapPenyanyi(MapInfoPenyanyi *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    (*M).jumlahAlbum = mapNil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMapPenyanyi(MapInfoPenyanyi M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.jumlahAlbum == mapNil;
}

boolean IsFullMapPenyanyi(MapInfoPenyanyi M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.jumlahAlbum == mapMaxEl;
}

/* ********** Operator Dasar Map ********* */
mapvaluetype ValueMapPenyanyi(MapInfoPenyanyi M, mapkeytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    int idx = 0, iterator;

    while (idx < M.Count) {
        if (M.Elements[idx].Key == k) return M.Elements[idx].Value;
        idx++;
    }

    return mapUndefined;
}

void InsertMapPenyanyi(MapInfoPenyanyi *M, mapkeytype k, mapvaluetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMemberMap(*M, k)) return;

    M->Elements[M->Count].Key = k;
    M->Elements[M->Count].Value = v;
    M->Count++;
}

void DeleteMapPenyanyi(MapInfoPenyanyi *M, mapkeytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    if (!IsMemberMapPenyanyi(*M, k)) return;

    boolean found = false;
    int idx = 0, iterator;

    while (idx < M->Count) {
        if (M->Elements[idx].Key == k) break;
        idx++;
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->Elements[iterator - 1].Key = M->Elements[iterator].Key;
        M->Elements[iterator - 1].Value = M->Elements[iterator].Value;
    }

    M->Count--;
}

boolean IsMemberMapPenyanyi(MapInfoPenyanyi M, mapkeytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int idx = 0, iterator;
    
    while (idx < M.Count) {
        if (M.Elements[idx].Key == k) return true;
        idx++;
    }
    
    return false;
}