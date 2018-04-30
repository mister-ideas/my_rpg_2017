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
	if (game->keys->esc == sfTrue && game->current_scene != 0 &&
	game->current_scene != 1 && game->current_scene != 3) {
		game->last_scene = game->current_scene;
		game->current_scene = 3;
	}
	if (game->keys->space == sfTrue && game->current_scene == 2)
		game->current_scene = 4;
}

static void controls_events(game_t *game)
{
	if (game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3) {
		if (game->current_weapon == 0 || game->current_weapon == 1)
			bow_spell_walk(game);
		if (game->current_weapon == 2) {
			spear_walk(game);
			spear_attack(game);
		}
		if (game->current_weapon == 0)
			spell_attack(game);
		if (game->current_weapon == 1)
			bow_attack(game);
	}
}

void game_events(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window->window,
					&(game->window->event))) {
		general_events(game);
		if (game->window->event.type == sfEvtKeyPressed)
			check_pressed_keys(game);
		if (game->window->event.type == sfEvtKeyReleased)
			check_released_keys(game);
		game_keys_events(game);
		controls_events(game);
		if (game->keys->z == sfFalse && game->keys->q == sfFalse &&
		game->keys->s == sfFalse && game->keys->d == sfFalse &&
		game->keys->up == sfFalse && game->keys->left == sfFalse &&
		game->keys->down == sfFalse && game->keys->right == sfFalse) {
			game->character->char_obj->rect.top = 4600;
			game->character->char_obj->rect.left = 240;
			game->character->clock_max = 240;
			game->character->move.x = 0;
			game->character->move.y = 0;
		}
	}
}
