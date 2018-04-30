/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/spear_walk.c
*/

#include "my_rpg.h"

static void spear_walk_z(game_t *game)
{
	if (game->keys->z == sfTrue) {
		game->character->char_obj->rect.top = 3205;
		game->character->clock_max = 1248;
		if (game->keys->q == sfFalse && game->keys->d == sfFalse) {
			game->character->move.x = 0;
			game->character->move.y = -3;
		}
		if (game->keys->q == sfTrue) {
			game->character->move.x = -3;
			game->character->move.y = -3;
		}
		if (game->keys->d == sfTrue) {
			game->character->move.x = 3;
			game->character->move.y = -3;
		}
	}
}

static void spear_walk_q(game_t *game)
{
	if (game->keys->q == sfTrue && game->keys->z == sfFalse &&
	game->keys->s == sfFalse) {
		game->character->char_obj->rect.top = 3325;
		game->character->clock_max = 1248;
		game->character->move.x = -3;
		game->character->move.y = 0;
	}
}

static void spear_walk_s(game_t *game)
{
	if (game->keys->s == sfTrue) {
		game->character->char_obj->rect.top = 3460;
		game->character->clock_max = 1248;
		if (game->keys->q == sfFalse && game->keys->d == sfFalse) {
			game->character->move.x = 0;
			game->character->move.y = 3;
		}
		if (game->keys->q == sfTrue) {
			game->character->move.x = -3;
			game->character->move.y = 3;
		}
		if (game->keys->d == sfTrue) {
			game->character->move.x = 3;
			game->character->move.y = 3;
		}
	}
}

static void spear_walk_d(game_t *game)
{
	if (game->keys->d == sfTrue && game->keys->z == sfFalse &&
	game->keys->s == sfFalse) {
		game->character->char_obj->rect.top = 3585;
		game->character->clock_max = 1248;
		game->character->move.x = 3;
		game->character->move.y = 0;
	}
}

void spear_walk(game_t *game)
{
	spear_walk_z(game);
	spear_walk_q(game);
	spear_walk_s(game);
	spear_walk_d(game);
}
