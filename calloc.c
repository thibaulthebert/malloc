/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Calloc file
*/

#include "memory.h"

void	*calloc(size_t nmemb, size_t size)
{
	char *new = NULL;
	size_t i = 0;

	if (size == 0)
		return (new);
	new = malloc(nmemb * size);
	if (new == NULL)
		return (new);
	while (i <= nmemb * size) {
		new[i] = 0;
		i++;
	}
	return (new);
}