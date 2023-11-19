#include "help.c"
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n == 1){
        InitialHelp();
    }
    else{
        SessionHelp();
    }
}

