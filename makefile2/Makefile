#define for *.h files + compiler
IDIR= ../include
ODIR= obj
EDIR=../exe
CFLAGS=-I$(IDIR)

all: $(EDIR)/universalDrawer

$(ODIR)/draw.o: draw.c $(IDIR)/draw.h $(IDIR)/shared.h
	arm-none-eabi-gcc --specs=nosys.specs -c -o $(ODIR)/draw.o draw.c $(CFLAGS)
$(ODIR)/read.o: read.c $(IDIR)/read.h
	arm-none-eabi-gcc --specs=nosys.specs -c -o $(ODIR)/read.o read.c $(CFLAGS)
$(ODIR)/main.o: main.c $(IDIR)/read.h $(IDIR)/draw.h
	arm-none-eabi-gcc --specs=nosys.specs -c -o $(ODIR)/main.o main.c $(CFLAGS)
$(EDIR)/universalDrawer: $(ODIR)/main.o $(ODIR)/read.o $(ODIR)/draw.o
	arm-none-eabi-gcc --specs=nosys.specs -static -o $(EDIR)/universalDrawer $(ODIR)/main.o $(ODIR)/read.o $(ODIR)/draw.o $(CFLAGS)
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o main
