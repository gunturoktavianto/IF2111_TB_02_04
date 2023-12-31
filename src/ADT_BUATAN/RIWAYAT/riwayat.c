#include "riwayat.h"

Stack r;

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    // KAMUS

    // ALGORTIMA
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    // KAMUS

    // ALGORTIMA
    return (Top(S)==Nil);
}

boolean IsFullStack(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    // KAMUS

    // ALGORTIMA
    return (Top(S)==MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotypeStack X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    // KAMUS

    // ALGORTIMA
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotypeStack *X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    // KAMUS
    *X = InfoTop(*S);
    Top(*S)--;
}

Stack copyStack(Stack input, Stack *hasil)
{
    // KAMUS
    infotypeStack X;
    Stack temp;
    // ALGORITMA
    CreateStack(&temp);
    while(!IsEmptyStack(input))
    {
        Pop(&input, &X);
        Push(&temp, X);
    }   
    while(!IsEmptyStack(temp))
    {
        Pop(&temp, &X);
        Push(hasil, X);
    }  
    return *hasil; 
}

int NbElmtStack(Stack *S)
{
    // KAMUS
    int count = 0;
    infotypeStack X;
    Stack temp;
    // ALGORITMA
    CreateStack(&temp);
    while(!IsEmptyStack(*S))
    {
        count++;
        Pop(S, &X);
        Push(&temp, X);
        
    }
    while(!IsEmptyStack(temp))
    {
        Pop(&temp, &X);
        Push(S, X);
    }
    return count;
}

void displayStackUrutan(Stack *S)
{
    // KAMUS
    infotypeStack X;
    int j= 1;
    Stack temp;
    // ALGORITMA
    CreateStack(&temp);
    printf("Daftar Riwayat :\n");
    if(IsEmptyStack(*S))
    {
        printf("Riwayatmu Kosong\n");
    }
    while(!IsEmptyStack(*S))
    {
        Pop(S, &X);
        Push(&temp, X);
    }   
    while(!IsEmptyStack(temp))
    {
        Pop(&temp, &X);
        printf("    %d. \"%s\" oleh \"%s\"\n", j, X.nama.TabWord, X.penyanyi.TabWord);
        Push(S, X);
        j++;
    } 
}

void displayRiwayat(Stack *S)
{
    // KAMUS
    infotypeStack X;
    int j= 1;
    Stack temp;
    // ALGORITMA
    CreateStack(&temp);
    printf("Daftar Riwayat :\n");
    if(IsEmptyStack(*S))
    {
        printf("Riwayatmu Kosong\n");
    }
    while(!IsEmptyStack(*S))
    {
        Pop(S, &X);
        printf("    -) \"%s\" oleh \"%s\"\n", X.nama.TabWord, X.penyanyi.TabWord);
        Push(&temp, X);
        j++;
    }   
    while(!IsEmptyStack(temp))
    {
        Pop(&temp, &X);
        Push(S, X);
    } 
}

void ReplaceCS(Stack *S, Lagu L){
/* Mengganti currentsong dengan Lagu L*/
/* Jika tidak Nil, menempatkan currentsong pada stack riwayat paling atas*/
    if (!isEmptyQueueLagu(q))
        Push(S, currentsong);
    currentsong = L;
}

void ReversedStack(Stack *S) {
    /* Membalikan seluruh isi stack S */
    // Create a temporary stack
    Stack temp, temp1;
    CreateStack(&temp);
    CreateStack(&temp1);

    infotypeStack x;
    while (!IsEmptyStack(*S)) {
        Pop(S, &x);
        Push(&temp, x);
    }

    // Copy temp ke temp1
    while (!IsEmptyStack(temp)) {
        Pop(&temp, &x);
        Push(&temp1, x);
    }

    // Copy temp1 ke S
    while (!IsEmptyStack(temp1)) {
        Pop(&temp1, &x);
        Push(S, x);
    }
}
