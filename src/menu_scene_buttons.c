/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** menu_scene_buttons_1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

button_t *menu_scene_play(void)
{
	button_t *play = malloc(sizeof(*play));

	if (play == NULL)
		return (NULL);
	play->pos.x = 415;
	play->pos.y = 679;
	play->size.x = 326;
	play->size.y = 74;
	play->rect.height = 74;
	play->rect.left = 3155;
	play->rect.top = 2291;
	play->rect.width = 326;
	play->push_rect.height = 74;
	play->push_rect.left = 3155;
	play->push_rect.top = 2365;
	play->push_rect.width = 326;
	play->callback = &(play_button);
	play->state = OFF;
	return (play);
}

button_t *menu_scene_quit(void)
{
	button_t *quit = malloc(sizeof(*quit));

	if (quit == NULL)
		return (NULL);
	quit->pos.x = 1181;
	quit->pos.y = 679;
	quit->size.x = 326;
	quit->size.y = 74;
	quit->rect.height = 74;
	quit->rect.left = 3155;
	quit->rect.top = 2735;
	quit->rect.width = 326;
	quit->push_rect.height = 74;
	quit->push_rect.left = 3155;
	quit->push_rect.top = 2809;
	quit->push_rect.width = 326;
	quit->callback = &(quit_button);
	quit->state = OFF;
	return (quit);
}
