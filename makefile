
#Make file used to quickly compile the files used in Necrostromo
CC = g++
CFLAGS = -g -Wall -std=c++11

#when adding new classes make sure to add their .o files to this recipe
a.out: Necrostromo.o board.o entity.o board.h tile.o tile.h entity.h player.o player.h 
	$(CC) $(CFLAGS) Necrostromo.o board.o tile.o entity.o player.o -lncurses -o a.out 

Necrostromo.o: Necrostromo.cc board.h tile.h
	$(CC) -c $(CFLAGS) Necrostromo.cc 

board.o: board.cc board.h tile.h
	$(CC) -c $(CFLAGS) board.cc

tile.o: tile.cc tile.h
	$(CC) -c $(CFLAGS) tile.cc

entity.o: entity.cc entity.h
	$(CC) -c $(CFLAGS) entity.cc

player.o: player.cc player.h
	$(CC) -c $(CFLAGS) player.cc

clean:
	rm -rf *.o a.out