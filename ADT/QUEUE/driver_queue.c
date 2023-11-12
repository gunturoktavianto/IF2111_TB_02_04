#include <stdio.h>
#include "queue.h"

Queue song;

int main(){
    CreateQueue(&song);


    int n = 2;
    for(int i=0; i<n; i++){
        if(i==0){currentWord.TabWord[i] = "Ginna";}
        if(i==1){currentWord.TabWord[i] = "Labbs";}
        enqueue(&song, currentWord);
    }


    
}