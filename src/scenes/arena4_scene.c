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

static object_t *arena4_scene_potion(void)
{
	object_t *potion = malloc(sizeof(*potion));

	if (potion == NULL)
		return (NULL);
	potion->pos.x = 935;
	potion->pos.y = 610;
	potion->rect.height = 50;
	potion->rect.left = 1973;
	potion->rect.top = 2281;
	potion->rect.width = 50;
	potion->type = POTION;
	return (potion);
}

scene_t *arena4_scene(game_t *game)
{
	scene_t *arena4 = malloc(sizeof(*arena4));
	object_t *background;
	object_t *potion;

	if (arena4 == NULL)
		return (NULL);
	background = arena4_scene_background();
	potion = arena4_scene_potion();
	background = create_object(background, game);
	potion = create_object(potion, game);
	if (background == NULL || potion == NULL)
		return (NULL);
	arena4->objects = list_init();
	if (arena4->objects == NULL)
		return (NULL);
	put_end_list(arena4->objects, background);
	put_end_list(arena4->objects, potion);
	arena4->buttons = NULL;
	arena4->mobs_nb = 4;
	arena4->kills = 0;
	return (arena4);
}
