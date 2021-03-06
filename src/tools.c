/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** tools.c
*/

#include "my_rpg.h"

int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos)
{
	return (clickPos.x < pos.x + size.x && clickPos.x > pos.x &&
		clickPos.y < pos.y + size.y && clickPos.y > pos.y);
}

void check_kill(game_t *game, int i)
{
	if (game->mobs[i]->health <= 0) {
		game->scenes[game->current_scene]->kills++;
		game->character->exp += 50;
		game->mobs[i]->move.x = 0;
		game->mobs[i]->move.y = 0;
		sfSprite_setPosition(game->mobs[i]->
		mob_obj->sprite, (sfVector2f){0, 0});
	}
	if (game->character->exp == 500) {
		game->character->general_bonus = 1;
		game->character->level = 2;
		sfSound_play(game->sounds[3]);
	}
	if (game->scenes[game->current_scene]->kills ==
	game->scenes[game->current_scene]->mobs_nb)
		sfSound_play(game->sounds[1]);
}

int check_collision(object_t *obj, object_t *mob, sfVector2f obj_pos,
		sfVector2f mob_pos)
{
	if ((obj_pos.x > mob_pos.x && obj_pos.x <
	mob_pos.x + mob->rect.width) &&
	(obj_pos.y > mob_pos.y && obj_pos.y < mob_pos.y + mob->rect.height))
		return (1);
	if ((obj_pos.x + obj->rect.width > mob_pos.x &&
	obj_pos.x + obj->rect.width < mob_pos.x + mob->rect.width) &&
	(obj_pos.y > mob_pos.y && obj_pos.y < mob_pos.y + mob->rect.height))
		return (1);
	if ((obj_pos.x > mob_pos.x && obj_pos.x <
	mob_pos.x + mob->rect.width) &&
	(obj_pos.y + obj->rect.height > mob_pos.y &&
	obj_pos.y + obj->rect.height < mob_pos.y + mob->rect.height))
		return (1);
	if ((obj_pos.x + obj->rect.width > mob_pos.x &&
	obj_pos.x + obj->rect.width < mob_pos.x + mob->rect.width) &&
	(obj_pos.y + obj->rect.height > mob_pos.y &&
	obj_pos.y + obj->rect.height < mob_pos.y + mob->rect.height))
		return (1);
	return (0);
}

void check_button_state(button_t *but, game_t *game, int in_area)
{
	if (in_area == 1)
		sfRectangleShape_setTextureRect(but->shape,
						but->hover);
	else if (in_area == 0)
		sfRectangleShape_setTextureRect(but->shape, but->rect);
	if (in_area == 1 && game->window->click == 1)
		sfRectangleShape_setTextureRect(but->shape,
						but->active);
	else if (in_area == 1 && game->window->click == 0) {
		but->callback(game);
		game->window->click = 2;
	}
}

void int_to_text(int num, char str[])
{
	int rem;
	int len = 0;
	int n;
	int i;

	n = num;
	if (n == 0)
		len = 1;
	while (n) {
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++) {
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}
