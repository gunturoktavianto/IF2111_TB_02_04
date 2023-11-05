#include <stdio.h>
#include "hashmap.h"

/* *** Konstruktor/Kreator *** */
void CreateHash(HashMap *M){
    /* I.S. Sembarang */
    /* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
    /* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */
    for (int i=0; i<MaxEl; i++)
    {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
    M->Count = Nil;
}

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
    /* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */
    return (K % MaxEl);
}

/* ********** Operator Dasar HashMap ********* */
valuetype ValueHash(HashMap M, keytype k){
    /* Mengembalikan nilai value dengan key k dari M */
    /* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    int idx = Hash(k);
    if (M.Elements[idx].Key == Undefined)
    {
        return Undefined;
    }
    else
    {
        for (int i=idx; i<MaxEl; i++)
        {
            if (M.Elements[i].Key == k)
            {
                return M.Elements[i].Value;
            }
        }
        return Undefined;
    }
}

void InsertHash(HashMap *M, keytype k, valuetype v){
    /* Menambahkan Elmt sebagai elemen HashMap M. */
    /* I.S. M mungkin kosong, M tidak penuh
            M mungkin sudah beranggotakan v dengan key k */
    /* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
            index yang digunakan untuk menyimpan v adalah hash dari k
            gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */
    int idx = Hash(k);

    while((*M).Elements[idx].Key != Undefined) 
    {
        idx = (idx + 1) % MaxEl;
    }
    (*M).Elements[idx].Value = v;
    (*M).Elements[idx].Key = k;
    (*M).Count++;
}            

int MaxSub(int *arr, int n) {
    HashMap m;
    CreateHash(&m);
    int sum = 0;
    int maxlen = 0;
    for (int i=0; i<n; i++)
    {   
        sum += arr[i];
    }
    return maxlen;
}

void PrintHashMap(HashMap M) {
    for (int i=0; i<MaxEl; i++)
    {
        if (M.Elements[i].Key != Undefined)
        {
            printf("<%d, %d>\n", M.Elements[i].Key, M.Elements[i].Value);
        }
    }
}