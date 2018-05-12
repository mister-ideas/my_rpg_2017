/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** sounds.c
*/

#include <stdio.h>
#include "my_rpg.h"

static int init_effect(game_t *game, char *path, int i)
{
	game->buffer = sfSoundBuffer_createFromFile(path);
	if (game->buffer == NULL)
		return (84);
	sfSound_setBuffer(game->sounds[i], game->buffer);
	return (0);
}

static int init_effects(game_t *game)
{
	if (init_effect(game, CHARACTER_HIT_S, 0) == 84)
		return (84);
	if (init_effect(game, EMPTY_SCENE_S, 1) == 84)
		return (84);
	if (init_effect(game, MOB_HIT_S, 2) == 84)
		return (84);
	if (init_effect(game, POWERUP_S, 3) == 84)
		return (84);
	if (init_effect(game, SPELL_S, 4) == 84)
		return (84);
	return (0);
}

static int init_musics(game_t *game)
{
	game->musics[0] = sfMusic_createFromFile(BOSS_SCENE_S);
	game->musics[1] = sfMusic_createFromFile(END_GAME_S);
	game->musics[2] = sfMusic_createFromFile(INTRO_SCENE_S);
	game->musics[3] = sfMusic_createFromFile(MENU_SCENE_S);
	game->musics[4] = sfMusic_createFromFile(MOB_SCENE_S);
	for (int i = 0; i < NB_MUSICS; i++) {
		if (game->musics[i] == NULL)
			return (84);
	}
	return (0);
}

int init_sounds(game_t *game)
{
	for (int i = 0; i < NB_SOUNDS; i++) {
		game->sounds[i] = sfSound_create();
		if (game->sounds[i] == NULL)
			return (84);
	}
	if (init_effects(game) == 84)
		return (84);
	if (init_musics(game) == 84)
		return (84);
	return (0);
}
