##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## Makefile
##

SRC_DIR=	src/

LIB_SRC_DIR=	lib/src/

CC=		gcc

SRC=		$(SRC_DIR)my_rpg.c				\
		$(SRC_DIR)linked_list.c				\
		$(SRC_DIR)scene.c				\
		$(SRC_DIR)tools.c				\
		$(SRC_DIR)window.c				\
		$(SRC_DIR)events.c				\
		$(SRC_DIR)doors.c				\
		$(SRC_DIR)walls.c				\
		$(SRC_DIR)pressed_keys.c			\
		$(SRC_DIR)released_keys.c			\
		$(SRC_DIR)free.c				\
		$(SRC_DIR)display.c				\
		$(SRC_DIR)button.c				\
		$(SRC_DIR)object.c				\
		$(SRC_DIR)particules/particules.c		\
		$(SRC_DIR)particules/particules_init.c		\
		$(SRC_DIR)controls/bow_spell_walk.c  		\
		$(SRC_DIR)controls/spear_walk.c			\
		$(SRC_DIR)controls/spell_attack.c		\
		$(SRC_DIR)controls/spear_attack.c		\
		$(SRC_DIR)controls/bow_attack.c			\
		$(SRC_DIR)scenes/menu_scene.c			\
		$(SRC_DIR)scenes/htp_scene.c			\
		$(SRC_DIR)scenes/intro_scene.c			\
		$(SRC_DIR)scenes/pause_scene.c			\
		$(SRC_DIR)scenes/stats_inv_scene.c		\
		$(SRC_DIR)scenes/win_scene.c			\
		$(SRC_DIR)scenes/lose_scene.c			\
		$(SRC_DIR)scenes/arena1_scene.c			\
		$(SRC_DIR)scenes/arena2_scene.c                 \
		$(SRC_DIR)scenes/arena3_scene.c                 \
		$(SRC_DIR)scenes/arena4_scene.c                 \
		$(SRC_DIR)scenes/bossarena_scene.c		\
		$(SRC_DIR)objects/character.c			\
		$(SRC_DIR)objects/weapons.c			\
		$(SRC_DIR)objects/texts.c			\
		$(SRC_DIR)objects/mobs.c			\
		$(SRC_DIR)objects/arrows.c			\
		$(SRC_DIR)objects/check_arrows.c		\
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
		$(MAKE) -C $(LIB_SRC_DIR)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(MAKE) clean -C $(LIB_SRC_DIR)
		$(RM) $(OBJ)

fclean: 	clean
		make fclean -C $(LIB_SRC_DIR)
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
