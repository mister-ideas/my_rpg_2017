/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display.c
*/

#include "my.h"
#include "my_rpg.h"

void display_buttons(struct node *button, game_t *game)
{
	button_t *but;
	int clicked = 0;

	for (; button != NULL; button = button->next) {
		but = (button_t *)button->data;
		clicked = mouse_is_in_area(but->pos, but->size,
					game->window->mouse_pos);
		if (clicked == 1 && game->window->is_clicked == 1)
			but->callback(but, game);
		if (clicked == 1 && but->state == OFF) {
			but->callback(but, game);
			but->state = ACTIVE;
		} else if (clicked == 0 && but->state == ACTIVE) {
			sfRectangleShape_setTextureRect(but->shape, but->rect);
			but->state = OFF;
		}
		sfRenderWindow_drawRectangleShape(game->window->window,
						but->shape, NULL);
	}
}

void display_objects(struct node *obj, game_t *game)
{
	object_t *ok;

	for (; obj != NULL; obj = obj->next) {
		ok = (object_t *)obj->data;
		sfRenderWindow_drawSprite(game->window->window,
					ok->sprite, NULL);
	}
}

int display(game_t *game)
{
	struct node *button = game->scenes[game->current_scene]->buttons->start;
	struct node *obj = game->scenes[game->current_scene]->objects->start;

	display_buttons(button, game);
	display_objects(obj, game);
	return (0);
}
