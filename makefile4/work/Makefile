############ VARIABLES ############

## PATHs ##
# header files path
IPATH=./include
# object files path
OPATH=./obj
# exe file path
EPATH=./exe

## OPTIONS ##
ifdef PREFIX
	COMPILER=$(PREFIX)-gcc
	LOPTIONS=-Wall -static --specs=nosys.specs
else
	COMPILER=gcc
	LOPTIONS=-Wall
endif
COPTIONS=-Wall -iquote $(IPATH) -c
COMPILE=$(COMPILER) $(COPTIONS)
LINK=$(COMPILER) $(LOPTIONS)

## MAIN FILE NAME ##
MAIN=main

## OBJECTS ##

_OBJ = $(MAIN).o draw.o read.o
OBJ = $(patsubst %, $(OPATH)/%, $(_OBJ))

############ BODY #############

all: $(EPATH)/$(MAIN)

$(EPATH)/$(MAIN): $(OBJ)
	$(LINK) $^ -o $@

$(OPATH)/%.o: %.c $(IPATH)/draw.h $(IPATH)/read.h
	$(COMPILE) $< -o $@	

# cleaning recipe
.PHONY: clean
clean:
	rm -f $(OPATH)/*.o $(EPATH)/$(MAIN)	