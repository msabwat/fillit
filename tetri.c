/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:19:58 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 11:44:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri.h"
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
		tab[i]->str = NULL;
		tab[i]->bin_tab = NULL;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		tetri_init(t_tetri *self, char *str)
{
	self->str = str;
	self->bin_tab = ft_strtobin(str);
}

void		tetri_dtor(t_tetri *self)
{
	int		i;

	i = -1;
	if (self != NULL)
	{
		if (self->str != NULL)
			free(self->str);
		if (self->bin_tab != NULL)
		{
			while (self->bin_tab[++i] != NULL)
				free(self->bin_tab[i]);
			free(self->bin_tab);
		}
		self->str = NULL;
		self->bin_tab = NULL;
		free(self);
		self = NULL;
	}
}
