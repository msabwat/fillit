/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:28:18 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 11:24:11 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

int		**ft_strtobin(char *str)
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

void	ft_freeall(t_tetri **list, char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i++] = NULL;
		}
		free(tab);
	}
	i = 0;
	if (list != NULL)
	{
		while (list[i] != NULL)
			tetri_dtor(list[i++]);
		free(list);
	}
}

void	ft_putbintab(int **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != -1)
		{
			ft_putchar((tab[i][j]) ? '#' : '.');
			j++;
		}
		i++;
		j = 0;
	}
}
