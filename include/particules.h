/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** particules.h
*/

#pragma once
#include <SFML/Graphics.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct info
{
	float life;
	sfVector2f speed;
} t_info;

typedef struct s_partBuffer
{
	sfVertex *vertex;
	uint size;
	t_info *info;
} partBuffer;

partBuffer *buffer;
sfRenderWindow *window;

uint new_part(partBuffer *this);
partBuffer *new_part_buffer(int  size);
void set_part_v1(partBuffer *this, uint id, sfVector2f pos);
void set_part_v2(partBuffer *this, uint id, sfVector2f pos, sfColor color);
void draw_part_buffer(partBuffer *this, sfRenderWindow *window);
int particules_init(int type);
int particules_type(int type);
void update_part_buffer(partBuffer *this);
void update_part_buffer_set(partBuffer *this, uint id);
