/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls/spell_attack.c
*/

#include "my.h"
#include "my_rpg.h"

void spell_attack_up(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 0) {
		game->character->char_obj->rect.top = 2200;
		game->character->clock_max = 1248;
		game->character->move.x = 0;
		game->character->move.y = -3;
	}
}

void spell_attack_left(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 0) {
		game->character->char_obj->rect.top = 2325;
		game->character->clock_max = 1248;
		game->character->move.x = -3;
		game->character->move.y = 0;
	}
}

void spell_attack_down(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 0) {
		game->character->char_obj->rect.top = 2445;
		game->character->clock_max = 1248;
		game->character->move.x = 0;
		game->character->move.y = 3;
	}
}

void spell_attack_right(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue &&
	game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 3 && game->current_weapon == 0) {
		game->character->char_obj->rect.top = 2575;
		game->character->clock_max = 1248;
		game->character->move.x = 3;
		game->character->move.y = 0;
	}
}
