CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude
SRC_DIR = src
INCLUDE_DIR = include
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Archiving $@"
	ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	rm -f $(OBJS)

fclean: clean
	@echo "Removing library"
	rm -f $(NAME)

re: fclean all

TEST = ft_strcpy_test
TEST_SRC = src/ft_strcpy.c

$(TEST): $(TEST_SRC) $(NAME)
	@echo "Compiling test program $@"
	$(CC) $(CFLAGS) $(TEST_SRC) -L. -lft -o $(TEST)

run: $(TEST)
	@echo "Running test program"
	./$(TEST)

.PHONY: all clean fclean re