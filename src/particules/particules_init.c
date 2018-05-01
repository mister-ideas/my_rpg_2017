/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** particules_init.c
*/

#include "particules.h"

partBuffer *new_part_buffer(int size)
{
	partBuffer *this;
	const size_t size_m = (sizeof(partBuffer) +
	sizeof(sfVertex) * size * 4 +
	sizeof(t_info) * size);
	void *ptn = malloc(size_m);

	if (ptn == NULL)
		return (NULL);
	memset(ptn, 0, size_m);
	this = (partBuffer *)(ptn);
	this->size = size;
	this->vertex = (sfVertex *)(ptn + sizeof(partBuffer));
	this->info = (t_info *)(this->vertex + (size * 4));
	return (this);
}

uint new_part(partBuffer *this)
{
	for (uint id = this->size - 1; id != 0; id -= 1)
		if (this->info[id].life <= 0)
			return (id);
	return ((uint)(-1));
}

int particules_init(int type)
{
	uint nb_particules = 1000;

	if (window == NULL)
		return (0);
	sfRenderWindow_setFramerateLimit(window, 60);
	buffer = new_part_buffer(nb_particules);
	if (buffer == NULL)
		return (0);
	for (uint i = 0; i < nb_particules; i += 1) {
		if (type == 1)
			set_part_v1(buffer, i, (sfVector2f)
			{250 + (rand() %150 - 75), 250 + (rand() % 150 - 75)});
		if (type == 2)
			set_part_v2(buffer, i, (sfVector2f){250 + (rand()
			% 150 - 75), 250 + (rand() % 150 - 75)},
			(sfColor){rand() % 255, rand()% 255,
			rand() % 255, 255});
	}
	return (1);
}

void particules(int type)
{
	uint id;

	update_part_buffer(buffer);
	for (int i = 0; i < 10; i += 1) {
		id = new_part(buffer);
		if (id == (uint)(-1))
			break;
		if (type == 1)
			set_part_v1(buffer, id, (sfVector2f){250, 250});
		if (type == 2)
			set_part_v2(buffer, id, (sfVector2f){250, 250},
			(sfColor){rand() % 255, rand()
			% 255, rand() % 255, 255});
	}
	sfRenderWindow_clear(window, sfBlack);
	draw_part_buffer(buffer, window);
	sfRenderWindow_display(window);
}

int particules_type(int type)
{
	if (particules_init(type) == 0)
		return (1);
	particules(type);
	return (0);
}
