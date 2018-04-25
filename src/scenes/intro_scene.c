/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/intro_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

object_t *intro_scene_background(void)
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

scene_t *intro_scene(game_t *game)
{
	scene_t *intro = malloc(sizeof(*intro));
	object_t *background;
	object_t *character;

	if (intro == NULL)
		return (NULL);
	background = intro_scene_background();
	character = character_object();
	background = create_object(background, game->atlas);
	character = create_object(character, game->atlas);
	if (background == NULL || character == NULL)
		return (NULL);
	game->char_rect = character->rect;
	intro->objects = list_init();
	if (intro->objects == NULL)
		return (NULL);
	put_end_list(intro->objects, background);
	put_end_list(intro->objects, character);
	intro->buttons = NULL;
	return (intro);
}
