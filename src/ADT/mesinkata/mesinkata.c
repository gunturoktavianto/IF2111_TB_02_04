#include "mesinkata.h"
#include <stdio.h>
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while((currentChar==BLANK) && (currentChar!=MARK)) 
        ADV();
}

void IgnoreCR()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while((currentChar==CR) && (currentChar!=MARK)) 
        ADV();
}

void IgnoreEOL()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    if((currentChar==EOL) && (currentChar!=MARK)) 
        ADV();
}

void IgnoreSC()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    if((currentChar==SC) && (currentChar!=MARK)) 
        ADV();
}

void STARTWORD(FILE *input)
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START(input);
    IgnoreBlanks();
    IgnoreCR();
    if(currentChar==MARK) EndWord=true;
    else {EndWord=false;}
}

void STARTWORDFILE(char *fileaddress)
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    STARTFILE(fileaddress);
    IgnoreBlanks();
    IgnoreCR();
    if(currentChar==MARK) EndWord=true;
    else {EndWord=false;}
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    IgnoreBlanks();
    IgnoreCR();
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
    IgnoreSC();
    for (int i=0; i<NMax; i++) currentWord.TabWord[i]='\0';
    int i=0;
    while(currentChar!=MARK && currentChar!=BLANK && currentChar!=EOL && currentChar!= CR && currentChar!=SC)
    {
        if(i<NMax)
        {
            currentWord.TabWord[i]=currentChar; i++;
        }
        ADV();
    }
    currentWord.Length=i;
}

void STARTWORDLOAD(FILE *input)
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START(input);
    
    if(currentChar==MARK) EndWord=true;
    else {EndWord=false; ADVWORDLOAD();}
}
void ADVWORDLOAD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    
    if(currentChar==MARK) EndWord=true;
    else 
    {
        EndWord=false;
        CopyWordLoad();
        
    }
}
void CopyWordLoad()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    for (int i=0; i<NMax; i++) currentWord.TabWord[i]='\0';
    int i=0;
    while(currentChar!=MARK && currentChar!='\n')
    {
        if(i<NMax)
        {
            currentWord.TabWord[i]=currentChar; i++;
        }
        ADVLOAD();
        

    }
    ADVLOAD();
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
    for (int i = 0; i < w.Length; i++) {
        if (w.TabWord[i] - '0' < 0 || w.TabWord[i] - '0' > 9) return false;
    }
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

Word GetInput()
{
    FILE *input=stdin;
    STARTWORD(input);
    Word temp;
    temp.Length=0;
    int i=0;
    while(currentChar!=';') 
    {
        temp.TabWord[i]=currentChar;
        ADV();
        i++;
        temp.Length++;
    }
    temp.TabWord[temp.Length]='\0';
    ADV();
    return temp;
}

boolean IsWordNumber (Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        if (kata.TabWord[i] - '0' < 0 || kata.TabWord[i] - '0' > 9) return false;
    }
    return kata.Length > 0;
}

char* wordToString(Word word)
{
    char *str = (char *)malloc(sizeof(char) * word.Length);
    for (int i = 0; i < word.Length; i++)
    {
        str[i] = word.TabWord[i];
        if (i == word.Length - 1)
        {
            str[i + 1] = '\0';
        }
    }
    return str;
}

Word concatWord(Word w1, Word w2)
{
    Word ans;
    ans.Length = w1.Length + w2.Length;
    int i;
    for(i = 0; i < w1.Length; i++){
        ans.TabWord[i] = w1.TabWord[i];
    }
    for(i = 0; i < w2.Length;i++){
        ans.TabWord[i+w1.Length] = w2.TabWord[i];
    }
    return ans;
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