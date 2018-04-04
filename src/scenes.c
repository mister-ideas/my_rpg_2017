/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int set_scenes(game_t *game)
{
	game->scenes = malloc(sizeof(scene_t*) * NB_SCENES);
	game->atlas = sfImage_create(3840, 3467);
	game->atlas = sfImage_createFromFile(ATLAS_PATH);
	if (game->scenes == NULL || game->atlas == NULL)
		return (84);
	/* init scenes here */
	/* check scenes NULL here */
	return (0);
}
