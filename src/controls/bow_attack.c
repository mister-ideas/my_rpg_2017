/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/bow_attack.c
*/

#include "my_rpg.h"

static void bow_attack_up(game_t *game)
{
	if (game->keys->up == sfTrue) {
		game->character->char_obj->rect.top = 3710;
		game->character->clock_max = 1626;
		game->character->move.x = 0;
		game->character->move.y = 0;
	}
}

static void bow_attack_left(game_t *game)
{
	if (game->keys->left == sfTrue) {
		game->character->char_obj->rect.top = 3845;
		game->character->clock_max = 1626;
		game->character->move.x = 0;
		game->character->move.y = 0;
	}
}

static void bow_attack_down(game_t *game)
{
	if (game->keys->down == sfTrue) {
		game->character->char_obj->rect.top = 3970;
		game->character->clock_max = 1626;
		game->character->move.x = 0;
		game->character->move.y = 0;
	}
}

static void bow_attack_right(game_t *game)
{
	if (game->keys->right == sfTrue) {
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
