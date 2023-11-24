#include "album.h"

//
Album album;

#include <stdio.h>

int main() {
    Album myAlbum;
    CreateEmptyAlbum(&myAlbum);

    printf("Is Album Empty? %s\n", IsEmptyAlbum(myAlbum) ? "Yes" : "No");

    keytype albumKey = toKata("MyAlbum");
    valuetypeAlbum songSet = MakeSetLagu(3);

    InsertAlbum(&myAlbum, albumKey, songSet);

    printf("Is '%s' in the Album? %s\n", albumKey.TabWord,
           IsMemberAlbum(myAlbum, albumKey) ? "Yes" : "No");

    valuetypeAlbum retrievedSet = ValueAlbum(myAlbum, albumKey);
    printf("Number of songs in '%s' album: %d\n", albumKey.TabWord, retrievedSet.Count);

    printf("\n Album:\n");
    PrintAlbum(myAlbum);

    keytype albumKeyToDelete = toKata("NonExistentAlbum");
    printf("\nDeleting '%s' album...\n", albumKeyToDelete.TabWord);
    DeleteAlbum(&myAlbum, albumKeyToDelete);

    printf("\nAlbum after deletion:\n");
    PrintAlbum(myAlbum);

    Album newAlbum = MakeAlbum(MakeSetLagu(2), 2);

    //  the new Album
    printf("\nNew Album:\n");
    PrintAlbum(newAlbum);

    return 0;
}

