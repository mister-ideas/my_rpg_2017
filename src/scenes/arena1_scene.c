/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/arena1_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static object_t *arena1_scene_background(game_t *game)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 1920;
	background->rect.top = 1080;
	background->rect.width = 1920;
	background->type = BG;
	background = create_object(background, game);
	return (background);
}

scene_t *arena1_scene(game_t *game)
{
	scene_t *arena1 = malloc(sizeof(*arena1));
	object_t *background;

	if (arena1 == NULL)
		return (NULL);
	background = arena1_scene_background(game);
	if (background == NULL)
		return (NULL);
	arena1->objects = list_init();
	if (arena1->objects == NULL)
		return (NULL);
	put_end_list(arena1->objects, background);
	arena1->buttons = NULL;
	arena1->mobs_nb = 2;
	arena1->kills = 0;
	return (arena1);
}
