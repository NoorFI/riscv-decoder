CC = gcc 
CFLAGS = -Wall -Wextra -std=c11 -g 

INCLUDES = -Iinclude

SRC = src/main.c \
	src/decoder.c \
	src/memory.c

DEBUG_FLAGS = -DDEBUG

TEST_FILES = \
	test/programs/mixed.hex \
	test/programs/branch.hex \
	test/programs/r_type.hex \
	test/programs/i_type.hex

TARGET = riscv-decoder

.PHONY: all clean test debug valgrind

all: $(TARGET)
$(TARGET):
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	@for file in $(TEST_FILES); do \
		echo "Running: $$file"; \
		./$(TARGET) $$file; \
		echo ""; \
	done

debug:
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) \
	$(INCLUDES) $(SRC) \
	-o $(TARGET)

valgrind: $(TARGET)
	@for file in $(TEST_FILES); do \
		echo "Valgrind: $$file"; \
		valgrind --leak-check=full \
				--show-leak-kinds=all \
				./$(TARGET) $$file; \
		echo ""; \
	done