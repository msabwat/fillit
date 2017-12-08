/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:15:47 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/08 06:04:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "solve_def.h"
#include "libft/libft.h"
#include <stdlib.h>

static void		concat_maps(t_map *m1, t_map **m2)
{
	int		i;

	i = 0;
	while (i < 12)
	{
		(*m2)->tab[i] = m1->tab[i];
		i++;
	}
}

static int		solve_map(t_tetri ***tetri_list, t_map ***map_list, int i)
{
	int		res;

	res = 0;
	if (A_TETRI == NULL)
		return (1);
	if (i > 0)
		concat_maps((*map_list)[i - 1], &A_MAP);
	A_TETRI->x = 0;
	A_TETRI->y = 0;
	while (A_TETRI->y + A_TETRI->height <= A_MAP->map_size)
	{
		A_TETRI->x = 0;
		while (A_TETRI->x + A_TETRI->width <= A_MAP->map_size)
		{
			if ((res = map_add_tetri(A_MAP, A_TETRI)) == 1)
				if (solve_map(&(*tetri_list), &(*map_list), i + 1) == 1)
					return (1);
			A_TETRI->x++;
		}
		A_TETRI->y++;
	}
	if (i > 0)
		map_rem_tetri((*map_list)[i - 1], (*tetri_list)[i - 1]);
	return (0);
}

static char		**print_solution(t_map **map_list, int map_size)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	map_list = NULL;
	if ((tab = (char**)malloc(sizeof(char*) * (map_size + 1))) == NULL)
		return (NULL);
	while (i < map_size)
	{
		j = 0;
		if ((tab[i] = ft_strnew(map_size)) == NULL)
			return (NULL);
		while (j < map_size)
			tab[i][j++] = '.';
		i++;
	}
	tab[i] = NULL;
	i = 0;
	while (tab[i] != NULL)
		
	return (tab);
}

static void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

void			solve(t_tetri ***tetri_list, t_map ***map_list)
{
	int		i;
	int		prev_ms;
	char	**tab;

	i = 0;
	prev_ms = (*map_list)[0]->map_size;
	while (!solve_map(tetri_list, map_list, 0))
	{
		prev_ms++;
		while (A_MAP != NULL)
		{
			free(A_MAP->tab);
			map_init(A_MAP, prev_ms);
			i++;
		}
		i = 0;
	}
	if (!(tab = print_solution((*map_list), (*(*map_list))->map_size)))
		return ;
	i = 0;
	while (tab[i] != NULL)
		ft_putendl(tab[i++]);
	free_tab(tab);
}
