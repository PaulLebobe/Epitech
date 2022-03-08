##
## EPITECH PROJECT, 2021
## B-NWP-400-LYN-4-1-myftp-paul.lebobe
## File description:
## Makefile
##

CFLAGS += -g

SRC	=	$(shell find . -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_cli

RM	=	rm -f

CFLAGS	+=	-I../libs/myteams

CFLAGS	+=	-I./include

LDFLAGS	+=	-L../libs/myteams -lmyteams

MV	=	mv myteams_cli ../

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) -luuid
	$(MV)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all