#include "help.h"

// Fungsi untuk menampilkan menu help saat belum memasuki sesi
void InitialHelp() {
    printf("=====[ Menu Help WayangWave ]=====\n");
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
}

// Fungsi untuk menampilkan menu help setelah memasuki sesi
void SessionHelp() {
    printf("=====[ Menu Help WayangWave ]=====\n");
    printf("1. LIST -> Untuk menampilkan daftar lagu, playlist,  penyanyi, album dari penyanyi, dan lagu yang ada di album tersebut.\n");
    printf("2. PLAY -> Untuk memulai suatu lagu, terdapat dua jenis command untuk PLAY yaitu SONG dan PLAYLIST.\n");
    printf("3. QUEUE -> Untuk memanipulasi queue lagu yang memiliki 5 tipe command, yaitu SONG, PLAYLIST, SWAP, REMOVE, dan CLEAR\n");
    printf("4. SONG -> Untuk navigasi lagu yang ada pada queue lagu saat ini, terdapat dua tipe navigasi yaitu NEXT dan PREVIOUS\n");
    printf("5. PLAYLIST -> Untuk melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE dan DELETE\n");
    printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar\n");
    printf("7. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf("8. QUIT -> Untuk keluar dari sesi\n");
}