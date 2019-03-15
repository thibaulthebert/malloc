/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** project malloc
*/

#include "memory.h"

size_t	get_total_size() {
	size_t	total_size = 0;
	mdata_t	*elem = _data_tmp;

	while (elem->next != _data_tmp) {
		total_size += sizeof(elem) + elem->size;
		elem = elem->next;
	}
	return (total_size + 1);
}
