/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** menu_scene.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

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

scene_t *menu_scene(sfImage *atlas)
{
	scene_t *menu = malloc(sizeof(*menu));
	button_t *play;
	button_t *quit;
	object_t *background;

	if (menu == NULL)
		return (NULL);
	play = menu_scene_play();
	quit = menu_scene_quit();
	background = menu_scene_background();
	if (play == NULL || quit == NULL || background == NULL)
		return (NULL);
	play = create_button(play, atlas);
	quit = create_button(quit, atlas);
	background = create_object(background, atlas);
	if (play == NULL || quit == NULL || background == NULL)
		return (NULL);
	menu->buttons = list_init();
	menu->objects = list_init();
	if (menu->buttons == NULL || menu->objects == NULL)
		return (NULL);
	put_end_list(menu->buttons, play);
	put_end_list(menu->buttons, quit);
	put_end_list(menu->objects, background);
	return (menu);
}
