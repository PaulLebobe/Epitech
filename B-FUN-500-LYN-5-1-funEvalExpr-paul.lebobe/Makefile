##
## EPITECH PROJECT, 2021
## fun-evalexpr
## File description:
## Makefile
##

PROJECT_NAME	=	funEvalExpr

all: $(PROJECT_NAME)

$(PROJECT_NAME):
	stack install --local-bin-path . --exec 'mv fun-evalexpr-exe funEvalExpr'

tests_run:
	stack test

tests_run_coverage:
	stack test --coverage

clean:
	rm -f $(PROJECT_NAME)

fclean: clean

re: fclean all