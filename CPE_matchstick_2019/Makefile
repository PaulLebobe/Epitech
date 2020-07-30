##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

CFLAGS += -g

SRC		=	main.c		\
			my_putstr.c	\
			my_strlen.c	\
			game.c		\
			compute.c	\
			my_input.c	\
			my_getnbr.c

OBJ		=	$(SRC:.c=.o)

NAME	=	matchstick

RM 		=	rm -f

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all