/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/spell_attack.c
*/

#include "my_rpg.h"

static void spell_attack_up(game_t *game)
{
	if (game->keys->up == sfTrue) {
		game->character->char_obj->rect.top = 2185;
		game->character->clock_max = 996;
	}
}

static void spell_attack_left(game_t *game)
{
	if (game->keys->left == sfTrue) {
		game->character->char_obj->rect.top = 2310;
		game->character->clock_max = 996;
	}
}

static void spell_attack_down(game_t *game)
{
	if (game->keys->down == sfTrue) {
		game->character->char_obj->rect.top = 2430;
		game->character->clock_max = 996;
	}
}

static void spell_attack_right(game_t *game)
{
	if (game->keys->right == sfTrue) {
		game->character->char_obj->rect.top = 2560;
		game->character->clock_max = 996;
	}
}

void spell_attack(game_t *game)
{
	spell_attack_up(game);
	spell_attack_left(game);
	spell_attack_down(game);
	spell_attack_right(game);
}
