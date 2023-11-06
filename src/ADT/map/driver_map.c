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

Map Album;
int main(){
    CreateMap(&Album);

    int i=0;
    while(i < Album.Count){
        InsertMap(&Album, i, )
    }
}