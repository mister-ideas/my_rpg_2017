/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/bow_attack.c
*/

#include "my_rpg.h"

static void bow_attack_up(game_t *game)
{
	if (game->keys->up == sfTrue && game->keys->z == sfFalse &&
	game->keys->q == sfFalse && game->keys->s == sfFalse &&
	game->keys->d == sfFalse) {
		if (game->character->char_obj->rect.left == 1626) {
			add_arrow_up(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 3710;
		game->character->clock_max = 1626;
		game->character->move.x = 0;
		game->character->move.y = 0;
	}
}

static void bow_attack_left(game_t *game)
{
	if (game->keys->left == sfTrue && game->keys->z == sfFalse &&
	game->keys->q == sfFalse && game->keys->s == sfFalse &&
	game->keys->d == sfFalse) {
		if (game->character->char_obj->rect.left == 1626) {
			add_arrow_left(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 3845;
		game->character->clock_max = 1626;
		game->character->move.x = 0;
		game->character->move.y = 0;
	}
}

static void bow_attack_down(game_t *game)
{
	if (game->keys->down == sfTrue && game->keys->z == sfFalse &&
	game->keys->q == sfFalse && game->keys->s == sfFalse &&
	game->keys->d == sfFalse) {
		if (game->character->char_obj->rect.left == 1626) {
			add_arrow_down(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 3970;
		game->character->clock_max = 1626;
		game->character->move.x = 0;
		game->character->move.y = 0;
	}
}

static void bow_attack_right(game_t *game)
{
	if (game->keys->right == sfTrue && game->keys->z == sfFalse &&
	game->keys->q == sfFalse && game->keys->s == sfFalse &&
	game->keys->d == sfFalse) {
		if (game->character->char_obj->rect.left == 1626) {
			add_arrow_right(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 4100;
		game->character->clock_max = 1626;
		game->character->move.x = 0;
		game->character->move.y = 0;
	}
}

void bow_attack(game_t *game)
{
	bow_attack_up(game);
	bow_attack_left(game);
	bow_attack_down(game);
	bow_attack_right(game);
}
