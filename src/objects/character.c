/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/character.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int character_init(game_t *game)
{
	game->character->char_obj->pos.x = 820;
	game->character->char_obj->pos.y = 650;
	game->character->char_obj->rect.height = 130;
	game->character->char_obj->rect.left = 230;
	game->character->char_obj->rect.top = 4600;
	game->character->char_obj->rect.width = 126;
	game->character->move.x = 0;
	game->character->move.y = 0;
	game->character->clock_max = 230;
	game->character->char_obj->type = CHAR;
	game->character->char_clock->clock = sfClock_create();
	if (game->character->char_clock->clock == NULL)
		return (84);
	return (0);
}

void character_clock(game_t *game, character_t *character)
{
	character->char_clock->time =
		sfClock_getElapsedTime(character->char_clock->clock);
	character->char_clock->seconds =
		character->char_clock->time.microseconds / 1000000.0;
	if (character->char_clock->seconds > 0.1) {
		if (character->char_obj->rect.left != character->clock_max)
			character->char_obj->rect.left += 126;
		else
			character->char_obj->rect.left = 230;
		sfSprite_setTextureRect(character->char_obj->sprite,
					character->char_obj->rect);
		sfClock_restart(character->char_clock->clock);
	}
}
