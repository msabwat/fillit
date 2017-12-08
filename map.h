/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:15:50 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/08 05:03:47 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdint.h>

typedef struct		s_map
{
	int				map_size;
	uint16_t		*tab;
}					t_map;

t_map				**map_creator(int count);

void				map_init(t_map *self, int map_size);
int					map_add_tetri(t_map *self, t_tetri *tetri);
int					map_rem_tetri(t_map *self, t_tetri *tetri);
void				map_dtor(t_map *self);

#endif
