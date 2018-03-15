/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scenes.c
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"

scene_t **set_scenes(void)
{
	scene_t **scenes = malloc(sizeof(scene_t *) * SCENES_NB);
	sfImage *atlas = sfImage_create(3840, 3467);

	atlas = sfImage_createFromFile(ATLAS_PATH);
	if (scenes == NULL || atlas == NULL)
		return (NULL);
	//scenes[0] = scene_name(atlas);
	//if (scenes[0] == NULL)
		return (NULL);
	return (scenes);
}
