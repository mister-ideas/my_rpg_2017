/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/stats_inv_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static object_t *stats_inv_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 5760;
	background->rect.top = 2160;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

static object_t *stats_inv_scene_slot(void)
{
	object_t *slot = malloc(sizeof(*slot));

	if (slot == NULL)
		return (NULL);
	slot->pos.x = 916;
	slot->pos.y = 818;
	slot->rect.height = 90;
	slot->rect.left = 1797;
	slot->rect.top = 2253;
	slot->rect.width = 90;
	slot->type = SLOT;
	return (slot);
}

scene_t *stats_inv_scene(game_t *game)
{
	scene_t *stats_inv = malloc(sizeof(*stats_inv));
	object_t *background;
	object_t *slot;

	if (stats_inv == NULL)
		return (NULL);
	background = stats_inv_scene_background();
	slot = stats_inv_scene_slot();
	background = create_object(background, game);
	slot = create_object(slot, game);
	if (background == NULL || slot == NULL)
		return (NULL);
	stats_inv->objects = list_init();
	if (stats_inv->objects == NULL)
		return (NULL);
	put_end_list(stats_inv->objects, background);
	put_end_list(stats_inv->objects, slot);
	stats_inv->buttons = NULL;
	stats_inv->mobs_nb = 0;
	stats_inv->kills = 0;
	return (stats_inv);
}
