#include "playlist.h"
ArrayDin daftarPlaylist;
/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
    ArrayDin arr;
    arr.A=((List*)malloc(InitialSize*sizeof(List)));
    arr.Neff=0;
    arr.Capacity=InitialSize;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
    free((*array).A);
    (*array).Neff=0;
    (*array).Capacity=0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayDin(ArrayDin array)
{
    return (array.Neff==0);
}
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayDin(ArrayDin array)
{
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
List GetArrayDin(ArrayDin array, IdxType i)
{
    return *(array.A+i);
}
/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityArrayDin(ArrayDin array)
{
    return array.Capacity;
}
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtArrayDin(ArrayDin *array, List el, IdxType i)
{ 
    if ((*array).Neff>=(*array).Capacity)
    {
        List *tmpArray;
        tmpArray=(List*)malloc(InitialSize*sizeof(List));
        for(int j=0; j<(*array).Neff; j++) *(tmpArray+j)=*((*array).A+j);
        free((*array).A);
        (*array).A=(List*)malloc((InitialSize*2)*sizeof(List));
        for (int j=0; j<(*array).Neff; j++) *((*array).A+j)=*(tmpArray+j);
    }
    for(int j=(*array).Neff-1; j>=i; j--) *((*array).A+j+1)=*((*array).A+j);
    *((*array).A+i)=el;
    (*array).Neff++;
}
/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtArrayDin(ArrayDin *array, IdxType i)
{
    if((*array).Neff>(*array).Capacity/4)
    {
        (*array).Neff--;
        for (int j=i; j<(*array).Neff; j++)
        {
            *((*array).A+j)=*((*array).A+j+1);
        }
    }
    else
    {
        int newcap;
        if(InitialSize>(*array).Capacity) newcap=InitialSize;
        else newcap=(*array).Capacity;
        List *tmpArray;
        tmpArray=(List*)malloc(newcap*sizeof(List));
        for(int j=0; j<(*array).Neff; j++) *(tmpArray+j)=*((*array).A+j);
        (*array).Neff--;
        for (int j=i; j<(*array).Neff; j++)
        {
            *(tmpArray+j)=*(tmpArray+j+1);
        }
        free((*array).A);
        (*array).A=(List*)malloc(newcap*sizeof(List));
        for (int j=0; j<(*array).Neff; j++) *((*array).A+j)=*(tmpArray+j);
        (*array).Capacity=newcap;
        free(tmpArray);
    }
}

boolean IsEmptyLinkedList (List L)
/* Mengirim true jika list kosong */
{
    return First(L)==Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyPlaylist (Word w, List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    for(int i=0; i<NMax; i++) (*L).NamaPlaylist.TabWord[i]='\0';
    (*L).NamaPlaylist=w;
    First(*L)=Nil;
}
/****************** Manajemen Memori ******************/
alamat Alokasi (infotype X)
/* Mengirimkan alamat hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka alamat tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    alamat P=(alamat) malloc(1*sizeof(ElmtList));
    if (P!=Nil) {Info(P)=X; Next(P)=Nil; return P;}
    else return Nil;
}
void Dealokasi (alamat *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian alamat P */
{
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
alamat SearchPlaylist (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan alamat elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    alamat P=First(L);
    while (P!=Nil)
    {
        if(IsWordEq(Info(P).nama,X.nama)) return P;
        P=Next(P);
    }
    return Nil;
    
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    alamat P=Alokasi(X);
    if (P!=Nil) InsertFirst(L,P);
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    alamat P=Alokasi(X);
    if(P!=Nil) InsertLast(L,P);
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    alamat P;
    DelFirst(L,&P);
    *X=Info(P);
    Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    alamat P;
    DelLast(L,&P);
    *X=Info(P);
    Dealokasi(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, alamat P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-alamat P sebagai elemen pertama */
{
    Next(P)=First(*L);
    First(*L)=P;
}
void InsertAfter (List *L, alamat P, alamat Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P)=Next(Prec);
    Next(Prec)=P;
}
void InsertLast (List *L, alamat P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsEmptyLinkedList(*L)) InsertFirst(L,P);
    else
    {
        alamat Last=First(*L);
        while(Next(Last)!=Nil)
        {
            Last=Next(Last);
        }
        Next(Last)=P;
        Next(P)=Nil;
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, alamat *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P=First(*L);
    First(*L)=Next(*P);
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beralamat P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    alamat P=First(*L);
    infotype y;
    if(Info(P).nama.TabWord==X.nama.TabWord) DelVFirst(L,&y);
    else
    {
        alamat prec=Nil;
        while(P!=Nil)
        {
            if(Info(P).nama.TabWord==X.nama.TabWord)
            {
                DelAfter(L,&P,prec); 
                Dealokasi(&P);
                break;
            }
            prec=P;
            P=Next(P);
        }
    }   
}
void DelLast (List *L, alamat *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    alamat Prec=Nil;
    alamat Loc=First(*L);
    while(Next(Loc)!=Nil)
    {
        Prec=Loc;
        Loc=Next(Loc);
    }
    *P=Loc;
    if(Prec==Nil) {First(*L)=Nil;}
    else Next(Prec)=Nil;
}
void DelAfter (List *L, alamat *Pdel, alamat Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel=Next(Prec);
    Next(Prec)=Next(*Pdel);
}

void DisplayDaftarPlaylist()
{
    for(int i=0; i<LengthArrayDin(daftarPlaylist); i++)
    {
        printf("    %d. %s\n",i+1,daftarPlaylist.A[i].NamaPlaylist.TabWord);
    }
}
void DisplayLaguPlaylist(List L)
{
    printf("Daftar lagu pada playlist %s:\n",L.NamaPlaylist.TabWord);
    alamat P=First(L);
    int i=1;
    while(P!=Nil)
    {
        printf("%d. %s\n",i,Info(P).nama.TabWord);
        P=Next(P);
        i++;
    }
}

Lagu LaguIndeksKe (List l, int idx)
{
    alamat P=First(l);
    int cnt=0;
    while(P!=Nil)
    {
        if(cnt==idx-1) return Info(P);
        cnt++;
        P=Next(P);
    }
    return Info(P);
}
alamat alamatIndeksKe (List l, int idx)
{
    alamat P=First(l);
    int cnt=0;
    while(P!=Nil)
    {
        if(cnt==idx-1) return P;
        cnt++;
        P=Next(P);
    }
    return P;
}

int NbElmtPlaylist (List L){
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count = 0;
    if (!IsEmptyLinkedList(L)){
        alamat P = First(L);
        while (Next(P) != Nil)
        {
            count++;
            P = Next(P);
        }
        count++;
    }
    return count;
}
/****************** PROSES SEMUA ELEMEN LIST ******************/