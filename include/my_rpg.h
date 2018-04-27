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

#define NB_SCENES 9
#define NB_SOUNDS 0

#define ATLAS_PATH "./ressources/img/atlas.png"
#define FONT_PATH "./ressources/font/XpressiveRegular.ttf"

enum TYPE {
	BG,
	CHAR,
	MISC
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

typedef struct clock
{
	sfClock *clock;
	sfTime time;
	float seconds;
} my_clock_t;

typedef struct object
{
	enum TYPE type;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rect;
} object_t;

typedef struct character
{
	object_t *char_obj;
	my_clock_t *char_clock;
	sfVector2f move;
	int clock_max;
} character_t;

typedef struct game
{
	scene_t **scenes;
	int current_scene;
	int last_scene;
	int current_weapon;
	sfFont *font;
	sfMusic *sounds[NB_SOUNDS];
	sfImage *atlas;
	window_t *window;
	character_t *character;
} game_t;

typedef struct button
{
	sfVector2f pos;
	sfVector2f size;
	sfIntRect rect;
	sfIntRect hover;
	sfIntRect active;
	sfTexture *texture;
	enum STATUS state;
	sfRectangleShape *shape;
	void (*callback)(game_t *game);
} button_t;

extern const sfIntRect atlas_rect;

/* window.c */
int init_window(game_t *game, sfVideoMode video);
int display_window(game_t *game);
int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos);

/* events.c */
void game_events(game_t *game);

/* scenes.c */
int set_scenes(game_t *game);

/* scenes */
scene_t *menu_scene(game_t *game);
scene_t *htp_scene(game_t *game);
scene_t *intro_scene(game_t *game);
scene_t *pause_scene(game_t *game);
scene_t *arena1_scene(game_t *game);
scene_t *arena2_scene(game_t *game);
scene_t *arena3_scene(game_t *game);
scene_t *arena4_scene(game_t *game);
scene_t *boss_scene(game_t *game);

/* buttons */
button_t *play_button(game_t *game);
button_t *quit_button(game_t *game);
button_t *htp_button(game_t *game);
button_t *resume_button(game_t *game);
button_t *return_button(game_t *game);

/* controls/controls_bow_spell_walk.c */
void bow_spell_walk_z(game_t *game);
void bow_spell_walk_q(game_t *game);
void bow_spell_walk_s(game_t *game);
void bow_spell_walk_d(game_t *game);

/* objects/character.c */
int character_init(game_t *game);
void character_clock(game_t *game, character_t *character);

/* display.c */
int display_game(game_t *game);

/* free.c */
void quit_game(game_t *game);

/* linked_list.c */
dll_t *list_init(void);
dll_t *put_end_list(dll_t *list, void *new);

/* buttons.c */
button_t *create_button(button_t *new, sfImage *img);

/* objects.c */
object_t *create_object(object_t *new, sfImage *img);

#endif
