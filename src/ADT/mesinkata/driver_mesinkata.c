#include "mesinkata.c"
#include "mesinkarakter.c"

int main() {
    FILE *inputFile;

    // Testing START dan ADV
    printf("Testing START and ADV functions:\n");
    inputFile = fopen("coba.txt", "r"); // contoh file input
    if (inputFile != NULL) {
        START(inputFile);
        while (!EOP) {
            printf("%c", currentChar);
            ADV();
        }
        fclose(inputFile);
        printf("\n\n");
    } else {
        printf("Input file gagal.\n\n");
    }

    // Testing STARTFILE dan ADVLOAD 
    printf("Testing STARTFILE and ADVLOAD functions:\n");
    inputFile = fopen("coba.txt", "r"); // contoh file input
    if (inputFile != NULL) {
        STARTFILE("coba.txt");
        while (!EOP) {
            printf("%c", currentChar);
            ADVLOAD();
        }
        fclose(inputFile);
        printf("\n\n");
    } else {
        printf("gagal membuka.\n\n");
    }

    // Testing STARTWORD, ADVWORD, dan CopyWord
    printf("Testing STARTWORD, ADVWORD, dan CopyWord:\n");
    inputFile = fopen("coba.txt", "r"); // Provide a sample input file with words
    if (inputFile != NULL) {
        STARTWORD(inputFile);
        while (!EndWord) {
            printf("Word: %s\n", wordToString(currentWord));
            ADVWORD();
        }
        fclose(inputFile);
        printf("\n\n");
    } else {
        printf("gagal membuka.\n\n");
    }

    // Test STARTWORDFILE, ADVWORDLOAD, and CopyWordLoad functions
    printf("Testing STARTWORDFILE, ADVWORDLOAD, dan CopyWordLoad:\n");
    inputFile = fopen("coba.txt", "r"); // Provide a sample input file with words
    if (inputFile != NULL) {
        STARTWORDFILE("coba.txt");
        while (!EndWord) {
            printf("Word: %s\n", wordToString(currentWord));
            ADVWORDLOAD();
        }
        fclose(inputFile);
        printf("\n\n");
    } else {
        printf("gagal membuka.\n\n");
    }

    // Test other utility functions
    printf("Testing fungsi kata:\n");
    Word exampleWord = toKata("Hello");
    printf("Panjang kata 'Hello': %d\n", exampleWord.Length);

    Word concatenatedWord = concatWord(toKata("Hello"), toKata("World"));
    printf("Kata gabungan: %s\n", wordToString(concatenatedWord));

    return 0;
}
