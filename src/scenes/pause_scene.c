/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/pause_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static int pause_scene_init_buttons(button_t *resume, button_t *quit)
{
	if (resume == NULL || quit == NULL)
		return (84);
	resume->pos.x = 589;
	resume->pos.y = 451;
	quit->pos.x = 1100;
	quit->pos.y = 451;
	return (0);
}

static object_t *pause_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 3840;
	background->rect.top = 0;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

static int pause_scene_lists(scene_t *pause, button_t *resume,
		button_t *quit)
{
	pause->buttons = list_init();
	pause->objects = list_init();
	if (pause->buttons == NULL || pause->objects == NULL)
		return (84);
	put_end_list(pause->buttons, resume);
	put_end_list(pause->buttons, quit);
	return (0);
}

scene_t *pause_scene(game_t *game)
{
	scene_t *pause = malloc(sizeof(*pause));
	object_t *background;
	button_t *resume = resume_button();
	button_t *quit = quit_button();

	if (pause == NULL)
		return (NULL);
	if (pause_scene_init_buttons(resume, quit) == 84)
		return (NULL);
	background = pause_scene_background();
	background = create_object(background, game->atlas);
	resume = create_button(resume, game->atlas);
	quit = create_button(quit, game->atlas);
	if (resume == NULL || quit == NULL || background == NULL)
		return (NULL);
	if (pause_scene_lists(pause, resume, quit) == 84)
		return (NULL);
	put_end_list(pause->objects, background);
	return (pause);
}
