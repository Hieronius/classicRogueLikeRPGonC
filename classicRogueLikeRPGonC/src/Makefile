CC = gcc
CFLAGS = -lncurses
SOURCES = *.c

all: rogue run clean # compile and run the program and after clean it if there is no error

rogue:
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

run:
	./rogue

clean:
	rm rogue
