#define for *.h files + compiler
IDIR= ../include
ifdef CC
else
	CC=gcc
CFLAGS= -I$(IDIR)

#define for *.o files
ODIR= obj

_DEPS= shared.h read.h draw.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o read.o draw.o
OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o 
