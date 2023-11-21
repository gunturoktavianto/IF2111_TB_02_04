#include "riwayat.h"

int main(){
    // KAMUS
    Word lagu, penyanyi, album;
    Lagu song1, song2;
    infotypeStack X;
    Stack riwayat, temp;
    int i=0, j=1;
    // ALGORITMA
    CreateStack(&riwayat);
    song1.nama = toKata("Namaku Favian");
    song1.penyanyi = toKata("Favian Ga");
    song1.album = toKata("Perjalan favian menguasai dunia kelinci");
    Push(&riwayat, song1);
    song2.nama = toKata("I am the strongest");
    song2.penyanyi = toKata("Almin heavy metal");
    song2.album = toKata("my motorbike is rock");
    
    Push(&riwayat, song2);
    displayRiwayat(&riwayat);
    Pop(&riwayat, &X);
    displayRiwayat(&riwayat);   
}