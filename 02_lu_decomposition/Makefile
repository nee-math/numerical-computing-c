CC = gcc
CFLAGS = -Wall -Wextra -O2 -lm

all: solver

solver: main.o lu.o
	$(CC) $(CFLAGS) -o solver main.o lu.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o solver