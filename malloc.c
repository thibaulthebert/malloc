/*
** EPITECH PROJECT, 2017
** Malloc
** File description:
** Malloc project file
*/

#include "memory.h"

mdata_t *_data_tmp = NULL;
void *break_point = NULL;
int page_size = 0;

void	move_sbrk_fwd(size_t size, int pos)
{
	unsigned int nb_page = 0;

	size += sizeof(mdata_t);
	size -= (page_size - pos);
	nb_page = (size / page_size) + 1;
	break_point = sbrk(nb_page * page_size) + page_size * nb_page;
}

void	*malloc_with_page(size_t size)
{
	void *address = (void *)_data_tmp;
	address += sizeof(mdata_t) + _data_tmp->size;
	mdata_t *new = (mdata_t *) address;

	new->size = size;
	if (_data_tmp->next == NULL) {
		_data_tmp->next = new;
		_data_tmp->prev = new;
		new->next = _data_tmp;
	} else {
		_data_tmp->next->prev = new;
		new->next = _data_tmp->next;
		_data_tmp->next = new;
	}
	new->prev = _data_tmp;
	_data_tmp = new;
	new->is_free = false;
	return (DATA((void *)new));
}

void	*new_malloc(size_t size)
{
	mdata_t *new = NULL;
	int pos = get_current_pos();

	if (pos + DATA(size) >= page_size)
		move_sbrk_fwd(size, pos);
	new = malloc_with_page(size);
	return (new);
}

void	*first_malloc(size_t size)
{
	mdata_t *meta_data = (mdata_t *) break_point;
	size_t nb_page = 1;
	size_t tmp = size + sizeof(mdata_t);

	while (tmp > (size_t) page_size) {
		tmp -= page_size;
		nb_page++;
	}
	break_point = sbrk(page_size * nb_page) + page_size * nb_page;
	meta_data->size = size;
	meta_data->prev = NULL;
	meta_data->next = NULL;
	meta_data->is_free = false;
	_data_tmp = meta_data;
	return (DATA((void *)meta_data));
}

void	*malloc(size_t size)
{
	void *ret = NULL;
	size_t tmp;

	size = size % 8 == 0 ? size : size + (8 - (size % 8));
	if (!_data_tmp) {
		break_point = sbrk(0);
		tmp = (size_t)break_point % 8;
		break_point = sbrk(tmp);
		page_size = getpagesize();
	}
	if (page_size <= 0)
		return (NULL);
	if (break_point == (void *) - 1 || size == 0)
		return (ret);
	ret = _data_tmp ? new_malloc(size) : first_malloc(size);
	return (ret);
}
