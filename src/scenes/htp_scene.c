/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/htp_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static int htp_scene_init_buttons(button_t *play, button_t *back, game_t *game)
{
	play->pos.x = 1214;
	play->pos.y = 877;
	play = create_button(play, game);
	back->pos.x = 1521;
	back->pos.y = 877;
	back = create_button(back, game);
	if (play == NULL || back == NULL)
		return (84);
	return (0);
}

static object_t *htp_scene_background(game_t *game)
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
	background = create_object(background, game);
	return (background);
}

static int htp_scene_lists(scene_t *htp, button_t *play,
		button_t *back, object_t *background)
{
	htp->buttons = list_init();
	htp->objects = list_init();
	if (htp->buttons == NULL || htp->objects == NULL)
		return (84);
	put_end_list(htp->buttons, play);
	put_end_list(htp->buttons, back);
	put_end_list(htp->objects, background);
	return (0);
}

scene_t *htp_scene(game_t *game)
{
	scene_t *htp = malloc(sizeof(*htp));
	object_t *background;
	button_t *play = play_button();
	button_t *back = return_button();

	if (htp == NULL || play == NULL || back == NULL ||
	htp_scene_init_buttons(play, back, game) == 84)
		return (NULL);
	background = htp_scene_background(game);
	if (background == NULL)
		return (NULL);
	if (htp_scene_lists(htp, play, back, background) == 84)
		return (NULL);
	htp->mobs_nb = 0;
	htp->kills = 0;
	return (htp);
}
