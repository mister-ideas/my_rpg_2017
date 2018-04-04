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

enum TYPE {
	BG,
	MISC,
	ANIM
};

enum STATUS {
	ACTIVE,
	OFF
};

typedef struct window
{
	sfRenderWindow *window;
	sfEvent event;
	sfVector2i mouse_pos;
	int click;
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

typedef struct object
{
	enum TYPE type;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rectangle;
} object_t;

typedef struct button
{
	sfVector2f pos;
	sfVector2f size;
	sfIntRect rect;
	sfIntRect push_rect;
	sfTexture *texture;
	enum STATUS state;
	sfRectangleShape *shape;
	void (*callback)(struct button*, game_t*);
} button_t;

/* window.c */
int init_window(game_t *game, sfVideoMode video);
int display_window(game_t *game);
int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos);

/* scenes.c */
int set_scenes(game_t *game);

/* display.c */
int display_game(game_t *game);

/* free.c */
void quit_game(game_t *game);

#endif
