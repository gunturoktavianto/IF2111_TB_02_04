#include "penyanyi.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyPenyanyi(Penyanyi *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Penyanyi M kosong berkapasitas MaxEl */
/* Ciri Penyanyi kosong : count bernilai Nil */
    // KAMUS

    // ALGORITMA
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyPenyanyi(Penyanyi M){
/* Mengirim true jika Penyanyi M kosong*/
/* Ciri Penyanyi kosong : count bernilai Nil */
    // KAMUS

    // ALGORITMA
    return M.Count == Nil;
}

boolean IsFullPenyanyi(Penyanyi M){
/* Mengirim true jika Penyanyi M penuh */
/* Ciri Penyanyi penuh : count bernilai MaxEl */
    // KAMUS

    // ALGORITMA
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Penyanyi ********* */
valuetypePenyanyi ValuePenyanyi(Penyanyi *M, keytype *k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
   /* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan valuetypePenyanyi.Count == 0 */
    // KAMUS
    address idx = 0;
    // ALGORTIMA
    while (idx < (*M).Count) {
        if (IsWordEq((*M).InfoPenyanyi[idx].Key,(*k))) 
            return (*M).InfoPenyanyi[idx].Value;
        idx++;
    }
    valuetypePenyanyi temp;
    temp.Count=0;
    return temp;
}

void InsertPenyanyi(Penyanyi *M, keytype *k, valuetypePenyanyi *v){
/* Menambahkan Elmt sebagai elemen Penyanyi M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    // KAMUS

    // ALGORITMA
    if (IsMemberPenyanyi(M, k)) return;
    
    M->InfoPenyanyi[M->Count].Key = *k;
    M->InfoPenyanyi[M->Count].Key.TabWord[M->InfoPenyanyi[M->Count].Key.Length]='\0';
    M->InfoPenyanyi[M->Count].Value = *v;
    M->Count++;
}

void DeletePenyanyi(Penyanyi *M, keytype *k){
/* Menghapus Elmt dari Penyanyi M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    // KAMUS
    address idx = 0, i;

    // ALGORITMA
    if (!IsMemberPenyanyi(M, k)) return;
    
    while (idx < M->Count) {
        if (IsWordEq(M->InfoPenyanyi[idx].Key, *k)) break;
        idx++;
    }

    for (i = (idx + 1); i < M->Count; i++) {
        M->InfoPenyanyi[i - 1].Key = M->InfoPenyanyi[i].Key;
        M->InfoPenyanyi[i - 1].Value = M->InfoPenyanyi[i].Value;
    }

    M->Count--;
}

void printPenyanyi(Penyanyi *penyanyi)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i =0;
    // ALGORITMA
    printf("Daftar Penyanyi :\n");
    for(i = 0; i< penyanyi->Count ; i++)
    {
        printf("    %d. %s\n", i+1,penyanyi->InfoPenyanyi[i].Key.TabWord);
    }   
}

int IdxPenyanyi(Penyanyi *M, keytype k){
/* Mengembalikan true jika k adalah member dari M */
    // KAMUS
    address idx = 0, iterator;
    boolean found = false;
    // ALGORITMA
    while (idx < M->Count && !found) {
        if (IsWordEq(M->InfoPenyanyi[idx].Key,k)) found = true;
        else idx++;
    }
    
    return idx;
}

boolean IsMemberPenyanyi(Penyanyi *M, keytype *k){
/* Mengembalikan true jika k adalah member dari M */
    // KAMUS
    address idx = 0;
    
    // ALGORITMA
    while (idx < (*M).Count) {
        if (IsWordEq((*M).InfoPenyanyi[idx].Key,*k)) return true;
        idx++;
    }
    
    return false;
}

/* *** Konstruktor/Kreator *** */
void CreateEmptyListPenyanyi(ListPenyanyi*S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah List S kosong berkapasitas MaxEl */
/* Ciri List kosong : count bernilai Nil */
    // KAMUS

    // ALGORITMA
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyListPenyanyi(ListPenyanyi S){
/* Mengirim true jika List S kosong*/
/* Ciri List kosong : count bernilai Nil */
    // KAMUS

    // ALGORITMA
    return S.Count == Nil;
}

boolean IsFullListPenyanyi(ListPenyanyi S){
/* Mengirim true jika List S penuh */
/* Ciri List penuh : count bernilai MaxEl */
    // KAMUS

    // ALGORITMA
    return S.Count == MaxEl;
}

/* ********** Operator Dasar List ********* */
void InsertListPenyanyi(ListPenyanyi *S, infotypePenyanyi *Elmt){
/* Menambahkan Elmt sebagai elemen List S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
    // KAMUS

    // ALGORITMA
    if (IsMemberListPenyanyi(S, Elmt)) return;
    S->PenyanyiKe[S->Count].InfoPenyanyi[S->Count].Key = (*Elmt).Key;
    S->PenyanyiKe[S->Count].InfoPenyanyi[S->Count].Key.TabWord[ S->PenyanyiKe[S->Count].InfoPenyanyi[S->Count].Key.Length]='\0';
    S->PenyanyiKe[S->Count].InfoPenyanyi[S->Count].Value = (*Elmt).Value;
    S->Count++;
}

void DeleteListPenyanyi(ListPenyanyi *S, infotypePenyanyi *Elmt){
/* Menghapus Elmt dari List S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
    // KAMUS
    address idx = 0, i;

    // ALGORITMA
    if (!IsMemberListPenyanyi(S, Elmt)) return;
    
    while (idx < S->Count) {
        if (IsWordEq(S->PenyanyiKe[idx].InfoPenyanyi[idx].Key, (*Elmt).Key)) break;
        idx++;
    }

    for (i = (idx + 1); i < S->Count; i++) {
        S->PenyanyiKe[i - 1].InfoPenyanyi[i - 1].Key = S->PenyanyiKe[i].InfoPenyanyi[i].Key;
        S->PenyanyiKe[i - 1].InfoPenyanyi[i - 1].Value = S->PenyanyiKe[i].InfoPenyanyi[i].Value;
    }
    S->Count--;
}

boolean IsMemberListPenyanyi(ListPenyanyi *S, infotypePenyanyi *Elmt){
/* Mengembalikan true jika Elmt adalah member dari S */
    // KAMUS
    address idx = 0;
    
    // ALGORITMA
    while (idx < S->Count) {
        if (IsWordEq(S->PenyanyiKe[idx].InfoPenyanyi[idx].Key, Elmt->Key )) return true;
        idx++;
    }
    
    return false;
}

void printdaftarPenyanyi(ListPenyanyi *daftarpenyanyi)
{
    // Menampilkan list penyanyi yang ada
    // KAMUS
    int i =0;
    // ALGORITMA
    printf("Daftar List Penyanyi :\n");
    for(i = 0; i< daftarpenyanyi->Count ; i++)
    {
        printf("    %d. %s\n", i+1, daftarpenyanyi->PenyanyiKe[i].InfoPenyanyi[i].Key.TabWord);
    }   
}

int IdxDaftarPenyanyi(ListPenyanyi *M, keytype k){
/* Mengembalikan true jika k adalah member dari M */
    // KAMUS
    address idx = 0, iterator;
    boolean found = false;
    // ALGORITMA
    while (idx < M->Count && !found) {
        if (IsWordEq(M->PenyanyiKe[idx].InfoPenyanyi[idx].Key,k)) found = true;
        else idx++;
    }
    
    return idx;
}

void MakePenyanyiDummy()
{
    // KAMUS
    Penyanyi penyanyi;
    Word namapenyanyi1,namapenyanyi2;
    Album albumRamadhan, FavianRuleTheWorld;
    // ALGORITMA
    CreateEmptyPenyanyi(&penyanyi);
    namapenyanyi1 = toKata("Ramadhan Bintang");
    namapenyanyi2 = toKata("Favian Ganz");
    InsertPenyanyi(&penyanyi, &namapenyanyi1, &albumRamadhan);
    InsertPenyanyi(&penyanyi, &namapenyanyi2, &FavianRuleTheWorld);
}

void makeListPenyanyi()
{
    Word namapenyanyi1,namapenyanyi2;
    ListPenyanyi daftarpenyanyi;
    Album albumRamadhan, FavianRuleTheWorld;
    infotypePenyanyi elmt1, elmt2;
    // ALGORITMA
    CreateEmptyListPenyanyi(&daftarpenyanyi);
    namapenyanyi1 = toKata("Ramadhan Bintang");
    namapenyanyi2 = toKata("Favian Ganz");
    elmt1.Key = namapenyanyi1;
    elmt2.Key = namapenyanyi2;
    elmt1.Value = albumRamadhan;
    elmt2.Value = FavianRuleTheWorld;   
    InsertListPenyanyi(&daftarpenyanyi, &elmt1);
    InsertListPenyanyi(&daftarpenyanyi, &elmt2);
}

boolean AnggotaListPenyanyi(ListPenyanyi *M, keytype *k)
{
    /* Mengembalikan true jika k adalah member dari M */
    // KAMUS
    address idx = 0;
    
    // ALGORITMA
    while (idx < (*M).Count) {
        if (IsWordEq((*M).PenyanyiKe[idx].InfoPenyanyi[idx].Key,*k)) return true;
        idx++;
    }
    
    return false;
}