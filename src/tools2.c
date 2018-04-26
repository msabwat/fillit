/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabwat <msabwat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:36:46 by msabwat           #+#    #+#             */
/*   Updated: 2018/04/26 14:33:01 by msabwat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

static char			*fill_line(char *str, int map_size, char l)
{
	char	*new_str;
	int		size;
	int		i;

	i = 0;
	size = map_size - ft_strlen(str);
	if (!(new_str = ft_strnew(size + 1)))
		return (NULL);
	new_str[size] = '\0';
	while (i < size)
		new_str[i++] = '.';
	ft_strcat(new_str, str);
	i = 0;
	while (i < map_size)
	{
		if (new_str[i] == '1')
			new_str[i] = l;
		else
			new_str[i] = '.';
		i++;
	}
	return (new_str);
}

static char			**fill(t_map *map, char **str, int index_sol)
{
	char	*temp;
	int		i;

	i = 0;
	if (map->tab == NULL)
		return (NULL);
	while (i < map->map_size)
	{
		temp = ft_itoa_base(map->tab[i], 2);
		str[i] = fill_line(temp, map->map_size, 'A' + index_sol);
		free(temp);
		i++;
	}
	return (str);
}

char				**fillit(int i, char **tab, char **temp, t_map *map_list)
{
	int j;
	int t;

	if (i == 0)
		tab = fill(map_list, tab, i);
	else if (i > 0)
	{
		temp = fill(map_list, temp, i);
		j = 0;
		while (temp[j] != NULL)
		{
			t = 0;
			while (temp[j][t])
			{
				if (!ft_isalpha(tab[j][t]))
					tab[j][t] = temp[j][t];
				t++;
			}
			j++;
		}
	}
	return (tab);
}
