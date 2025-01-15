CC = cc

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c\
      src/init.c\
      src/error.c\
      src/operation_1.c\
      src/operation_2.c\
      src/operation_argument_1.c\
      src/operation_argument_2.c\
      src/operation_argument_3.c\
      src/parsing.c\
      src/sorting.c

OBJ = $(SRC:.c=.o)

LIBFTDIR = utils/libft

LIBFT_LIB = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
