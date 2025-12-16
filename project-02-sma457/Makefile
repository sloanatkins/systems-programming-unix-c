#-----------------------------------------------------------------------------
# Makefile for ThreadFibServer and FibInterface
#-----------------------------------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -pthread
LDFLAGS = -pthread

all: ThreadFibServer.out FibInterface.out

ThreadFibServer.out: ThreadFibServer.c
	$(CC) $(CFLAGS) -o ThreadFibServer.out ThreadFibServer.c $(LDFLAGS)

FibInterface.out: FibInterface.c
	$(CC) $(CFLAGS) -o FibInterface.out FibInterface.c

clean:
	rm -f ThreadFibServer.out FibInterface.out FIBOPIPE

.PHONY: all clean
