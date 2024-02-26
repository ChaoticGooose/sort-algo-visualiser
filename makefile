CC = gcc
LIBDIR = $(shell pwd)/lib/

# -g	adds debug info to executable
#  -Wall turns on most compiler warnings
CFLAGS = -g -Wall

default: sort

sort: sort_visualiser.o sort.o
	$(CC) $(CFLAGS) -o sort sort_visualiser.o sort.o

sort_visuliser.o: sort_visualiser.c
	$(CC) $(CFLAGS) -c sort_visualiser.c

sort.o: $(LIBDIR)sort.c $(LIBDIR)sort.h
	$(CC) $(CFLAGS) -c $(LIBDIR)sort.c
