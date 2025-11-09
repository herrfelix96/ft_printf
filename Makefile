CC=cc
OPTIONS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRC_FILES=ft_printf.c helpers.c
OBJ_FILES=$(SRC_FILES:.c=.o)
HEADER=ft_printf.h

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rc $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) -c $(OPTIONS) $< -o $@

OBJ_FILES: $(HEADER)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: clean fclean re all
