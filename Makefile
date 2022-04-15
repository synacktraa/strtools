BIN=gcc
CFLAGS=-g -Wall
SRCDIR=src

all: strtools

strtools.o: $(SRCDIR)/strtools.c
	$(BIN) $(CFLAGS) -c $^

utils.o: $(SRCDIR)/utils.c
	$(BIN) $(CFLAGS) -c $^

file_handler.o: $(SRCDIR)/file_handler.c
	$(BIN) $(CFLAGS) -c $^

validator.o: $(SRCDIR)/validator.c
	$(BIN) $(CFLAGS) -c $^

strtools: strtools.o utils.o file_handler.o validator.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:

ifeq ($(OS),Windows_NT)
	del *.o, strtools.exe
else
	rm *.o strtools
endif