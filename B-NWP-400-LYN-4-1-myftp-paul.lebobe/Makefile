##
## EPITECH PROJECT, 2021
## B-NWP-400-LYN-4-1-myftp-paul.lebobe
## File description:
## Makefile
##

CFLAGS += -g

SRC		=	$(shell find . -name '*.c')

OBJ		=	$(SRC:.c=.o)

NAME	=	myftp

RM 		=	rm -f

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all