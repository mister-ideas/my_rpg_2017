/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scene.c
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
	game->scenes[0] = menu_scene(game);
	game->scenes[1] = htp_scene(game);
	game->scenes[2] = pause_scene(game);
	game->scenes[3] = intro_scene(game);
	game->scenes[4] = arena1_scene(game);
	game->scenes[5] = arena2_scene(game);
	game->scenes[6] = arena4_scene(game);
	game->scenes[7] = arena3_scene(game);
	game->scenes[8] = boss_scene(game);
	for (int i = 0; i < NB_SCENES; i++) {
		if (game->scenes[i] == NULL)
			return (84);
	}
	return (0);
}
