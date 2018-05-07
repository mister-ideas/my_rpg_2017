/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

const sfIntRect atlas_rect = {0, 0, 7680, 4885};

static void init_keys(game_t *game)
{
	game->keys->z = sfFalse;
	game->keys->q = sfFalse;
	game->keys->s = sfFalse;
	game->keys->d = sfFalse;
	game->keys->up = sfFalse;
	game->keys->left = sfFalse;
	game->keys->down = sfFalse;
	game->keys->right = sfFalse;
	game->keys->esc = sfFalse;
	game->keys->space = sfFalse;
	game->keys->shift = sfFalse;
	game->keys->alt = sfFalse;
}

static int init_objects(game_t *game)
{
	object_t *char_obj = malloc(sizeof(*char_obj));
	object_t *weapons = malloc(sizeof(*weapons));
	my_clock_t *char_clock = malloc(sizeof(*char_clock));

	game->character = malloc(sizeof(*game->character));
	if (game->character == NULL || char_obj == NULL ||
	weapons == NULL || char_clock == NULL)
		return (84);
	game->character->char_obj = char_obj;
	game->character->char_clock = char_clock;
	game->weapons = weapons;
	if (init_character(game) == 84)
		return (84);
	init_weapons(game);
	return (0);
}

static int init_game(game_t *game, particules_t *particules)
{
	sfVideoMode video = {1920, 1080, 32};

	game->keys = malloc(sizeof(*game->keys));
	if (game->keys == NULL)
		return (84);
	init_keys(game);
	particules_init(particules, 1);
	init_window(game, video);
	set_scenes(game);
	game->current_scene = 0;
	game->current_weapon = 0;
	game->current_text = 1;
	if (init_objects(game) == 84)
		return (84);
	game->character->char_obj =
		create_object(game->character->char_obj, game->atlas);
	game->weapons =
		create_object(game->weapons, game->atlas);
	if (game->character->char_obj == NULL || game->weapons == NULL)
		return (84);
	return (0);
}

int main(void)
{
	extern char **environ;
	game_t *game = malloc(sizeof(*game));
	particules_t *particules = malloc(sizeof(*particules));

	if (environ[0] == NULL)
		return (84);
	if (game == NULL || particules == NULL)
		return (84);
	if (init_game(game, particules) == 84)
		return (84);
	if (display_window(game, particules) == 84)
		return (84);
	return (0);
}
