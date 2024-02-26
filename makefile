CC = gcc
LIBDIR = $(shell pwd)/lib/

# -g	adds debug info to executable
#  -Wall turns on most compiler warnings
CFLAGS = -g -Wall

default: sort

sort: sort_visuliser.o sort.o
	$(CC) $(CFLAGS) -o sort sort_visuliser.o sort.o

sort_visuliser.o: sort_visuliser.c
	$(CC) $(CFLAGS) -c sort_visuliser.c

sort.o: $(LIBDIR)sort.c $(LIBDIR)sort.h
	$(CC) $(CFLAGS) -c $(LIBDIR)sort.c
