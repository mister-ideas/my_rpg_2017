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
	game->current_scene != 7 && game->character->cur_pos.x < 275 &&
	(game->character->cur_pos.y >= 455 &&
	game->character->cur_pos.y <= 545)) {
		game->doors = 1;
		game->current_scene -= 1;
		game->character->char_obj->pos.x = 1505;
		game->character->char_obj->pos.y = 455;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void right_doors(game_t *game)
{
	if (game->current_scene != 6 && game->current_scene != 7 &&
	game->character->cur_pos.x > 1515 &&
	(game->character->cur_pos.y >= 455 &&
	game->character->cur_pos.y <= 545)) {
		game->doors = 1;
		game->current_scene += 1;
		game->character->char_obj->pos.x = 285;
		game->character->char_obj->pos.y = 455;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void up_doors(game_t *game)
{
	if (game->current_scene != 3 && game->current_scene != 4 &&
	game->current_scene != 5 && game->character->cur_pos.y < 120 &&
	(game->character->cur_pos.x >= 885 &&
	game->character->cur_pos.x <= 960)) {
		game->doors = 1;
		if (game->current_scene == 6)
			game->current_scene = 8;
		else if (game->current_scene == 7)
			game->current_scene = 5;
		game->character->char_obj->pos.x = 890;
		game->character->char_obj->pos.y = 750;
		sfSprite_setPosition(game->character->char_obj->sprite,
		game->character->char_obj->pos);
	}
}

static void down_doors(game_t *game)
{
	if (game->current_scene != 3 && game->current_scene != 4 &&
	game->current_scene != 6 && game->current_scene != 7 &&
	game->character->cur_pos.y > 760 &&
	(game->character->cur_pos.x >= 885 &&
	game->character->cur_pos.x <= 960)) {
		game->doors = 1;
		if (game->current_scene == 5)
			game->current_scene = 7;
		else if (game->current_scene == 8)
			game->current_scene = 6;
		game->character->char_obj->pos.x = 890;
		game->character->char_obj->pos.y = 130;
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
