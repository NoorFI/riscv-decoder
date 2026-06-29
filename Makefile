CC = gcc 
CFLAGS = -Wall -Wextra -std=c11 -g 

INCLUDES = -Iinclude

SRC = src/main.c \
	src/decoder.c \
	src/memory.c

TARGET = riscv-decoder

.PHONY: all clean #test debug valgrind

all: $(TARGET)
$(TARGET):
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)