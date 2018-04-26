/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:09:18 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/07 20:05:24 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_H
# define TETRI_H
# include <stdint.h>

typedef struct		s_tetri
{
	int				x;
	int				y;
	int				width;
	int				height;
	uint16_t		bin;
}					t_tetri;

t_tetri				**tetri_creator(int count);

void				tetri_init(t_tetri *self, char *str);
void				tetri_upleft(t_tetri *self);
uint16_t			tetri_good(t_tetri *self, int map_size, int index);
void				tetri_dtor(t_tetri *self);

#endif
