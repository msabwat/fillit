/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:15:47 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 18:45:36 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		**solve(t_tetri **tetri_list)
{
	int		**result;

	result = NULL;
	ft_putnbr(tetri_list[0]->bin_str);
	tetri_list++;
	tetri_list--;
	return (result);
}
