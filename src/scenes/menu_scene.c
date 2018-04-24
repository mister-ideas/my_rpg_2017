/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes/menu_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int menu_scene_init_buttons(button_t *play, button_t *quit, button_t *htp)
{
	if (play == NULL || quit == NULL || htp == NULL)
		return (84);
	play->pos.x = 664;
	play->pos.y = 585;
	quit->pos.x = 1016;
	quit->pos.y = 585;
	htp->pos.x = 843;
	htp->pos.y = 454;
	return (0);
}

object_t *menu_scene_background(void)
{
	object_t *background = malloc(sizeof(*background));

	if (background == NULL)
		return (NULL);
	background->pos.x = 0;
	background->pos.y = 0;
	background->rect.height = 1080;
	background->rect.left = 0;
	background->rect.top = 0;
	background->rect.width = 1920;
	background->type = BG;
	return (background);
}

int menu_scene_lists(scene_t *menu, button_t *play,
		button_t *quit, button_t *htp)
{
	menu->buttons = list_init();
	menu->objects = list_init();
	if (menu->buttons == NULL || menu->objects == NULL)
		return (84);
	put_end_list(menu->buttons, play);
	put_end_list(menu->buttons, quit);
	put_end_list(menu->buttons, htp);
	return (0);
}

scene_t *menu_scene(game_t *game)
{
	scene_t *menu = malloc(sizeof(*menu));
	object_t *background;
	button_t *play = play_button(game);
	button_t *quit = quit_button(game);
	button_t *htp = htp_button(game);

	if (menu == NULL)
		return (NULL);
	if (menu_scene_init_buttons(play, quit, htp) == 84)
		return (NULL);
	background = menu_scene_background();
	background = create_object(background, game->atlas);
	play = create_button(play, game->atlas);
	quit = create_button(quit, game->atlas);
	htp = create_button(htp, game->atlas);
	if (play == NULL || quit == NULL || htp == NULL || background == NULL)
		return (NULL);
	if (menu_scene_lists(menu, play, quit, htp) == 84)
		return (NULL);
	put_end_list(menu->objects, background);
	return (menu);
}