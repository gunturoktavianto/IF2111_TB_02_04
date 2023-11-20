#include "album.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyAlbum(Album *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Album M kosong berkapasitas MaxEl */
/* Ciri Album kosong : count bernilai Nil */
    (*M).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyAlbum(Album M){
/* Mengirim true jika Album M kosong*/
/* Ciri Album kosong : count bernilai Nil */
    return M.Count == Nil;
}

boolean IsFullAlbum(Album M){
/* Mengirim true jika Album M penuh */
/* Ciri Album penuh : count bernilai MaxEl */
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Album ********* */
valuetypeAlbum ValueAlbum(Album M, keytype k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan valuetypeAlbum.Count == 0 */
    address idx = 0;

    while (idx < M.Count) {
        if (IsWordEq(M.InfoAlbum[idx].Key,k)) 
            return M.InfoAlbum[idx].Value;
        idx++;
    }
    valuetypeAlbum temp;
    temp.Count=0;
    return temp;
}

boolean IsMemberAlbum(Album M, keytype k){
/* Apakah NamaAlbum tertentu terdapat pada album penyanyi tertentu*/
/* Mengembalikan true jika k adalah member dari M */
    address idx = 0;
    while (idx < M.Count) {
        if (IsWordEq(M.InfoAlbum[idx].Key,k)) return true;
        idx++;
    }
    return false;
}

void InsertAlbum(Album *M, keytype k, valuetypeAlbum v){
/* Menambahkan Elmt sebagai elemen Album M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (IsMemberAlbum(*M, k)) return;

    M->InfoAlbum[M->Count].Key = k;
    M->InfoAlbum[M->Count].Value = v;
    M->Count++;
}

void DeleteAlbum(Album *M, keytype k){
/* Menghapus Elmt dari Album M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M 
        (Map, NamaAlbum) yang ingin dihapus*/
/* F.S. element dengan key k bukan anggota dari M */
    if (!IsMemberAlbum(*M, k)) return;
    address idx = 0, i;

    // mencari index
    while (idx < (*M).Count) {
        if (IsWordEq((*M).InfoAlbum[idx].Key,k)) break;
        idx++;
    }

    for (i = (idx + 1); i < (*M).Count; i++) {
        M->InfoAlbum[i - 1].Key = M->InfoAlbum[i].Key;
        M->InfoAlbum[i - 1].Value = M->InfoAlbum[i].Value;
    }

    (*M).Count--;
}

void PrintAlbum(Album M){
/* Mencetak keseluruhan elemen album*/
/* Format: 
[Penyanyi, Album, Nama]
[Penyanyi, Album, Nama]*/
    int idx = 0;
    while (idx < M.Count){
        printf("%s\n",M.InfoAlbum[idx].Key.TabWord);
        PrintLagu(M.InfoAlbum[idx].Value);
        idx++;
    }
}

Album MakeAlbum(valuetypeAlbum setlagu, int jumlahalbum){
/* Mengisi Lagu*/
    Album temp;
    int i=0;
    while (i<jumlahalbum){
        temp.Count++;
        // Buat album baru
        char strnama[30];
        printf("Input nama album ke-%d: ", i+1);
        scanf(" %[^\n]",strnama);
        temp.InfoAlbum[i].Key=toKata(strnama);
        temp.InfoAlbum[i].Key.TabWord[stringLength(strnama)] = '\0';

        // Isi album baru dengan setlagu
        int N;
        printf("Input jumlah lagu dalam album ke-%d: ", i+1);
        scanf("%d",&N);
        temp.InfoAlbum[i].Value=MakeSetLagu(N); 

        // Crosscheck nama album baru = nama album dalam setlagu baru
        int j=0;
        while(!IsMemberAlbum(temp, temp.InfoAlbum[i].Value.InfoLagu[j].album)){
            printf("Nama album lagu harus sesuai dengan nama album baru\n");
            temp.InfoAlbum[i].Value=MakeSetLagu(N); 
            j++;
        }
        
        printf("\n");
        i++;
    }
    return temp;
}