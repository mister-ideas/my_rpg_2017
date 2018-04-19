/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/play.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void play_function(void)
{
	my_putstr("play\n");
}

button_t *play_button_active(button_t *play)
{
	play->active.height = 0;
	play->active.left = 0;
	play->active.top = 0;
	play->active.width = 0;
	return (play);
}

button_t *play_button_hover(button_t *play)
{
	play->hover.height = 0;
	play->hover.left = 0;
	play->hover.top = 0;
	play->hover.width = 0;
	return (play);
}

button_t *play_button(void)
{
	button_t *play = malloc(sizeof(*play));

	if (play == NULL)
		return (NULL);
	play->size.x = 235;
	play->size.y = 85;
	play->rect.height = 0;
	play->rect.left = 0;
	play->rect.top = 0;
	play->rect.width = 0;
	play = play_button_hover(play);
	play = play_button_active(play);
	play->callback = &(play_function);
	play->state = OFF;
	return (play);
}
