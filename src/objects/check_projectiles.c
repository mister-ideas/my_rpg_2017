/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/check_projectiles.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

void delete_projectile(object_t *data)
{
	sfSprite_setColor(data->sprite, sfTransparent);
	sfSprite_setPosition(data->sprite, (sfVector2f){0, 0});
	sfSprite_move(data->sprite, (sfVector2f){0, 0});
}

void check_projectile_hit(game_t *game, object_t *data, sfVector2f cur_pos)
{
	sfColor color;

	for (int i = 0; i < game->scenes[game->current_scene]->mobs_nb; i++) {
		color = sfSprite_getColor(game->mobs[i]->mob_obj->sprite);
		if (check_collision(data, cur_pos,
		game->mobs[i]->cur_pos) == 1 && game->mobs[i]->health > 0) {
			game->mobs[i]->health -= game->character->attack;
			color.a -= 64;
			sfSprite_setColor(game->mobs[i]->
			mob_obj->sprite, color);
			delete_projectile(data);
			check_kill(game, i);
		}
	}
}
