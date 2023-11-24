#include "lagu.h"

int main() {
    SetLagu lagu;
    CreateEmptySetLagu(&lagu);

    // Testing InsertSetLagu
    printf("Menambahkan lagu...\n");
    InsertSetLagu(&lagu, MakeLagu(toKata("Penyanyi1"), toKata("Album1"), toKata("Lagu1")));
    InsertSetLagu(&lagu, MakeLagu(toKata("Penyanyi2"), toKata("Album2"), toKata("Lagu2")));
    InsertSetLagu(&lagu, MakeLagu(toKata("Penyanyi3"), toKata("Album3"), toKata("Lagu3")));
    PrintLagu(lagu);

    // Testing DeleteSetLagu
    printf("\nMenghapus lagu...\n");
    Lagu songToDelete = MakeLagu(toKata("Penyanyi2"), toKata("Album2"), toKata("Lagu2"));
    DeleteSetLagu(&lagu, songToDelete);
    PrintLagu(lagu);

    // Testing IsMemberSetLagu
    printf("\nChecking membership...\n");
    Lagu songToCheck = MakeLagu(toKata("Penyanyi1"), toKata("Album1"), toKata("Lagu1"));
    if (IsMemberSetLagu(lagu, songToCheck)) {
        printf("The song is a member of the set.\n");
    } else {
        printf("The song is not a member of the set.\n");
    }

    // Testing MakeSetLagu
    printf("Membuat set lagu...\n");
    SetLagu newSet = MakeSetLagu(3);
    PrintLagu(newSet);

    return 0;
}
