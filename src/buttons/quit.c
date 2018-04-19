/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/quit.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void quit_function(void)
{
	my_putstr("quit\n");
}

button_t *quit_button_active(button_t *quit)
{
	quit->active.height = 0;
	quit->active.left = 0;
	quit->active.top = 0;
	quit->active.width = 0;
	return (quit);
}

button_t *quit_button_hover(button_t *quit)
{
	quit->hover.height = 0;
	quit->hover.left = 0;
	quit->hover.top = 0;
	quit->hover.width = 0;
	return (quit);
}

button_t *quit_button(void)
{
	button_t *quit = malloc(sizeof(*quit));

	if (quit == NULL)
		return (NULL);
	quit->size.x = 235;
	quit->size.y = 85;
	quit->rect.height = 0;
	quit->rect.left = 0;
	quit->rect.top = 0;
	quit->rect.width = 0;
	quit = quit_button_hover(quit);
	quit = quit_button_active(quit);
	quit->callback = &(quit_function);
	quit->state = OFF;
	return (quit);
}
