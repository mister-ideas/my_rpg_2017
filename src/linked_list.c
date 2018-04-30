/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** linked_list.c
*/

#include <stdlib.h>
#include "linked_list.h"

dll_t *list_init(void)
{
	dll_t *list = malloc(sizeof(*list));

	if (list != NULL) {
		list->nb_elems = 0;
		list->end = NULL;
		list->start = NULL;
	}
	return (list);
}

dll_t *put_end_list(dll_t *list, void *new)
{
	struct node *new_data = malloc(sizeof(*new_data));

	if (new_data != NULL) {
		new_data->data = new;
		new_data->next = NULL;
		if (list->end == NULL) {
			new_data->prev = NULL;
			list->start = new_data;
			list->end = new_data;
		} else {
			list->end->next = new_data;
			new_data->prev = list->end;
			list->end = new_data;
		}
		list->nb_elems++;
	}
	return (list);
}
