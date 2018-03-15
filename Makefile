##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## Makefile
##

SRC_DIR=	src

SRC=		$(SRC_DIR)/my_rpg.c		\
		$(SRC_DIR)/linked_list.c	\
		$(SRC_DIR)/buttons.c		\
		$(SRC_DIR)/display.c		\
		$(SRC_DIR)/window.c		\
		$(SRC_DIR)/scenes.c		\
		$(SRC_DIR)/end_game.c		\

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-W -Wall -fno-builtin

CPPFLAGS =	-I include

LFLAGS=		-l c_graph_prog -L lib/my/ -l my

NAME=		my_rpg

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/src/
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		make clean -C lib/src/
		rm -f $(OBJ)

fclean: 	clean
		make fclean -C lib/src/
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
