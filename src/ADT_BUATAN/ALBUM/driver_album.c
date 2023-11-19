#include "album.h"

//
Album album;

int main() {
    // Kamus lokal
    int i=0,N;

    // Generalisasi 
    CreateEmptyAlbum(&album);

    // input sebanyak jumlah album
    printf("Jumlah album yang ingin dimasukkan: ");
    scanf("%d",&N);
    while(i<N){
        char strkey[30]; 
        printf("Input nama album ke-%d: ", i+1);
        scanf(" %[^\n]",strkey);
        album.InfoAlbum[i].Key=toKata(strkey);
        album.InfoAlbum[i].Key.TabWord[stringLength(strkey)] = '\0';
        album.Count++;
        i++;
    }

    // Print the Album
    printf("\nAlbum setelah input: \n");
    PrintAlbum(album);

    // Buat lagu dummy
    SetLagu lagu;
    CreateEmptySetLagu(&lagu);
    lagu.Count = 1;
    lagu.InfoLagu[0].penyanyi = toKata("OLIV");
    lagu.InfoLagu[0].album = toKata("BOSSCHA");
    lagu.InfoLagu[0].nama = toKata("RUNGKAD");

    // Initialize value here
    InsertAlbum(&album, toKata("HARTA"), lagu);

    printf("\nAlbum setelah insert: \n");
    PrintAlbum(album);

    // Test IsMemberAlbum
    if (IsMemberAlbum(album, toKata("HARTA"))) {
        printf("Test IsMemberAlbum: Passed\n");
    } else {
        printf("Test IsMemberAlbum: Failed\n");
    }

    // Test DeleteAlbum
    DeleteAlbum(&album, toKata("HARTA"));

    // Test IsEmptyAlbum again
    if (IsEmptyAlbum(album)) {
        printf("Album kosong\n");
    } else {
        printf("Album tidak kosong\n");
    }

    return 0;
}
