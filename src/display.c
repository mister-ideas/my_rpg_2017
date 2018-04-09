/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display.c
*/

#include "my_rpg.h"

void display_but(struct node *button, game_t *game)
{
	button_t *but;
	int in_area = 0;

	for (; button != NULL; button = button->next) {
		but = (button_t *)button->data;
		in_area = mouse_is_in_area(but->pos, but->size,
					game->window->mouse_pos);
		if (in_area == 1)
			sfRectangleShape_setTextureRect(but->shape, but->push_rect);
		else if (in_area == 0)
			sfRectangleShape_setTextureRect(but->shape, but->rect);
		if (in_area == 1 && game->window->click == 1)
			but->callback();
		sfRenderWindow_drawRectangleShape(game->window->window,
						but->shape, NULL);
	}
}

void display_obj(struct node *obj, game_t *game)
{
	object_t *ok;

	for (; obj != NULL; obj = obj->next) {
		ok = (object_t *)obj->data;
		sfRenderWindow_drawSprite(game->window->window,
					ok->sprite, NULL);
	}
}

int display_game(game_t *game)
{
	struct node *button = game->scenes[game->current_scene]->buttons->start;
	struct node *obj = game->scenes[game->current_scene]->objects->start;

	display_but(button, game);
	display_obj(obj, game);
	return (0);
}
