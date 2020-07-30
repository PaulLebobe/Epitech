##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##

SRC     =	src/main.c	\
			src/dig.c	\
			src/dig2.c	\
			src/way_free.c	\
			src/rm_road.c	\
			src/pair.c	\
			src/imperfect.c

OBJ	=	$(SRC:.c=.o)

NAME    =       generator

CFLAGS = -Iinclude/
CFLAGS += -Wall -Wextra -g3

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C src/lib_my
	gcc -o $(NAME) $(OBJ) src/lib_my/lib.a

clean:
	make clean -C src/lib_my
	rm -f $(OBJ)

fclean: clean
	make fclean -C src/lib_my
	rm -f $(NAME)

re:     fclean all
