
#Make file used to quickly compile the files used in necrostromo
CC = g++
CFLAGS = -g -Wall -std=c++11

#when adding new classes make sure to add their .o files to this recipe
a.exe: necrostromo.o board.o entity.o board.h tile.o tile.h entity.h
	$(CC) $(CFLAGS) necrostromo.o board.o tile.o entity.o -o a.exe

necrostromo.o: necrostromo.cc board.h tile.h
	$(CC) -c $(CFLAGS) necrostromo.cc 

board.o: board.cc board.h tile.h
	$(CC) -c $(CFLAGS) board.cc

tile.o: tile.cc
	$(CC) -c $(CFLAGS) tile.cc

entity.o: entity.cc
	$(CC) -c $(CFLAGS) entity.cc

clean:
	del /f /q *.o a.exe