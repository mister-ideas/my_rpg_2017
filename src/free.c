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
			free((button_t *)search->data);
		}
		free(scene->buttons);
	}
	search = scene->objects->start;
	for (; search != NULL; search = search->next) {
		sfSprite_destroy(((object_t *)search->data)->sprite);
		free((object_t *)search->data);
	}
	free(scene->objects);
}

static void destroy_special_obj(game_t *game)
{
	sfClock_destroy(game->character->char_clock->clock);
	sfSprite_destroy(game->character->char_obj->sprite);
	free(game->character->char_obj);
	free(game->character->char_clock);
	free(game->character);
	for (int i = 0; i < NB_MOBS; i++) {
		sfClock_destroy(game->mobs[i]->mob_clock->clock);
		sfSprite_destroy(game->mobs[i]->mob_obj->sprite);
		free(game->mobs[i]->mob_obj);
		free(game->mobs[i]->mob_clock);
		free(game->mobs[i]);
	}
	free(game->mobs);
	sfSprite_destroy(game->weapons->sprite);
	free(game->weapons);
	sfText_destroy(game->texts->health);
	sfText_destroy(game->texts->attack);
	sfText_destroy(game->texts->defense);
	sfText_destroy(game->texts->speed);
	sfText_destroy(game->texts->level);
}

void quit_game(game_t *game, particules_t *particules)
{
	for (int i = 0; i < NB_SCENES; i++) {
		destroy_scene(game->scenes[i]);
		free(game->scenes[i]);
	}
	free(game->scenes);
	destroy_special_obj(game);
	free(game->keys);
	free(game->texts);
	sfFont_destroy(game->font);
	sfTexture_destroy(game->texture);
	sfImage_destroy(game->atlas);
	sfRenderWindow_destroy(game->window->window);
	free(game->window);
	free(particules);
	free(game);
}
