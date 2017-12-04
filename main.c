/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:03:44 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 11:17:28 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include "tetri.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

static int		error_handler(void)
{
	ft_putendl("error");
	return (0);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		**tab;
	t_tetri		**tetri_list;

	if (argc != 2)
		return (error_handler());
	fd = open(argv[1], 'r');
	if (!(tab = check_file_content(fd)))
		return (error_handler());
	if (!(tetri_list = check_valid(tab)))
		return (error_handler());
	ft_putbintab(solve(tetri_list));
	ft_freeall(tetri_list, tab);
	close(fd);
	return (0);
}
