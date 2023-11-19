#include "album.h"

//
Album album;

int main() {
    // Kamus lokal
    int i=0,N;

    // Generalisasi 
    CreateEmptyAlbum(&album);

    // input sebanyak jumlah album
    printf("Jumlah lagu yang ingin dimasukkan: ");
    scanf("%d",&N);
    while(i<N){
        char strnama[30], stralbum[30], strpenyanyi[30]; 
        printf("Input penyanyi lagu ke-%d: ", i+1);
        scanf(" %[^\n]",strpenyanyi);
        lagu.InfoLagu[i].penyanyi=toKata(strpenyanyi);
        lagu.InfoLagu[i].penyanyi.TabWord[stringLength(strpenyanyi)] = '\0';
        printf("Input album lagu ke-%d: ", i+1);
        scanf(" %[^\n]",stralbum);
        lagu.InfoLagu[i].album=toKata(stralbum);
        lagu.InfoLagu[i].album.TabWord[stringLength(stralbum)] = '\0';
        printf("Input nama lagu ke-%d: ", i+1);
        scanf(" %[^\n]",strnama);
        lagu.InfoLagu[i].nama=toKata(strnama);
        lagu.InfoLagu[i].nama.TabWord[stringLength(strnama)] = '\0';
        lagu.Count++;
        i++;
    }

    // Initialize value here
    InsertAlbum(&album, key, value);

    // Test IsMemberAlbum
    if (IsMemberAlbum(album, key)) {
        printf("Test IsMemberAlbum: Passed\n");
    } else {
        printf("Test IsMemberAlbum: Failed\n");
    }

    // Test ValueAlbum
    valuetype result = ValueAlbum(album, key);
    // Check if result is as expected

    // Test DeleteAlbum
    DeleteAlbum(&album, key);

    // Test IsEmptyAlbum again
    if (IsEmptyAlbum(album)) {
        printf("Test IsEmptyAlbum after DeleteAlbum: Passed\n");
    } else {
        printf("Test IsEmptyAlbum after DeleteAlbum: Failed\n");
    }

    return 0;
}
