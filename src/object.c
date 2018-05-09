/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** object.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

object_t *create_object(object_t *new, game_t *game)
{
	new->texture = game->texture;
	if ((new->sprite = sfSprite_create()) == NULL)
		return (NULL);
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, new->rect);
	sfSprite_setPosition(new->sprite, new->pos);
	return (new);
}
