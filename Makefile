C=gcc
CFLAGS=-std=c99 -Wall -Wextra -D_XOPEN_SOURCE=700
LDFLAGS=-lrt

all: trans command_comparison

trans: trans.c
	$(CC) $(CFLAGS) -o trans trans.c $(LDFLAGS)

command_comparison: command_comparison.c
	$(CC) $(CFLAGS) -o command_comparison command_comparison.c

clean:
	rm -f trans command_comparison
