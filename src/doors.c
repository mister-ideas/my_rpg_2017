/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** doors.c
*/

#include "my_rpg.h"

static void left_doors(game_t *game)
{
	if (game->current_scene != 3 && game->current_scene != 4 &&
	game->current_scene != 7 && game->current_scene != 10 &&
	game->current_scene != 11 && game->character->cur_pos.x < 255 &&
	(game->character->cur_pos.y >= 435 &&
	game->character->cur_pos.y <= 545)) {
		game->current_scene -= 1;
		game->character->char_obj->pos.x = 1530;
		game->character->char_obj->pos.y = 455;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void right_doors(game_t *game)
{
	if (game->current_scene != 9 && game->current_scene != 10 &&
	game->current_scene != 11 && game->character->cur_pos.x > 1540 &&
	(game->character->cur_pos.y >= 435 &&
	game->character->cur_pos.y <= 545)) {
		if (game->current_scene == 3)
			game->current_scene = 7;
		else
			game->current_scene += 1;
		game->character->char_obj->pos.x = 265;
		game->character->char_obj->pos.y = 455;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void up_doors(game_t *game)
{
	if (game->current_scene != 7 && game->current_scene != 8 &&
	game->current_scene != 11 && game->character->cur_pos.y < 170 &&
	(game->character->cur_pos.x >= 865 &&
	game->character->cur_pos.x <= 960)) {
		if (game->current_scene == 9)
			game->current_scene = 11;
		else if (game->current_scene == 10)
			game->current_scene = 8;
		game->character->char_obj->pos.x = 890;
		game->character->char_obj->pos.y = 770;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void down_doors(game_t *game)
{
	if (game->current_scene != 7 && game->current_scene != 9 &&
	game->current_scene != 10 && game->character->cur_pos.y > 780 &&
	(game->character->cur_pos.x >= 865 &&
	game->character->cur_pos.x <= 960)) {
		if (game->current_scene == 8)
			game->current_scene = 10;
		else if (game->current_scene == 11)
			game->current_scene = 9;
		game->character->char_obj->pos.x = 890;
		game->character->char_obj->pos.y = 180;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

void check_doors(game_t *game)
{
	left_doors(game);
	right_doors(game);
	up_doors(game);
	down_doors(game);
}
