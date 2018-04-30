/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/htp_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static int htp_scene_init_buttons(button_t *play, button_t *back)
{
	if (play == NULL || back == NULL)
		return (84);
	play->pos.x = 1214;
	play->pos.y = 877;
	back->pos.x = 1521;
	back->pos.y = 877;
	return (0);
}

static object_t *htp_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 1920;
	background->rect.top = 0;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

static int htp_scene_lists(scene_t *htp, button_t *play,
		button_t *back)
{
	htp->buttons = list_init();
	htp->objects = list_init();
	if (htp->buttons == NULL || htp->objects == NULL)
		return (84);
	put_end_list(htp->buttons, play);
	put_end_list(htp->buttons, back);
	return (0);
}

scene_t *htp_scene(game_t *game)
{
	scene_t *htp = malloc(sizeof(*htp));
	object_t *background;
	button_t *play = play_button(game);
	button_t *back = return_button(game);

	if (htp == NULL)
		return (NULL);
	if (htp_scene_init_buttons(play, back) == 84)
		return (NULL);
	background = htp_scene_background();
	background = create_object(background, game->atlas);
	play = create_button(play, game->atlas);
	back = create_button(back, game->atlas);
	if (play == NULL || back == NULL || background == NULL)
		return (NULL);
	if (htp_scene_lists(htp, play, back) == 84)
		return (NULL);
	put_end_list(htp->objects, background);
	return (htp);
}
