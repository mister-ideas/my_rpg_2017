/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/play.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void play_function(game_t *game)
{
	game->current_scene = 3;
	sfMusic_stop(game->musics[3]);
	sfMusic_play(game->musics[2]);
	sfMusic_setLoop(game->musics[2], sfTrue);
}

static button_t *play_button_active(button_t *play)
{
	play->active.height = 85;
	play->active.left = 0;
	play->active.top = 2639;
	play->active.width = 235;
	return (play);
}

static button_t *play_button_hover(button_t *play)
{
	play->hover.height = 85;
	play->hover.left = 0;
	play->hover.top = 2553;
	play->hover.width = 235;
	return (play);
}

button_t *play_button(void)
{
	button_t *play = malloc(sizeof(*play));

	if (play == NULL)
		return (NULL);
	play->size.x = 235;
	play->size.y = 85;
	play->rect.height = 85;
	play->rect.left = 0;
	play->rect.top = 2467;
	play->rect.width = 235;
	play = play_button_hover(play);
	play = play_button_active(play);
	play->callback = &(play_function);
	return (play);
}
