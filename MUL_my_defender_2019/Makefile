##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

CFLAGS += -g

SRC		=	main.c		\
			init.c		\
			game.c		\
			tower.c		\
			into_str.c	\
			init2.c		\
			init3.c		\
			moves.c		\
			attacks.c 	\
			cr_attacks.c\
			atk_check.c	\
			life_check.c\
			game_over.c \
			how_to.c	\
			init_over.c \
			elec_atk.c	\
			print_tw.c	\
			zomb3_init.c\
			zomb3.c 	\
			menu.c


NAME	=	my_defender

all:	$(NAME)

$(NAME):
	gcc $(SRC) -lm -o $(NAME) -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -I. -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all