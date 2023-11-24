#include "playlist.c"

int main() {
    // Your testing code here
    ArrayDin daftarPlaylist = MakeArrayDin();

    // Test InsertAtArrayDin
    List playlist1, playlist2;
    CreateEmptyPlaylist((Word){"Playlist1", 9}, &playlist1);
    CreateEmptyPlaylist((Word){"Playlist2", 9}, &playlist2);

    InsertAtArrayDin(&daftarPlaylist, playlist1, 0);
    InsertAtArrayDin(&daftarPlaylist, playlist2, 1);

    // Test DisplayDaftarPlaylist
    printf("Daftar Playlist:\n");
    DisplayDaftarPlaylist(daftarPlaylist);

    // Test InsVFirst and InsVLast
    infotype lagu1 = {{"Lagu1", 5}, {"Album1", 6}, {"Penyanyi1", 9}};
    infotype lagu2 = {{"Lagu2", 5}, {"Album2", 6}, {"Penyanyi2", 9}};

    InsVFirst(&playlist1, lagu1);
    InsVLast(&playlist1, lagu2);

    // Test DisplayLaguPlaylist
    DisplayLaguPlaylist(playlist1);

    // Test DelVFirst and DelVLast
    infotype deletedLagu;
    DelVFirst(&playlist1, &deletedLagu);
    printf("Deleted Lagu: %s\n", deletedLagu.nama.TabWord);

    DelVLast(&playlist1, &deletedLagu);
    printf("Deleted Lagu: %s\n", deletedLagu.nama.TabWord);

    // Test DisplayLaguPlaylist after deletion
    printf("Daftar lagu setelah penghapusan:\n");
    DisplayLaguPlaylist(playlist1);

    // Test InsertAfter and DelP
    infotype lagu3 = {{"Lagu3", 5}, {"Album3", 6}, {"Penyanyi3", 9}};
    alamat P = alamatIndeksKe(playlist1, 0);

    InsertAfter(&playlist1, Alokasi(lagu3), P);
    printf("Daftar lagu setelah penambahan:\n");
    DisplayLaguPlaylist(playlist1);

    DelP(&playlist1, lagu2);
    printf("Daftar lagu setelah penghapusan Lagu2:\n");
    DisplayLaguPlaylist(playlist1);

    // Test LaguIndeksKe
    int indexToRetrieve = 0;
    Lagu retrievedLagu = LaguIndeksKe(playlist1, indexToRetrieve);
    printf("Lagu pada indeks %d: %s\n", indexToRetrieve, retrievedLagu.nama.TabWord);

    // Test NbElmtPlaylist
    int count = NbElmtPlaylist(playlist1);
    printf("Jumlah lagu dalam playlist: %d\n", count);

    // Deallocation
    DeallocateArrayDin(&daftarPlaylist);

    return 0;
}
