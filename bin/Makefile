# KAMUS
CC = gcc
CFLAGS = -Wall -Werror -std=c11

.PHONY: all clean test
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


# # UNTUK PROGRAM UTAMA
# List seluruh .c yang ingin di compile
# ../src/ADT_BUATAN/LAGU/lagu.c ../src/ADT_BUATAN/LAGU/driver_lagu.c
# ../src/ADT_BUATAN/ALBUM/album.c ../src/ADT_BUATAN/ALBUM/driver_album.c
# ../src/ADT_BUATAN/PENYANYI/penyanyi.c ../src/ADT_BUATAN/PENYANYI/driver_penyanyi.c
# ../src/ADT_BUATAN/PLAYLIST/playlist.c ../src/ADT_BUATAN/PLAYLIST/driver_playlist.c
# ../src/ADT_BUATAN/QUEUELAGU/queuelagu.c ../src/ADT_BUATAN/QUEUELAGU/driver_queuelagu.c
# ../src/ADT_BUATAN/RIWAYAT/riwayat.c ../src/ADT_BUATAN/RIWAYAT/driver_riwayat.c
SRC_MAIN = ../src/ADT/mesinkata/mesinkata.c ../src/ADT/mesinkata/mesinkarakter.c ../src/ADT_BUATAN/LAGU/lagu.c ../src/ADT_BUATAN/ALBUM/album.c ../src/ADT_BUATAN/PENYANYI/penyanyi.c ../src/ADT_BUATAN/PLAYLIST/playlist.c ../src/ADT_BUATAN/QUEUELAGU/queuelagu.c ../src/ADT_BUATAN/RIWAYAT/riwayat.c ../src/COMMAND/START/start.c ../src/COMMAND/PLAY/play.c

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


# # UNTUK SETIAP ADT, contoh awal Stack
SRC_STACK = ADT/STACK/stack.c
OBJ_STACK = $(SRC_STACK:.c=.o)

allStack: Stack_program mfoo
Stack_program: $(OBJ_STACK)
	$(CC) $(CFLAGS) -o $@ $^

runStack: Stack_program 
	./Stack_program

cleanStack:
	rm -f main_program mfoo $(OBJ_STACK) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)
	rm -f Stack_program mfoo $(OBJ_STACK) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)