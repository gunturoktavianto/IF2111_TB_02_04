# Tugas Besar Algoritma Struktur Data STI 2023

---
## Kebucinan Bandowoso kepada Roro tidak berhenti meski harus membuat candi. Bandowoso juga ingin membuat aplikasi WayangWave untuk meluluhkan hati Roro. Aplikasi WayangWave dibuat dengan menggunakan bahasa C dan memanfaatkan struktur ADT yang merupakan modifikasi dari ADT List, Mesin Karakter dan Mesin Kata, Queue, Stack, Set & Map, dan List dengan struktur berkait. Adapun library yang digunakan adalah stdio.h, stdlib.h, math.h dan time.h.  

## Maka dari itu, kami sebagai peserta IF2111 Kelompok 4 K2, berinisiatif untuk membantu Bondowoso (sekali lagi) dengan membuat aplikasi WayangWave tersebut

## Fitur utama WayangWave antara lain memutar lagu, menampilkan daftar lagu, membuat dan menghapus playlist, mengatur urutan dimainkan lagu, dan menampilkan status dari aplikasi. Fitur-fitur ini direalisasikan melalui kode perogram yang terdiri dari main menu yang berisi fungsi start, load, dan help. Serta penanganan command lain.

## Cara menjalankan aplikasi WayangWave 
1. Clone repository ini pada komputer Anda dengan mengetikkan command berikut pada powershell.
```
git clone https://github.com/gunturoktavianto/IF2111_TB_02_04.git
```
2. Gunakan command "make" pada terminal yang direktorinya sudah pada folder ini (menggunakan Makefile)
```
make run
```
3. Apabila command "make" tidak bisa digunakan, copy perintah compile yang ada pada Makefile (bagian bawah)
```
gcc -o run main.c console.c ../src/ADT_BUATAN/ALBUM/album.c ../src/ADT_BUATAN/LAGU/lagu.c ../src/ADT_BUATAN/PENYANYI/penyanyi.c ../src/ADT_BUATAN/PLAYLIST/playlist.c ../src/ADT_BUATAN/QUEUELAGU/queuelagu.c ../src/ADT_BUATAN/RIWAYAT/riwayat.c ../src/COMMAND/LIST/listlagu.c ../src/COMMAND/LOAD/load.c ../src/COMMAND/PLAY/play.c ../src/COMMAND/HELP/help.c ../src/COMMAND/PLAYLIST/playlistcmd.c ../src/COMMAND/QUEUE/queuecmd.c ../src/COMMAND/QUIT/quit.c ../src/COMMAND/SAVE/save.c ../src/COMMAND/SONG/song.c ../src/COMMAND/START/start.c ../src/COMMAND/STATUS/status.c ../src/ADT/mesinkata/mesinkata.c ../src/ADT/mesinkata/mesinkarakter.c 
```
4. Untuk menjalankan WayangWave, buka file run.exe atau ketikkan "./run" pada terminal
```
./run
```
5. Selamat menikmati 🥂
---
Side note: Belum dilakukan pengujian terhadap MacOS karena keterbatasan finansial kami

P.S. Aplikasi ini 100% aman dari plagiarisme karena dibuat semata-mata untuk mengejar deadline tubes :D
