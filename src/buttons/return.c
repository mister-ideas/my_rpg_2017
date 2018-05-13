/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/return.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void return_function(game_t *game)
{
	game->current_scene = 0;
	sfSprite_setPosition(game->character->
	char_obj->sprite, (sfVector2f){890, 460});
	for (int i = 0; i < NB_MOBS; i++) {
		sfSprite_setPosition(game->mobs[i]->
		mob_obj->sprite, (sfVector2f){0, 0});
	}
	sfMusic_stop(game->musics[0]);
	sfMusic_stop(game->musics[2]);
	sfMusic_stop(game->musics[4]);
	sfMusic_play(game->musics[3]);
	sfMusic_setLoop(game->musics[3], sfTrue);
}

static button_t *return_button_active(button_t *back)
{
	back->active.height = 85;
	back->active.left = 0;
	back->active.top = 3413;
	back->active.width = 235;
	return (back);
}

static button_t *return_button_hover(button_t *back)
{
	back->hover.height = 85;
	back->hover.left = 0;
	back->hover.top = 3327;
	back->hover.width = 235;
	return (back);
}

button_t *return_button(void)
{
	button_t *back = malloc(sizeof(*back));

	if (back == NULL)
		return (NULL);
	back->size.x = 235;
	back->size.y = 85;
	back->rect.height = 85;
	back->rect.left = 0;
	back->rect.top = 3241;
	back->rect.width = 235;
	back = return_button_hover(back);
	back = return_button_active(back);
	back->callback = &(return_function);
	return (back);
}
