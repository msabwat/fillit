/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:28:18 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/26 14:32:48 by msabwat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

int				**ft_strtobin(char *str)
{
	int		i;
	int		j;
	int		**tab;

	i = 0;
	j = 0;
	if ((tab = (int**)malloc(sizeof(int*) * 5)) == NULL)
		return (NULL);
	while (i < 4)
	{
		if ((tab[i] = (int*)malloc(sizeof(int) * 4)) == NULL)
			return (NULL);
		while (j < 4)
		{
			tab[i][j] = (str[j + (i * 4)] == '#') ? 1 : 0;
			j++;
		}
		i++;
		j = 0;
	}
	tab[i] = NULL;
	return (tab);
}

int				tetri_count(t_tetri **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	return (i);
}

static void		ft_settetri(t_tetri *self, int width, int height)
{
	self->width = width;
	self->height = height;
}

void			tetri_id(t_tetri *self)
{
	uint16_t	i;

	i = self->bin;
	if (i == 34952)
		ft_settetri(self, 1, 4);
	else if (i == 61440)
		ft_settetri(self, 4, 1);
	else if (i == 52224)
		ft_settetri(self, 2, 2);
	else if (i == 51328 || i == 17600 || i == 35968 || i == 19520 ||
		i == 19584 || i == 35904 || i == 35008 || i == 50240)
		ft_settetri(self, 2, 3);
	else
		ft_settetri(self, 3, 2);
}
