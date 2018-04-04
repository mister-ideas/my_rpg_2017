/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** window.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int init_window(game_t *game, sfVideoMode video)
{
	sfVector2i pos = {0, 0};

	game->window = malloc(sizeof(game->window));
	if (game->window == NULL)
		return (84);
	game->window->mode = video;
	game->window->window = sfRenderWindow_create(game->window->mode,
						"RPG", sfClose, NULL);
	if (game->window->window == NULL)
		return (84);
	game->window->mouse_pos = pos;
	return (0);
}
