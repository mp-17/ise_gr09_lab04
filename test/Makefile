############ VARIABLES ############

## PATHs ##
# header files path
IPATH=./include
# object files path
OPATH=./obj
# exe file path
EPATH=./exe
# script files path
SPATH=./script
# common path
CPATH=./common

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

_OBJ = $(MAIN).o draw.o read.o aid.o
OBJ = $(patsubst %, $(OPATH)/%, $(_OBJ))

############ BODY #############

all: $(EPATH)/$(MAIN)

$(EPATH)/$(MAIN): $(OBJ)
	mkdir -p $(EPATH)
	$(LINK) $^ -o $@
	chmod +x $(EPATH)/$(MAIN) 

$(OPATH)/%.o: %.c $(IPATH)/draw.h $(IPATH)/read.h $(IPATH)/shared.h $(IPATH)/aid.h
	mkdir -p $(OPATH)
	$(COMPILE) $< -o $@	

# cleaning recipe
.PHONY: clean
clean:
	rm -r -f $(OPATH) $(EPATH)

.PHONY: test
test:
	mkdir -p $(CPATH)
	python3 $(SPATH)/inputGenerator.py
	python3 $(SPATH)/universalDrawer.py
	$(EPATH)/$(MAIN) < $(CPATH)/cmd.txt
	diff $(CPATH)/py_matrix.txt $(CPATH)/drawnMtx.txt  
