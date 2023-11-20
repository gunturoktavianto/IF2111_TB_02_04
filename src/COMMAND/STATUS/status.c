include "ADT/LISTLINIER/driver_listlinier.c"
#include "ADT/LIST/driver_list.c"
#include "ADT/MAP/driver_map.c"
#include "ADT/SET/driver_set.c"
#include "ADT/QUEUE/driver_queue.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

boolean playlistStatus(){
    // I.S. currentsong, queueLagu
    // F.S. mengirimkan true jika currentsong beserta keseluruhan queue berada dalam satu playlist yang sama
    int currentsong;
    Queue queueLagu;
    boolean found = false;
    ListLL playlist;
    address p = First(playlist);

    if (!IsEmptyLL(playlist) && currentsong == Info(p))
    {   Queue queueTemp;
        copyQueue(&queueLagu, &queueTemp);
        p = Next(p);
        while ((!found) && (p != Nil))
        {
            int X;
            dequeue(&queueTemp, &X);
            if (Info(p) != X)
            {
                found = true;}
            else
            {
                p = Next(p);
            }
        }
    }
    return found;
}

void Mapping(int currentsong, int idxp, int idxa, int idxl){
    // I.S. mencari lokasi suatu lagu disimpan, lagu terdefinisi. input berupa address of index
    // Inisiasi index penyanyi, album, dan lagu
    int currentsong;
    int idxp = 0, idxa = 0, idxl = 0;
    boolean found = false;
    while(idxp < Length(ListPenyanyi) && !found){
        while(idxa < Penyanyi.Count && !found){
            while(idxl < Lagu.Count && !found){
                if(Lagu.ke[idxl] == currentsong){
                    found = true;
                    break;
                }
                idxl++;
            }
            idxa++;
        }
        idxp++;
    }
    // F.S. index penyanyi, album, dan lagu 
}

int Status(){
    // Initial state : currentsong from album x from penyanyi x
    // Penyanyi.Elements[0].Lagu->Elements[0].lagu
    // dummy var
    int currentsong, idxp, idxa, idxl;
    Mapping(currentsong, &idxp, &idxa, &idxl);
    Queue playPlaylist;

    // Tidak ada lagu yang diputar
    if(currentsong == Nil){
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }

    // Ada lagu, tapi queue kosong
    else if(currentsong != Nil && isEmpty(playPlaylist)){
        printf("Now Playing:\n%d - %d - %d\n\nQueue:\nYour queue is empty.",
        Penyanyi.NamaPenyanyi);
    }
    
    // Ada lagu dan ada queue
    else if(currentsong != Nil && !isEmpty(playPlaylist) && playlistStatus()){
        printf("Now Playing:\n%d - %d - %d\n\nQueue:\n",Penyanyi.Elements[0].Key, Penyanyi.Elements[0].Value, Penyanyi.Elements[0].Lagu->Elements[0].lagu);
        Queue queueLagu;
        Queue status;
        int i = 0;
        while(!isEmpty(status)){
            // anggap val = elemen lagu di set 
            int val;
            enqueue(&queueLagu,val);
            printf("%d. %d - %d - %d\n",i+1, Penyanyi.Elements[0].Key, Penyanyi.Elements[0].Value, Penyanyi.Elements[0].Lagu->Elements[0].lagu);
        }
    }

    // Ada lagu, queue, dan playlist
    // Hanya ditampilkan ketika melakukan playlist. Tidak ditampilkan jika terdapat lagu selain dari playlist 
    // 
    else if(playlistStatus()){
        printf("Current Playlist: %d\n\nNow Playing:\n%d - %d - %d\n\nQueue:\n",Penyanyi.Elements[0].Key, Penyanyi.Elements[0].Value, Penyanyi.Elements[0].Lagu->Elements[0].lagu);
        Queue queueLagu;
        Queue status;
        int i = 0;
        while(!isEmpty(status)){
            // anggap val = elemen lagu di set 
            int val;
            enqueue(&queueLagu,val);
            printf("%d. %d - %d - %d\n",i+1, Penyanyi.Elements[0].Key, Penyanyi.Elements[0].Value, Penyanyi.Elements[0].Lagu->Elements[0].lagu);
        }
    }
}