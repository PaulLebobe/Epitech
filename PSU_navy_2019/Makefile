##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

CFLAGS += -g

SRC		=	main.c		\
			buff.c		\
			map.c		\
			my_getnbr.c	\
			game.c		\
			handler.c	\
			init.c		\
			game_pass.c \
			my_puts.c

OBJ		=	$(SRC:.c=.o)

NAME	=	navy

RM 		=	rm -f

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all