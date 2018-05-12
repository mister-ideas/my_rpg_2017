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

static object_t *arena3_scene_powerup(void)
{
	object_t *powerup = malloc(sizeof(*powerup));

	if (powerup == NULL)
		return (NULL);
	powerup->pos.x = 935;
	powerup->pos.y = 610;
	powerup->rect.height = 45;
	powerup->rect.left = 1978;
	powerup->rect.top = 2370;
	powerup->rect.width = 45;
	powerup->type = POWERUP;
	return (powerup);
}

scene_t *arena3_scene(game_t *game)
{
	scene_t *arena3 = malloc(sizeof(*arena3));
	object_t *background;
	object_t *powerup;

	if (arena3 == NULL)
		return (NULL);
	background = arena3_scene_background();
	powerup = arena3_scene_powerup();
	background = create_object(background, game);
	powerup = create_object(powerup, game);
	if (background == NULL || powerup == NULL)
		return (NULL);
	arena3->objects = list_init();
	if (arena3->objects == NULL)
		return (NULL);
	put_end_list(arena3->objects, background);
	put_end_list(arena3->objects, powerup);
	arena3->buttons = NULL;
	arena3->mobs_nb = 2;
	arena3->kills = 0;
	return (arena3);
}
