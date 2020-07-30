##
## EPITECH PROJECT, 2020
## redirections
## File description:
## Makefile
##

SRC     =	src/write_redirec.c	\
			src/read_redirec.c	\
			src/condition_to_use_redirection.c

OBJ	=	$(SRC:.c=.o)

NAME    =       redirections.a

PATH_LIB	=	../lib_my/
AR_LIB	=	$(PATH_LIB)lib.a

CFLAGS =	-Iinclude/
CFLAGS += -Wall -Wextra -g3

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C $(PATH_LIB)
	ar rc $(NAME) $(AR_LIB) $(OBJ)

clean:
	make clean -C $(PATH_LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(PATH_LIB)
	rm -f $(NAME)

re:     fclean all