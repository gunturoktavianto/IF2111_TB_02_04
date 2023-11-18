#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
<<<<<<< HEAD
    while (currentChar == BLANK || currentChar == '\r')
=======
    while (currentChar == BLANK)
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
    {
        ADV();
    }
}

<<<<<<< HEAD
void STARTWORD(FILE* input)
=======
void STARTWORD()
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
<<<<<<< HEAD
    START(input);
=======
    START();
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
<<<<<<< HEAD
    while (currentChar != BLANK && currentChar != '\r' && currentChar != MARK)
=======
    while (currentChar != BLANK && currentChar != MARK)
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}

<<<<<<< HEAD
void GetCommand() {
    currentWord.Length = 0;
    STARTWORD(stdin);
}

Word AccessCommand(Word comm, int Idx) {
    int count = 0, i = 0;
    Word out;
    out.Length = 0;

    while (i < comm.Length && count <= Idx) {
        out.TabWord[out.Length] = comm.TabWord[i];
        if (comm.TabWord[i] != ' ') {
            out.Length++;
        }
        if (comm.TabWord[i] == ' ') {
            if (count < Idx) {
                out.Length = 0;
            }
            count++;
        }
        i++;
    }
    return out;
}

void TulisWord(Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
}

boolean IsWordEq (Word kata1, Word kata2) {
    if (kata1.Length != kata2.Length) {
        return false;
    }
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

boolean IsWordNumber (Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        if (kata.TabWord[i] - '0' < 0 || kata.TabWord[i] - '0' > 9) return false;
    }
    return kata.Length > 0;
}

Word toKata(char *str) {
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */
    Word kata;
    kata.Length = stringLength(str);

    for (int i = 0; i < kata.Length; i++) {
        kata.TabWord[i] = str[i];
    }
    return kata;
}

Word intToWord(int n) {
    Word num; num.Length = 0;
    if (n == 0) {
        num.TabWord[num.Length] = '0'; num.Length++;
    } else {
        while (n != 0) {
            for (int i = num.Length; i > 0; i--) {
                num.TabWord[i] = num.TabWord[i-1];
            }
            num.Length++;
            num.TabWord[0] = (n % 10) + '0';
            n = n / 10;
        }
    }
    return num;
}

int stringLength(char *str) {
/*  Fungsi yang menerima sebuah parameter str bertipe string
    Kemudian mengembalikan panjang dari string tersebut */
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
=======
/* ********** KONVERTER ********** */
/* Fungsi untuk merubah tipe data dari word menjadi integer.
 * Mengembalikan nilai hasil convert dari word ke integer.
 * Prekondisi : pemrosesan telah berjalan */
int WordToInt(Word word)
{
	/*KAMUS LOKAL*/
	int hasil = 0;
	int i;
	/*ALGORITMA*/
	hasil += word.TabWord[0] - 48;
	for (i = 1; i < word.Length; i++)
	{
		hasil *= 10;
		hasil += word.TabWord[i] - 48;
	}
	return hasil;
}

/* Fungsi untuk Merubah tipe data dari word menjadi string.
 * Mengembalikan nilai hasil convert dari word ke string.
 * Prekondisi : pemrosesan telah berjalan */
char *WordToString(Word word)
{
	/*KAMUS LOKAL*/
	int i;
	/*ALGORITMA*/
	char *C = malloc(word.Length * sizeof(char));
	while (C == NULL)
	{
		C = malloc(word.Length * sizeof(char));
	}
	for (i = 0; i < word.Length; i++)
	{
		C[i] = word.TabWord[i];
	}
	C[i] = '\0';
	return C;
}

/* Fungsi untuk merubah tipe data dari string menjadi word.
 * Mengembalikan nilai hasil convert dari string ke word.
 * Prekondisi : pemrosesan telah berjalan */
Word StringtoWord(char *string)
{
	/*KAMUS LOKAL*/
	Word kata;
	int i = 0;
	kata.Length = 0;
	/*ALGORITMA*/
	while (string[i] != '\0')
	{
		kata.TabWord[i] = string[i];
		kata.Length++;
		i++;
	}
	return kata;
}

/* ********** SELEKTOR ********** */
/* Fungsi untuk mengambil kata ke - {ke} dari suatu kalimat hasil input dari user.
 * Prekondisi : pemrosesan telah berjalan */
Word takeword(Word command, int ke)
{
	/*KAMUS LOKAL*/
	Word w;
	int i = 0;
	int j = 0;
	/*ALGORITMA*/
	while (j != ke - 1 && i < command.Length)
	{
		if (command.TabWord[i] == ' ')
		{
			j++;
		}
		i++;
		if (i == command.Length)
		{
			j++;
		}
	}
	boolean cek = false;
	int length = 0;
	while (i < command.Length && !cek)
	{
		if (command.TabWord[i] == ' ')
		{
			cek = true;
		}
		else
		{
			w.TabWord[length] = command.TabWord[i];
			length++;
			i++;
		}
	}
	w.Length = length;
	return w;
}

/* ********** OPERASI OPERASI ********** */
/* Fungsi untuk menggabungkan dua buah variabel bertipe char.
 * Dalam program ini, kedua variabel tersebut adalah path dan filename
 * Prekondisi : pemrosesan telah berjalan */
char *ConcateChar(char *path, char *filename)
{
	/*KAMUS LOKAL*/
	int i;
	int j = 0;
	/*ALGORITMA*/
	Word dir = StringtoWord(path);
	Word file = StringtoWord(filename);
	int len = dir.Length + file.Length;
	for (i = dir.Length; i < len; i++)
	{
		dir.TabWord[i] = file.TabWord[j];
		dir.Length++;
		j++;
	}
	char *dir_file = WordToString(dir);
	return dir_file;
}

/* ********** TEST KEBENARAN ********** */
/* Fungsi untuk mengembalikan true jika kata w tersebut sama dengan string c.
 * Mengembalikan false jika kata w tidak sama dengan string c.
 * Prekondisi : pemrosesan telah berjalan */
boolean IsEqual(Word w, char *c)
{
	/*KAMUS LOKAL*/
	boolean equal = true;
	int i = 0, ctr = 0;
	/*ALGORITMA*/
	while (c[i] != '\0')
	{
		i++;
	}
	ctr = i;

	if (w.Length != ctr)
	{
		equal = false;
	}

	else
	{
		for (i = 0; i < w.Length; i++)
		{
			if (w.TabWord[i] != c[i])
			{
				equal = false;
			}
		}
	}
	return equal;
}

/* Fungsi yang mengembalikan nilai kebenaran jika ada word yang dicari dalam mesin kata
 * Prekondisi : pemrosesan telah berjalan */
boolean IsInWord(char *dicari, Word sumber)
{
	/*KAMUS LOKAL*/
	boolean notfound = true;
	int i = 0;
	/*ALGORTIMA*/
	while ((notfound) && (i < sumber.Length))
	{
		if (sumber.TabWord[i] == dicari[0])
		{
			notfound = false;
		}
		else
		{
			i++;
		}
	}
	return !notfound;
}

void capsLock(char *huruf)
{
    int i = 0;
    while (huruf[i] != '\0') {
        if ((huruf[i] >= 97) && (huruf[i] <= 122))
        {
            huruf[i] -= 32;
        }
        i++;
    }
}
/* Membuat semua huruf menjadi uppercase */

void lowerCase(char *huruf)
{
    int i = 0;
    while (huruf[i] != '\0') {
        if ((huruf[i] >= 65) && (huruf[i] <= 90))
        {
            huruf[i] += 32;
        }
        i++;
    }
}
/* Membuat semua huruf menjadi uppercase */
>>>>>>> 34f31173c125b02e596bcfa44df8bdbf16e391c4
