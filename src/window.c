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
	window_t *window = malloc(sizeof(*window));
	sfVector2i mouse_pos = {0, 0};

	if (window == NULL)
		return (84);
	game->window = window;
	game->window->window = sfRenderWindow_create(video,
					"Initiation Quest", sfClose, NULL);
	if (game->window->window == NULL)
		return (84);
	game->window->mouse_pos = mouse_pos;
	game->window->click = 2;
	return (0);
}

int display_window(game_t *game, particules_t *particules)
{
	sfRenderWindow_setFramerateLimit(game->window->window, 60);
	while (sfRenderWindow_isOpen(game->window->window)) {
		game_events(game);
		sfRenderWindow_clear(game->window->window, sfBlack);
		display_game(game);
		sfRenderWindow_display(game->window->window);
	}
	quit_game(game, particules);
	return (0);
}
