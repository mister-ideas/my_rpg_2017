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
#include "particules.h"
#include "linked_list.h"

#define NB_SCENES 12
#define NB_SOUNDS 0

#define ATLAS_PATH "./ressources/img/atlas.png"
#define FONT_PATH "./ressources/font/XpressiveRegular.ttf"

enum TYPE {
	BG,
	TEXT,
	SLOT,
	MISC
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
	sfVector2f cur_pos;
	int clock_max;
} character_t;

typedef struct keys
{
	sfBool z;
	sfBool q;
	sfBool s;
	sfBool d;
	sfBool up;
	sfBool left;
	sfBool down;
	sfBool right;
	sfBool esc;
	sfBool space;
	sfBool shift;
	sfBool alt;
} keys_t;

typedef struct game
{
	scene_t **scenes;
	int current_scene;
	int last_scene;
	int current_weapon;
	int current_text;
	int doors;
	sfFont *font;
	sfMusic *sounds[NB_SOUNDS];
	sfImage *atlas;
	window_t *window;
	character_t *character;
	object_t *weapons;
	void *freeparticule;
	keys_t *keys;
} game_t;

typedef struct button
{
	sfVector2f pos;
	sfVector2f size;
	sfIntRect rect;
	sfIntRect hover;
	sfIntRect active;
	sfTexture *texture;
	sfRectangleShape *shape;
	void (*callback)(game_t *game);
} button_t;

extern const sfIntRect atlas_rect;

/* window.c */
int init_window(game_t *game, sfVideoMode video);
int display_window(game_t *game, particules_t *particules);
int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos);

/* events.c */
void game_events(game_t *game);
void check_doors(game_t *game);

/* scenes.c */
int set_scenes(game_t *game);

/* scenes */
scene_t *menu_scene(game_t *game);
scene_t *htp_scene(game_t *game);
scene_t *intro_scene(game_t *game);
scene_t *pause_scene(game_t *game);
scene_t *stats_inv_scene(game_t *game);
scene_t *win_scene(game_t *game);
scene_t *lose_scene(game_t *game);
scene_t *arena1_scene(game_t *game);
scene_t *arena2_scene(game_t *game);
scene_t *arena3_scene(game_t *game);
scene_t *arena4_scene(game_t *game);
scene_t *bossarena_scene(game_t *game);

/* buttons */
button_t *play_button(void);
button_t *quit_button(void);
button_t *htp_button(void);
button_t *resume_button(void);
button_t *return_button(void);

/* particules */
int particules_init(particules_t *particules, int type);
void particules_display(particules_t *particules, game_t *game, int type);

/* keys */
void init_keys(game_t *game);
void check_pressed_keys(game_t *game);
void check_released_keys(game_t *game);
int check_all_keys_released(game_t *game);

/* controls */
void bow_spell_walk(game_t *game);
void spear_walk(game_t *game);
void spell_attack(game_t *game);
void spear_attack(game_t *game);
void bow_attack(game_t *game);

/* objects */
void default_character(game_t *game);
int init_character(game_t *game);
void check_walls(game_t *game);
void character_clock(character_t *character);
void init_weapons(game_t *game);
void check_weapon(game_t *game);

/* display.c */
int display_game(game_t *game);

/* free.c */
void quit_game(game_t *game, particules_t *particules);

/* linked_list.c */
dll_t *list_init(void);
dll_t *put_end_list(dll_t *list, void *new);

/* buttons.c */
button_t *create_button(button_t *new, sfImage *img);

/* objects.c */
object_t *create_object(object_t *new, sfImage *img);

#endif
