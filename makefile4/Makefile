############ VARIABLES ############

## PATHs ##
# header files path
IPATH=
# object files path
OPATH=.
# exe file path
EPATH=.

## OPTIONS ##
COMPILER=gcc
OPTIONS=
COMPILE=$(COMPILER) $(OPTIONS) -Wall -c
LINK=$(COMPILER) $(OPTIONS) -Wall

## MAIN FILE NAME ##
MAIN=main

_OBJ = $(MAIN).o draw.o read.o
OBJ = $(patsubst %, $(OPATH)/%, $(_OBJ))

############ BODY #############

all: $(MAIN)

$(MAIN): $(OBJ)
	$(LINK) $(OBJ) -o $(EPATH)/$@

$(MAIN).o: $(MAIN).c draw.c read.c $(IPATH)/draw.h $(IPATH)/read.h
	$(COMPILE) $^ -o $(OPATH)/$@	

draw.o: draw.c $(IPATH)/draw.h
	$(COMPILE) $^ -o $(OPATH)/$@

read.o: read.c $(IPATH)/read.h
	$(COMPILE) $^ -o $(OPATH)/$@

# cleaning recipe
.PHONY clean
clean:
	rm -f $(OPATH)/*.o $(EPATH)/$(MAIN)	
