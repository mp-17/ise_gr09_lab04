
CC= gcc

ODIR = $(pwd)

_DEPS = shared.h read.h draw.h
DEPS = $(pathsubst %, $(ODIR)/%, $(_DEPS))

_OBJ = main.o draw.o read.o

all: universalDrawer

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -Wall $< 

universalDrawer: $(_OBJ)
	$(CC) -static -o $@ $(_OBJ)

.PHONY: clean

clean:
	rm -f $(ODIR)*.o $(ODIR)universalDrawer
