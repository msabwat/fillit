/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:54:47 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/26 14:31:36 by msabwat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

static void	ft_freemap(t_map ***list)
{
	int		i;

	i = 0;
	if ((*list) != NULL)
	{
		while ((*list)[i] != NULL)
			map_dtor((*list)[i++]);
		free((*list));
		(*list) = NULL;
	}
}

void		ft_freeall(t_tetri ***list, t_map ***map_list, char ***tab)
{
	int		i;

	i = 0;
	ft_freemap(map_list);
	if (*tab != NULL)
	{
		while ((*tab)[i] != NULL)
		{
			free((*tab)[i]);
			(*tab)[i++] = NULL;
		}
		free((*tab));
	}
	i = 0;
	if ((*list) != NULL)
	{
		while ((*list)[i] != NULL)
			tetri_dtor((*list)[i++]);
		free((*list));
		(*list) = NULL;
	}
}
