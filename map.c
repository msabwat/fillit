/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:30:58 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/08 05:33:02 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

t_map		**map_creator(int count)
{
	t_map		**tab;
	int			i;

	i = 0;
	if ((tab = (t_map**)malloc(sizeof(t_map*) * (count + 1))) == NULL)
		return (NULL);
	while (i < count)
	{
		if ((tab[i] = (t_map*)malloc(sizeof(t_map))) == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		map_init(t_map *self, int map_size)
{
	int		i;

	i = 0;
	self->map_size = map_size;
	if ((self->tab = (uint16_t*)malloc(sizeof(uint16_t) * 12)) == NULL)
		return ;
	while (i < 12)
	{
		self->tab[i] = 0;
		i++;
	}
}

int			map_add_tetri(t_map *self, t_tetri *tetri)
{
	uint16_t	tetri_map_value;
	int			i;

	i = 0;
	while (i < tetri->height)
	{
		if ((tetri_good(tetri, self->map_size, i)
			& self->tab[i + tetri->y]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < tetri->height)
	{
		tetri_map_value = tetri_good(tetri, self->map_size, i);
		self->tab[i + tetri->y] = tetri_map_value | self->tab[i + tetri->y];
		i++;
	}
	return (1);
}

int			map_rem_tetri(t_map *self, t_tetri *tetri)
{
	uint16_t	tetri_map_value;
	int			i;

	i = 0;
	while (i < tetri->height)
	{
		tetri_map_value = tetri_good(tetri, self->map_size, i);
		self->tab[i + tetri->y] = self->tab[i + tetri->y] - tetri_map_value;
		i++;
	}
	return (1);
}

void		map_dtor(t_map *self)
{
	if (self != NULL)
	{
		if (self->tab != NULL)
		{
			free(self->tab);
			self->tab = NULL;
		}
		free(self);
		self = NULL;
	}
}
