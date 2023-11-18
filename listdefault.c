#include "main.c"
#include <stdio.h>
#include <stdlib.h>

void listSpotify(List Penyanyi, Map Album, Set Lagu){ // sementara sebelum ada load
    // KAMUS
    boolean valid = false;
    char input;
    int i=0;
    ListLL L;
    // ALGORITMA
    // printf(">> ");
    ADVWORD();      // TURN THIS OFF IF YOU WANT TO USE THE DRIVER
    // STARTWORD(); // TURN THIS ON IF YOU WANT TO USE THE DRIVER
    // ADVWORD();
    // printf("%s\n", currentWord.TabWord);

    if (stringComp(currentWord.TabWord, "DEFAULT")){
        // IF DEFAULT PROCESS GHOSTRULE.TXT
        // stringCopy(currentWord.TabWord, "ghostrule.txt");
        loadSpotify();

        printf("Daftar Penyanyi :\n");
        while(Penyanyi.A[i]!=Mark){
            printf("  %d. %d\n", i+1, Penyanyi.A[i]);
            i++;
        }

        printf("Ingin melihat album yang ada?(Y/N): ");
        STARTWORD();
        // ADVWORD();
        // printf("%s\n", charToWord(currentWord.TabWord[0]));

        // scanf("%s", pilihan); UBAH JADI CHAR, BUKAN WORD
        while(currentWord.TabWord[0] != 'Y' || currentWord.TabWord[0] != 'N' || currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'n')
        {
            printf("Input salah. Masukkan Y atau N: ");
            STARTWORD();
            // ADVWORD();
        }
        
        input = currentWord.TabWord[0];
        
        // printf("%c\n", pilihan);

        // comparing string
        if(input == 'N' || input == 'n'){
            return;
        }

        // pilih album
        printf("Pilih penyanyi untuk melihat album mereka: ");
        char penyanyi[100];
        stringMakeEmpty(penyanyi);
        STARTLINE();
        // ADVWORD();
        stringCopy(penyanyi, currentWord.TabWord);
        // scanf("%s", penyanyi);

        // printf("%s\n", penyanyi);
        printf("Daftar Album oleh %s:\n", penyanyi);
        int idx_penyanyi = showAlbum(charToWord(penyanyi), l);


        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100];
        stringMakeEmpty(album);
        // ADVWORD();
        STARTLINE();
        // ADVWORD();
        // printf("%s\n", currentLine.TabLine);
        stringCopy(album, currentLine.TabWord);

        printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
        showLagu(charToWord(album), idx_penyanyi, l);
        return;
    }
    else if (stringComp(currentLine.TabWord, "PLAYLIST")){
        DisplayDaftarPlaylist(L);
        return;
    }
    else{
        printf("invalid command\n");
        return;
    }
}