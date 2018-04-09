##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## Makefile
##

SRC_DIR=	src/

LIB_SRC_DIR=	lib/src/

SRC=		$(SRC_DIR)my_rpg.c			\
		$(SRC_DIR)linked_list.c			\
		$(SRC_DIR)scenes.c			\
		$(SRC_DIR)window.c			\
		$(SRC_DIR)free.c			\
		$(SRC_DIR)display.c			\
		$(SRC_DIR)buttons.c			\
		$(SRC_DIR)buttons_functions.c   	\
		$(SRC_DIR)objects.c			\
		$(SRC_DIR)menu_scene.c          	\
		$(SRC_DIR)menu_scene_buttons.c   	\

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-Wall -Wextra -g3

CPPFLAGS =	-I include

LDFLAGS=	-l c_graph_prog -L lib/my/ -l my

NAME=		my_rpg

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_SRC_DIR)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		make clean -C $(LIB_SRC_DIR)
		rm -f $(OBJ)

fclean: 	clean
		make fclean -C $(LIB_SRC_DIR)
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
