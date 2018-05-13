/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/lose_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static int lose_scene_init_buttons(button_t *quit, game_t *game)
{
	quit->pos.x = 842;
	quit->pos.y = 495;
	quit = create_button(quit, game);
	if (quit == NULL)
		return (84);
	return (0);
}

static object_t *lose_scene_background(game_t *game)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 5760;
	background->rect.top = 3240;
	background->rect.width = 1920;
	background->type = BG;
	background = create_object(background, game);
	return (background);
}

static int lose_scene_lists(scene_t *lose, button_t *quit, object_t *background)
{
	lose->buttons = list_init();
	lose->objects = list_init();
	if (lose->buttons == NULL || lose->objects == NULL)
		return (84);
	put_end_list(lose->buttons, quit);
	put_end_list(lose->objects, background);
	return (0);
}

scene_t *lose_scene(game_t *game)
{
	scene_t *lose = malloc(sizeof(*lose));
	object_t *background;
	button_t *quit = quit_button();

	if (lose == NULL || quit == NULL ||
	lose_scene_init_buttons(quit, game) == 84)
		return (NULL);
	background = lose_scene_background(game);
	if (background == NULL)
		return (NULL);
	if (lose_scene_lists(lose, quit, background) == 84)
		return (NULL);
	lose->mobs_nb = 0;
	lose->kills = 0;
	return (lose);
}
