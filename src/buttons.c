/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_rpg.h"

float get_vect_info(FILE *fd, size_t *size)
{
	char *info_str = NULL;
	int len = 0;
	int nb = 0;
	int i = 0;

	if (getline(&info_str, size, fd) == -1)
		return (-1);
	len = my_strlen(info_str);
	info_str[len - 1] = '\0';
	for (; info_str[i] < '0' || info_str[i] > '9'; i++);
	info_str += i;
	nb = my_getnbr(info_str);
	free(info_str - i);
	return (nb);
}

void set_button_pos(FILE *fd, size_t size, struct button_compo *new)
{
	new->pos.x = get_vect_info(fd, &size);
	new->pos.y = get_vect_info(fd, &size);
	new->size.x = get_vect_info(fd, &size);
	new->size.y = get_vect_info(fd, &size);
	new->rect.height = get_vect_info(fd, &size);
	new->rect.left = get_vect_info(fd, &size);
	new->rect.top = get_vect_info(fd, &size);
	new->rect.width = get_vect_info(fd, &size);
	new->push_rect.height = get_vect_info(fd, &size);
	new->push_rect.left = get_vect_info(fd, &size);
	new->push_rect.top = get_vect_info(fd, &size);
	new->push_rect.width = get_vect_info(fd, &size);
}

struct button_compo *compo_from_file(char const *name,
				void (*function)(button_t *, game_t *))
{
	struct button_compo *new = malloc(sizeof(struct button_compo));
	char *infos = NULL;
	size_t size = 0;
	FILE *fd;
	int len = 0;

	if (new == NULL)
		return (NULL);
	fd = fopen(INIT_FILE, "r");
	do {
		getline(&infos, &size, fd);
		len = my_strlen(infos);
		infos[len - 1] = '\0';
	} while (my_strcmp(infos, name) != 0);
	new->function = function;
	set_button_pos(fd, size, new);
	fclose(fd);
	return (new);
}

button_t *create_button(struct button_compo *component, sfImage *img)
{
	button_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->pos = component->pos;
	new->rect = component->rect;
	new->push_rect = component->push_rect;
	new->callback = component->function;
	new->size = component->size;
	new->texture = sfTexture_createFromImage(img, &atlas_rect);
	new->state = OFF;
	if (new->texture == NULL)
		return (NULL);
	if ((new->shape = sfRectangleShape_create()) == NULL)
		return (NULL);
	sfRectangleShape_setTexture(new->shape, new->texture, sfTrue);
	sfRectangleShape_setTextureRect(new->shape, new->rect);
	sfRectangleShape_setSize(new->shape, component->size);
	sfRectangleShape_setPosition(new->shape, component->pos);
	free(component);
	return (new);
}

void display_button(dll_t *buttons, window_t *window)
{
	struct node *button = buttons->start;
	button_t *ok;

	while (button != NULL) {
		ok = (button_t *)button->data;
		sfRenderWindow_drawRectangleShape(window->window,
						ok->shape, NULL);
		button = button->next;
	}
}
