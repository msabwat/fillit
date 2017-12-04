/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:09:18 by schaaban          #+#    #+#             */
/*   Updated: 2017/12/04 18:34:40 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_H
# define TETRI_H

typedef struct		s_tetri
{
	char			*str;
	int				**bin_tab;
	int				bin_str;
}					t_tetri;

t_tetri				**tetri_creator(int count);

void				tetri_init(t_tetri *self, char *str);
void				tetri_dtor(t_tetri *self);

#endif
