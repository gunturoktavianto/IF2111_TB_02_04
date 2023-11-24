# KAMUS
CC = gcc
CFLAGS = -Wall -Werror -std=c11

.PHONY: all clean test
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


# # UNTUK PROGRAM UTAMA
# List seluruh .c yang ingin di compile
SRC_MAIN = ../src/ADT/mesinkata/mesinkata.c ../src/ADT/mesinkata/mesinkarakter.c ../src/ADT_BUATAN/LAGU/lagu.c ../src/ADT_BUATAN/ALBUM/album.c ../src/ADT_BUATAN/PENYANYI/penyanyi.c ../src/ADT_BUATAN/PLAYLIST/playlist.c ../src/ADT_BUATAN/QUEUELAGU/queuelagu.c ../src/ADT_BUATAN/RIWAYAT/riwayat.c ../src/COMMAND/HELP/help.c ../src/COMMAND/LIST/listlagu.c ../src/COMMAND/LOAD/load.c ../src/COMMAND/PLAY/play.c ../src/COMMAND/PLAYLIST/playlistcmd.c ../src/COMMAND/QUEUE/queuecmd.c ../src/COMMAND/QUIT/quit.c ../src/COMMAND/SAVE/save.c ../src/COMMAND/SONG/song.c ../src/COMMAND/START/start.c ../src/COMMAND/STATUS/status.c ../src/console.c ../src/main.c 

OBJ_MAIN = $(SRC_MAIN:.c=.o)

# compile 
all: main_program mfoo			
main_program: $(OBJ_MAIN) $(OBJ_FOO)
	$(CC) $(CFLAGS) -o $@ $^

# hapus file compile
clean:
	rm -f main_program mfoo $(OBJ_MAIN) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)

# run + compile
run: main_program
	./main_program

# Alternatif jika makefile tidak dapat dijalankan
# 1. ketik "cd src" pada terminal anda
# 2. Copy and paste text berikut:
# gcc -o run main.c console.c ../src/ADT_BUATAN/ALBUM/album.c ../src/ADT_BUATAN/LAGU/lagu.c ../src/ADT_BUATAN/PENYANYI/penyanyi.c ../src/ADT_BUATAN/PLAYLIST/playlist.c ../src/ADT_BUATAN/QUEUELAGU/queuelagu.c ../src/ADT_BUATAN/RIWAYAT/riwayat.c ../src/COMMAND/LIST/listlagu.c ../src/COMMAND/LOAD/load.c ../src/COMMAND/PLAY/play.c ../src/COMMAND/HELP/help.c ../src/COMMAND/PLAYLIST/playlistcmd.c ../src/COMMAND/QUEUE/queuecmd.c ../src/COMMAND/QUIT/quit.c ../src/COMMAND/SAVE/save.c ../src/COMMAND/SONG/song.c ../src/COMMAND/START/start.c ../src/COMMAND/STATUS/status.c ../src/ADT/mesinkata/mesinkata.c ../src/ADT/mesinkata/mesinkarakter.c 
# 3. ketik "./run" pada terminal anda dan aplikasi berhasil dijalankan