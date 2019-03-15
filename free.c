/*
** EPITECH PROJECT, 2017
** malloc/free
** File description:
** projet malloc
*/

#include "memory.h"

void	abort_program()
{
	show_alloc_mem();
	abort();
}

void	move_sbrk(mdata_t *ptr)
{
	size_t	nb_delete = 0;

	nb_delete = (ptr->size + sizeof(mdata_t)) / page_size;
	sbrk(-(nb_delete * page_size));
}

void	free_action(mdata_t *elem)
{
	mdata_t *tmp = _data_tmp;

	elem->is_free = true;
	_data_tmp = elem->prev;
	if (tmp->prev != NULL && elem == tmp) {
		_data_tmp->next = elem->next;
		elem->next->prev = _data_tmp;
		move_sbrk(elem);
	}
}

void	free_well(mdata_t *elem)
{
	if (elem == _data_tmp) {
		free_action(elem);
	}
	else {
		elem->is_free = !(elem->is_free);
	}
}

void	free(void *ptr)
{
	mdata_t	*elem = _data_tmp;

	if (ptr == NULL)
		return;
	if (elem->next == NULL) {
		if (DATA((void *)elem) == ptr) {
			free_well(elem);
			return;
		}
		abort_program();
	}
	while (elem->next != _data_tmp) {
		if (DATA((void *)elem) == ptr) {
			free_well(elem);
			return;
		}
		elem = elem->next;
	}
	DATA((void *)elem) != ptr ? abort_program() : free_well(elem);
}