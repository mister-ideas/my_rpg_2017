/*
** EPITECH PROJECT, 2018
** rpg_text
** File description:
** rpg_text.c
*/

#include <SFML/Graphics/Color.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>


typedef struct my_text{
	// »       sfRenderWindow·*window;$ »       sfVideoMode·video_mode; »       sfEvent·event;$    servent juste pour le main 

	sfRenderWindow *window;
	sfVideoMode video_mode;
	sfVector2f positionstext;
	int lvlint;
	sfFont* font;
	sfEvent event;
	sfText* text;
}text;


void init_text(text *new)
{
	new->font = sfFont_createFromFile("arial.ttf");
	new->text = sfText_create();
	sfText_setCharacterSize(new->text,25);
	sfText_setFont(new->text,new->font);
}

void initwindow(text *new)
{
	new->video_mode.width = 1920;
	new->video_mode.height = 1080;
	new->video_mode.bitsPerPixel = 32;
	new->window =sfRenderWindow_create				\
		(new->video_mode,"MyWindow",sfDefaultStyle,NULL);
	new->font = sfFont_createFromFile("arial.ttf");
	new->text = sfText_create();
	sfText_setCharacterSize(new->text,25);
	sfText_setFont(new->text,new->font);
	new->lvlint = 0;
}

void dialogue(char **textmenu)
{
	textmenu[0] = "Dans une contree lointaine un jeune aventurier\
 et son maitre s'appretent a rentrer dans un donjon.";
	textmenu[1] = "Maitre : Mon jeune apprenti soit prudent\
les accidents arrives souvent au premier donjon solo.";
	textmenu[2] = "Apprenti : ne vous inquitez pas, je serai prudent ";
	textmenu[3] = "Maitre : Parfait, ton ojectif\
 est de trouver l'epee legendaire";
	textmenu[4] = "Apprendti : Tres bien";
	textmenu[5] = "Maitre : Courage et que la force soit avec toi";
	textmenu[6] = "Apprenti : YOSHHHH";
}

void positiondialogue(text *new,char **textmenu)
{
	new->positionstext.x = 220;
	new->positionstext.y = 775;
	sfText_setColor(new->text,sfWhite);
	sfText_setPosition(new->text,new->positionstext);
	sfText_setString(new->text,textmenu[new->lvlint]);
}

void introtext(text * new)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
		 new->lvlint = new->lvlint + 1;
		 while (1) {
			 if (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse) {
				 break;
			 }
		 }
	}
	char **textmenu;
	textmenu = malloc(sizeof(char *) * 8);
	for (int i = 0;i < 7;i++){
		textmenu[i] = malloc(sizeof(char) * (102 + 3));
		textmenu[i][102 + 2] = '\0';
	}
	dialogue(textmenu);
	positiondialogue(new,textmenu);
	sfRenderWindow_drawText(new->window, new->text, NULL);
}

/*

int main()
{
        text new;
        initwindow(&new);
	while (sfRenderWindow_isOpen(new.window)) {
                while (sfRenderWindow_pollEvent(new.window,&new.event)) {
                        if (new.event.type == sfEvtClosed)
                                sfRenderWindow_close(new.window);
                }
		sfRenderWindow_clear(new.window,sfBlack);
		 if (new.lvlint > 5)
			 return (1);

                introtext(&new);
                sfRenderWindow_display(new.window);
	}
        return (0);
}
/*
