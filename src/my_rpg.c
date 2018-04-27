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

int init_game(game_t *game)
{
	character_t *character = malloc(sizeof(*character));
	object_t *char_obj = malloc(sizeof(*char_obj));
	my_clock_t *char_clock = malloc(sizeof(*char_clock));
	sfVideoMode video = {1920, 1080, 32};

	if (character == NULL || char_obj == NULL || char_clock == NULL)
		return (84);
	game->character = character;
	game->character->char_obj = char_obj;
	game->character->char_clock = char_clock;
	init_window(game, video);
	set_scenes(game);
	game->current_scene = 0;
	game->current_weapon = 0;
	if (character_init(game) == 84)
		return (84);
	game->character->char_obj =
		create_object(game->character->char_obj, game->atlas);
	return (0);
}

int main(void)
{
	extern char **environ;
	game_t *game = malloc(sizeof(*game));

	if (environ[0] == NULL)
		return (84);
	if (game == NULL)
		return (84);
	if (init_game(game) == 84)
		return (84);
	if (display_window(game) == 84)
		return (84);
	return (0);
}
