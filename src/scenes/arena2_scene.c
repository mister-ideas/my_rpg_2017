/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/arena2_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static object_t *arena2_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 3840;
	background->rect.top = 1080;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

scene_t *arena2_scene(game_t *game)
{
	scene_t *arena2 = malloc(sizeof(*arena2));
	object_t *background;

	if (arena2 == NULL)
		return (NULL);
	background = arena2_scene_background();
	background = create_object(background, game);
	if (background == NULL)
		return (NULL);
	arena2->objects = list_init();
	if (arena2->objects == NULL)
		return (NULL);
	put_end_list(arena2->objects, background);
	arena2->buttons = NULL;
	arena2->mobs_nb = 4;
	arena2->kills = 0;
	return (arena2);
}
