/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:04:12 by schaaban          #+#    #+#             */
/*   Updated: 2017/11/30 16:04:25 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ONE_LINE_H
# define GET_ONE_LINE_H

# include <string.h>
# define BUFF_SIZE	1000

typedef struct	s_line
{
	int				fd;
	char			*content;
	struct s_line	*next;
}				t_line;

int				get_one_line(const int fd, char **line);

#endif
