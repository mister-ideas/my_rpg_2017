/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "linked_list.h"

#define NB_SCENES 0
#define NB_SOUNDS 0

#define ATLAS_PATH "./ressources/img/atlas.png"
#define FONT_PATH "./ressources/font/XpressiveRegular.ttf"

typedef struct window
{
	sfRenderWindow *window;
	sfEvent event;
	sfVideoMode mode;
	sfVector2i mouse_pos;
} window_t;

typedef struct scene
{
	dll_t *buttons;
	dll_t *objects;
} scene_t;

typedef struct game
{
	scene_t **scenes;
	int current_scene;
	sfFont *font;
	sfMusic *sounds[NB_SOUNDS];
	sfImage *atlas;
	window_t *window;
} game_t;

/* window.c */
int init_window(game_t *game, sfVideoMode video);

/* scenes.c */
int set_scenes(game_t *game);
	
#endif
