/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/resume.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void resume_function(game_t *game)
{
	game->current_scene = game->last_scene;
}

static button_t *resume_button_active(button_t *resume)
{
	resume->active.height = 85;
	resume->active.left = 0;
	resume->active.top = 3155;
	resume->active.width = 235;
	return (resume);
}

static button_t *resume_button_hover(button_t *resume)
{
	resume->hover.height = 85;
	resume->hover.left = 0;
	resume->hover.top = 3069;
	resume->hover.width = 235;
	return (resume);
}

button_t *resume_button(void)
{
	button_t *resume = malloc(sizeof(*resume));

	if (resume == NULL)
		return (NULL);
	resume->size.x = 235;
	resume->size.y = 85;
	resume->rect.height = 85;
	resume->rect.left = 0;
	resume->rect.top = 2983;
	resume->rect.width = 235;
	resume = resume_button_hover(resume);
	resume = resume_button_active(resume);
	resume->callback = &(resume_function);
	return (resume);
}
