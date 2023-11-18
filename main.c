#include "ADT/LIST/list.h"
#include "ADT/LISTDP/listdp.h"
#include "ADT/LISTLINIER/listlinier.h"
#include "ADT/MAP/map.h"
#include "ADT/MAP/hashmap.h"
#include "ADT/MESINKATA/mesinkata.h"
#include "ADT/QUEUE/queue.h"
#include "ADT/SET/set.h"
#include "ADT/STACK/stack.h"
#include "ADT/ARRAYDIN/arraydin.h"
#include "listplaylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main(){
    // KAMUS
    ArrayDin arr;
    
    // ALGORITMA
    arr = MakeArrayDin();
   InsertAtarrdin(&arr, 12, 0);
   InsertAtarrdin(&arr, 15, 1);
   InsertAtarrdin(&arr, 21, 2);
   InsertAtarrdin(&arr, 51, 3);
   InsertAtarrdin(&arr, 11, 4);
    DisplayDaftarPlaylist(arr);
}
