/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** objects/spells.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int add_spell_up(game_t *game, dll_t *list)
{
	object_t *spell = malloc(sizeof(*spell));

	if (spell == NULL)
		return (84);
	spell->pos.x = game->character->cur_pos.x + 50;
	spell->pos.y = game->character->cur_pos.y + 50;
	spell->rect.height = 40;
	spell->rect.left = 1688;
	spell->rect.top = 2500;
	spell->rect.width = 40;
	spell->type = SPELL_UP;
	spell = create_object(spell, game);
	put_end_list(list, spell);
	return (0);
}

int add_spell_left(game_t *game, dll_t *list)
{
	object_t *spell = malloc(sizeof(*spell));

	if (spell == NULL)
		return (84);
	spell->pos.x = game->character->cur_pos.x + 50;
	spell->pos.y = game->character->cur_pos.y + 50;
	spell->rect.height = 40;
	spell->rect.left = 1688;
	spell->rect.top = 2500;
	spell->rect.width = 40;
	spell->type = SPELL_LEFT;
	spell = create_object(spell, game);
	put_end_list(list, spell);
	return (0);
}

int add_spell_down(game_t *game, dll_t *list)
{
	object_t *spell = malloc(sizeof(*spell));

	if (spell == NULL)
		return (84);
	spell->pos.x = game->character->cur_pos.x + 50;
	spell->pos.y = game->character->cur_pos.y + 50;
	spell->rect.height = 40;
	spell->rect.left = 1688;
	spell->rect.top = 2500;
	spell->rect.width = 40;
	spell->type = SPELL_DOWN;
	spell = create_object(spell, game);
	put_end_list(list, spell);
	return (0);
}

int add_spell_right(game_t *game, dll_t *list)
{
	object_t *spell = malloc(sizeof(*spell));

	if (spell == NULL)
		return (84);
	spell->pos.x = game->character->cur_pos.x + 50;
	spell->pos.y = game->character->cur_pos.y + 50;
	spell->rect.height = 40;
	spell->rect.left = 1688;
	spell->rect.top = 2500;
	spell->rect.width = 40;
	spell->type = SPELL_RIGHT;
	spell = create_object(spell, game);
	put_end_list(list, spell);
	return (0);
}

void check_spell_type(object_t *data, sfVector2f cur_pos)
{
	if (data->type == SPELL_UP) {
		if (cur_pos.y < 160)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){0, -10});
	}
	if (data->type == SPELL_LEFT) {
		if (cur_pos.x < 245)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){-10, 0});
	}
	if (data->type == SPELL_DOWN) {
		if (cur_pos.y > 790)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){0, 10});
	}
	if (data->type == SPELL_RIGHT) {
		if (cur_pos.x > 1550)
			delete_projectile(data);
		sfSprite_move(data->sprite, (sfVector2f){10, 0});
	}
}
