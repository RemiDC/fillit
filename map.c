/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:52:04 by reda-con          #+#    #+#             */
/*   Updated: 2018/12/06 15:24:16 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	free_map(t_fillit *data)
{
	int		i;

	i = 0;
	while (i < data->max_pos)
	{
		free(data->map[i]);
		++i;
	}
	free(data->map);
}

char	**refill_dot(int size, char **mao, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (mao[i][j] == c)
				mao[i][j] = '.';
			++j;
		}
		++i;
	}
	return (mao);
}

char	**write_map_dot(int size, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			++j;
		}
		map[i][j] = '\0';
		++i;
	}
	map[i] = NULL;
	return (map);
}

char	**init_map(t_fillit *data)
{
	int		i;

	i = 0;
	if (!(data->map = (char**)malloc(sizeof(char*) * (data->max_pos + 1))))
	{
		free(data->map);
		return (NULL);
	}
	while (i < data->max_pos)
	{
		if (!(data->map[i] = (char*)malloc(sizeof(char) * (data->max_pos + 1))))
		{
			free_map(data);
			return (NULL);
		}
		++i;
	}
	data->map = write_map_dot(data->max_pos, data->map);
	return (data->map);
}

int		init_all(t_fillit *data)
{
	data->max_pos = 2;
	if (!(data->map = init_map(data)))
		return (1);
	return (0);
}
