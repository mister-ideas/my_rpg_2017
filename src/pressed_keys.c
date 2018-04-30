/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** pressed_keys.c
*/

#include "my_rpg.h"

static void check_pressed_move_keys(game_t *game)
{
	if (game->window->event.key.code == sfKeyZ)
		game->keys->z = sfTrue;
	if (game->window->event.key.code == sfKeyQ)
		game->keys->q = sfTrue;
	if (game->window->event.key.code == sfKeyS)
		game->keys->s = sfTrue;
	if (game->window->event.key.code == sfKeyD)
		game->keys->d = sfTrue;
}

static void check_pressed_attack_keys(game_t *game)
{
	if (game->window->event.key.code == sfKeyUp)
		game->keys->up = sfTrue;
	if (game->window->event.key.code == sfKeyLeft)
		game->keys->left = sfTrue;
	if (game->window->event.key.code == sfKeyDown)
		game->keys->down = sfTrue;
	if (game->window->event.key.code == sfKeyRight)
		game->keys->right = sfTrue;
}

static void check_pressed_other_keys(game_t *game)
{
	if (game->window->event.key.code == sfKeyEscape)
		game->keys->esc = sfTrue;
	if (game->window->event.key.code == sfKeySpace)
		game->keys->space = sfTrue;
	if (game->window->event.key.code == sfKeyLShift)
		game->keys->shift = sfTrue;
}

void check_pressed_keys(game_t *game)
{
	check_pressed_move_keys(game);
	check_pressed_attack_keys(game);
	check_pressed_other_keys(game);
}
