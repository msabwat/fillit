/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:42:21 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 11:48:58 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "tetri.h"
#include "libft/libft.h"

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

static int	ck_check_tetri(t_tetri *tt)
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
			if ((links = ck_check_value(tt->bin_tab, i, j)) >= 2)
				if ((double_links += (links - 1)) == 2)
					return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

t_tetri		**check_valid(char **tab)
{
	int			i;
	t_tetri		**tetri_list;

	i = 0;
	while (tab[i] != NULL)
		i++;
	tetri_list = tetri_creator(i);
	i = -1;
	while (tetri_list[++i] != NULL)
	{
		tetri_init(tetri_list[i], ft_strdup(tab[i]));
		if (!(ck_check_tetri(tetri_list[i])))
		{
			ft_freeall(tetri_list, tab);
			return (NULL);
		}
	}
	return (tetri_list);
}
