CC=gcc
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
SOURCE_DIR=src/
TEST_DIR=tests/

all: check

check: roman
	./roman

roman: romanconverter.o check_romanconverter.o
	$(CC) -o roman romanconverter.o check_romanconverter.o $(LIBS)
	echo roman: make complete

romanconverter.o: $(SOURCE_DIR)romanconverter.c $(SOURCE_DIR)romanconverter.h
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)romanconverter.c

check_romanconverter.o: $(SOURCE_DIR)romanconverter.c $(TEST_DIR)check_romanconverter.c
	$(CC) $(CFLAGS) -c $(TEST_DIR)check_romanconverter.c $(LIBS)

clean:
	rm roman
	rm romanconverter.o
	rm check_romanconverter.o

valgrind: roman
	valgrind ./roman
