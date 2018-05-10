/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** particules_init.c
*/

#include "my_rpg.h"

partBuffer_t *partbuffer_init(int size)
{
	partBuffer_t *this;
	const size_t size_m = (sizeof(partBuffer_t) +
	sizeof(sfVertex) * size * 4 +
	sizeof(info_t) * size);
	void *ptr = malloc(size_m);

	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, size_m);
	this = (partBuffer_t *)(ptr);
	this->size = size;
	this->vertex = (sfVertex *)(ptr + sizeof(partBuffer_t));
	this->info = (info_t *)(this->vertex + (size * 4));
	return (this);
}

uint new_part(partBuffer_t *this)
{
	for (uint id = this->size - 1; id; id -= 1)
		if (this->info[id].life <= 0)
			return (id);
	return ((uint)(-1));
}

int init_particules(particules_t *particules, int type)
{
	int part_nb = 100;

	particules->buffer = partbuffer_init(part_nb);
	if (particules->buffer == NULL)
		return (1);
	for (int i = 0; i <= part_nb; i += 1) {
		if (type == 1)
			set_part_type1(particules->buffer, i,
			(sfVector2f){10, 10});
		if (type == 2)
			set_part_type2(particules->buffer, i,
			(sfVector2f){250, 250},
			(sfColor){rand() % 255, rand() % 255,
			rand() % 255, 255});
	}
	return (0);
}

void display_particules(particules_t *particules, game_t *game, int type)
{
	uint id;

	update_partbuffer(particules->buffer);
	for (int i = 0; i < 10; i += 1) {
		id = new_part(particules->buffer);
		if (id == (uint)(-1))
			break;
		if (type == 1)
			set_part_type1(particules->buffer, id,
			(sfVector2f){10, 10});
		if (type == 2)
			set_part_type2(particules->buffer, id,
			(sfVector2f){250, 250},
			(sfColor){rand() % 255, rand() % 255,
			rand() % 255, 255});
	}
	draw_partbuffer(particules->buffer, game->window->window);
}
