##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

CFLAGS += -g

SRC		=		main.c		\
				files.c		\
				switch.c	\
				game.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

RM 		=	rm -f

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses -I. my.h

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all