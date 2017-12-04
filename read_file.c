/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:59:22 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/30 16:08:48 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_one_line.h"
#include "libft/libft.h"
#include <stdlib.h>

static char		*rf_read_file(int fd)
{
	char	*str;
	char	*line;
	char	*tmp;

	str = NULL;
	while ((get_one_line(fd, &line)) == 1)
	{
		if (ft_strlen(line) != 1 && ft_strlen(line) != 5)
		{
			free(line);
			return (NULL);
		}
		tmp = str;
		if (ft_strlen(line) == 5)
		{
			line[4] = '\0';
			str = ft_strjoin(str, line);
		}
		else if (ft_strlen(line) == 1)
			str = ft_strjoin(str, "O");
		if (tmp != NULL)
			free(tmp);
		free(line);
	}
	return (str);
}

static char		*rf_check_tetriminos(char *str)
{
	int		i;
	int		count_sha;
	int		count_dot;

	i = -1;
	count_dot = 0;
	count_sha = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 'O')
		{
			if (count_sha != 4 || count_dot != 12)
				return (NULL);
			count_dot = 0;
			count_sha = 0;
		}
		else if (str[i] == '.')
			count_dot++;
		else if (str[i] == '#')
			count_sha++;
		else
			return (NULL);
	}
	return ((count_sha != 4 || count_dot != 12) ? NULL : str);
}

char			**check_file_content(int fd)
{
	char	*str;
	char	**tab;

	if (!(str = rf_read_file(fd)))
		return (NULL);
	str = rf_check_tetriminos(str);
	if (str == NULL)
		return (NULL);
	tab = ft_strsplit(str, 'O');
	free(str);
	return (tab);
}
