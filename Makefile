CC = gcc
INC = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
TARGET = $(BIN)/collections.a
CFLAGS = -I $(INC) -Wall -Wextra -Werror -fPIC -c

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN)
	ar rcs $@ $^

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ):
	mkdir -p $@

$(BIN):
	mkdir -p $@

check: $(TARGET)
	@echo "Success, all tests passed."

clean:
	rm -r $(OBJ) $(BIN)
