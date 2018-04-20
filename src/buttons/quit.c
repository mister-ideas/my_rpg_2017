/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/quit.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void quit_function(game_t *game)
{
	sfRenderWindow_close(game->window->window);
}

button_t *quit_button_active(button_t *quit)
{
	quit->active.height = 85;
	quit->active.left = 0;
	quit->active.top = 3240;
	quit->active.width = 235;
	return (quit);
}

button_t *quit_button_hover(button_t *quit)
{
	quit->hover.height = 85;
	quit->hover.left = 0;
	quit->hover.top = 3154;
	quit->hover.width = 235;
	return (quit);
}

button_t *quit_button(game_t *game)
{
	button_t *quit = malloc(sizeof(*quit));

	if (quit == NULL)
		return (NULL);
	quit->size.x = 235;
	quit->size.y = 85;
	quit->rect.height = 85;
	quit->rect.left = 0;
	quit->rect.top = 3068;
	quit->rect.width = 235;
	quit = quit_button_hover(quit);
	quit = quit_button_active(quit);
	quit->callback = &(quit_function);
	quit->state = OFF;
	return (quit);
}
