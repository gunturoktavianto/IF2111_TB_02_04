#include "ADT/LIST/driver_list.c"
#include "ADT/MAP/driver_map.c"
#include "ADT/SET/driver_set.c"
#include "ADT/QUEUE/driver_queue.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int Status(){
    // Initial state : currentsong from album x from penyanyi x
    // Penyanyi.Elements[0].Lagu->Elements[0].lagu
    // dummy var
    int currentsong;
    Queue playPlaylist;
    printf("%d\n", Penyanyi.Elements[0].Lagu->Elements[0].lagu);
    printf("Now Playing:\n");

    // Tidak ada lagu yang diputar
    if(currentsong == Nil){
        printf("No songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }

    // Ada lagu, tapi queue kosong
    else if(currentsong != Nil && isEmpty(playPlaylist)){
        printf("%d - %d - %d\n\nQueue:\nYour queue is empty.",Penyanyi.Elements[0].Key, Penyanyi.Elements[0].Value, Penyanyi.Elements[0].Lagu->Elements[0].lagu);
    }
    // Ada lagu dan ada queue
    else if(currentsong != Nil && !isEmpty(playPlaylist)){
        printf("%d - %d - %d\n\nQueue:\n",Penyanyi.Elements[0].Key, Penyanyi.Elements[0].Value, Penyanyi.Elements[0].Lagu->Elements[0].lagu);
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
    else if(){
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