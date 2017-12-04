/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:39:20 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 18:39:59 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str <= 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str != '\0')
	{
		if (ft_value(*str) >= 0 && ft_value(*str) < str_base)
			result = (result * str_base) + ft_value(*str);
		else
			return (0);
		str++;
		if (*str == '\0')
			return (result * sign);
	}
	return (0);
}
