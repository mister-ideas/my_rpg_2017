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
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "linked_list.h"
#include "my.h"

#define SCENES_NB 1
#define INIT_FILE "./src/init.txt"
#define ATLAS_PATH "./ressources/img/atlas.png"
#define FONT_PATH "./ressources/font/XpressiveRegular.ttf"

typedef struct game game_t;
extern const sfIntRect atlas_rect;

enum TYPE {
	BG,
};

enum STATUS {
	ACTIVE,
	NON_ACTIVE,
	OFF,
	MOUSE_ON,
	LAUNCH,
};

typedef struct scene_s
{
	dll_t *buttons;
	dll_t *objects;
} scene_t;

typedef struct window
{
	sfRenderWindow *window;
	sfEvent event;
	sfVideoMode mode;
	sfVector2i mouse_pos;
	int is_clicked;
} window_t;

typedef struct object
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rect;
	enum TYPE type;
} object_t;

typedef struct game
{
	struct scene_s **scenes;
	int current_scene;
	sfFont *font;
	sfImage *atlas;
	window_t *window;
} game_t;

typedef struct button
{
	void (*callback)(struct button *, game_t *);
	sfIntRect rect;
	sfIntRect push_rect;
	sfVector2f pos;
	sfVector2f size;
	sfTexture *texture;
	sfRectangleShape *shape;
	enum STATUS state;
} button_t;

struct button_compo
{
	void (*function)(button_t *, game_t *);
	sfIntRect rect;
	sfIntRect push_rect;
	sfVector2f size;
	sfVector2f pos;
};

/* buttons.c */

float get_vect_info(FILE *fd, size_t *size);
void set_button_pos(FILE *fd, size_t size, struct button_compo *new);
struct button_compo *compo_from_file(char const *name,
				void (*function)(button_t *, game_t *));
button_t *create_button(struct button_compo *component, sfImage *img);
void display_button(dll_t *buttons, window_t *window);

/* display.c */

void display_buttons(struct node *button, game_t *game);
void display_objects(struct node *obj, game_t *game);
int display(game_t *game);

/* end_game.c */

void destroy_scene(scene_t *scene);
void quit_game(game_t *game);

/* linked_list.c */

dll_t *list_init(void);
dll_t *put_end_list(dll_t *list, void *new);
void find_data(dll_t *list, void *elem, struct node *find, struct node *temp);
dll_t *delete_data(dll_t *list, void *elem);
void remove_end_list(dll_t *list);

/* my_rpg.c */

game_t *init_game(scene_t **scenes, window_t *window);

/* scenes.c */

scene_t **set_scenes(void);

/* window.c */

int mouse_is_in_area(sfVector2f pos, sfVector2f size, sfVector2i clickPos);
window_t *create_window(sfVideoMode video_size);
int game_events(game_t *game);
int display_window(game_t *game);

#endif
