/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** window.c
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"

int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos)
{
	return (clickPos.x < pos.x + size.x && clickPos.x > pos.x &&
		clickPos.y < pos.y + size.y && clickPos.y > pos.y);
}

window_t *create_window(sfVideoMode video_size)
{
	window_t *new = malloc(sizeof(*new));
	sfVector2i pos = {0, 0};

	if (new == NULL)
		return (NULL);
	new->is_clicked = 0;
	new->mode = video_size;
	new->window = sfRenderWindow_create(new->mode, "Burgers World",
					sfClose, NULL);
	if (new->window == NULL)
		return (NULL);
	new->mouse_pos = pos;
	return (new);
}

int game_events(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window->window,
					&(game->window->event))) {
		if (game->window->event.type == sfEvtClosed)
			sfRenderWindow_close(game->window->window);
		if (game->window->event.type == sfEvtMouseMoved) {
			game->window->mouse_pos =
			sfMouse_getPositionRenderWindow(game->window->window);
		}
		if (game->window->event.type == sfEvtMouseButtonPressed)
			game->window->is_clicked = 1;
		else if (game->window->event.type == sfEvtMouseButtonReleased)
			game->window->is_clicked = 0;
		if (game->window->event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue &&
		game->current_scene == 1)
			game->current_scene = 2;
	}
	return (0);
}

int display_window(game_t *game)
{
	sfRenderWindow_setFramerateLimit(game->window->window, 60);
	while (sfRenderWindow_isOpen(game->window->window)) {
		game_events(game);
		sfRenderWindow_clear(game->window->window, sfBlack);
		if (display(game) == 84)
			return (84);
		sfRenderWindow_display(game->window->window);
	}
	quit_game(game);
	return (0);
}
