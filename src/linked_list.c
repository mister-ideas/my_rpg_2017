/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** linked_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

dll_t *list_init(void)
{
	dll_t *list = malloc(sizeof(*list));

	if (list != NULL) {
		list->lenght = 0;
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
		list->lenght++;
	}
	return (list);
}

void find_data(dll_t *list, void *elem, struct node *find, struct node *temp)
{
	while (find != NULL && find->data != elem)
		find = find->next;
	if (find->data == elem && find->next != NULL && find->prev != NULL) {
		temp = find;
		find = find->prev;
		find->next = temp->next;
		temp->next->prev = find;
		free(temp);
	} else if (find->data == elem && find->next == NULL &&
		find->prev != NULL) {
		temp = find;
		find = find->prev;
		find->next = temp->next;
		list->end = find;
		free(temp);
	}
}

dll_t *delete_data(dll_t *list, void *elem)
{
	struct node *find = list->start;
	struct node *temp = list->start;

	find_data(list, elem, find, temp);
	if (find->data == elem && find->prev == NULL && find->next != NULL) {
		temp = find;
		find = find->next;
		find->prev = temp->prev;
		list->start = find;
		free(temp);
	}
	if (find->data == elem && find->next == NULL && find->prev == NULL) {
		list->start = NULL;
		list->end = NULL;
		free(find);
	}
	return (list);
}

void remove_end_list(dll_t *list)
{
	struct node *last = list->end;

	if (list->end != NULL) {
		list->end = last->prev;
		if (list->end != NULL)
			list->end->next = NULL;
		free(last);
	}
}
