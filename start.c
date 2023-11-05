#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void playSong(){
    FILE *file;
    char buffer;

    file = fopne("dummy.txt", "r");
    if (file == NULL) {
        printf("File konfigurasi aplikasi tidak berhasil dibaca.\n");
        exit(0);
    }

    printf("Isi file:\n");

    while ((buffer = fgetc(file)) != EOF){
        printf("%c", buffer);
    }

    fclose(file);
    return 0;
}