#include "riwayat.h"
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotypeStack *X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    // KAMUS

    // ALGORTIMA
    printf("n1");
    *X = S->T[S->TOP];
    
    Top(*S)--;
    printf("n3");
}