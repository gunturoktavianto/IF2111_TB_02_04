#include "penyanyi.h"

int main() {
    // Test Penyanyi
    Penyanyi penyanyi;
    CreateEmptyPenyanyi(&penyanyi);

    keytype penyanyiKey1, penyanyiKey2;
    Word nama1, nama2;
    nama1.Length = 3;
    nama1.TabWord[0] = 'A';
    nama1.TabWord[1] = 'n';
    nama1.TabWord[2] = 'd';

    nama2.Length = 4;
    nama2.TabWord[0] = 'J';
    nama2.TabWord[1] = 'o';
    nama2.TabWord[2] = 'h';
    nama2.TabWord[3] = 'n';

    penyanyiKey1 = nama1;
    penyanyiKey2 = nama2;

    valuetypePenyanyi penyanyiValue1, penyanyiValue2;
    penyanyiValue1.Count = 0;
    penyanyiValue2.Count = 0;

    InsertPenyanyi(&penyanyi, &penyanyiKey1, &penyanyiValue1);
    InsertPenyanyi(&penyanyi, &penyanyiKey2, &penyanyiValue2);

    // Test ListPenyanyi
    ListPenyanyi listPenyanyi;
    CreateEmptyListPenyanyi(&listPenyanyi);

    infotypePenyanyi penyanyiInfo1, penyanyiInfo2;
    penyanyiInfo1.Key = penyanyiKey1;
    penyanyiInfo1.Value = penyanyiValue1;

    penyanyiInfo2.Key = penyanyiKey2;
    penyanyiInfo2.Value = penyanyiValue2;

    InsertListPenyanyi(&listPenyanyi, &penyanyiInfo1);
    InsertListPenyanyi(&listPenyanyi, &penyanyiInfo2);

    // Print daftar penyanyi
    printdaftarPenyanyi(&listPenyanyi);

    return 0;
}
