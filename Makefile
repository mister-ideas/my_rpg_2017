##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## Makefile
##

SRC_DIR=	src/

LIB_SRC_DIR=	lib/src/

SRC=		$(SRC_DIR)my_rpg.c				\
		$(SRC_DIR)linked_list.c				\
		$(SRC_DIR)scene.c				\
		$(SRC_DIR)window.c				\
		$(SRC_DIR)events.c				\
		$(SRC_DIR)free.c				\
		$(SRC_DIR)display.c				\
		$(SRC_DIR)button.c				\
		$(SRC_DIR)object.c				\
		$(SRC_DIR)controls/bow_spell_walk.c  		\
		$(SRC_DIR)controls/spear_walk.c			\
		$(SRC_DIR)controls/spell_attack.c		\
		$(SRC_DIR)scenes/menu_scene.c			\
		$(SRC_DIR)scenes/htp_scene.c			\
		$(SRC_DIR)scenes/intro_scene.c			\
		$(SRC_DIR)scenes/pause_scene.c			\
		$(SRC_DIR)scenes/arena1_scene.c			\
		$(SRC_DIR)scenes/arena2_scene.c                 \
		$(SRC_DIR)scenes/arena3_scene.c                 \
		$(SRC_DIR)scenes/arena4_scene.c                 \
		$(SRC_DIR)scenes/boss_scene.c                	\
		$(SRC_DIR)objects/character.c			\
		$(SRC_DIR)buttons/play.c   			\
		$(SRC_DIR)buttons/quit.c             		\
		$(SRC_DIR)buttons/how_to_play.c      		\
		$(SRC_DIR)buttons/resume.c			\
		$(SRC_DIR)buttons/return.c			\

OBJ=		$(SRC:.c=.o)

CFLAGS= 	-W -Wall -Wextra

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
