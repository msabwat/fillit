/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:42:21 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/07 22:03:32 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

static int	ck_check_value(int **tab, int i, int j)
{
	int		links;

	links = 0;
	if (tab[i][j] == 1)
	{
		if (i - 1 >= 0)
			links += (tab[i - 1][j]);
		if (i + 1 < 4)
			links += (tab[i + 1][j]);
		if (j - 1 >= 0)
			links += (tab[i][j - 1]);
		if (j + 1 < 4)
			links += (tab[i][j + 1]);
	}
	return (links);
}

static int	ck_check_tetri(int **tab)
{
	int		i;
	int		j;
	int		links;
	int		double_links;

	i = 0;
	j = 0;
	links = 0;
	double_links = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if ((links = ck_check_value(tab, i, j)) >= 2)
				if ((double_links += (links - 1)) == 2)
					return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

static int	free_bintab(int ***bin_tab)
{
	int		i;

	i = 0;
	if ((*bin_tab) != NULL)
	{
		while (i < 4)
			free((*bin_tab)[i++]);
		free((*bin_tab));
	}
	return (0);
}

int			check_valid(char **tab, t_tetri ***tetri_list, t_map ***map_list)
{
	int			i;
	int			tetri_cnt;
	int			**bin_tab;

	tetri_cnt = 0;
	while (tab[tetri_cnt] != NULL)
		tetri_cnt++;
	*tetri_list = tetri_creator(tetri_cnt);
	*map_list = map_creator(tetri_cnt);
	i = -1;
	while ((*map_list)[++i] != NULL)
		map_init((*map_list)[i], ft_sqrt(tetri_cnt * 4));
	i = -1;
	while ((*tetri_list)[++i] != NULL)
	{
		tetri_init((*tetri_list)[i], ft_strdup(tab[i]));
		bin_tab = ft_strtobin(tab[i]);
		if (!(ck_check_tetri(bin_tab)))
			return (free_bintab(&bin_tab));
		free_bintab(&bin_tab);
	}
	return ((tetri_cnt > NUMTETRI) ? 0 : 1);
}
