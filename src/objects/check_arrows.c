/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/arrows.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static void delete_arrow(object_t *data)
{
	sfSprite_setColor(data->sprite, sfTransparent);
	sfSprite_setPosition(data->sprite, (sfVector2f){0, 0});
	sfSprite_move(data->sprite, (sfVector2f){0, 0});
}

void check_arrow_hit(game_t *game, object_t *data, sfVector2f cur_pos)
{
	sfColor color;

	for (int i = 0; i < game->scenes[game->current_scene]->mobs_nb; i++) {
		color = sfSprite_getColor(game->mobs[i]->mob_obj->sprite);
		if (check_collision(data, cur_pos,
		game->mobs[i]->cur_pos) == 1 && game->mobs[i]->health > 0) {
			color.a -= 85;
			game->mobs[i]->health -= game->character->attack;
			if (game->mobs[i]->health <= 0) {
				game->scenes[game->current_scene]->kills++;
				game->mobs[i]->move.x = 0;
				game->mobs[i]->move.y = 0;
			}
			sfSprite_setColor(game->mobs[i]->
			mob_obj->sprite, color);
			delete_arrow(data);
		}
	}
}

void check_arrow_type(object_t *data, sfVector2f cur_pos)
{
	if (data->type == ARROW_UP) {
		if (cur_pos.y < 160)
			delete_arrow(data);
		sfSprite_move(data->sprite, (sfVector2f){0, -10});
	}
	if (data->type == ARROW_LEFT) {
		if (cur_pos.x < 245)
			sfSprite_setColor(data->sprite, sfTransparent);
		sfSprite_move(data->sprite, (sfVector2f){-10, 0});
	}
	if (data->type == ARROW_DOWN) {
		if (cur_pos.y > 790)
			sfSprite_setColor(data->sprite, sfTransparent);
		sfSprite_move(data->sprite, (sfVector2f){0, 10});
	}
	if (data->type == ARROW_RIGHT) {
		if (cur_pos.x > 1550)
			sfSprite_setColor(data->sprite, sfTransparent);
		sfSprite_move(data->sprite, (sfVector2f){10, 0});
	}
}
