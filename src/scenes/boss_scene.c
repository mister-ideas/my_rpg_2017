/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/boss_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

object_t *boss_scene_background(void)
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
	return (background);
}

scene_t *boss_scene(game_t *game)
{
	scene_t *boss = malloc(sizeof(*boss));
	object_t *background;

	if (boss == NULL)
		return (NULL);
	background = boss_scene_background();
	background = create_object(background, game->atlas);
	if (background == NULL)
		return (NULL);
	boss->objects = list_init();
	if (boss->objects == NULL)
		return (NULL);
	put_end_list(boss->objects, background);
	boss->buttons = NULL;
	return (boss);
}
