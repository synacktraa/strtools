BIN=gcc
CFLAGS=-g -Wall

all: strtools

strtools.o: strtools.c
	$(BIN) $(CFLAGS) -c $^

utils.o: utils.c
	$(BIN) $(CFLAGS) -c $^

file_handler.o: file_handler.c
	$(BIN) $(CFLAGS) -c $^

validator.o: validator.c
	$(BIN) $(CFLAGS) -c $^

strtools: strtools.o utils.o file_handler.o validator.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:

ifeq ($(OS),Windows_NT)
	del *.o, strtools.exe
else
	rm *.o strtools
endif