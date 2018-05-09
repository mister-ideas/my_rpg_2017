/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** button.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

button_t *create_button(button_t *new, game_t *game)
{
	new->texture = game->texture;
	if ((new->shape = sfRectangleShape_create()) == NULL)
		return (NULL);
	sfRectangleShape_setTexture(new->shape, new->texture, sfTrue);
	sfRectangleShape_setTextureRect(new->shape, new->rect);
	sfRectangleShape_setSize(new->shape, new->size);
	sfRectangleShape_setPosition(new->shape, new->pos);
	return (new);
}
