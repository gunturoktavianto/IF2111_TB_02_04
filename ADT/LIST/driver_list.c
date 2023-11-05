#include <stdio.h>
#include "list.h"

List Penyanyi;

int main(){
    int n = 2;
    for(int i=0; i<n; i++){
        InsertAt(&Penyanyi, i+1, i);
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", Penyanyi.A[i]);
    }
    printf("\n");
}