##
## EPITECH PROJECT, 2021
## B-NWP-400-LYN-4-1-myteams-adrien.rocourt
## File description:
## Makefile
##

SERVER	=	server/

CLIENT	=	client/

all:
	@echo "\n\033[38;5;11m START Compliation of $(SERVER) & .h\033[0m\033[K\n"
	make -s -C $(SERVER)
	@echo "\n\033[38;5;22m MAKE $(SERVER)\033[0m\033[K\n"
	@echo "\n\033[38;5;11m START Compliation of $(CLIENT) & .h\033[0m\033[K\n"
	make -s -C $(CLIENT)
	@echo "\n\033[38;5;22m MAKE $(CLIENT)\033[0m\033[K\n"

server: re

client: re

clean:
	@echo "\n\033[38;5;124m CLEANING .o & vgcore\033[0m\033[K\n"
	make -s -C $(SERVER) clean
	make -s -C $(CLIENT) clean
	@rm -rf myteams_cli
	@rm -rf myteams_server
	@echo "\n\033[38;5;124m CLEANED .o & vgcore\033[0m\033[K\n"

fclean: clean
	@echo "\n\033[38;5;124m FCLEANING \033[0m\033[K\n"
	make -s -C $(SERVER) fclean
	make -s -C $(CLIENT) fclean
	@echo "\n\033[38;5;124m FCLEANED \033[0m\033[K\n"

re:	fclean all

.PHONY:	all clean fclean re