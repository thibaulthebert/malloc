/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** project malloc
*/

#include "memory.h"

char	*copy_data(size_t size, char *data)
{
	size_t	it = 0;
	char 	*new = malloc(size);

	if (new == NULL)
		return (NULL);
	while (it != size) {
		new[it] = data[it];
		it++;
	}
	return (new);
}

mdata_t	*find_equivalent(void *ptr)
{
	mdata_t	*new_elem = _data_tmp;

	if (_data_tmp->next == NULL)
		return (ptr == DATA((void *)new_elem) ? new_elem : NULL);
	while (new_elem->next != _data_tmp) {
		if (DATA((void *)new_elem) == ptr)
			break;
		new_elem = new_elem->next;
	}
	return (ptr == DATA((void *)new_elem) ? new_elem : NULL);
}

void	*realloc(void *ptr, size_t size)
{
 	mdata_t	*old_elem;
	char	*new = NULL;
	char	*data;

	if (ptr == NULL)
		return (malloc(size));
	if (ptr != NULL && size == 0){
		free(ptr);
		return (NULL);
	}
	old_elem = find_equivalent(ptr);
	if (old_elem == NULL)
		return (NULL);
	else if (old_elem->size >= size)
		return (ptr);
	new = copy_data(size, (char *)DATA((void *)old_elem));
	if (new == NULL)
		return (NULL);
	return ((void *)new);
}
