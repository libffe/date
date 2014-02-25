OPTIMIZATION ?= -O2
DEBUG = -g -ggdb
WARN = -Wall -pedantic
CFLAGS += $(WARN) $(DEBUG)

default: libdate.a

all: libdate.a test

libdate.a: date.o
	ar rcs libdate.a date.o

date.o: date.c date.h
	$(CC) $(CFLAGS) -c $< -o $@

test: date.c date.h
	$(CC) $(CFLAGS) -DDATE_TEST $< -o $@
	./test

clean:
	-@rm -rf *.o *.a test

.PHONY: default all test
