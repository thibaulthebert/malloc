/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** show alloc mem function
*/

#include "memory.h"

void	print_data_infos(mdata_t *tmp)
{
	long address = (long)tmp;

	my_putstr("0x");
	my_putnbr_hex(address + sizeof(mdata_t));
	my_putstr(" - 0x");
	my_putnbr_hex(address + sizeof(mdata_t) + tmp->size);
	my_putstr(" : ");
	my_putnbr(tmp->size);
	my_putstr(" bytes\n");
}

void	show_alloc_mem(void)
{
	long address = (long)break_point;
	mdata_t	*tmp = _data_tmp && _data_tmp->next ?
			_data_tmp->next : _data_tmp;

	my_putstr("break : 0x");
	my_putnbr_hex(address);
	my_putchar('\n');
	if (!tmp)
		return;
	else if (tmp && tmp == _data_tmp)
		print_data_infos(tmp);
	else {
		while (tmp != _data_tmp) {
			if (!(tmp->is_free))
				print_data_infos(tmp);
			tmp = tmp->next;
		}
		if (!(tmp->is_free))
			print_data_infos(tmp);
	}
}