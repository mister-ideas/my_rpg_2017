/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/character.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

object_t *character_init(void)
{
	object_t *character = malloc(sizeof(*character));

	if (character == NULL)
		return (NULL);
	character->pos.x = 0;
	character->pos.y = 0;
	character->rect.height = 120;
	character->rect.left = 233;
	character->rect.top = 3575;
	character->rect.width = 130;
	character->type = CHAR;
	return (character);
}

my_clock_t *character_clock_init(void)
{
	my_clock_t *char_clock = malloc(sizeof(*char_clock));

	if (char_clock == NULL)
		return (NULL);
	char_clock->clock = sfClock_create();
	if (char_clock->clock == NULL)
		return (NULL);
	return (char_clock);
}

void character_clock(object_t *character, my_clock_t *char_clock)
{
	char_clock->time = sfClock_getElapsedTime(char_clock->clock);
	char_clock->seconds = char_clock->time.microseconds / 1000000.0;
	if (char_clock->seconds > 0.1) {
		if (character->rect.left != 883)
			character->rect.left += 130;
		else
			character->rect.left = 233;
		sfSprite_setTextureRect(character->sprite,
					character->rect);
		sfClock_restart(char_clock->clock);
	}
}
