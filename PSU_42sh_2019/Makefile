##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## M
##


SRC     =	src/main.c	\
			src/env_term_pos_disp.c	\
			src/my_strcmp.c	\
			src/read_term.c	\
			src/test.c	\
			src/clean_string.c	\
			src/create_argv.c	\
			src/exec.c	\
			src/in_path.c	\
			src/my_strncmp.c	\
			src/my_putstr.c		\
			src/cd.c			\
			src/str_adopte.c	\
			src/first_word.c	\
			src/exec_command.c	\
			src/symbol.c	\
			src/command_line_test.c	\
			src/new_create_argv.c	\
			src/pipe.c

OBJ	=	$(SRC:.c=.o)

NAME    =       42sh

CFLAGS = -Iinclude/
CFLAGS += -Wall -Wextra -g3

PATH_REDIR	=	redirections/
AR_REDIR	=	$(PATH_REDIR)redirections.a

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C lib_my/
	make -C $(PATH_REDIR)
	gcc -o $(NAME) $(OBJ) lib_my/lib.a $(AR_REDIR) -W -Wall -g3

clean:
	make clean -C src/lib_my/
	make clean -C $(PATH_REDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C src/lib_my/
	make fclean -C $(PATH_REDIR)
	rm -f $(NAME)

re:     fclean all
