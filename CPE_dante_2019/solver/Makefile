##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

CFLAGS += -g

SRC		=	main.c		\
			buffer.c	\
			my_puts.c

OBJ		=	$(SRC:.c=.o)

NAME	=	solver

RM 		=	rm -f

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g -I.

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all