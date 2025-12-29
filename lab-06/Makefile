#-------------------------------------------------------------------------------

CC = gcc
CFLAGS = -Wall -O6

SRC = mystrings.c Person.c NameAge.c
OBJ = $(SRC:.c=.o)

EXEC = NameAge

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

all: $(EXEC)

clean:
	rm -f $(OBJ)

#-------------------------------------------------------------------------------
