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

re: fclean allgit 

MAIN = main
MAIN_SRC = src/main.c

$(MAIN): $(MAIN_SRC) $(NAME)
	@echo "Compiling main test program $@"
	$(CC) $(CFLAGS) $(MAIN_SRC) -L. -lft -o $(MAIN)

run: $(MAIN)
	@echo "Running main test program"
	./$(MAIN)


.PHONY: all clean fclean re
