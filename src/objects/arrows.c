/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/arrows.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int add_arrow_up(game_t *game, dll_t *list)
{
	object_t *arrow = malloc(sizeof(*arrow));

	if (arrow == NULL)
		return (84);
	arrow->pos.x = game->character->cur_pos.x + 50;
	arrow->pos.y = game->character->cur_pos.y + 50;
	arrow->rect.height = 65;
	arrow->rect.left = 1701;
	arrow->rect.top = 2423;
	arrow->rect.width = 15;
	arrow->type = ARROW_UP;
	arrow = create_object(arrow, game);
	put_end_list(list, arrow);
	return (0);
}

int add_arrow_left(game_t *game, dll_t *list)
{
	object_t *arrow = malloc(sizeof(*arrow));

	if (arrow == NULL)
		return (84);
	arrow->pos.x = game->character->cur_pos.x + 50;
	arrow->pos.y = game->character->cur_pos.y + 50;
	arrow->rect.height = 15;
	arrow->rect.left = 1674;
	arrow->rect.top = 2393;
	arrow->rect.width = 65;
	arrow->type = ARROW_LEFT;
	arrow = create_object(arrow, game);
	put_end_list(list, arrow);
	return (0);
}

int add_arrow_down(game_t *game, dll_t *list)
{
	object_t *arrow = malloc(sizeof(*arrow));

	if (arrow == NULL)
		return (84);
	arrow->pos.x = game->character->cur_pos.x + 50;
	arrow->pos.y = game->character->cur_pos.y + 50;
	arrow->rect.height = 65;
	arrow->rect.left = 1701;
	arrow->rect.top = 2311;
	arrow->rect.width = 15;
	arrow->type = ARROW_DOWN;
	arrow = create_object(arrow, game);
	put_end_list(list, arrow);
	return (0);
}

int add_arrow_right(game_t *game, dll_t *list)
{
	object_t *arrow = malloc(sizeof(*arrow));

	if (arrow == NULL)
		return (84);
	arrow->pos.x = game->character->cur_pos.x + 50;
	arrow->pos.y = game->character->cur_pos.y + 50;
	arrow->rect.height = 15;
	arrow->rect.left = 1674;
	arrow->rect.top = 2274;
	arrow->rect.width = 65;
	arrow->type = ARROW_RIGHT;
	arrow = create_object(arrow, game);
	put_end_list(list, arrow);
	return (0);
}

void check_arrow_type(object_t *data, sfVector2f cur_pos)
{
	if (data->type == ARROW_UP) {
		if (cur_pos.y < 160)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){0, -20});
	}
	if (data->type == ARROW_LEFT) {
		if (cur_pos.x < 245)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){-20, 0});
	}
	if (data->type == ARROW_DOWN) {
		if (cur_pos.y > 790)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){0, 20});
	}
	if (data->type == ARROW_RIGHT) {
		if (cur_pos.x > 1550)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){20, 0});
	}
}
