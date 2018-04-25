/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

const sfIntRect atlas_rect = {0, 0, 3840, 4547};

int init_game(game_t *game)
{
	sfVideoMode video = {1920, 1080, 32};

	init_window(game, video);
	set_scenes(game);
	game->font = sfFont_createFromFile(FONT_PATH);
	if (game->font == NULL)
		return (84);
	game->current_scene = 0;
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
