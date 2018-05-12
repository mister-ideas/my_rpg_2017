/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display.c
*/

#include "my_rpg.h"

static void display_but(struct node *but, game_t *game)
{
	button_t *button;
	int in_area = 0;

	for (; but != NULL; but = but->next) {
		button = (button_t *)but->data;
		in_area = mouse_is_in_area(button->pos, button->size,
		game->window->mouse_pos);
		check_button_state(button, game, in_area);
		sfRenderWindow_drawRectangleShape(game->window->window,
		button->shape, NULL);
	}
}

static void display_mob(mob_t *mob, game_t *game)
{
	if (mob->health > 0) {
		if (mob->mob_obj->type == MISC)
			mob_clock(mob);
		sfRenderWindow_drawSprite(game->window->window,
		mob->mob_obj->sprite, NULL);
		sfSprite_move(mob->mob_obj->sprite,
		mob->move);
	}
}

static void display_special_obj(game_t *game)
{
	if (game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 2 && game->current_scene != 4 &&
	game->current_scene != 5 && game->current_scene != 6) {
		check_weapon(game);
		sfSprite_setTextureRect(game->weapons->sprite,
		game->weapons->rect);
		if (game->current_scene >= 7 && game->current_scene <= 11)
			sfRenderWindow_drawSprite(game->window->window,
			game->weapons->sprite, NULL);
		character_clock(game->character);
		sfRenderWindow_drawSprite(game->window->window,
		game->character->char_obj->sprite, NULL);
		sfSprite_move(game->character->char_obj->sprite,
		game->character->move);
		for (int i = 0; i < game->scenes
		[game->current_scene]->mobs_nb; i++)
			display_mob(game->mobs[i], game);
	}
}

static void display_texts(game_t *game)
{
	char str[12];

	int_to_text(game->character->health, str);
	update_text(game, game->texts->health, str,
	(sfVector2f){965, 300});
	int_to_text(game->character->attack, str);
	update_text(game, game->texts->attack, str,
	(sfVector2f){965, 385});
	int_to_text(game->character->defense, str);
	update_text(game, game->texts->defense, str,
	(sfVector2f){965, 475});
	int_to_text(game->character->speed, str);
	update_text(game, game->texts->speed, str,
	(sfVector2f){965, 560});
	int_to_text(game->character->level, str);
	update_text(game, game->texts->level, str,
	(sfVector2f){965, 635});
}

void display_game(game_t *game)
{
	struct node *but;
	struct node *obj = game->scenes[game->current_scene]->objects->start;
	object_t *data;

	if (game->scenes[game->current_scene]->buttons) {
		but = game->scenes[game->current_scene]->buttons->start;
		display_but(but, game);
	}
	for (; obj != NULL; obj = obj->next) {
		data = (object_t *)obj->data;
		check_text_type(game, data);
		sfRenderWindow_drawSprite(game->window->window,
		data->sprite, NULL);
	}
	display_special_obj(game);
	if (game->current_scene == 4)
		display_texts(game);
}
