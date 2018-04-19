/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons/how_to_play.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void htp_function(void)
{
	my_putstr("htp\n");
}

button_t *htp_button_active(button_t *htp)
{
	htp->active.height = 0;
	htp->active.left = 0;
	htp->active.top = 0;
	htp->active.width = 0;
	return (htp);
}

button_t *htp_button_hover(button_t *htp)
{
	htp->hover.height = 0;
	htp->hover.left = 0;
	htp->hover.top = 0;
	htp->hover.width = 0;
	return (htp);
}

button_t *htp_button(void)
{
	button_t *htp = malloc(sizeof(*htp));

	if (htp == NULL)
		return (NULL);
	htp->size.x = 235;
	htp->size.y = 85;
	htp->rect.height = 0;
	htp->rect.left = 0;
	htp->rect.top = 0;
	htp->rect.width = 0;
	htp = htp_button_hover(htp);
	htp = htp_button_active(htp);
	htp->callback = &(htp_function);
	htp->state = OFF;
	return (htp);
}
