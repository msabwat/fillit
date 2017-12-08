/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:19:58 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/08 04:10:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

t_tetri		**tetri_creator(int count)
{
	t_tetri		**tab;
	int			i;

	i = 0;
	if ((tab = (t_tetri**)malloc(sizeof(t_tetri*) * (count + 1))) == NULL)
		return (NULL);
	while (i < count)
	{
		if ((tab[i] = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		tetri_init(t_tetri *self, char *str)
{
	int		i;

	i = -1;
	if (str == NULL)
		return ;
	while (str[++i] != '\0')
		str[i] = (str[i] == '#') ? '1' : '0';
	self->bin = (uint16_t)ft_atoi_base(str, 2);
	self->x = 0;
	self->y = 0;
	tetri_upleft(self);
	tetri_id(self);
	free(str);
}

void		tetri_upleft(t_tetri *self)
{
	self->bin = self->bin;
	while ((self->bin & 0xf000) == 0)
		self->bin = self->bin << 4;
	while ((self->bin & 0x8888) == 0)
		self->bin = self->bin << 1;
}

uint16_t	tetri_good(t_tetri *self, int map_size, int index)
{
	uint16_t	mask;
	uint16_t	tetri_line;

	mask = 0xf000 >> (index * 4);
	tetri_line = self->bin & mask;
	tetri_line = tetri_line >> (((3 - index) * 4) + (4 - self->width));
	tetri_line = tetri_line << (map_size - self->x - self->width);
	return (tetri_line);
}

void		tetri_dtor(t_tetri *self)
{
	if (self != NULL)
	{
		free(self);
		self = NULL;
	}
}
