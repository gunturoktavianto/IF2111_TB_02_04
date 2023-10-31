#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "console.h"
#include "boolean.h"

boolean isValid = false;
char choice[10];

int main(){
    welcome_message();

    while(!isValid){
        printf(">> ");
        scanf("%s", &choice);

        if (checkEqualityStr(choice, "START")){
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.");
            isValid = true;
        } else if(checkEqualityStr(choice, "LOAD")){
            isValid = true;
            break;
        } else if(checkEqualityStr(choice, "HELP")){
            isValid = true;
            break;
        } else {
            printf("Masukkan tidak valid!\n");
        }
    }
    return 0;
}


void welcome_message(){
    printf("Selamat datang!\n");
    printf("MAIN MENU:\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. HELP\n");
}

int checkEqualityStr(const char *str1, const char *str2) {
    // Fungsi ini memeriksa apakah str1 sama dengan str2
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0; // Tidak sama
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}