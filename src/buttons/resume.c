/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/resume.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void resume_function(void)
{
	my_putstr("resume\n");
}

button_t *resume_button_active(button_t *resume)
{
	resume->active.height = 0;
	resume->active.left = 0;
	resume->active.top = 0;
	resume->active.width = 0;
	return (resume);
}

button_t *resume_button_hover(button_t *resume)
{
	resume->hover.height = 0;
	resume->hover.left = 0;
	resume->hover.top = 0;
	resume->hover.width = 0;
	return (resume);
}

button_t *resume_button(void)
{
	button_t *resume = malloc(sizeof(*resume));

	if (resume == NULL)
		return (NULL);
	resume->size.x = 235;
	resume->size.y = 85;
	resume->rect.height = 0;
	resume->rect.left = 0;
	resume->rect.top = 0;
	resume->rect.width = 0;
	resume = resume_button_hover(resume);
	resume = resume_button_active(resume);
	resume->callback = &(resume_function);
	resume->state = OFF;
	return (resume);
}
