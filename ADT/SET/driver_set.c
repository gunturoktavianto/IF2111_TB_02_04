#include <stdio.h>
#include "set.h"

Set Lagu;

void PrintSet(Set s){
    int i=0;
    // printf("{ ");
    while(i!=s.Count){
        printf("%d. %d\n", i+1, s.Elements[i]);
        i++;
    }
    // printf("}\n");
}

int main(){
    CreateSet(&Lagu);

    int n=2;
    for(int i=0; i<n; i++){
        InsertSet(&Lagu, i+1000);
    }

    PrintSet(Lagu);
    return 0;
}