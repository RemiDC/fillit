/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:32:50 by reda-con          #+#    #+#             */
/*   Updated: 2018/12/07 08:08:21 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	fill(t_fillit *data, int piece, t_point act_pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		data->map[act_pos.x + data->pieces[piece].blocs[i].x]\
			[act_pos.y + data->pieces[piece].blocs[i].y] =\
			data->pieces[piece].alphabet;
		++i;
	}
}

int		if_place(t_fillit *data, int piece, int i, t_point act_pos)
{
	if ((act_pos.x + (data->pieces[piece].blocs[i]).x >= data->max_pos ||\
			act_pos.y + data->pieces[piece].blocs[i].y >= data->max_pos) ||\
			(act_pos.x + data->pieces[piece].blocs[i]. x < 0 ||\
			act_pos.y + data->pieces[piece].blocs[i].y < 0))
		return (1);
	if (data->map[act_pos.x + data->pieces[piece].blocs[i].x]\
			[act_pos.y + data->pieces[piece].blocs[i].y] != '.')
		return (1);
	return (0);
}

int		check_place(t_fillit *data, int piece, t_point act_pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (if_place(data, piece, i, act_pos))
			return (1);
		++i;
	}
	return (0);
}

int		real_fill(t_fillit *data, int ct, t_point act_pos)
{
	if (ct == data->nb_piece)
		return (0);
	if (act_pos.y < 0)
		return (1);
	if (!check_place(data, ct, act_pos))
	{
		fill(data, ct, act_pos);
		if (!real_fill(data, ct + 1, set_point(0, 0)))
			return (0);
		data->map = refill_dot(data->max_pos, data->map,\
				data->pieces[ct].alphabet);
	}
	return (real_fill(data, ct, next_pos(act_pos, data)));
}

int		fillit(t_fillit *data)
{
	t_point		act_pos;

	act_pos = set_point(0, 0);
	while (real_fill(data, 0, act_pos))
	{
		++data->max_pos;
		free_map(data);
		if (!(data->map = init_map(data)))
			return (1);
	}
	return (0);
}
