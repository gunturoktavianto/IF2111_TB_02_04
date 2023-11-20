/*#include "ADT/LIST/driver_list.c"
#include "ADT/LISTDP/driver_listdp.c"
#include "ADT/LISTLINIER/driver_listlinier.c"
#include "ADT/MAP/driver_map.c"
#include "ADT/MAP/hashmap.h"
#include "ADT/MESINKATA/mesinkata.h"
#include "ADT/QUEUE/driver_queue.c"
#include "ADT/SET/driver_set.c"
#include "ADT/STACK/driver_stack.c"*/

#include "ADT/LIST/list.h"
#include "ADT/LISTDIN/arraydin.h"
#include "ADT/LISTLINIER/listlinier.h"
#include "ADT/MAP/map.h"
/*#include "ADT/MAP/hashmap.h"*/
/*#include "ADT/MESINKATA/mesinkata.h"*/
#include "ADT/QUEUE/queue.h"
#include "ADT/SET/set.h"
#include "ADT/STACK/stack.h"

#include "boolean.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

void BacaConfig(){
    FILE *file;
    file = fopen("dummy.txt", "r");

    int jumlahPenyanyi, jumlahAlbum, jumlahLagu;
    char penyanyi[100], namaAlbum[100], judulLagu[100];
    Set SetPenyanyi;

    fscanf(file, "%d", &jumlahPenyanyi);

    for (int i = 0; i < jumlahPenyanyi; i++) {
        fscanf(file, "%d", &jumlahAlbum);
        fscanf(file, " %[^\n]s", penyanyi);
        Insert(&SetPenyanyi, penyanyi);

        printf("%d %s\n", jumlahAlbum, penyanyi);

        for (int j = 0; j < jumlahAlbum; j++) {
            fscanf(file, "%d %[^\n]s", &jumlahLagu, namaAlbum);
            printf("%d %s\n", jumlahLagu, namaAlbum);

            for (int k = 0; k < jumlahLagu; k++) {
                fscanf(file, " %[^\n]s", judulLagu);
                printf("%s\n", judulLagu);
            }
        }
    }

    fclose(file);
}

int main() {
    char input[100];
    boolean isValid = true;
    
    printf("\n>> ");
    scanf("%s", input);
    
    if (strcmp(input, "START") == 0) {
        
        BacaConfig();
    }

    return 0;
}