TARGET_LIB := libft.a
COMPILER := cc

SRC_DIR := ./srcs
C_FILES := ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRC_FILES := $(addprefix $(SRC_DIR)/,$(C_FILES))
OBJ_FILES := $(SRC_FILES:.c=.o)

INC_DIRS := includes
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := $(INC_FLAGS) -Wall -Wextra -Werror

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJ_FILES)
	ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(TARGET_LIB)

re: fclean all

.PHONY: all re clean fclean
