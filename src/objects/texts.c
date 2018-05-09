/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/texts.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void update_text(game_t *game, sfText *text, char str[], sfVector2f pos)
{
	sfText_setString(text, str);
	sfText_setFont(text, game->font);
	sfText_setCharacterSize(text, 60);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(game->window->window,
	text, NULL);
}

int init_texts(game_t *game)
{
	game->texts->health = sfText_create();
	game->texts->attack = sfText_create();
	game->texts->defense = sfText_create();
	game->texts->speed = sfText_create();
	game->texts->level = sfText_create();
	if (game->texts->health == NULL || game->texts->attack == NULL ||
	game->texts->defense == NULL || game->texts->speed == NULL ||
	game->texts->level == NULL)
		return (84);
	return (0);
}
