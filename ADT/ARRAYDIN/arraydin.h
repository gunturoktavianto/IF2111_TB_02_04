#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef int IdxTypeArrDin;
typedef int ElTypeArrDin;
typedef struct {
    ElTypeArrDin *A;
    int Capacity;
    int Neff;
} ArrayDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrDin(ArrayDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrDin(ArrayDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeArrDin GetArrDin(ArrayDin array, IdxTypeArrDin i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityArrDin(ArrayDin array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtArrDin(ArrayDin *array, ElTypeArrDin el, IdxTypeArrDin i);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtArrDin(ArrayDin *array, IdxTypeArrDin i);

#endif