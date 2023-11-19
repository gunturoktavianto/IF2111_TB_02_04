#include <stdio.h>
#include "stack.h"

Stack riwayat;
int main(){
    CreateStack(&riwayat);
    Push(&riwayat, 1);
    Push(&riwayat, 2);
    return 0;
}