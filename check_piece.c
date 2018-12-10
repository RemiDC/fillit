/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:11:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 14:33:57 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_piece		*corner_coord(t_piece *piece)
{
	int		x_new;
	int		y_new;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	x_new = piece->blocs[0].x;
	y_new = piece->blocs[0].y;
	while (i < 4)
	{
		piece->blocs[i] =
			set_point(piece->blocs[i].x - x_new, piece->blocs[i].y - y_new);
		++i;
	}
	return (piece);
}

int			is_diese_join(t_piece *piece, int flag, int i)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if (piece->blocs[i].x == piece->blocs[j].x &&
				piece->blocs[i].y + 1 == piece->blocs[j].y)
			++flag;
		if (piece->blocs[i].x == piece->blocs[j].x &&
				piece->blocs[i].y - 1 == piece->blocs[j].y)
			++flag;
		if (piece->blocs[i].x + 1 == piece->blocs[j].x &&
				piece->blocs[i].y == piece->blocs[j].y)
			++flag;
		if (piece->blocs[i].x - 1 == piece->blocs[j].x &&
				piece->blocs[i].y == piece->blocs[j].y)
			++flag;
		++j;
	}
	return (flag);
}

t_piece		*check_piece(t_piece *piece)
{
	int		i;
	int		flag;
	int		flag_connect;
	int		flag_connect_2;

	i = -1;
	flag_connect = 0;
	flag_connect_2 = 0;
	while (++i < 4)
	{
		flag = 0;
		flag = is_diese_join(piece, flag, i);
		if (flag == 0)
			return (free_piece(piece));
		if (flag == 2)
			++flag_connect_2;
		else if (flag == 3)
			++flag_connect;
	}
	piece = corner_coord(piece);
	if (flag_connect == 0 && flag_connect_2 == 4)
		return (piece);
	if (flag_connect != 1 && flag_connect_2 != 2)
		return (free_piece(piece));
	return (piece);
}
