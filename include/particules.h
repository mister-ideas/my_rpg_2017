/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** particules.h
*/

#include <string.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

typedef unsigned int uint;

typedef struct info_s
{
	float life;
	sfVector2f speed;
} info_t;

typedef struct partBuffer_s
{
	sfVertex *vertex;
	uint size;
	info_t *info;
} partBuffer_t;

typedef struct particules_s
{
	partBuffer_t *buffer;
} particules_t;

uint new_part(partBuffer_t *this);
partBuffer_t *partbuffer_init(int size);
void set_part_type1(partBuffer_t *this, uint id, sfVector2f pos);
void set_part_type2(partBuffer_t *this, uint id, sfVector2f pos, sfColor color);
void draw_partbuffer(partBuffer_t *this, sfRenderWindow *window);
void update_partbuffer(partBuffer_t *this);
void update_partbuffer_set(partBuffer_t *this, uint id);
