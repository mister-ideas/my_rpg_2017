/*
** EPITECH PROJECT, 2018
** particules
** File description:
** particules.h
*/

#include <string.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_rpg.h"

typedef  unsigned  int  uint;
typedef  struct   s_info
{
        float           life;
        sfVector2f     speed;
} t_info;

typedef  struct   s_partBuffer
{
        sfVertex       *vertex;
        uint            size;
        t_info          *info;
} partBuffer;

partBuffer   *buffer;

static uint newPart(partBuffer *this);
partBuffer *newPartBuffer(int  size);
void setPartv1(partBuffer *this , uint id , sfVector2f  pos);
void setPartv2(partBuffer *this , uint id , sfVector2f  pos, sfColor  color);
void drawPartBufer(partBuffer *this , sfRenderWindow *window);
int init(int type);
void particule (int type,game_t *game);
void updatePartBuffer(partBuffer *this);
void updatepartbufferset(partBuffer *this,uint id);

