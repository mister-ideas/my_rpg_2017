/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/spear_attack.c
*/

#include "my_rpg.h"

static void spear_attack_up(game_t *game)
{
	if (game->keys->up == sfTrue) {
		game->character->char_obj->rect.top = 2675;
		game->character->clock_max = 1122;
	}
}

static void spear_attack_left(game_t *game)
{
	if (game->keys->left == sfTrue) {
		game->character->char_obj->rect.top = 2810;
		game->character->clock_max = 1122;
	}
}

static void spear_attack_down(game_t *game)
{
	if (game->keys->down == sfTrue) {
		game->character->char_obj->rect.top = 2945;
		game->character->clock_max = 1122;
	}
}

static void spear_attack_right(game_t *game)
{
	if (game->keys->right == sfTrue) {
		game->character->char_obj->rect.top = 3075;
		game->character->clock_max = 1122;
	}
}

void spear_attack(game_t *game)
{
	spear_attack_up(game);
	spear_attack_left(game);
	spear_attack_down(game);
	spear_attack_right(game);
}
