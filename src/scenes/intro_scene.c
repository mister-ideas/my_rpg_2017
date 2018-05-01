/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/intro_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static object_t *intro_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 0;
	background->rect.top = 1080;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

static object_t *intro_scene_text(void)
{
	object_t *text = malloc(sizeof(*text));

	if (text == NULL)
		return (NULL);
	text->pos.x = 310;
	text->pos.y = 700;
	text->rect.height = 40;
	text->rect.left = 1380;
	text->rect.top = 2625;
	text->rect.width = 1200;
	text->type = TEXT;
	return (text);
}

static object_t *intro_scene_master(void)
{
	object_t *master = malloc(sizeof(*master));

	if (master == NULL)
		return (NULL);
	master->pos.x = 1100;
	master->pos.y = 730;
	master->rect.height = 150;
	master->rect.left = 1175;
	master->rect.top = 2315;
	master->rect.width = 140;
	master->type = MISC;
	return (master);
}

static int intro_scene_lists(scene_t *intro, object_t *background,
			object_t *text, object_t *master)
{
	intro->objects = list_init();
	if (intro->objects == NULL)
		return (84);
	put_end_list(intro->objects, background);
	put_end_list(intro->objects, text);
	put_end_list(intro->objects, master);
	return (0);
}

scene_t *intro_scene(game_t *game)
{
	scene_t *intro = malloc(sizeof(*intro));
	object_t *background;
	object_t *text;
	object_t *master;

	if (intro == NULL)
		return (NULL);
	background = intro_scene_background();
	text = intro_scene_text();
	master = intro_scene_master();
	background = create_object(background, game->atlas);
	text = create_object(text, game->atlas);
	master = create_object(master, game->atlas);
	if (background == NULL || text == NULL || master == NULL)
		return (NULL);
	if (intro_scene_lists(intro, background, text, master) == 84)
		return (NULL);
	intro->buttons = NULL;
	return (intro);
}
