/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** window.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos)
{
	return (clickPos.x < pos.x + size.x && clickPos.x > pos.x &&
		clickPos.y < pos.y + size.y && clickPos.y > pos.y);
}

int init_window(game_t *game, sfVideoMode video)
{
	window_t *window = malloc(sizeof(*window));
	sfVector2i mouse_pos = {0, 0};

	if (window == NULL)
		return (84);
	game->window = window;
	game->window->window = sfRenderWindow_create(video,
						"RPG", sfClose, NULL);
	if (game->window->window == NULL)
		return (84);
	game->window->mouse_pos = mouse_pos;
	game->window->click = 2;
	return (0);
}

int game_events(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window->window,
					&(game->window->event))) {
		if (game->window->event.type == sfEvtClosed)
			sfRenderWindow_close(game->window->window);
		if (game->window->event.type == sfEvtMouseMoved)
			game->window->mouse_pos =
				sfMouse_getPositionRenderWindow
				(game->window->window);
		if (game->window->event.type == sfEvtMouseButtonPressed)
			game->window->click = 1;
		if (game->window->event.type == sfEvtMouseButtonReleased)
			game->window->click = 0;
	}
	return (0);
}

int display_window(game_t *game)
{
	sfRenderWindow_setFramerateLimit(game->window->window, 60);
	while (sfRenderWindow_isOpen(game->window->window)) {
		game_events(game);
		sfRenderWindow_clear(game->window->window, sfBlack);
		if (display_game(game) == 84)
			return (84);
		sfRenderWindow_display(game->window->window);
	}
	quit_game(game);
	return (0);
}
