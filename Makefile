CFLAGS = -I./include -fno-stack-protector -nostdlib -nostartfiles -W -g3

SRC_C = $(shell find src -name "*.c")
SRC_S = $(shell find src -name "*.s")

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.s=.o)

OBJ = $(OBJ_C) $(OBJ_S)

TARGET = main

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Règle pour compiler les fichiers .c en fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour compiler les fichiers .s en fichiers .o
%.o: %.s
	$(AS) -c $< -o $@

all: $(TARGET)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
