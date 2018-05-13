/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/mob.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static mob_t *init_mob(mob_t *mob)
{
	object_t *mob_obj = malloc(sizeof(*mob_obj));
	my_clock_t *mob_clock = malloc(sizeof(*mob_clock));

	mob = malloc(sizeof(*mob));
	if (mob == NULL || mob_obj == NULL || mob_clock == NULL)
		return (NULL);
	mob->mob_obj = mob_obj;
	mob->mob_clock = mob_clock;
	mob->mob_obj->pos.x = 0;
	mob->mob_obj->pos.y = 0;
	mob->mob_obj->rect.height = 65;
	mob->mob_obj->rect.left = 2082;
	mob->mob_obj->rect.top = 2202;
	mob->mob_obj->rect.width = 65;
	mob->move.x = rand() % 3;
	mob->move.y = rand() % 3;
	mob->health = 4;
	mob->mob_clock->clock = sfClock_create();
	if (mob->mob_clock->clock == NULL)
		return (NULL);
	return (mob);
}

static mob_t *init_boss(mob_t *boss)
{
	object_t *boss_obj = malloc(sizeof(*boss_obj));

	boss = malloc(sizeof(*boss));
	if (boss == NULL || boss_obj == NULL)
		return (NULL);
	boss->mob_obj = boss_obj;
	boss->mob_clock = NULL;
	boss->mob_obj->pos.x = 0;
	boss->mob_obj->pos.y = 0;
	boss->mob_obj->rect.height = 130;
	boss->mob_obj->rect.left = 1395;
	boss->mob_obj->rect.top = 2860;
	boss->mob_obj->rect.width = 270;
	boss->move.x = rand() % 3;
	boss->move.y = 0;
	boss->health = 256;
	return (boss);
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

static int init_mobs(game_t *game)
{
	game->mobs[0] = init_mob(game->mobs[0]);
	game->mobs[1] = init_mob(game->mobs[1]);
	game->mobs[2] = init_mob(game->mobs[2]);
	game->mobs[3] = init_mob(game->mobs[3]);
	game->mobs[4] = init_boss(game->mobs[4]);
	for (int i = 0; i < NB_MOBS; i++) {
		if (game->mobs[i] == NULL)
			return (84);
	}
	game->mobs[0]->mob_obj = create_object(game->mobs[0]->mob_obj, game);
	game->mobs[1]->mob_obj = create_object(game->mobs[1]->mob_obj, game);
	game->mobs[2]->mob_obj = create_object(game->mobs[2]->mob_obj, game);
	game->mobs[3]->mob_obj = create_object(game->mobs[3]->mob_obj, game);
	game->mobs[4]->mob_obj = create_object(game->mobs[4]->mob_obj, game);
	return (0);
}

int set_mobs(game_t *game)
{
	game->mobs = malloc(sizeof(mob_t) * NB_MOBS);
	if (game->mobs == NULL || init_mobs(game) == 84)
	    return (84);
	for (int i = 0; i < NB_MOBS; i++) {
		game->mobs[i]->mob_obj->type = MISC;
		if (game->mobs[i] == NULL)
			return (84);
	}
	game->mobs[4]->mob_obj->type = BOSS;
	return (0);
}
