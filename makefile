# genera automáticamente los ejecutable del programa
# genera el ejecutable programa y el ejecutable test

CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99

SRC = trie.c utilities.c main.c test.c
OBJ = $(SRC:.c=.o)
HEADER = trie.h utilities.h
EXECUTABLE = programa
TEST_EXECUTABLE = test

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

$(EXECUTABLE): main.o utilities.o trie.o
	$(CC) main.o utilities.o trie.o -o $(EXECUTABLE)

$(TEST_EXECUTABLE): test.o utilities.o trie.o
	$(CC) test.o utilities.o trie.o -o $(TEST_EXECUTABLE)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE) $(TEST_EXECUTABLE)
