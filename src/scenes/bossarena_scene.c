/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/bossarena_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static object_t *bossarena_scene_background(game_t *game)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 5760;
	background->rect.top = 0;
	background->rect.width = 1920;
	background->type = BG;
	background = create_object(background, game);
	return (background);
}

scene_t *bossarena_scene(game_t *game)
{
	scene_t *bossarena = malloc(sizeof(*bossarena));
	object_t *background;

	if (bossarena == NULL)
		return (NULL);
	background = bossarena_scene_background(game);
	if (background == NULL)
		return (NULL);
	bossarena->objects = list_init();
	if (bossarena->objects == NULL)
		return (NULL);
	put_end_list(bossarena->objects, background);
	bossarena->buttons = NULL;
	bossarena->mobs_nb = 5;
	bossarena->kills = 0;
	return (bossarena);
}
