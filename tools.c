/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:28:18 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/08 05:28:21 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

int			**ft_strtobin(char *str)
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

void		ft_putbintab(t_map *map)
{
	int		i;
	int		t;
	char	*str;

	i = 0;
	t = 0;
	if (map->tab == NULL)
		return ;
	while (i < map->map_size)
	{
		str = ft_itoa_base(map->tab[i], 2);
		while ((ft_strlen(str) + t++) < (size_t)map->map_size)
			ft_putchar('0');
		ft_putendl(str);
		free(str);
		i++;
		t = 0;
	}
}

int			tetri_count(t_tetri **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	return (i);
}

static void	ft_settetri(t_tetri *self, int width, int height)
{
	self->width = width;
	self->height = height;
}

void		tetri_id(t_tetri *self)
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
