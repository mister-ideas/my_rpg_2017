/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/win_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static int win_scene_init_buttons(button_t *quit, game_t *game)
{
	quit->pos.x = 842;
	quit->pos.y = 495;
	quit = create_button(quit, game);
	if (quit == NULL)
		return (84);
	return (0);
}

static object_t *win_scene_background(game_t *game)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 3840;
	background->rect.top = 3240;
	background->rect.width = 1920;
	background->type = BG;
	background = create_object(background, game);
	return (background);
}

static int win_scene_lists(scene_t *win, button_t *quit, object_t *background)
{
	win->buttons = list_init();
	win->objects = list_init();
	if (win->buttons == NULL || win->objects == NULL)
		return (84);
	put_end_list(win->buttons, quit);
	put_end_list(win->objects, background);
	return (0);
}

scene_t *win_scene(game_t *game)
{
	scene_t *win = malloc(sizeof(*win));
	object_t *background;
	button_t *quit = quit_button();

	if (win == NULL || quit == NULL ||
	win_scene_init_buttons(quit, game) == 84)
		return (NULL);
	background = win_scene_background(game);
	if (background == NULL)
		return (NULL);
	if (win_scene_lists(win, quit, background) == 84)
		return (NULL);
	win->mobs_nb = 0;
	win->kills = 0;
	return (win);
}
