##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

CFLAGS += -g

SRC		=	main.c			\
			my_getnbr.c		\
			print.c			\
			puts.c 			\
			my_strcmp.c	\
			do_init.c	\
			lemin_tools.c	\
			utils.c	\
			my_strdup.c	\
			dijkstra.c	\
			dijkstra_tools.c	\
			my_strlen.c	\
			manage_tools.c	\
			error.c	\
			my_norm.c	\
			str_to_word_tab.c	\
			manage_path.c	\
			path_tools.c	\
			my_split_str.c	\
			my_add_str.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	lem_in

RM 		=	rm -f

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all