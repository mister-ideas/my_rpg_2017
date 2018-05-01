/*
** EPITECH PROJECT, 2018
** particuleinit
** File description:
** particuleinit.c
*/


#include"particules.h"
partBuffer *newPartBuffer(int  size)
{
	partBuffer     *this;
	const  size_t   size_m = (sizeof(partBuffer) +
				  sizeof(sfVertex) * size * 4 +
				  sizeof(t_info) * size);
	void *ptn = malloc(size_m);
	if (ptn == NULL)
		return (NULL);
	memset(ptn , 0, size_m);
	this = (partBuffer *)(ptn);
	this ->size = size;
	this ->vertex = (sfVertex *)(ptn + sizeof(partBuffer));
	this ->info = (t_info *)(this ->vertex + (size * 4));
	return (this);
}

static uint newPart(partBuffer *this)
{
	for (uint id = this ->size - 1; id != 0; id  -= 1)
		if (this ->info[id].life  <= 0)
			return  (id);
	return ((uint)(-1));
}

int init(int type)
{
	int nb_particule = 1000;

	if (window == NULL)
		return (0);
	sfRenderWindow_setFramerateLimit(window , 120);
	buffer = newPartBuffer (nb_particule);
	if (buffer  == NULL)
		return  (0);
	for (uint i = 0; i < nb_particule; i += 1) {
		if (type == 1)
			setPartv1(buffer , i,(sfVector2f)
			{250+(rand() %150-75), 250+(rand() % 150 -75)});
		if (type == 2)
			setPartv2(buffer , i, (sfVector2f){250+(rand()
			% 150-75),250+(rand() % 150 -75)},(sfColor){rand()
			% 255,rand()% 255, rand() % 255, 255});
		}
	return (1);
}

void particule (int type)
{
	updatePartBuffer(buffer);
	for (int i = 0; i < 10; i += 1)
	{
		uint id = newPart(buffer);
		if (id == (uint)(-1))
			break;
		if(type == 1)
			setPartv1(buffer , id , (sfVector2f){250, 250});
		if(type == 2)
			setPartv2(buffer , id , (sfVector2f){250, 250},
				(sfColor){rand() % 255, rand()
				% 255, rand() % 255, 255});
	}
	sfRenderWindow_clear(window , sfBlack);
	drawPartBufer(buffer , window);
	sfRenderWindow_display(window);
}

int particuletype(int type)
{
	if (init(type) == 0)
		return (1);
	particule(type);
	return (0);
}
