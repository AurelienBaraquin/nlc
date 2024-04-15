CFLAGS = -I./include -nostdlib -W

SRC = $(shell find src -name "*.c")

OBJ = $(SRC:.c=.o)

TARGET = main

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

all: $(TARGET)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re:	fclean all
