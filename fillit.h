/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:58:09 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/08 05:33:54 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define NUMTETRI	26
# include <string.h>
# include "tetri.h"
# include "map.h"

int			check_valid(char **tab, t_tetri ***tetri_list, t_map ***map_list);

int			check_file_content(int fd, char ***tab);

int			**ft_strtobin(char *str);
void		ft_freeall(t_tetri ***list, t_map ***map_list, char ***tab);
void		ft_putbintab(t_map *map);
int			tetri_count(t_tetri **tab);
void		tetri_id(t_tetri *self);

void		solve(t_tetri ***tetri_list, t_map ***map_list);

int			ft_atoi_base(const char *str, int str_base);
char		*ft_itoa_base(int value, int base);
int			ft_sqrt(int nb);

#endif
