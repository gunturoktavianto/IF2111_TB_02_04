#include <stdio.h>
#include <string.h>

void START() {
    char command[100];
    printf(">> ");
    fgets(command, sizeof(command), stdin);
    // Memeriksa apakah perintah adalah "START;"
    if (strcmp(command, "START;\n") == 0) {
        // Perintah "START;" dieksekusi.
        printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        load();
    } else {
        printf("Perintah tidak valid\n");
    }
}
