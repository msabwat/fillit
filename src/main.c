/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:03:44 by schaaban          #+#    #+#             */
/*   Updated: 2018/04/26 14:32:09 by msabwat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

static int		error_handler(t_tetri **tetri_list,
	t_map **map_list, char **tab)
{
	ft_freeall(&tetri_list, &map_list, &tab);
	ft_putendl("error");
	return (0);
}

static int		error_usage(t_tetri **tetri_list,
	t_map **map_list, char **tab)
{
	ft_freeall(&tetri_list, &map_list, &tab);
	ft_putendl("usage: fillit source_file");
	return (0);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		**tab;
	t_tetri		**tetri_list;
	t_map		**map_list;

	if (argc != 2)
		return (error_usage(NULL, NULL, NULL));
	if ((fd = open(argv[1], 'r')) < 0)
		return (error_handler(NULL, NULL, NULL));
	if (!(check_file_content(fd, &tab)))
		return (error_handler(NULL, NULL, tab));
	if (!(check_valid(tab, &tetri_list, &map_list)))
		return (error_handler(tetri_list, map_list, tab));
	solve(&tetri_list, &map_list);
	ft_freeall(&tetri_list, &map_list, &tab);
	close(fd);
	return (0);
}
