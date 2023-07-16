TARGET := do-op
SRC_DIR := ./src
INC_DIR := ./include
C_FILES := main.c ops.c check.c display.c
SRC_FILES := $(addprefix $(SRC_DIR)/,$(C_FILES))
OBJ_FILES := $(SRC_FILES:.c=.o)
FLAGS := -Wall -Wextra -Werror -I$(INC_DIR)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	cc $(FLAGS) $^ -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	cc $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
