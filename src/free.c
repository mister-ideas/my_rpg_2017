/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free.c
*/

#include <stdlib.h>
#include "my_rpg.h"

static void destroy_scene(scene_t *scene)
{
	struct node *search;

	if (scene->buttons) {
		search = scene->buttons->start;
		for (; search != NULL; search = search->next) {
			sfRectangleShape_destroy(
			((button_t *)search->data)->shape);
			sfTexture_destroy(((button_t *)search->data)->texture);
			free((button_t *)search->data);
		}
		free(scene->buttons);
	}
	search = scene->objects->start;
	for (; search != NULL; search = search->next) {
		sfSprite_destroy(((object_t *)search->data)->sprite);
		sfTexture_destroy(((object_t *)search->data)->texture);
		free((object_t *)search->data);
	}
	free(scene->objects);
}

void quit_game(game_t *game)
{
	for (int i = 0; i < NB_SCENES; i++)
		destroy_scene(game->scenes[i]);
	free(game->scenes);
	sfClock_destroy(game->character->char_clock->clock);
	sfSprite_destroy(game->character->char_obj->sprite);
	sfSprite_destroy(game->weapons->sprite);
	sfTexture_destroy(game->character->char_obj->texture);
	sfTexture_destroy(game->weapons->texture);
	free(game->character);
	free(game->weapons);
	sfRenderWindow_destroy(game->window->window);
	free(game->window);
	free(game->keys);
	sfImage_destroy(game->atlas);
	free(game);
}
