COMPILATORE_1 = gcc
COMPILATORE_2 = arm-none-eabi-gcc
ifdef PREFIX
else
PREFIX=gcc
endif

ifeq ($(PREFIX), $(COMPILATORE_1))
OPZIONE=-static
endif
ifeq ($(PREFIX), $(COMPILATORE_2))
OPZIONE=--specs=nosys.specs
endif


DIR_OBJ=./obj
DIR_EXE=./exe
DIR_INCLUDE=../../../LAB3/ise_gr09_lab03/src

all: universalDrawer

main.o: $(DIR_INCLUDE)/main.c $(DIR_INCLUDE)/read.h $(DIR_INCLUDE)/draw.h
	mkdir $(DIR_OBJ)
	$(PREFIX) -Wall -o $(DIR_OBJ)/main.o -c $<

draw.o: $(DIR_INCLUDE)/draw.c $(DIR_INCLUDE)/draw.h $(DIR_INCLUDE)/shared.h
	$(PREFIX) -Wall -o $(DIR_OBJ)/draw.o -c $<

read.o: $(DIR_INCLUDE)/read.c $(DIR_INCLUDE)/read.h
	$(PREFIX) -Wall -o $(DIR_OBJ)/read.o -c $<

universalDrawer : main.o draw.o read.o
	mkdir $(DIR_EXE)
	$(PREFIX) -Wall $(OPZIONE) -o $(DIR_EXE)/universalDrawer  $(DIR_OBJ)/main.o $(DIR_OBJ)/draw.o $(DIR_OBJ)/read.o
	chmod +x $(DIR_EXE)/universalDrawer

.PHONY: clean
clean:
	rm -r $(DIR_OBJ)
	rm -r $(DIR_EXE)
