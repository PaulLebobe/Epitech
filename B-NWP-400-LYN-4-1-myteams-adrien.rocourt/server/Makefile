##
## EPITECH PROJECT, 2021
## B-NWP-400-LYN-4-1-myftp-paul.lebobe
## File description:
## Makefile
##

CFLAGS += -g

SRC	=	$(shell find . -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_server

RM	=	rm -f

MV	=	mv myteams_server ../

LDFLAGS	+=	-L../libs/myteams -lmyteams

all:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) -g -I. -luuid
		$(MV)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all