CC=gcc
SOURCE_DIR=src/
TEST_DIR=tests/

all: roman

roman: main.o romanconverter.o check_romanconverter.o
	$(CC) -o roman main.o romanconverter.o check_romanconverter.o
	echo roman: make complete

main.o: $(SOURCE_DIR)main.c
	$(CC) -c $(SOURCE_DIR)main.c

romanconverter.o: $(SOURCE_DIR)romanconverter.c $(SOURCE_DIR)romanconverter.h
	$(CC) -c $(SOURCE_DIR)romanconverter.c

check_romanconverter.o: $(SOURCE_DIR)romanconverter.c
	$(CC) -c $(TEST_DIR)check_romanconverter.c

clean:
	rm roman
	rm main.o
	rm romanconverter.o
	rm check_romanconverter.o
