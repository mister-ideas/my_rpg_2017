/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
	void *data;
	struct node *next;
	struct node *prev;
};

typedef struct linked_list {
	int lenght;
	struct node *start;
	struct node *end;
} dll_t;

dll_t *list_init(void);
dll_t *put_end_list(dll_t *list, void *new);

#endif
