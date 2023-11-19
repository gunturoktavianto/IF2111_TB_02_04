#include <stdio.h>
#include "map.h"

void PrintMap(Map s){
    int i=0;
    // printf("{ ");
    while(i!=s.Count){
        printf("%d. %d\n", i+1, s.Elements[i].Value);
        i++;
    }
    // printf("}\n");
}

Map Penyanyi;
Map Album;
int main(){
    CreateMap(&Penyanyi);

    int jumlah = 4;
    int i=0;
    while(i<=jumlah){
        InsertMap(&Penyanyi, i, i+20);
        i++;
    }
    PrintMap(Penyanyi);
}