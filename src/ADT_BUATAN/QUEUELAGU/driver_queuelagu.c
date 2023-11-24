#include "queuelagu.h"

int main() {
    ArrayDin arr = MakeArrayDin();
    printf("Kapasitas arrdin: %d\n", arr.Capacity);

    Queuelagu q;
    CreateQueueLagu(&q);

    ElTypeQueue song1, song2, song3;
    InitializeWord(&song1.nama, "Song1");
    InitializeWord(&song1.album, "Album1");
    InitializeWord(&song1.penyanyi, "Penyanyi1");

    InitializeWord(&song2.nama, "Song2");
    InitializeWord(&song2.album, "Album2");
    InitializeWord(&song2.penyanyi, "Penyanyi2");

    InitializeWord(&song3.nama, "Song3");
    InitializeWord(&song3.album, "Album3");
    InitializeWord(&song3.penyanyi, "Penyanyi3");

    enqueueLagu(&q, song1);
    enqueueLagu(&q, song2);
    enqueueLagu(&q, song3);

    printf("Queue setelah di enqueue:\n");
    displayQueueLagu(q);

    ElTypeQueue dequeueSong;
    dequeueLagu(&q, &dequeueSong);
    printf("\nHasil dequeue:\n");
    printf("Lagu yang di dequeue: %s - %s - %s\n", dequeueSong.penyanyi.TabWord, dequeueSong.nama.TabWord, dequeueSong.album.TabWord);

    Queuelagu copiedQueue;
    CreateQueueLagu(&copiedQueue);
    copyQueueLagu(&q, &copiedQueue);
    printf("\nQueue hasil copy:\n");
    displayQueueLagu(copiedQueue);

    ElTypeQueue searchSong;
    InitializeWord(&searchSong.nama, "Song2");
    InitializeWord(&searchSong.album, "Album2");
    InitializeWord(&searchSong.penyanyi, "Penyanyi2");

    if (isInQueueLagu(q, searchSong)) {
        printf("\n%s - %s - %s tidak terdapat dalam queue.\n", searchSong.penyanyi.TabWord, searchSong.nama.TabWord, searchSong.album.TabWord);
    } else {
        printf("\n%s - %s - %s tidak terdapat dalam queue.\n", searchSong.penyanyi.TabWord, searchSong.nama.TabWord, searchSong.album.TabWord);
    }

    Queuelagu reversedQueue;
    CreateQueueLagu(&reversedQueue);
    transferReverseQueueLagu(&q, &reversedQueue);
    printf("\nReversed Queue:\n");
    displayQueueLagu(reversedQueue);

    return 0;
}
