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
	sfRenderWindow_setFramerateLimit(game->window->window, 60);
	game->window->mouse_pos = mouse_pos;
	game->window->click = 2;
	return (0);
}

static void check_character(game_t *game, int i)
{
	sfColor color;

	if (check_collision(game->character->char_obj, game->mobs[i]->mob_obj,
	game->character->cur_pos, game->mobs[i]->cur_pos) == 1
	&& game->character->health > 0 && game->mobs[i]->health > 0) {
		color = sfSprite_getColor(game->mobs[i]->mob_obj->sprite);
		if (check_spear_hit(game, i) == 1)
			return;
		game->character->health -= (4 - game->character->defense);
		color = sfSprite_getColor(game->character->char_obj->sprite);
		color.a -= 64;
		sfSprite_setColor(game->character->char_obj->sprite, color);
		sfSprite_setPosition(game->character->
		char_obj->sprite, (sfVector2f){890, 460});
	}
}

static void check_mobs(game_t *game)
{
	for (int i = 0; i < NB_MOBS; i++) {
		game->mobs[i]->cur_pos =
			sfSprite_getPosition(game->mobs[i]->mob_obj->sprite);
		check_character(game, i);
		if (game->mobs[i]->cur_pos.x < 275) {
			game->mobs[i]->move.x = rand() % 2;
			game->mobs[i]->move.y = rand() % 2 - rand() % 4;
		} else if (game->mobs[i]->cur_pos.x > 1570) {
			game->mobs[i]->move.x = rand() % 2 * -1;
			game->mobs[i]->move.y = rand() % 2 - rand() % 4;
		}
		if (game->mobs[i]->cur_pos.y < 160) {
			game->mobs[i]->move.x = rand() % 2 - rand() % 4;
			game->mobs[i]->move.y = rand() % 2;
		} else if (game->mobs[i]->cur_pos.y > 840) {
			game->mobs[i]->move.x = rand() % 2 - rand() % 4;
			game->mobs[i]->move.y = rand() % 2 * -1;
		}
	}
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
	while (sfRenderWindow_isOpen(game->window->window)) {
		game_events(game);
		game->character->cur_pos =
		sfSprite_getPosition(game->character->char_obj->sprite);
		check_doors(game);
		check_walls(game);
		check_mobs(game);
		check_projectiles(game);
		check_end(game, particules);
		sfRenderWindow_clear(game->window->window, sfBlack);
		display_game(game);
		if (game->current_scene == 5)
			display_particules(particules, game, 2);
		else if (game->current_scene == 6)
			display_particules(particules, game, 1);
		sfRenderWindow_display(game->window->window);
	}
	quit_game(game, particules);
	return (0);
}
