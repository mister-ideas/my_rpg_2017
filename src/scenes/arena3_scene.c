/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/arena3_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static object_t *arena3_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 3840;
	background->rect.top = 2160;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

scene_t *arena3_scene(game_t *game)
{
	scene_t *arena3 = malloc(sizeof(*arena3));
	object_t *background;

	if (arena3 == NULL)
		return (NULL);
	background = arena3_scene_background();
	background = create_object(background, game);
	if (background == NULL)
		return (NULL);
	arena3->objects = list_init();
	if (arena3->objects == NULL)
		return (NULL);
	put_end_list(arena3->objects, background);
	arena3->buttons = NULL;
	arena3->mobs_nb = 2;
	arena3->kills = 0;
	return (arena3);
}
