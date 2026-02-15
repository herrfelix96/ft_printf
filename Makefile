CC=cc
CFLAGS=-Wall -Wextra -Werror -I.
NAME=libftprintf.a

SRC=ft_printf.c \
          helpers/ft_printf_formats.c \
          helpers/ft_printf_hex.c \
          helpers/ft_printf_numbers.c \
          helpers/ft_printf_utils.c

OBJ=$(SRC:.c=.o)
HEADER=ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
