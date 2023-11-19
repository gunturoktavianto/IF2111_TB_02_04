#include "lagu.h"
#include <string.h>

// Deklarasi global"
SetLagu lagu;

int main(){
    // Kamus lokal

    // Generalisasi
    CreateEmptySetLagu(&lagu);

    // Insert lagu baru newLagu
    Lagu newLagu;
    newLagu.nama.Length = 9;
    for (int i = 0; i < newLagu.nama.Length; i++) {
        newLagu.nama.TabWord[i] = "Nama Lagu"[i];
    }
    newLagu.nama.TabWord[newLagu.nama.Length] = '\0';

    newLagu.album.Length = 10;
    for (int i = 0; i < newLagu.album.Length; i++) {
        newLagu.album.TabWord[i] = "Nama Album"[i];
    }
    newLagu.album.TabWord[newLagu.album.Length] = '\0'; 

    newLagu.penyanyi.Length = 13;
    for (int i = 0; i < newLagu.penyanyi.Length; i++) {
        newLagu.penyanyi.TabWord[i] = "Nama Penyanyi"[i];
    }
    newLagu.penyanyi.TabWord[newLagu.penyanyi.Length] = '\0';

    // Insert the new Lagu into the SetLagu
    if (!IsFullSetLagu(lagu)) {
        InsertSetLagu(&lagu, newLagu);
    }

    // Print the SetLagu
    PrintLagu(lagu);

    return 0;
}