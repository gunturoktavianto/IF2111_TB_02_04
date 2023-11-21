#include "song.h"

int main()
{
    // DUMMY RIWAYAT
    Lagu song1, song2;
    infotypeStack X;
    Stack riwayat;
    
    int i=0, j=1;
    // ALGORITMA
    currentSong.nama = toKata("ASA DE");
    currentSong.penyanyi = toKata("ELDWIN BET");
    currentSong.album = toKata("POKOKE ELDWIN");
    CreateStack(&riwayat);

    // song1.nama = toKata("Namaku Favian");
    // song1.penyanyi = toKata("Favian Ga");
    // song1.album = toKata("Perjalan favian menguasai dunia kelinci");
    // Push(&riwayat, song1);
    // song2.nama = toKata("I am the strongest");
    // song2.penyanyi = toKata("Almin heavy metal");
    // song2.album = toKata("my motorbike is rock");
    // Push(&riwayat, song2);
    
    // // DUMMY QUEUE
    Queue myQueue;
    CreateQueueLagu(&myQueue);
    ElTypeQueue newLagu;

    // newLagu.nama.Length = 11;
    // for (int i = 0; i < newLagu.nama.Length; i++) {
    //     newLagu.nama.TabWord[i] = "LOLA PADAMU"[i];
    // }
    // newLagu.nama.TabWord[newLagu.nama.Length] = '\0';

    // newLagu.album.Length = 12;
    // for (int i = 0; i < newLagu.album.Length; i++) {
    //     newLagu.album.TabWord[i] = "FAVIAN DABES"[i];
    // }
    // newLagu.album.TabWord[newLagu.album.Length] = '\0'; 

    // newLagu.penyanyi.Length = 13;
    // for (int i = 0; i < newLagu.penyanyi.Length; i++) {
    //     newLagu.penyanyi.TabWord[i] = "RIZA BANGET"[i];
    // }
    // newLagu.penyanyi.TabWord[newLagu.penyanyi.Length] = '\0';
    // // // Initialize the elements with appropriate values
    // enqueueLagu(&myQueue, newLagu);

    song(&myQueue, &riwayat);
    displayQueueLagu(myQueue);
    displayRiwayat(&riwayat);
}