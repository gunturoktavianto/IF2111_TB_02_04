#include "adtplus.h"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "set.c"
#include "map.c"
int main()
{
    Word NamaLagu;
    Map AlbumtoPenyanyi;
    Map LagutoAlbum;
    mapCreateEmpty(&AlbumtoPenyanyi);
    mapCreateEmpty(&LagutoAlbum);
    FILE *input=fopen("config.txt","r");
    STARTWORD(input);
    int JumlahPenyanyi=WordtoInt(currentWord);
    nextLine();
    for (int i=0; i<JumlahPenyanyi; i++)
    {
        ADVWORD();
        //InfoPenyanyi[i].jumlahAlbum=WordtoInt(currentWord);
        //InfoPenyanyi[i].NamaPenyanyi=GetWords();
        int jumlahAlbum=WordtoInt(currentWord);
        Word NamaPenyanyi=GetWords();
        nextLine();
        for (int j=0; j<jumlahAlbum; j++)
        {
            ADVWORD();
            //InfoPenyanyi[i].InfoAlbum[j].jumlahLagu=WordtoInt(currentWord);
            int jumlahLagu=WordtoInt(currentWord);
            //printf("%d\n",InfoPenyanyi[i].InfoAlbum[j].lagu.Count);
            Word NamaAlbum=GetWords();
            //InfoPenyanyi[i].InfoAlbum[j].NamaAlbum=GetWords();
            mapInsert(&AlbumtoPenyanyi, NamaAlbum, NamaPenyanyi);
            //printf("%s %s\n",NamaPenyanyi.TabWord,NamaAlbum.TabWord);
            nextLine();
            for(int k=0; k<jumlahLagu; k++)
            {
                NamaLagu=GetWords();
                //InfoPenyanyi[i].InfoAlbum[j].lagu[k]=w;
                //mapInsert(&LagutoAlbum, NamaLagu, NamaAlbum);
                nextLine();
            }
        }
    }
    Word w;
    //for(int i=0; i<AlbumtoPenyanyi.Count; i++)printf("%s %s\n",AlbumtoPenyanyi.Elements[i].Key.TabWord,AlbumtoPenyanyi.Elements[i].Value.TabWord);
    
}