
#Make file used to quickly compile the files used in necrostromo
CC = g++
CFLAGS = -g -Wall -std=c++11

a.exe: necrostromo.o board.o board.h tile.o tile.h
	$(CC) $(CFLAGS) necrostromo.o board.o tile.o -o a.exe

necrostromo.o: necrostromo.cc board.h tile.h
	$(CC) -c $(CFLAGS) necrostromo.cc 

board.o: board.cc board.h tile.h
	$(CC) -c $(CFLAGS) board.cc

tile.o: tile.cc
	$(CC) -c $(CFLAGS) tile.cc
	