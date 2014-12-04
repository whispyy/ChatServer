CC      = gcc
CFLAGS  = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -DDEBUG
CFLAGS += -g

BINARIES = 	mtcs
OBJECTS = 	mtcs.o tools.o cnct.o

all : $(BINARIES) $(OBJECTS)

###------------------------------
### Entries
###------------------------------------------------------------
mtcs : $(OBJECTS)
	$(CC) -o $@ $^

###------------------------------
### Dependencies
###------------------------------------------------------------
# thanks to 'make depend'
cnct.o: cnct.c config.h tools.h cnct.h
mtcs.o: mtcs.c tools.h config.h cnct.h
tools.o: tools.c tools.h

###------------------------------
### Misc.
###------------------------------------------------------------
.PHONY: clean realclean depend
clean::
	$(RM) $(BINARIES)
realclean:: clean
	$(RM) $(OBJECTS) $(TRASHFILES)
depend:
	$(CC) $(CFLAGS) -MM *.c

