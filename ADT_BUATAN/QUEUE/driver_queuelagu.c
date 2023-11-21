#include "queuelagu.h"

int main() {
    // Create a queue
    Queue myQueue;
    CreateQueueLagu(&myQueue);

    // Enqueue some elements
    ElTypeQueue newLagu;
    newLagu.nama.Length = 15;
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
    // Initialize the elements with appropriate values

    enqueueLagu(&myQueue, newLagu);

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