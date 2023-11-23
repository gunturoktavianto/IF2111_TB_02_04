#include "start.h"
boolean stateWayangWave;

void startconfig()
{
    STARTWORDFILE("../save/config.txt");
    ADVWORD();
    l.Count=WordtoInt(currentWord);
    nextLine();
    for (int i=0; i<l.Count; i++)
    {
        ADVWORD();
        l.PenyanyiKe[i].Count=l.Count;
        l.PenyanyiKe[i].InfoPenyanyi[i].Value.Count=WordtoInt(currentWord);
        l.PenyanyiKe[i].InfoPenyanyi[i].Key =GetWords();
        nextLine();
        for (int j=0; j<l.PenyanyiKe[i].InfoPenyanyi[i].Value.Count; j++)
        {
            ADVWORD();
            l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.Count=WordtoInt(currentWord);//4
            l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Key=GetWords();//BORN PINK
            nextLine();
            int jumlahLagu=l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.Count;
            for(int k=0; k<jumlahLagu; k++)
            {
                Word w=GetWords();
                l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].nama=w;
                l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].album=l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Key;
                l.PenyanyiKe[i].InfoPenyanyi[i].Value.InfoAlbum[j].Value.InfoLagu[k].penyanyi=l.PenyanyiKe[i].InfoPenyanyi[i].Key;
                nextLine();
            }
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
    }
}