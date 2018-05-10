/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** walls.c
*/

#include "my_rpg.h"

static void left_wall(game_t *game)
{
	if (game->character->cur_pos.x < 245) {
		game->character->char_obj->pos.x = 255;
		game->character->char_obj->pos.y = game->character->cur_pos.y;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void right_wall(game_t *game)
{
	if (game->character->cur_pos.x > 1550) {
		game->character->char_obj->pos.x = 1540;
		game->character->char_obj->pos.y = game->character->cur_pos.y;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void up_wall(game_t *game)
{
	if (game->character->cur_pos.y < 160) {
		game->character->char_obj->pos.x = game->character->cur_pos.x;
		game->character->char_obj->pos.y = 170;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void down_wall(game_t *game)
{
	if (game->character->cur_pos.y > 790) {
		game->character->char_obj->pos.x = game->character->cur_pos.x;
		game->character->char_obj->pos.y = 780;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

void check_walls(game_t *game)
{
	left_wall(game);
	right_wall(game);
	up_wall(game);
	down_wall(game);
}
