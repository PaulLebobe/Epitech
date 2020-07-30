##
## EPITECH PROJECT, 2019
## Bistro
## File description:
## Makefile thomas
##

CC = gcc -g
CFLAGS = -c -Wall -Wextra -I include
EXEC = calc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)


all : $(EXEC)


%.o : %.c
	@$(CC) -o $@ $(CFLAGS) $<


$(EXEC) : $(OBJ)
	@$(CC) -o $@ $^

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(EXEC)

re : fclean all
