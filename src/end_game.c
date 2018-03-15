/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** end_game.c
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"

void destroy_scene(scene_t *scene)
{
	struct node *search = scene->buttons->start;

	for (; search != NULL; search = search->next) {
		sfRectangleShape_destroy(((button_t *)search->data)->shape);
		sfTexture_destroy(((button_t *)search->data)->texture);
		free((button_t *)search->data);
	}
	free(scene->buttons);
	search = scene->objects->start;

}

void quit_game(game_t *game)
{
	for (int i = 0; i < SCENES_NB; i++)
		destroy_scene(game->scenes[i]);
	free(game->scenes);
	sfRenderWindow_destroy(game->window->window);
	free(game->window);
	sfImage_destroy(game->atlas);
	free(game);
}
