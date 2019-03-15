/*
** EPITECH PROJECT, 2017
** Malloc
** File description:
** Utils funcs for malloc
*/

#include "memory.h"

int	get_current_pos(void)
{
	mdata_t *tmp = _data_tmp;
	size_t size = 0;

	if (tmp->next == NULL)
		return ((tmp->size + sizeof(mdata_t)) % page_size);
	while (tmp->next != _data_tmp) {
		size += tmp->size + sizeof(mdata_t);
		tmp = tmp->next;
	}
	size += tmp->size + sizeof(mdata_t);
	return (size % page_size);
}