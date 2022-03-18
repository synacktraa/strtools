BIN=gcc
CFLAGS=-g -Wall

all: toString

toString.o: toString.c
	$(BIN) $(CFLAGS) -c $^

toString_utils.o: toString_utils.c
	$(BIN) $(CFLAGS) -c $^

toString: toString.o toString_utils.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:

ifeq ($(OS),Windows_NT)
	del *.o, toString.exe
else
	CHECK := $(shell uname)
	ifeq ($(CHECK), Linux)
		rm *.o toString
	endif
endif