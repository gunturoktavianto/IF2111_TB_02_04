#include "ADT/LIST/driver_list.c"
#include "ADT/MAP/driver_map.c"
#include "ADT/SET/driver_set.c"
#include "ADT/QUEUE/driver_queue.c"
#include "ADT/STACK/driver_stack.c"
#include "ADT/LISTLINIER/driver_listlinier.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*PLAY merupakan command yang digunakan untuk memutar lagu atau playlist yang dipilih. Ketika command PLAY dieksekusi, queue yang ada dihapus ketika memainkan lagu atau digantikan oleh lagu dalam playlist ketika memainkan playlist. Terdapat dua jenis play, SONG dan PLAYLIST. */

/*PLAY SONG
Command PLAY SONG digunakan untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu. Ketika command ini berhasil dieksekusi, queue dan riwayat lagu akan menjadi kosong.

>> PLAY SONG;

Daftar Penyanyi :
New Jeans
BLACKPINK
Central Cee
Rich Brian
Denny Caknan
Via Vallen

Masukkan Nama Penyanyi yang dipilih : BLACKPINK;

Daftar Album oleh BLACKPINK :
BORN PINK
THE ALBUM
SQUARE ONE
SQUARE TWO

Masukkan Nama Album yang dipilih : BORN PINK;

Daftar Lagu Album BORN PINK oleh BLACKPINK : 
Pink Venom
Shut Down
Typa Girl
Yeah Yeah Yeah
Hard to Love
The Happiest Girl
Tally
Ready for Love

Masukkan ID Lagu yang dipilih : 3;

Memutar lagu “Type Girl” oleh “BLACKPINK”.

*/
int currentsong;
void PlaySong(){
    boolean valid = false;
    // menampilkan penyanyi, disimpan dalam ADT list statis
    int i=0;
    printf("Daftar Penyanyi :\n");
    while(ListPenyanyi.A[i]!=Mark){
        printf("  %d. %d\n", i+1, ListPenyanyi.A[i]);
    }

    // mencari penyanyi
    char namapenyanyi[100];
    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    while(valid == false){
        scanf("%s", &namapenyanyi); /*cuma baca sampai sebelum spasi*/
        if(Search(ListPenyanyi, namapenyanyi)){valid = true;}
        else{printf("Nama Penyanyi tidak ditemukan.\n");}
    }

    // menampilkan album dari penyanyi X, disimpan dalam ADT map
    printf("Daftar Album oleh %s :\n", namapenyanyi);
    PrintMap(Album);

    // mencari album
    char namaalbum[100];
    printf("\nMasukkan Nama Album yang dipilih : ");
    valid == false;
    while(valid == false){
        scanf("%s", &namaalbum); /*cuma baca sampai sebelum spasi*/
        if(IsMemberMap(Album, namaalbum)){valid = true;}
        else{printf("Nama Album tidak ditemukan.\n");}
    }

    // menampilkan lagu dari album X, disimpan dalam ADT set
    printf("Daftar Lagu Album %s oleh %s :\n", namaalbum, namapenyanyi);
    PrintMap(Album);

    // mencari lagu
    int IDlagu;
    printf("\nMasukkan ID Lagu yang dipilih : ");
    valid == false;
    while(valid == false){
        scanf("%d", &IDlagu); /*cuma baca sampai sebelum spasi*/
        InfoLagu temp;
        temp.lagu = IDlagu;
        if(IsMemberSet(Lagu, temp)){valid = true;}
        else{printf("ID Lagu tidak ditemukan.\n");}
    }
    printf("\nMemutar lagu \"%s\" oleh \"%s\".\n", Lagu.Elements[IDlagu], namapenyanyi);

    // Final State
    //Ketika command ini berhasil dieksekusi, queue dan riwayat lagu akan menjadi kosong
    Queue playPlaylist;
    CreateQueue(&playPlaylist);
    // Update currentsong
    currentsong = IDlagu;
}

/*PLAY PLAYLIST
Command PLAY PLAYLIST digunakan untuk memainkan lagu berdasarkan id playlist. Ketika command ini berhasil dieksekusi, queue akan berisi semua lagu yang ada dalam playlist yang dimainkan dan isi riwayat lagu sama dengan queue, tetapi dengan urutan yang di-reverse. Jika user memanggil fungsi start sebelumnya, maka playlist kosong.
*/

void PlayPlaylist(){
    /*Initial State*/
    /*playlist tidak kosong*/
    ListLL playlist; //temporary
    boolean valid = false;
    int IDplaylist;
    while(valid == false){
        printf("Masukkan ID Playlist: ");
        scanf("%d", &IDplaylist);
        infotypeLL temp;
        temp = IDplaylist;
        if(SearchLL(playlist, temp) != Nil){valid = true;}
        else{printf("ID Playlist tidak ditemukan.\n");}
    }
    printf("\nMemutar playlist \"%s\".\n", Lagu.Elements[IDplaylist]);

    /*Final State*/
    /*currentsong menjadi lagu urutan pertama dalam playlist*/
    currentsong = Info(First(playlist));

    /*queue berisi semua lagu dalam playlist*/
    Queue queueLagu;
    Queue playPlaylist;
    address p = First(playlist);
    while(p!=Nil){
        enqueue(&playPlaylist, Info(p));
        p = Next(p);
    }
    Queue tempPlaylist;
    copyQueue(&playPlaylist, &tempPlaylist);
    // masukin playlist ke queuelagu

    /*riwayat berisi queue yang di reverse*/
    Queue reversedPlaylist;
    Stack riwayat;
    transferReverse(&tempPlaylist, &reversedPlaylist);

    while(lengthQueue(reversedPlaylist)){
        int Elmt;
        dequeue(&reversedPlaylist, &Elmt);
        Push(&riwayat,Elmt);
    }

    
}


/*
1. daftar penyanyi dengan ADT list statis
2. daftar playlist dengan ADT list dinamis
3. Queue lagu dengan ADT queue
4. Riwayat lagu dengan ADT stack
5. Menyimpan lagu pada album dengan ADT set
6. Menyimpan album pada penyanyi dan menyimpan lagu dengan ADT map
7. Suatu kumpulan lagu yang kontigue dinamakan playlist, dibuat dengan ADT List dengan Struktur Berkait
*/

