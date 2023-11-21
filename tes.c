
#include "ADT_BUATAN/RIWAYAT/riwayat.h"
#include "ADT_BUATAN/QUEUE/queuelagu.h"
char yesorno ()
{
    // KAMUS
    Word command;
    char input;
    boolean valid = false;
    // ALGORITMA
    command = GetInput();
    while(!valid)
    {
        if(currentWord.Length > 1) command = GetInput();
        else
        {
            input = command.TabWord[0];
            if(input == 'Y' || input == 'y')
            {
                valid = true;
            }
            else if(input == 'N' || input == 'n')
            {
                valid = true;
            }
            else
            {
                command = GetInput();
            }
        } 
    }
    return input;
}

int main()
{
    // KAMUS
    Queue queueLagu;
    ElTypeQueue newLagu;
    Lagu song;
    Stack riwayat, temp;
    // ALGORITMA
   CreateQueueLagu(&queueLagu);
    newLagu.nama = toKata("aku anak menteng");
    newLagu.penyanyi = toKata("Almien Izza");
    newLagu.album = toKata("my tour to ibizza");
   CreateStack(&riwayat);
    song.nama = toKata("Namaku Favian");
    song.penyanyi = toKata("Favian Izza");
    song.album = toKata("Perjalan favian menguasai dunia kelinci");
    Push(&riwayat, song);
    displayQueueLagu(queueLagu);
    
}
