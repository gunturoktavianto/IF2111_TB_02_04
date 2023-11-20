#include "queuelagu.h"

int main() {
    // Create a queue
    Queue myQueue;
    CreateQueueLagu(&myQueue);

    // Enqueue some elements
    ElTypeQueue newLagu;
    //newLagu.nama.Length = 9;
    /*
    for (int i = 0; i < newLagu.nama.Length; i++) {
        newLagu.nama.TabWord[newLagu.nama.Length] = '\0';
    }
    for (int j = 0; j < newLagu.nama.Length; j++) {
        newLagu.nama.TabWord[i] = "Nama Lagu"[j];
    }

    newLagu.album.Length = 10;
    for (int i = 0; i < newLagu.album.Length; i++) {
        newLagu.album.TabWord[newLagu.album.Length] = '\0';
    }
    for (int i = 0; i < newLagu.album.Length; i++) {
        newLagu.album.TabWord[i] = "Nama Album"[i];
    }
    */
    int i=0, N;
    printf("Masukkan jumlah lagu: ");
    scanf("%d",&N);
    while(i<N){
        printf("1. ");
        char strlagu[30];
        scanf(" %[^\n]",strlagu);
        newLagu.nama = toKata(strlagu);
        
        printf("2. ");
        char stralbum[30];
        scanf(" %[^\n]",stralbum);
        newLagu.album = toKata(stralbum);

        printf("3. ");
        char strpenyanyi[30];
        scanf(" %[^\n]",strpenyanyi);
        newLagu.penyanyi = toKata(strpenyanyi);
        
        enqueueLagu(&myQueue, newLagu);
        i++;
    }


    // Initialize the elements with appropriate values

    // Display the queue
    printf("Queue Contents:\n");
    displayQueueLagu(myQueue);

    // Dequeue an element
    ElTypeQueue dequeuedElement;
    dequeueLagu(&myQueue, &dequeuedElement);

    // Display the updated queue
    printf("Queue After Dequeue:\n");
    displayQueueLagu(myQueue);

    // Test other queue operations as needed

    return 0;
}