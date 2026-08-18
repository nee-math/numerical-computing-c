CC = gcc
CFLAGS = -Wall -Wextra -O2 -lm

all: solver convergence

solver: main.o cg.o
	$(CC) $(CFLAGS) -o solver main.o cg.o

convergence: convergence.o cg.o
	$(CC) $(CFLAGS) -o convergence convergence.o cg.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o solver convergence