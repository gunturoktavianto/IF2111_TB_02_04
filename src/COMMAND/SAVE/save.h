#ifndef save_H
#define save_H

#include "../../ADT_BUATAN/RIWAYAT/riwayat.h"

#define MAX_LEN 128
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void startSave(Word filesave); //isi parameter sesuai variabel yang ada di load.c

#endif