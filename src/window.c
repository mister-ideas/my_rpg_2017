/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** window.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int init_window(game_t *game, sfVideoMode video)
{
	window_t *window = malloc(sizeof(*window));
	sfVector2i mouse_pos = {0, 0};

	if (window == NULL)
		return (84);
	game->window = window;
	game->window->window = sfRenderWindow_create(video,
	"Initiation Quest", sfClose, NULL);
	if (game->window->window == NULL)
		return (84);
	game->window->mouse_pos = mouse_pos;
	game->window->click = 2;
	return (0);
}

static void check_projectiles(game_t *game)
{
	struct node *obj;
	object_t *data;
	sfVector2f cur_pos;

	obj = game->scenes[game->current_scene]->objects->start;
	for (; obj != NULL; obj = obj->next) {
		data = (object_t *)obj->data;
		if (data->type == ARROW_UP || data->type == ARROW_LEFT ||
		data->type == ARROW_DOWN || data->type == ARROW_RIGHT) {
			cur_pos = sfSprite_getPosition(data->sprite);
			check_arrow_type(data, cur_pos);
			check_projectile_hit(game, data, cur_pos);
		} else if (data->type == SPELL_UP || data->type == SPELL_LEFT ||
		data->type == SPELL_DOWN || data->type == SPELL_RIGHT) {
			cur_pos = sfSprite_getPosition(data->sprite);
			check_spell_type(data, cur_pos);
			check_projectile_hit(game, data, cur_pos);
		}
	}
}

int display_window(game_t *game, particules_t *particules)
{
	sfRenderWindow_setFramerateLimit(game->window->window, 60);
	while (sfRenderWindow_isOpen(game->window->window)) {
		game_events(game);
		game->character->cur_pos =
		sfSprite_getPosition(game->character->char_obj->sprite);
		check_doors(game);
		check_walls(game);
		check_mobs(game);
		check_projectiles(game);
		sfRenderWindow_clear(game->window->window, sfBlack);
		display_game(game);
		sfRenderWindow_display(game->window->window);
	}
	quit_game(game, particules);
	return (0);
}
