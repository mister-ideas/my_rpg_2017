/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** mainc.c
*/

#include <SFML/Graphics.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct s_info
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

static uint newPart(partBuffer *this);

partBuffer *newPartBuffer(int size)
{
	partBuffer *this;
	const size_t size_m = (sizeof(partBuffer) +
				sizeof(sfVertex) * size * 4 +
				sizeof(t_info) * size);
	void *ptn = malloc(size_m);

	if (ptn == NULL)
		return (NULL);
	memset(ptn , 0, size_m);
	this = (partBuffer *)(ptn);
	this->size = size;
	this->vertex = (sfVertex *)(ptn + sizeof(partBuffer));
	this->info = (t_info *)(this ->vertex + (size * 4));
	return (this);
}

void setPart(partBuffer *this , uint id , sfVector2f  pos , sfColor  color)
{
	if (id >= this->size)
		return ;
	this->vertex[(id * 4) + 0].position = (sfVector2f){pos.x + 0, pos.y + 0};
	this->vertex[(id * 4) + 1].position = (sfVector2f){pos.x + 30, pos.y + 0};
	this->vertex[(id * 4) + 2].position = (sfVector2f){pos.x + 30, pos.y + 30};
	this->vertex[(id * 4) + 3].position = (sfVector2f){pos.x + 0, pos.y + 30};
	this->vertex[(id * 4) + 0].color = color;
	this->vertex[(id * 4) + 1].color = color;
	this->vertex[(id * 4) + 2].color = color;
	this->vertex[(id * 4) + 3].color = color;
	this->info[id].speed.x = (((float)(rand() % 255) / 255) - 0.5) * 0.1;
	this->info[id].speed.y = (((float)(rand() % 255) / 255) - 0.5) * 0.1;
	this->info[id].life = 1;
}

void drawPartBufer(partBuffer *this, sfRenderWindow *window)
{
	sfRenderWindow_drawPrimitives(window, this->vertex, this->size * 4, sfQuads, NULL);
}

int init(void)
{
	int w = 500;
	int h = 500;
	int nb_particule = 1000;
	window = sfRenderWindow_create((sfVideoMode){w, h, 32},
					"Test", sfResize | sfClose , NULL);
	if (window  == NULL)
		return  (0);
	sfRenderWindow_setFramerateLimit(window, 120);
	buffer = newPartBuffer(nb_particule);
	if (buffer == NULL)
		return (0);
	for (uint i = 0; i < nb_particule; i += 1)
		setPart(buffer, i, (sfVector2f){250 + (rand() % 150 - 75),
		250 + (rand() % 150 - 75)}, (sfColor){rand() % 255,
		rand() % 255, rand() % 255, 255});
	return (1);
}

void updatePartBuffer(partBuffer *this)
{
	for (uint id = 0; id < this->size; id += 1) {
		if (this->info[id].life <= 0)
			continue;
		this->info[id].life -= 1/120.;
		if (this->info[id].life <= 0) {
			memset(this->vertex + (id * 4), 0, sizeof(sfVertex) * 4);
			continue;
		}
		for (uint id = 0; id < this ->size; id += 1) {
			this->vertex[(id * 4) + 0].position.x += this->info[id].speed.x;
			this->vertex[(id * 4) + 1].position.x += this->info[id].speed.x;
			this->vertex[(id * 4) + 2].position.x += this->info[id].speed.x;
			this->vertex[(id * 4) + 3].position.x += this->info[id].speed.x;
			this->vertex[(id * 4) + 0].position.y += this->info[id].speed.y;
			this->vertex[(id * 4) + 1].position.y += this->info[id].speed.y;
			this->vertex[(id * 4) + 2].position.y += this->info[id].speed.y;
			this->vertex[(id * 4) + 3].position.y += this->info[id].speed.y;
			this->vertex[(id * 4) + 0].color.a = (int)(this->info[id].life * 255);
			this->vertex[(id * 4) + 1].color.a = (int)(this->info[id].life * 255);
			this->vertex[(id * 4) + 2].color.a = (int)(this->info[id].life * 255);
			this->vertex[(id * 4) + 3].color.a = (int)(this->info[id].life * 255);
		}
	}
}

void update(void)
{
	updatePartBuffer(buffer);
	for (int i = 0; i < 10; i += 1) {
		uint id = newPart(buffer);
		if (id == (uint)(-1))
			break;
		setPart(buffer, id, (sfVector2f){250, 250},
		(sfColor){rand() % 255, rand() % 255,
		rand() % 255, 255});
	}
	sfRenderWindow_clear(window, sfBlack);
	drawPartBufer(buffer, window);
	sfRenderWindow_display(window);
}

static uint newPart(partBuffer *this)
{
	for (uint id = this->size - 1; id != 0; id -= 1)
		if (this->info[id].life <= 0)
			return (id);
	return ((uint)(-1));
}

int main(void)
{
	sfEvent event;

	if (init() == 0)
		return (1);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed) {
				sfRenderWindow_close(window);
				return (0);
			}
		}
		update();
	}
	return (0);
}
