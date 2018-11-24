
CC= gcc

ODIR = $(pwd)

all: universalDrawer

universalDrawer: main.o draw.o read.o
	$(CC) -static -o universalDrawer main.o draw.o read.o

draw.o: draw.c shared.h draw.h
	$(CC) -c -Wall -static draw.c

read.o: read.c read.h
	$(CC) -c -Wall -static read.c

main.o: main.c draw.h read.h
	$(CC) -c -Wall -static main.c

.PHONY: clean

clean:
	rm -f $(ODIR)*.o $(ODIR)universalDrawer
