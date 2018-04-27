/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/spear_walk.c
*/

#include "my.h"
#include "my_rpg.h"

void spear_walk_z(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 2) {
		game->character->char_obj->rect.top = 3205;
		game->character->clock_max = 1248;
		game->character->move.x = 0;
		game->character->move.y = -3;
	}
}

void spear_walk_q(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 2) {
		game->character->char_obj->rect.top = 3335;
		game->character->clock_max = 1248;
		game->character->move.x = -3;
		game->character->move.y = 0;
	}
}

void spear_walk_s(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 2) {
		game->character->char_obj->rect.top = 3460;
		game->character->clock_max = 1248;
		game->character->move.x = 0;
		game->character->move.y = 3;
	}
}

void spear_walk_d(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 2) {
		game->character->char_obj->rect.top = 3585;
		game->character->clock_max = 1248;
		game->character->move.x = 3;
		game->character->move.y = 0;
	}
}
