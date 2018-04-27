/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** controls.c
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
		game->character->clock_max = 1238;
		game->character->move.x = 0;
		game->character->move.y = -1;
	}
}
