/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:58:09 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 18:40:14 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include "tetri.h"

t_tetri		**check_valid(char **tab);

char		**check_file_content(int fd);

int			**ft_strtobin(char *str);
void		ft_freeall(t_tetri **list, char **tab);
void		ft_putbintab(int **tab);

int			**solve(t_tetri **tetri_list);

int			ft_atoi_base(const char *str, int str_base);

#endif
