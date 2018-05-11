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
#define NB_MOBS 4
#define NB_SOUNDS 0

#define ATLAS_PATH "./ressources/img/atlas.png"
#define FONT_PATH "./ressources/font/XpressiveRegular.ttf"

enum TYPE {
	BG,
	ARROW_UP,
	ARROW_LEFT,
	ARROW_DOWN,
	ARROW_RIGHT,
	SPELL_UP,
	SPELL_LEFT,
	SPELL_DOWN,
	SPELL_RIGHT,
	TEXT,
	SFTEXT,
	SLOT,
	MISC
};

typedef struct window_s
{
	sfRenderWindow *window;
	sfEvent event;
	sfVector2i mouse_pos;
	int click;
} window_t;

typedef struct scene_s
{
	dll_t *buttons;
	dll_t *objects;
	int mobs_nb;
	int kills;
} scene_t;

typedef struct clock_s
{
	sfClock *clock;
	sfTime time;
	float seconds;
} my_clock_t;

typedef struct object_s
{
	enum TYPE type;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfIntRect rect;
} object_t;

typedef struct character_s
{
	object_t *char_obj;
	my_clock_t *char_clock;
	int clock_max;
	sfVector2f move;
	sfVector2f cur_pos;
	int health;
	int attack;
	int defense;
	int speed;
	int level;
	int exp;
} character_t;

typedef struct mob_s
{
	object_t *mob_obj;
	my_clock_t *mob_clock;
	sfVector2f move;
	sfVector2f cur_pos;
	int health;
} mob_t;

typedef struct texts_s
{
	sfText *health;
	sfText *attack;
	sfText *defense;
	sfText *speed;
	sfText *level;
} texts_t;

typedef struct keys_s
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

typedef struct game_s
{
	scene_t **scenes;
	mob_t **mobs;
	sfMusic *sounds[NB_SOUNDS];
	int current_scene;
	int last_scene;
	int current_weapon;
	int current_text;
	sfFont *font;
	sfImage *atlas;
	sfTexture *texture;
	window_t *window;
	character_t *character;
	object_t *weapons;
	texts_t *texts;
	keys_t *keys;
} game_t;

typedef struct button_s
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

/* events.c */
void game_events(game_t *game);
void check_doors(game_t *game);
void reset_map(game_t *game, sfVector2f pos);

/* scene.c */
int set_scenes(game_t *game);

/* mob.c */
int set_mobs(game_t *game);

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

/* tools */
void check_kill(game_t *game, int i);
int check_collision(object_t *obj, sfVector2f obj_pos,
		sfVector2f mob_pos);
void check_button_state(button_t *but, game_t *game, int in_area);
int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos);
void int_to_text(int num, char str[]);

/* buttons */
button_t *play_button(void);
button_t *quit_button(void);
button_t *htp_button(void);
button_t *resume_button(void);
button_t *return_button(void);

/* particules */
int init_particules(particules_t *particules, int type);
void display_particules(particules_t *particules, game_t *game, int type);

/* keys */
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

int init_texts(game_t *game);
void update_text(game_t *game, sfText *text, char str[], sfVector2f pos);
void check_text_type(game_t *game, object_t *data);

mob_t *init_mob(mob_t *mob);
void mob_clock(mob_t *mob);

int add_arrow_up(game_t *game, dll_t *list);
int add_arrow_left(game_t *game, dll_t *list);
int add_arrow_down(game_t *game, dll_t *list);
int add_arrow_right(game_t *game, dll_t *list);

void check_arrow_type(object_t *data, sfVector2f cur_pos);

int add_spell_up(game_t *game, dll_t *list);
int add_spell_left(game_t *game, dll_t *list);
int add_spell_down(game_t *game, dll_t *list);
int add_spell_right(game_t *game, dll_t *list);

void check_spell_type(object_t *data, sfVector2f cur_pos);

void delete_projectile(object_t *data);
void check_projectile_hit(game_t *game, object_t *data, sfVector2f cur_pos);
int check_spear(game_t *game, int i);

/* display.c */
void display_game(game_t *game);

/* free.c */
void quit_game(game_t *game, particules_t *particules);

/* linked_list.c */
dll_t *list_init(void);
dll_t *put_end_list(dll_t *list, void *new);

/* buttons.c */
button_t *create_button(button_t *new, game_t *game);

/* objects.c */
object_t *create_object(object_t *new, game_t *game);

#endif
