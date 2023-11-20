#include "start.h"
//void playSong(){
void startconfig()
{
    FILE *input=fopen("dummy.txt","r");
    STARTWORD(input);
    ADVWORD(); //2
    l.Count=WordtoInt(currentWord);
    nextLine();
    for (int i=0; i<l.Count; i++)
    {
        ADVWORD();
        l.PenyanyiKe[i].InfoPenyanyi[i].Value.Count=WordtoInt(currentWord);//2
        l.PenyanyiKe[i].InfoPenyanyi[i].Key =GetWords();//BLACKPINK
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
                //InfoPenyanyi[i].InfoAlbum[j].lagu[k]=w;
                //mapInsert(&LagutoAlbum, NamaLagu, NamaAlbum);
                nextLine();
            }
        }
    }
}
//}
            //printf("%d\n",InfoPenyanyi[i].InfoAlbum[j].lagu.Count);
            //printf("%s %s\n",NamaPenyanyi.TabWord,NamaAlbum.TabWord);
