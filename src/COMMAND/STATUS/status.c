#include "status.h"

/* SUPPORTING SECTION */
List currentplaylist;

boolean IsPlaylistinQueue(Queuelagu ql){
	int i=0;
	ElTypeQueue val;
	/*ALGORITMA*/
	while (IDX_HEAD(ql) != IDX_UNDEF)
	{
	    dequeueLagu(&ql, &val);

        /* MASIH SALAH*/
        /* 1. MENCARI PLAYLIST DENGAN ELEMEN PERTAMA = CURRENTSONG*/
        if (i==0){
            int j=0;
            while(!IsWordEq(currentsong.nama, Info(First(daftarPlaylist.A[j])).nama) && (j<daftarPlaylist.Neff)){
                if(j == daftarPlaylist.Neff-1 && !IsWordEq(currentsong.nama, Info(First(daftarPlaylist.A[j+1])).nama)){
                    return false;
                }
                j++;
            }
            currentplaylist = daftarPlaylist.A[j];
        }
        /* 2. MEMERIKSA KESELURUHAN ISI QUEUE APAKAH SAMA DENGAN PLAYLIST SEBELUMNYA*/
        else if (i>0 && SearchPlaylist(currentplaylist, val) == Nil){
            return false;
        }
        i++;
	}
    return true;
}

/* MAIN SECTION */
void startStatus(){
    printf("%s\n",currentsong.nama.TabWord);
    Word namacp = toKata("currentplaylist");
    CreateEmptyPlaylist(namacp, &currentplaylist);
    /* I.S. Tidak ada lagu yang diputar */
    if(currentsong.nama.Length==0){
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    } else{
        /* I.S. Ada lagu yang diputar */
        // I.S. Queue kosong
        if(isEmptyQueueLagu(q)){
            printf("Now Playing:\n%s - %s - %s\n\nQueue:\nYour queue is empty.", currentsong.penyanyi.TabWord, currentsong.album.TabWord, currentsong.nama.TabWord);
        } else{
            /* I.S. Queue tidak kosong */
            // I.S. Tidak memutar playlist //
            if (IsPlaylistinQueue(q)){
                printf("Now Playing:\n%s - %s - %s\n\nQueue:\n", currentsong.penyanyi.TabWord, currentsong.album.TabWord, currentsong.nama.TabWord);
                /* Queue untuk print*/
                int i=0;
                ElTypeQueue val;
                Queuelagu qq;
                CreateQueueLagu(&qq);
                copyQueueLagu(&q, &qq);
                while (IDX_HEAD(qq) != IDX_UNDEF)
                {
                    dequeueLagu(&qq, &val);
                    printf("%d. %s - %s - %s\n", i+1, val.penyanyi.TabWord, val.album.TabWord, val.nama.TabWord);
                    i++;
                }
            } else{
                /* I.S. Sedang memutar playlist */
                printf("Current Playlist: %s\n\nNow Playing:\n%s - %s - %s\n\nQueue:\n",currentplaylist.NamaPlaylist.TabWord, currentsong.penyanyi.TabWord, currentsong.album.TabWord, currentsong.nama.TabWord);
                }
            int i=0;
            ElTypeQueue val;
            Queuelagu qq;
            CreateQueueLagu(&qq);
            copyQueueLagu(&q, &qq);
            while (IDX_HEAD(qq) != IDX_UNDEF)
            {
                dequeueLagu(&qq, &val);
                printf("%d. %s - %s - %s\n", i+1, val.penyanyi.TabWord, val.album.TabWord, val.nama.TabWord);
                i++;
            }
            }
        }
}