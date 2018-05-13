/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** particules.h
*/

typedef unsigned int uint;

typedef struct info_s
{
	float life;
	sfVector2f speed;
} info_t;

typedef struct partbuffer_s
{
	sfVertex *vertex;
	uint size;
	info_t *info;
} partbuffer_t;

typedef struct particules_s
{
	partbuffer_t *buffer;
} particules_t;

uint new_part(partbuffer_t *this);
partbuffer_t *partbuffer_init(int size);
void set_part_type1(partbuffer_t *this, uint id, sfVector2f pos);
void set_part_type2(partbuffer_t *this, uint id, sfVector2f pos, sfColor color);
void draw_partbuffer(partbuffer_t *this, sfRenderWindow *window);
void update_partbuffer(partbuffer_t *this);
void update_partbuffer_set(partbuffer_t *this, uint id);
