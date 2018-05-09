/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/mob.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

mob_t *init_mob(mob_t *mob)
{
	object_t *mob_obj = malloc(sizeof(*mob_obj));
	my_clock_t *mob_clock = malloc(sizeof(*mob_clock));

	mob = malloc(sizeof(*mob));
	if (mob == NULL || mob_obj == NULL || mob_clock == NULL)
		return (NULL);
	mob->mob_obj = mob_obj;
	mob->mob_clock = mob_clock;
	mob->mob_obj->pos.x = 890;
	mob->mob_obj->pos.y = 460;
	mob->mob_obj->rect.height = 65;
	mob->mob_obj->rect.left = 2082;
	mob->mob_obj->rect.top = 2202;
	mob->mob_obj->rect.width = 65;
	mob->move.x = 0;
	mob->move.y = 0;
	mob->health = 4;
	mob->mob_clock->clock = sfClock_create();
	if (mob->mob_clock->clock == NULL)
		return (NULL);
	return (mob);
}

void mob_clock(mob_t *mob)
{
	mob->mob_clock->time =
		sfClock_getElapsedTime(mob->mob_clock->clock);
	mob->mob_clock->seconds =
		mob->mob_clock->time.microseconds / 1000000.0;
	if (mob->mob_clock->seconds > 0.1) {
		if (mob->mob_obj->rect.top < 2527)
			mob->mob_obj->rect.top += 65;
		else
			mob->mob_obj->rect.top = 2202;
		sfSprite_setTextureRect(mob->mob_obj->sprite,
					mob->mob_obj->rect);
		sfClock_restart(mob->mob_clock->clock);
	}
}
