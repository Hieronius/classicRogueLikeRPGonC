CC = gcc
CFLAGS = -lncurses -lm -I./include/
SOURCES = *.c

all: rogue # compile and run the program and after clean it if there is no error

rogue:
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue

clean:
	rm rogue
