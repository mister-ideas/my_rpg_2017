/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free.c
*/

#include <stdlib.h>
#include "my_rpg.h"

void check_end(game_t *game, particules_t *particules)
{
	if (game->scenes[11]->kills == 5 && game->current_scene == 11) {
		init_particules(particules, 2);
		game->current_scene = 5;
		sfMusic_stop(game->musics[0]);
		sfMusic_play(game->musics[1]);
		sfMusic_setLoop(game->musics[1], sfTrue);
	} else if (game->character->health <= 0 && game->current_scene != 6) {
		init_particules(particules, 1);
		game->current_scene = 6;
		sfMusic_stop(game->musics[0]);
		sfMusic_play(game->musics[1]);
		sfMusic_setLoop(game->musics[1], sfTrue);
	}
}

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
		if (game->mobs[i]->mob_clock) {
			sfClock_destroy(game->mobs[i]->mob_clock->clock);
			free(game->mobs[i]->mob_clock);
		}
		sfSprite_destroy(game->mobs[i]->mob_obj->sprite);
		free(game->mobs[i]->mob_obj);
		free(game->mobs[i]);
	}
	sfText_destroy(game->texts->health);
	sfText_destroy(game->texts->attack);
	sfText_destroy(game->texts->defense);
	sfText_destroy(game->texts->speed);
	sfText_destroy(game->texts->level);
	sfSprite_destroy(game->weapons->sprite);
}

static void destroy_sounds(game_t *game)
{
	sfSoundBuffer_destroy(game->buffer);
	for (int i = 0; i < NB_SOUNDS; i++)
		sfSound_destroy(game->sounds[i]);
	for (int i = 0; i < NB_MUSICS; i++)
		sfMusic_destroy(game->musics[i]);
}

void quit_game(game_t *game, particules_t *particules)
{
	for (int i = 0; i < NB_SCENES; i++) {
		destroy_scene(game->scenes[i]);
		free(game->scenes[i]);
	}
	free(game->scenes);
	destroy_special_obj(game);
	free(game->weapons);
	free(game->mobs);
	free(game->texts);
	free(game->keys);
	destroy_sounds(game);
	sfFont_destroy(game->font);
	sfTexture_destroy(game->texture);
	sfImage_destroy(game->atlas);
	sfRenderWindow_destroy(game->window->window);
	free(game->window);
	if (game->current_scene == 5 || game->current_scene == 6)
		free(particules->buffer);
	free(particules);
	free(game);
}
