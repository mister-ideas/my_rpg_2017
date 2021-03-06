/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** events.c
*/

#include "my_rpg.h"

static void general_events(game_t *game)
{
	if (game->window->event.type == sfEvtClosed)
		sfRenderWindow_close(game->window->window);
	if (game->window->event.type == sfEvtMouseMoved)
		game->window->mouse_pos =
		sfMouse_getPositionRenderWindow(game->window->window);
	if (game->window->event.type == sfEvtMouseButtonPressed)
		game->window->click = 1;
	if (game->window->event.type == sfEvtMouseButtonReleased)
		game->window->click = 0;
}

static void esc_alt_events(game_t *game)
{
	if (game->keys->esc == sfTrue && game->current_scene != 0 &&
	game->current_scene != 1 && game->current_scene != 2 &&
	game->current_scene != 4 && game->current_scene != 5 &&
	game->current_scene != 6) {
		game->last_scene = game->current_scene;
		game->current_scene = 2;
	}
	if (game->keys->alt == sfTrue && game->current_scene != 0 &&
	game->current_scene != 1 && game->current_scene != 2 &&
	game->current_scene != 3 && game->current_scene != 4 &&
	game->current_scene != 5 && game->current_scene != 6) {
		game->last_scene = game->current_scene;
		game->current_scene = 4;
	} else if (game->keys->alt == sfFalse && game->current_scene == 4)
		game->current_scene = game->last_scene;
}

static void space_shift_events(game_t *game)
{
	if (game->keys->space == sfTrue && game->current_scene == 3)
		game->current_text++;
	if (game->keys->shift == sfTrue && game->current_scene == 3) {
		game->current_scene = 7;
		reset_map(game, (sfVector2f){265, 455});
		sfMusic_stop(game->musics[2]);
		sfMusic_play(game->musics[4]);
		sfMusic_setLoop(game->musics[4], sfTrue);
	} else if (game->keys->shift == sfTrue && game->current_scene != 3) {
		if (game->current_weapon != 2)
			game->current_weapon++;
		else
			game->current_weapon = 0;
	}
}

static void controls_events(game_t *game)
{
	if (game->current_scene != 0 && game->current_scene != 1 &&
	game->current_scene != 2) {
		if (game->current_weapon == 0 || game->current_weapon == 1)
			bow_spell_walk(game);
		if (game->current_weapon == 2) {
			spear_walk(game);
			spear_attack(game);
		}
		if (game->current_weapon == 0)
			spell_attack(game);
		if (game->current_weapon == 1)
			bow_attack(game);
	}
}

void game_events(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window->window,
	&(game->window->event))) {
		general_events(game);
		if (game->window->event.type == sfEvtKeyPressed)
			check_pressed_keys(game);
		if (game->window->event.type == sfEvtKeyReleased)
			check_released_keys(game);
		esc_alt_events(game);
		space_shift_events(game);
		controls_events(game);
		if (check_all_keys_released(game) == 1)
			default_character(game);
	}
}
