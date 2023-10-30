#include <stdio.h>
#include <string.h>

void QUIT() {
    char command[100];

    while (1) {
        printf(">> ");
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "QUIT;\n") == 0) {
            char response[2];
            printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
            fgets(response, sizeof(response), stdin);

            if (response[0] == 'Y' || response[0] == 'y') {
                // memanggil save
                save();
            }

            printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
            break; // Keluar dari loop
        } else {
            printf("Perintah tidak valid\n");
        }
    }
}
