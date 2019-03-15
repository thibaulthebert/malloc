/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** utils functions
*/

#include "memory.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_strlen(char *str)
{
	int	it = 0;

	while (str[it] != '\0')
		it++;
	return (it);
}

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

void	my_putnbr(size_t nb)
{
	int div;

	if (nb < 0) {
		nb *= -1;
		my_putchar('-');
	}
	if (nb >= 10) {
		div = nb % 10;
		nb /= 10;
		my_putnbr(nb);
		my_putchar(div + 48);
	}
	else
		my_putchar(nb + 48);
}

void	my_putnbr_hex(size_t nb)
{
	char *base = "0123456789ABCDEF";
	int tmp = nb % 16;

	nb /= 16;
	if (nb > 0)
		my_putnbr_hex(nb);
	my_putchar(base[tmp]);
}