/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/weapons.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void check_weapon(game_t *game)
{
	switch (game->current_weapon) {
	case 0:
		game->weapons->rect.top = 2252;
		game->character->attack = 2;
		game->character->defense = 1;
		game->character->speed = 5;
		break;
	case 1:
		game->weapons->rect.top = 2342;
		game->character->attack = 3;
		game->character->defense = 0;
		game->character->speed = 5;
		break;
	case 2:
		game->weapons->rect.top = 2432;
		game->character->attack = 1;
		game->character->defense = 2;
		game->character->speed = 3;
		break;
	}
}

void init_weapons(game_t *game)
{
	game->weapons->pos.x = 340;
	game->weapons->pos.y = 910;
	game->weapons->rect.height = 90;
	game->weapons->rect.left = 1350;
	game->weapons->rect.top = 2252;
	game->weapons->rect.width = 257;
}
