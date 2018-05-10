/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** released_keys.c
*/

#include "my_rpg.h"

static void check_released_move_keys(game_t *game)
{
	if (game->window->event.key.code == sfKeyZ)
		game->keys->z = sfFalse;
	if (game->window->event.key.code == sfKeyQ)
		game->keys->q = sfFalse;
	if (game->window->event.key.code == sfKeyS)
		game->keys->s = sfFalse;
	if (game->window->event.key.code == sfKeyD)
		game->keys->d = sfFalse;
}

static void check_released_attack_keys(game_t *game)
{
	if (game->window->event.key.code == sfKeyUp)
		game->keys->up = sfFalse;
	if (game->window->event.key.code == sfKeyLeft)
		game->keys->left = sfFalse;
	if (game->window->event.key.code == sfKeyDown)
		game->keys->down = sfFalse;
	if (game->window->event.key.code == sfKeyRight)
		game->keys->right = sfFalse;
}

static void check_released_other_keys(game_t *game)
{
	if (game->window->event.key.code == sfKeyEscape)
		game->keys->esc = sfFalse;
	if (game->window->event.key.code == sfKeySpace)
		game->keys->space = sfFalse;
	if (game->window->event.key.code == sfKeyLShift)
		game->keys->shift = sfFalse;
	if (game->window->event.key.code == sfKeyLAlt)
		game->keys->alt = sfFalse;
}

int check_all_keys_released(game_t *game)
{
	if (game->keys->z == sfFalse && game->keys->q == sfFalse &&
	game->keys->s == sfFalse && game->keys->d == sfFalse) {
		game->character->move.x = 0;
		game->character->move.y = 0;
		if (game->keys->up == sfFalse && game->keys->left == sfFalse &&
		game->keys->down == sfFalse && game->keys->right == sfFalse)
			return (1);
	}
	return (0);
}

void check_released_keys(game_t *game)
{
	check_released_move_keys(game);
	check_released_attack_keys(game);
	check_released_other_keys(game);
}
