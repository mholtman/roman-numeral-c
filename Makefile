CC=cc
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
SOURCE_DIR=src/
TEST_DIR=tests/

all: check

check: roman
	./roman

roman: romanconverter.o check_romanconverter.o testRunner.o integerconverter.o romancalculator.o
	$(CC) -o roman romanconverter.o integerconverter.o check_romanconverter.o testRunner.o romancalculator.o $(LIBS)
	echo roman: make complete

romanconverter.o: $(SOURCE_DIR)romanconverter.c $(SOURCE_DIR)romanconverter.h
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)romanconverter.c

integerconverter.o: $(SOURCE_DIR)integerconverter.c $(SOURCE_DIR)integerconverter.h
		$(CC) $(CFLAGS) -c $(SOURCE_DIR)integerconverter.c

romancalculator.o: $(SOURCE_DIR)romancalculator.c $(SOURCE_DIR)romancalculator.h
		$(CC) $(CFLAGS) -c $(SOURCE_DIR)romancalculator.c

check_romanconverter.o: $(SOURCE_DIR)romanconverter.c $(TEST_DIR)check_romanconverter.c $(TEST_DIR)testRunner.c
	$(CC) $(CFLAGS) -c $(TEST_DIR)check_romanconverter.c  $(TEST_DIR)check_romanconverter.h $(TEST_DIR)testRunner.c $(LIBS)

clean:
	rm roman
	rm romanconverter.o
	rm check_romanconverter.o

valgrind: roman
	valgrind ./roman
