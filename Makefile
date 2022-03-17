BIN=gcc
CFLAGS=-g -Wall

all: toString

toString.o: toString.c
	$(BIN) $(CFLAGS) -c $^

toString_utils.o: toString_utils.c toString_utils.h
	$(BIN) $(CFLAGS) -c $^

toString: toString.o toString_utils.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:
	rm *.o toString *.gch