/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** events.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static void general_events(game_t *game)
{
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

static void game_keys_events(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1
	&& game->current_scene != 3) {
		game->last_scene = game->current_scene;
		game->current_scene = 3;
	}
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue &&
	game->current_scene == 2)
		game->current_scene = 4;
}

void game_events(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window->window,
					&(game->window->event))) {
		general_events(game);
		if (game->window->event.type == sfEvtKeyPressed) {
			game_keys_events(game);
			bow_spell_walk_z(game);
		} else if (game->window->event.type == sfEvtKeyReleased) {
			game->character->char_obj->rect.top = 4600;
			game->character->char_obj->rect.left = 230;
			game->character->clock_max = 230;
			game->character->move.x = 0;
			game->character->move.y = 0;
		}
	}
}
