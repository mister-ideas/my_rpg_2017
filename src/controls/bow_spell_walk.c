/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/bow_spell_walk.c
*/

#include "my.h"
#include "my_rpg.h"

static void bow_spell_walk_z(game_t *game)
{
	if (game->keys->z == sfTrue) {
		game->character->char_obj->rect.top = 4356;
		game->character->clock_max = 1248;
		if (game->keys->q == sfFalse && game->keys->d == sfFalse) {
			game->character->move.x = 0;
			game->character->move.y = game->character->speed * -1;
		}
		if (game->keys->q == sfTrue && game->keys->d == sfFalse) {
			game->character->move.x = game->character->speed * -1;
			game->character->move.y = game->character->speed * -1;
		}
		if (game->keys->d == sfTrue && game->keys->q == sfFalse) {
			game->character->move.x = game->character->speed;
			game->character->move.y = game->character->speed * -1;
		}
	}
}

static void bow_spell_walk_q(game_t *game)
{
	if (game->keys->q == sfTrue && game->keys->z == sfFalse &&
	game->keys->s == sfFalse) {
		game->character->char_obj->rect.top = 4475;
		game->character->clock_max = 1248;
		game->character->move.x = game->character->speed * -1;
		game->character->move.y = 0;
	}
}

static void bow_spell_walk_s(game_t *game)
{
	if (game->keys->s == sfTrue) {
		game->character->char_obj->rect.top = 4600;
		game->character->clock_max = 1248;
		if (game->keys->q == sfFalse && game->keys->d == sfFalse) {
			game->character->move.x = 0;
			game->character->move.y = game->character->speed;
		}
		if (game->keys->q == sfTrue && game->keys->d == sfFalse) {
			game->character->move.x = game->character->speed * -1;
			game->character->move.y = game->character->speed;
		}
		if (game->keys->d == sfTrue && game->keys->q == sfFalse) {
			game->character->move.x = game->character->speed;
			game->character->move.y = game->character->speed;
		}
	}
}

static void bow_spell_walk_d(game_t *game)
{
	if (game->keys->d == sfTrue && game->keys->z == sfFalse &&
	game->keys->s == sfFalse) {
		game->character->char_obj->rect.top = 4730;
		game->character->clock_max = 1248;
		game->character->move.x = game->character->speed;
		game->character->move.y = 0;
	}
}

void bow_spell_walk(game_t *game)
{
	if (game->current_scene != 3) {
		bow_spell_walk_z(game);
		bow_spell_walk_s(game);
	}
	bow_spell_walk_q(game);
	bow_spell_walk_d(game);
}
