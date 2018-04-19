/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free.c
*/

#include <stdlib.h>
#include "my_rpg.h"

void quit_game(game_t *game)
{
	for (int i = 0; i < NB_SOUNDS; i++)
		sfMusic_destroy(game->sounds[i]);
	free(game->scenes);
	sfRenderWindow_destroy(game->window->window);
	free(game->window);
	sfImage_destroy(game->atlas);
	free(game);
}
