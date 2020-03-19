
#Make file used to quickly compile the files used in Necrostromo
CC = g++
CFLAGS = -g -Wall -std=c++11

#when adding new classes make sure to add their .o files to this recipe
a.out: Necrostromo.o board.o entity.o  tile.o  player.o item.o  generator.o data/head.h
	$(CC) $(CFLAGS) Necrostromo.o board.o tile.o entity.o player.o generator.o item.o -lncurses -I/usr/local/include -L/usr/local/lib -lnoise -o a.out 

Necrostromo.o: Necrostromo.cc data/board.h data/tile.h
	$(CC) -c $(CFLAGS) Necrostromo.cc 

board.o: data/board.cc data/board.h data/tile.h
	$(CC) -c $(CFLAGS) data/board.cc

tile.o: data/tile.cc data/head.h
	$(CC) -c $(CFLAGS) data/tile.cc

entity.o: data/entity.cc data/entity.h
	$(CC) -c $(CFLAGS) data/entity.cc

player.o: data/player.cc data/player.h
	$(CC) -c $(CFLAGS) data/player.cc

generator.o: data/generator.cc data/generator.h
	$(CC) -c $(CFLAGS) data/generator.cc

item.o: data/item.cc data/item.h
	$(CC) -c $(CFLAGS) data/item.cc

clean:
	rm -rf *.o a.out

