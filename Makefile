CC = gcc
CFLAGS = -Wall -Wextra -Werror 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

MAIN = main
MAIN_SRC = main.c

$(MAIN): $(MAIN_SRC) $(NAME)
	@echo "Compiling main test program $@"
	$(CC) $(CFLAGS) $(MAIN_SRC) -L. -lft -o $(MAIN)

run: $(MAIN)
	./$(MAIN)

.PHONY: all clean fclean re