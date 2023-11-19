#include "HEADERQUEUE.h"


int main() {
    // Inisialisasi struktur data yang diperlukan
    Queue myQueue;
    List mySongList;
    ArrayDin myPlaylist;
    Map mySongMap;

    // Inisialisasi playlist dan lagu-lagu
    // ... (sesuaikan inisialisasi sesuai dengan struktur data dan kebutuhan program Anda)

    // Contoh penggunaan fungsi queueSong
    queueSong(&myQueue, mySongList);

    // Contoh penggunaan fungsi queuePlaylist
    queuePlaylist(myPlaylist, &myQueue);

    // Contoh penggunaan fungsi swapSongs
    int x = 1, y = 2;
    swapSongs(x, y, &myQueue);

    // Contoh penggunaan fungsi removeSong
    int songIdToRemove = 3;
    removeSong(songIdToRemove, &myQueue, mySongMap);

    // Contoh penggunaan fungsi clearQueue
    clearQueue(&myQueue);

    displayQueue(myQueue);

    return 0;
}
