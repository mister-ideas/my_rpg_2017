/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/bow_spell_walk.c
*/

#include "my.h"
#include "my_rpg.h"

void bow_spell_walk_z(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 &&
	(game->current_weapon == 0 || game->current_weapon == 1)) {
		game->character->char_obj->rect.top = 4356;
		game->character->clock_max = 1248;
		game->character->move.x = 0;
		game->character->move.y = -3;
	}
}

void bow_spell_walk_q(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 &&
	(game->current_weapon == 0 || game->current_weapon == 1)) {
		game->character->char_obj->rect.top = 4475;
		game->character->clock_max = 1248;
		game->character->move.x = -3;
		game->character->move.y = 0;
	}
}

void bow_spell_walk_s(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 &&
	(game->current_weapon == 0 || game->current_weapon == 1)) {
		game->character->char_obj->rect.top = 4600;
		game->character->clock_max = 1248;
		game->character->move.x = 0;
		game->character->move.y = 3;
	}
}

void bow_spell_walk_d(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 &&
	(game->current_weapon == 0 || game->current_weapon == 1)) {
		game->character->char_obj->rect.top = 4730;
		game->character->clock_max = 1248;
		game->character->move.x = 3;
		game->character->move.y = 0;
	}
}
