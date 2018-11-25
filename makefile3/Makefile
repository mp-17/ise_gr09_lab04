#AVAILABLE COMPILATORS
COMPILATORE_1 = gcc
COMPILATORE_2 = arm-none-eabi-gcc

#SETTING JOIN - IT USED TO BUILD THE CORRECT GCC COMMAND
ifdef PREFIX
JOIN=-
else
PREFIX=
JOIN=
endif

# SETTING OPTIONS OR SPECS
ifeq ($(PREFIX)$(JOIN)gcc, $(COMPILATORE_1))
OPZIONE=-static
endif
ifeq ($(PREFIX)$(JOIN)gcc, $(COMPILATORE_2))
OPZIONE=--specs=nosys.specs -static
endif


DIR_OBJ=./obj #OBJECT FILES PATH
DIR_EXE=./exe #EXE FILE PATH
DIR_CFILES=.
DIR_INCLUDE=./include #.H FILES PATH
CFLAGS=-iquote $(DIR_INCLUDE) #GCC NEEDS IT IF THE .H FILES PATH DIFFERS FROM THE .C PATH

all: $(DIR_EXE)/universalDrawer

$(DIR_OBJ)/main.o: $(DIR_CFILES)/main.c $(DIR_INCLUDE)/read.h $(DIR_INCLUDE)/draw.h $(DIR_INCLUDE)/aid.h
	mkdir -p $(DIR_OBJ)
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/main.o -c $< $(CFLAGS)

$(DIR_OBJ)/draw.o: $(DIR_CFILES)/draw.c $(DIR_INCLUDE)/draw.h $(DIR_INCLUDE)/shared.h
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/draw.o -c $< $(CFLAGS)

$(DIR_OBJ)/read.o: $(DIR_CFILES)/read.c $(DIR_INCLUDE)/read.h
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/read.o -c $< $(CFLAGS)

$(DIR_OBJ)/aid.o: $(DIR_CFILES)/aid.c $(DIR_INCLUDE)/aid.h $(DIR_INCLUDE)/shared.h
	$(PREFIX)$(JOIN)gcc -Wall -o $(DIR_OBJ)/aid.o -c $< $(CFLAGS)

$(DIR_EXE)/universalDrawer : $(DIR_OBJ)/main.o $(DIR_OBJ)/draw.o $(DIR_OBJ)/read.o $(DIR_OBJ)/aid.o
	mkdir -p $(DIR_EXE)
	$(PREFIX)$(JOIN)gcc -Wall $(OPZIONE) -o $(DIR_EXE)/universalDrawer  $(DIR_OBJ)/main.o $(DIR_OBJ)/draw.o $(DIR_OBJ)/read.o $(DIR_OBJ)/aid.o
	chmod +x $(DIR_EXE)/universalDrawer

.PHONY: clean
clean:
	rm -r -f $(DIR_OBJ)
	rm -r -f $(DIR_EXE)
