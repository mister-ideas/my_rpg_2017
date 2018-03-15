/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

const sfIntRect atlas_rect = {0, 0, 3840, 4547};

game_t *init_game(scene_t **scenes, window_t *window)
{
	game_t *game = malloc(sizeof(*game));

	if (game == NULL)
		return (NULL);
	game->font = sfFont_createFromFile(FONT_PATH);
	if (game->font == NULL)
		return (NULL);
	game->window = window;
	game->scenes = scenes;
	game->current_scene = 0;
	game->atlas = sfImage_createFromFile(ATLAS_PATH);
	if (game->atlas == NULL)
		return (NULL);
	return (game);
}

int main(void)
{
	sfVideoMode video = {1920, 1080, 32};
	game_t *game;
	window_t *window;
	struct scene_s **scenes = set_scenes();

	if (scenes == NULL)
		return (84);
	window = create_window(video);
	if (window == NULL)
		return (84);
	game = init_game(scenes, window);
	if (game == NULL)
		return (84);
	if (display_window(game) == 84)
		return (84);
	return (0);
}
