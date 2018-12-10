/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:03:54 by reda-con          #+#    #+#             */
/*   Updated: 2018/12/05 12:45:43 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_point		set_point(int x, int y)
{
	t_point		ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_point		next_pos(t_point act_pos, t_fillit *data)
{
	t_point	ret;
	int		i;
	int		j;

	ret = set_point(-1, -1);
	i = act_pos.y;
	j = act_pos.x + 1;
	while (i < data->max_pos)
	{
		while (j < data->max_pos)
		{
			if (data->map[j][i] == '.')
			{
				ret.x = j;
				ret.y = i;
				return (ret);
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (ret);
}
