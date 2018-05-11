/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** doors.c
*/

#include "my_rpg.h"

static void reset_map(game_t *game, sfVector2f pos)
{
	sfColor color;

	sfSprite_setPosition(game->character->char_obj->sprite, pos);
	for (int i = 0; i < NB_MOBS; i++) {
		color = sfSprite_getColor(game->mobs[i]->mob_obj->sprite);
		color.a = 255;
		sfSprite_setColor(game->mobs[i]->mob_obj->sprite, color);
		game->mobs[i]->move.x = rand() % 4;
		game->mobs[i]->move.y = rand() % 4;
		game->mobs[i]->health = 4;
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
		reset_map(game, (sfVector2f){265, 455});
	}
}

static void up_doors(game_t *game)
{
	if (game->current_scene != 7 && game->current_scene != 8 &&
	game->current_scene != 11 && game->character->cur_pos.y < 170 &&
	(game->character->cur_pos.x >= 865 &&
	game->character->cur_pos.x <= 960)) {
		if (game->current_scene == 9 && game->scenes[11]->kills == 0) {
			game->current_scene = 11;
			reset_map(game, (sfVector2f){890, 770});
		}
		if (game->current_scene == 10) {
			game->current_scene = 8;
			game->mobs[2]->health = 0;
			game->mobs[3]->health = 0;
			sfSprite_setPosition(game->character->char_obj->sprite,
			(sfVector2f){890, 770});
		}
	}
}

static void down_doors(game_t *game)
{
	if (game->current_scene != 7 && game->current_scene != 9 &&
	game->current_scene != 10 && game->character->cur_pos.y > 780 &&
	(game->character->cur_pos.x >= 865 &&
	game->character->cur_pos.x <= 960)) {
		if (game->current_scene == 8 && game->scenes[10]->kills == 0) {
			game->current_scene = 10;
			reset_map(game, (sfVector2f){890, 180});
		}
		if (game->current_scene == 11 && game->scenes[9]->kills == 0) {
			game->current_scene = 9;
			reset_map(game, (sfVector2f){890, 180});
		}
	}
}

void check_doors(game_t *game)
{
	if (game->scenes[game->current_scene]->kills ==
	game->scenes[game->current_scene]->mobs_nb) {
		right_doors(game);
		up_doors(game);
		down_doors(game);
	}
}
