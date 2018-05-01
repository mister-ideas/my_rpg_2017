/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display.c
*/

#include "my_rpg.h"

static void check_button_state(button_t *but, game_t *game, int in_area)
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

static void display_but(struct node *button, game_t *game)
{
	button_t *but;
	int in_area = 0;

	for (; button != NULL; button = button->next) {
		but = (button_t *)button->data;
		in_area = mouse_is_in_area(but->pos, but->size,
					game->window->mouse_pos);
		check_button_state(but, game, in_area);
		sfRenderWindow_drawRectangleShape(game->window->window,
						but->shape, NULL);
	}
}

static void display_special_obj(game_t *game)
{
	if (game->current_scene != 0 && game->current_scene != 1 &&
	    game->current_scene != 2) {
		if (game->current_scene != 3) {
			check_weapon(game);
			sfRenderWindow_drawSprite(game->window->window,
			game->weapons->sprite, NULL);
		}
		character_clock(game->character);
		sfRenderWindow_drawSprite(game->window->window,
		game->character->char_obj->sprite, NULL);
		sfSprite_move(game->character->char_obj->sprite,
		game->character->move);
	}
}

int display_game(game_t *game)
{
	struct node *button;
	struct node *obj = game->scenes[game->current_scene]->objects->start;
	object_t *data;

	if (game->scenes[game->current_scene]->buttons) {
		button = game->scenes[game->current_scene]->buttons->start;
		display_but(button, game);
	}
	for (; obj != NULL; obj = obj->next) {
		data = (object_t *)obj->data;
		if (data->type == TEXT && game->current_text < 10)
			data->rect.top = 2625 + game->current_text / 2 * 40;
		sfSprite_setTextureRect(data->sprite, data->rect);
		sfRenderWindow_drawSprite(game->window->window,
		data->sprite, NULL);
	}
	display_special_obj(game);
	return (0);
}
