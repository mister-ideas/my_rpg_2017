/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** check_items.c
*/

#include "my_rpg.h"

static void check_powerup(game_t *game, object_t *data)
{
	if (data->type == POWERUP) {
		if (check_collision(game->character->char_obj,
		data, game->character->cur_pos, data->pos) == 1 &&
		game->scenes[game->current_scene]->kills ==
		game->scenes[game->current_scene]->mobs_nb) {
			game->character->attack_bonus = 1;
			sfSprite_setColor(data->sprite, sfTransparent);
			sfSprite_setPosition(data->sprite, (sfVector2f){0, 0});
			sfSound_play(game->sounds[3]);
		}
	}
}

static void check_potion(game_t *game, object_t *data)
{
	if (data->type == POTION) {
		if (check_collision(game->character->char_obj,
		data, game->character->cur_pos, data->pos) == 1 &&
		game->scenes[game->current_scene]->kills ==
		game->scenes[game->current_scene]->mobs_nb) {
			game->slot_rect = 2343;
			sfSprite_setColor(data->sprite, sfTransparent);
			sfSprite_setPosition(data->sprite, (sfVector2f){0, 0});
			sfSound_play(game->sounds[3]);
		}
	}
}

static void check_slot(game_t *game, object_t *data)
{
	sfColor color;

	color = sfSprite_getColor(game->character->char_obj->sprite);
	if (data->type == SLOT) {
		data->rect.top = game->slot_rect;
		sfSprite_setTextureRect(data->sprite, data->rect);
		if (game->keys->e == sfTrue && game->slot_rect == 2343) {
			game->character->health += 4;
			color.a = 255;
			sfSprite_setColor(game->character->
			char_obj->sprite, color);
			game->slot_rect = 2253;
		}
	}
}

void check_items(game_t *game, object_t *data)
{
	check_powerup(game, data);
	check_potion(game, data);
	check_slot(game, data);
}
