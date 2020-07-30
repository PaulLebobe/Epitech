##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

CFLAGS += -g

SRC		=	main.c			\
			f_tetriminos.c	\
			my_puts.c		\
			my_strcat.c		\
			my_getnbr.c		\
			init.c			\
			my_putnbr.c 	\
			check.c			\
			moves.c			\
			print.c			\
			rand.c			\
			debug.c			\
			check_over.c	\
			game.c

OBJ		=	$(SRC:.c=.o)

NAME	=	tetris

RM 		=	rm -f

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses -g -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all