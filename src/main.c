#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

#define Nil 0
#define MaxEl 100

typedef struct {
    Word nama;
    Word album;
    Word penyanyi;
} Lagu;

typedef Lagu infotype;
typedef int address;

typedef struct
{
    infotype Elements[MaxEl];
    int Count;
} SetLagu;

#define Nil 0
#define MaxEl 10
#define Undefined -999

// typedef int bool;
typedef Word keytype;
typedef SetLagu valuetype;
typedef int address;

typedef struct {
	keytype Key;//NamaAlbum
	valuetype Value;//SetLagu
} infotype;

typedef struct {
	infotype InfoAlbum[MaxEl];
	address Count;
} Album;

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
valuetype ValueAlbum(Album M, keytype k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    address idx = 0, iterator;

    while (idx < M.Count) {
        if (M.InfoAlbum[idx].Key == k) return M.InfoAlbum[idx].Value;
        idx++;
    }

    return Undefined;
}
void InsertAlbum(Album *M, keytype k, valuetype v){
/* Menambahkan Elmt sebagai elemen Album M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (IsMember(*M, k)) return;

    M->InfoAlbum[M->Count].Key = k;
    M->InfoAlbum[M->Count].Value = v;
    M->Count++;
}

void DeleteAlbum(Album *M, keytype k){
/* Menghapus Elmt dari Album M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    if (!IsMember(*M, k)) return;

    boolean found = false;
    address idx = 0, iterator;

    while (idx < M->Count) {
        if (M->InfoAlbum[idx].Key == k) break;
        idx++;
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->InfoAlbum[iterator - 1].Key = M->InfoAlbum[iterator].Key;
        M->InfoAlbum[iterator - 1].Value = M->InfoAlbum[iterator].Value;
    }

    M->Count--;
}

boolean IsMemberAlbum(Album M, keytype k){
/* Mengembalikan true jika k adalah member dari M */
    address idx = 0, iterator;
    
    while (idx < M.Count) {
        if (M.InfoAlbum[idx].Key == k) return true;
        idx++;
    }
    
    return false;
}