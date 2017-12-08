/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:28:07 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/07 17:38:58 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		ft_get_char(int c)
{
	if (c < 10)
		return (c + '0');
	else
		return (c - 10 + 'A');
}

char			*ft_itoa_base(int value, int base)
{
	char		*result;
	int			tab[32];
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab[0] = 0;
	while (value != 0 || i == 0)
	{
		tab[i++] = value % base;
		value = value / base;
	}
	if ((result = (char*)malloc(sizeof(char) * (32 + 2))) == 0)
		return (0);
	if (tab[--i] < 0)
		result[j++] = '-';
	while (i >= 0)
	{
		result[j++] = ft_get_char((tab[i] < 0) ? (-tab[i]) : (tab[i]));
		i--;
	}
	result[j] = '\0';
	return (result);
}
