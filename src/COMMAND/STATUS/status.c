#include "status.h"

/* SUPPORTING SECTION */
List currentplaylist;

boolean IsPlaylistinQueue(Queuelagu ql){
	int i=0;
	ElTypeQueue val;
	/*ALGORITMA*/
	    dequeueLagu(&ql, &val);
        /* MASIH SALAH*/
        /* 1. MENCARI PLAYLIST DENGAN ELEMEN PERTAMA = CURRENTSONG*/
        boolean found = false;
        int iD=0;
        for(iD=0; iD<LengthArrayDin(daftarPlaylist); iD++){
            if(SearchPlaylist(daftarPlaylist.A[iD],val)!=Nil){
                found = true;
                break;
            }
        }
        if(found){
            enqueueLagu(&ql, val);
            if(lengthQueueLagu(ql)!=NbElmtPlaylist(daftarPlaylist.A[iD])) return false;
            else
            {
                int cnt=0;
                for (i=1; i<=NbElmtPlaylist(daftarPlaylist.A[iD]); i++)
                {
                    if (isInQueueLagu(ql, LaguIndeksKe(daftarPlaylist.A[iD],i))) {cnt++;}
                }
                if(cnt==NbElmtPlaylist(daftarPlaylist.A[iD])) {currentplaylist=daftarPlaylist.A[iD];return true;}
                return false;
            }
        } 
        else return false;
}

/* MAIN SECTION */
void startStatus(){
    displayQueueLagu(q);
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
            if (!IsPlaylistinQueue(q)){
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