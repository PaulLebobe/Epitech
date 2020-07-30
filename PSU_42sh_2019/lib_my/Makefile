##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	int_to_char.c	\
			my_realloc.c	\
			two_string_in_one.c	\
			my_putstring.c	\
			is_equal.c	\
			get_next_line.c	\
			puissance.c	\
			my_strlen.c	\
			my_strlen_2d.c	\
			char_to_int.c	\
			str_copy.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Iinclude_lib

NAME = lib.a

all:    $(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
