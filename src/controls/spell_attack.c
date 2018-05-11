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
		if (game->character->char_obj->rect.left == 996) {
			add_spell_up(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 2185;
		game->character->clock_max = 996;
	}
}

static void spell_attack_left(game_t *game)
{
	if (game->keys->left == sfTrue) {
		if (game->character->char_obj->rect.left == 996) {
			add_spell_left(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 2310;
		game->character->clock_max = 996;
	}
}

static void spell_attack_down(game_t *game)
{
	if (game->keys->down == sfTrue) {
		if (game->character->char_obj->rect.left == 996) {
			add_spell_down(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 2430;
		game->character->clock_max = 996;
	}
}

static void spell_attack_right(game_t *game)
{
	if (game->keys->right == sfTrue) {
		if (game->character->char_obj->rect.left == 996) {
			add_spell_right(game, game->
			scenes[game->current_scene]->objects);
			game->character->char_obj->rect.left = 240;
		}
		game->character->char_obj->rect.top = 2560;
		game->character->clock_max = 996;
	}
}

void spell_attack(game_t *game)
{
	if (game->current_scene != 3) {
		spell_attack_up(game);
		spell_attack_left(game);
		spell_attack_down(game);
		spell_attack_right(game);
	}
}
