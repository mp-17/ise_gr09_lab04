#define for *.h files + compiler
IDIR= ../include
ODIR= obj
CFLAGS=-I$(IDIR)

all: universalDrawer

$(ODIR)/draw.o: draw.c $(IDIR)/draw.h $(IDIR)/shared.h
	arm-none-eabi-gcc --specs=nosys.specs -static -c -o $(ODIR)/draw.o draw.c $(CFLAGS)
$(ODIR)/read.o: read.c $(IDIR)/read.h
	arm-none-eabi-gcc --specs=nosys.specs -static -c -o $(ODIR)/read.o read.c $(CFLAGS)
$(ODIR)/main.o: main.c $(IDIR)/read.h $(IDIR)/draw.h
	arm-none-eabi-gcc --specs=nosys.specs -static -c -o $(ODIR)/main.o main.c $(CFLAGS)
universalDrawer: $(ODIR)/main.o $(ODIR)/read.o $(ODIR)/draw.o
	arm-none-eabi-gcc --specs=nosys.specs -static -o universalDrawer $(ODIR)/main.o $(ODIR)/read.o $(ODIR)/draw.o $(CFLAGS)
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o main
