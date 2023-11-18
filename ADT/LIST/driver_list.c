#include <stdio.h>
#include "list.h"

List ListPenyanyi;

int main(){
    int n = 2;
    for(int i=0; i<n; i++){
        InsertAt(&ListPenyanyi, i+1, i);
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", ListPenyanyi.A[i]);
    }
    printf("\n");
}

// int main(){
//     char* kata1 = "Halo";
//     char* kata2 = "Dunia";
//     InsertLast(&ListPenyanyi, kata1);
//     printf("%s ", ListPenyanyi.A[0]);
//     InsertLast(&ListPenyanyi, kata2);
//     printf("%s ", ListPenyanyi.A[1]);

//     // for(int i=0; i<Length(ListPenyanyi); i++){
//     //     printf("%s ", ListPenyanyi.A[i]);
//     // }
//     // printf("\n");
// }