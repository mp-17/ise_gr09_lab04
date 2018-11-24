COMPILATORE_1 = gcc
COMPILATORE_2 = arm-none-eabi-gcc

ifdef PREFIX
JOIN=-
else
PREFIX=
JOIN=
endif

ifeq ($(PREFIX)$(JOIN)gcc, $(COMPILATORE_1))
OPZIONE=-static
endif
ifeq ($(PREFIX)$(JOIN)gcc, $(COMPILATORE_2))
OPZIONE=--specs=nosys.specs -static
endif


DIR_OBJ=./obj
DIR_EXE=./exe
DIR_INCLUDE=../../../LAB3/ise_gr09_lab03/src

all: universalDrawer

main.o: $(DIR_INCLUDE)/main.c $(DIR_INCLUDE)/read.h $(DIR_INCLUDE)/draw.h $(DIR_INCLUDE)/aid.h 
	mkdir -p $(DIR_OBJ)
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/main.o -c $<

draw.o: $(DIR_INCLUDE)/draw.c $(DIR_INCLUDE)/draw.h $(DIR_INCLUDE)/shared.h
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/draw.o -c $<

read.o: $(DIR_INCLUDE)/read.c $(DIR_INCLUDE)/read.h
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/read.o -c $<

aid.o: $(DIR_INCLUDE)/aid.c $(DIR_INCLUDE)/aid.h $(DIR_INCLUDE)/shared.h
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/aid.o -c $<

universalDrawer : main.o draw.o read.o aid.o
	mkdir -p $(DIR_EXE)
	$(PREFIX)$(JOIN)gcc -Wall $(OPZIONE) -o $(DIR_EXE)/universalDrawer  $(DIR_OBJ)/main.o $(DIR_OBJ)/draw.o $(DIR_OBJ)/read.o $(DIR_OBJ)/aid.o
	chmod +x $(DIR_EXE)/universalDrawer

.PHONY: clean
clean:
	rm -r $(DIR_OBJ)
	rm -r $(DIR_EXE)
