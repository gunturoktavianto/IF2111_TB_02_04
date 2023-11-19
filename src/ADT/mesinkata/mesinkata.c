#include "mesinkata.h"
#include <stdio.h>
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while(currentChar==BLANK) ADV();
}
void STARTWORD(FILE *input)
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START(input);
    IgnoreBlanks();
    if(currentChar==MARK) EndWord=true;
    else {EndWord=false; ADVWORD();}
}
void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    IgnoreBlanks();
    if(currentChar==MARK) EndWord=true;
    else 
    {
        EndWord=false;
        CopyWord();
        IgnoreBlanks();
    }
}
void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    for (int i=0; i<NMax; i++) currentWord.TabWord[i]='\0';
    int i=0;
    while(currentChar!=MARK && currentChar!=BLANK && currentChar!='\n')
    {
        if(i<NMax)
        {
            currentWord.TabWord[i]=currentChar; i++;
        }
        ADV();
    }
    currentWord.Length=i;
}
void nextLine()
{
    ADV();
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

int WordtoInt(Word w)
{
    int x=0;
    for(int i=0; i<w.Length; i++)
    {
        x*=10;
        x+=w.TabWord[i]-'0';
    }
    return x;
}

Word GetWords()
{
    Word temp;
    for (int i=0; i<NMax; i++) temp.TabWord[i]='\0';
    temp.Length=0;
    // int idx=0;
    while(currentChar!='\n')
    {
        ADVWORD();
        for (int i=0; i<currentWord.Length; i++)
        {
            temp.TabWord[temp.Length]=currentWord.TabWord[i];
            temp.Length++;
        }
        if (currentChar!='\n') {temp.TabWord[temp.Length]=' '; temp.Length++;}
    }
    return temp;
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

Word toKata(char *str) {
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */
    Word kata;
    kata.Length = stringLength(str);

    for (int i = 0; i < kata.Length; i++) {
        kata.TabWord[i] = str[i];
    }
    kata.TabWord[kata.Length]='\0'; 
    return kata;
}