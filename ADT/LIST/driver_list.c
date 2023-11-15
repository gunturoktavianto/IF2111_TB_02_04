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

// int main(){
//     char* kata1 = "Halo";
//     char* kata2 = "Dunia";
//     InsertLast(&Penyanyi, kata1);
//     printf("%s ", Penyanyi.A[0]);
//     InsertLast(&Penyanyi, kata2);
//     printf("%s ", Penyanyi.A[1]);

//     // for(int i=0; i<Length(Penyanyi); i++){
//     //     printf("%s ", Penyanyi.A[i]);
//     // }
//     // printf("\n");
// }