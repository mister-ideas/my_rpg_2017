/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

button_t *create_button(button_t *new, sfImage *img)
{
	new->texture = sfTexture_createFromImage(img, &atlas_rect);
	if (new->texture == NULL)
		return (NULL);
	if ((new->shape = sfRectangleShape_create()) == NULL)
		return (NULL);
	sfRectangleShape_setTexture(new->shape, new->texture, sfTrue);
	sfRectangleShape_setTextureRect(new->shape, new->rect);
	sfRectangleShape_setSize(new->shape, new->size);
	sfRectangleShape_setPosition(new->shape, new->pos);
	return (new);
}
