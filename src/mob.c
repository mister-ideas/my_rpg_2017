/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** mobs.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static void init_mobs(game_t *game)
{
	game->mobs[0] = init_mob(game->mobs[0]);
	game->mobs[0]->mob_obj = create_object(game->mobs[0]->mob_obj, game);
	game->mobs[1] = init_mob(game->mobs[1]);
	game->mobs[1]->mob_obj = create_object(game->mobs[1]->mob_obj, game);
	game->mobs[2] = init_mob(game->mobs[2]);
	game->mobs[2]->mob_obj = create_object(game->mobs[2]->mob_obj, game);
	game->mobs[3] = init_mob(game->mobs[3]);
	game->mobs[3]->mob_obj = create_object(game->mobs[3]->mob_obj, game);
}

int set_mobs(game_t *game)
{
	game->mobs = malloc(sizeof(mob_t *) * NB_MOBS);
	if (game->mobs == NULL)
		return (84);
	init_mobs(game);
	for (int i = 0; i < NB_MOBS; i++) {
		if (game->mobs[i] == NULL)
			return (84);
	}
	return (0);
}
