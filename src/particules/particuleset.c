/*
** EPITECH PROJECT, 2018
** particuleset
** File description:
** particuleset.c
*/

#include"particules.h"

void updatepartbufferset(partBuffer *this,uint id)
{
	this ->vertex [(id * 4) + 0]. position.x += this->info[id].speed.x;
	this ->vertex [(id * 4) + 1]. position.x += this->info[id].speed.x;
	this ->vertex [(id * 4) + 2]. position.x += this->info[id].speed.x;
	this ->vertex [(id * 4) + 3]. position.x += this->info[id].speed.x;
	this ->vertex [(id * 4) + 0]. position.y += this->info[id].speed.y;
	this ->vertex [(id * 4) + 1]. position.y += this->info[id].speed.y;
	this ->vertex [(id * 4) + 2]. position.y += this->info[id].speed.y;
	this ->vertex [(id * 4) + 3]. position.y += this->info[id].speed.y;
	this ->vertex [(id * 4) + 0]. color.a
	= (int)(this ->info[id].life * 255.);
	this ->vertex [(id * 4) + 1].
	color.a = (int)(this ->info[id].life * 255.);
	this ->vertex [(id * 4) + 2].
	color.a = (int)(this ->info[id].life * 255.);
	this ->vertex [(id * 4) + 3].
	color.a = (int)(this ->info[id].life * 255.);

}
void drawPartBufer(partBuffer *this , sfRenderWindow *window)
{
	sfRenderWindow_drawPrimitives(window , this ->vertex
	, this ->size * 4, sfQuads , NULL);
}

void setPartv1(partBuffer *this , uint id , sfVector2f  pos)
{
	if (id  >= this ->size)
		return;
	this ->vertex [(id * 4) + 0]. position
		= (sfVector2f){pos.x + 0 , pos.y + 0};
	this ->vertex [(id * 4) + 1]. position
		= (sfVector2f){pos.x + 45, pos.y + 0};
	this ->vertex [(id * 4) + 2]. position
		= (sfVector2f){pos.x + 45, pos.y + 45};
	this ->vertex [(id * 4) + 3]. position
		= (sfVector2f){pos.x + 0, pos.y + 45};
	this ->vertex [(id * 4) + 0]. color = sfRed;
	this ->vertex [(id * 4) + 1]. color = sfMagenta;
	this ->vertex [(id * 4) + 2]. color = sfBlack;
	this ->vertex [(id * 4) + 3]. color = sfRed;
	this ->info[id]. speed.x = ((( float)(rand() % 255) / 255) - 0.5) *0.1;
	this ->info[id]. speed.y = ((( float)(rand() % 255) / 255) - 0.5) *0.1;
	this ->info[id].life = 1;
}

void setPartv2(partBuffer *this , uint id , sfVector2f  pos, sfColor  color)
{
	if (id  >= this ->size)
		return ;
	this ->vertex [(id * 4) + 0]. position =
		(sfVector2f){pos.x + 0 , pos.y + 0};
	this ->vertex [(id * 4) + 1]. position =
		(sfVector2f){pos.x + 45, pos.y + 0};
	this ->vertex [(id * 4) + 2]. position =
		(sfVector2f){pos.x + 45, pos.y + 45};
	this ->vertex [(id * 4) + 3]. position =
		(sfVector2f){pos.x + 0 , pos.y + 45};
	this ->vertex [(id * 4) + 0]. color = color;
	this ->vertex [(id * 4) + 1]. color = color;
	this ->vertex [(id * 4) + 2]. color = color;
	this ->vertex [(id * 4) + 3]. color = color;
	this ->info[id]. speed.x = ((( float)(rand() % 255) / 255) - 0.5) *0.1;
	this ->info[id]. speed.y = ((( float)(rand() % 255) / 255) - 0.5) *0.1;
	this ->info[id].life = 1;
}

void updatePartBuffer(partBuffer *this)
{
	for (uint id = 0; id < this ->size; id += 1)
	{
		if (this ->info[id].life  <= 0)
			continue;
		this ->info[id].life  -= 1/120.;
		if (this ->info[id].life  <= 0)
		{
			memset(this ->vertex +
			(id * 4), 0, sizeof(sfVertex) * 4);
			continue;
		}
		for (uint id = 0; id < this ->size; id += 1)
		{
			updatepartbufferset(this,id);
		}
	}
}
