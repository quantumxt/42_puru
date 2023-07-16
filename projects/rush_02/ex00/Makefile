TARGET := rush-02
COMPILER := cc

SRC_DIR := ./src
C_FILES := main.c extract.c utils.c conversion.c check.c reader.c display.c
SRC_FILES := $(addprefix $(SRC_DIR)/,$(C_FILES))
OBJ_FILES := $(SRC_FILES:.c=.o)

INC_DIRS := ./include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := $(INC_FLAGS) -Wall -Wextra -Werror -g

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(COMPILER) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all re clean fclean
