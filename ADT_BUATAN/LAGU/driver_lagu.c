#include "lagu.h"

// Deklarasi global"
SetLagu lagu;

int main(){
    // Kamus lokal
    int i=0, N;
    
    // Generalisasi
    CreateEmptySetLagu(&lagu);

    // input sebanyak jumlah lagu
    printf("Jumlah lagu yang ingin dimasukkan: ");
    scanf("%d",&N);
    while(i<N){
        char strnama[30], stralbum[30], strpenyanyi[30]; 
        printf("Input penyanyi lagu ke-%d: ", i+1);
        scanf(" %s[^\n]",strpenyanyi);
        lagu.InfoLagu[i].penyanyi=toKata(strpenyanyi);
        lagu.InfoLagu[i].penyanyi.TabWord[stringLength(strpenyanyi)] = '\0';
        printf("Input album lagu ke-%d: ", i+1);
        scanf(" %s[^\n]",stralbum);
        lagu.InfoLagu[i].album=toKata(stralbum);
        lagu.InfoLagu[i].album.TabWord[stringLength(stralbum)] = '\0';
        printf("Input nama lagu ke-%d: ", i+1);
        scanf(" %s[^\n]",strnama);
        lagu.InfoLagu[i].nama=toKata(strnama);
        lagu.InfoLagu[i].nama.TabWord[stringLength(strnama)] = '\0';
        lagu.Count++;
        i++;
    }
    // Print the SetLagu
    printf("\n SetLagu setelah input: \n");
    PrintLagu(lagu);

    // Insert [OLIV, BOSSCHA, RUNGKAD]
    InsertSetLagu(&lagu, MakeLagu(toKata("OLIV"), toKata("BOSSCHA"), toKata("RUNGKAD")));
    printf("\nSetLagu setelah ditambah lagu RUNGKAD: \n");
    PrintLagu(lagu);

    // Delete 
    DeleteSetLagu(&lagu, MakeLagu(toKata("OLIV"), toKata("BOSSCHA"), toKata("RUNGKAD")));
    printf("\nSetLagu setelah lagu RUNGKAD dihapus: \n");
    PrintLagu(lagu);

    return 0;
}

