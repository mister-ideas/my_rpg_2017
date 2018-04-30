/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/arena1_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static object_t *arena4_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 5760;
	background->rect.top = 1080;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

scene_t *arena4_scene(game_t *game)
{
	scene_t *arena4 = malloc(sizeof(*arena4));
	object_t *background;

	if (arena4 == NULL)
		return (NULL);
	background = arena4_scene_background();
	background = create_object(background, game->atlas);
	if (background == NULL)
		return (NULL);
	arena4->objects = list_init();
	if (arena4->objects == NULL)
		return (NULL);
	put_end_list(arena4->objects, background);
	arena4->buttons = NULL;
	return (arena4);
}
