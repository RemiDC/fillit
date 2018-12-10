/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:06:49 by reda-con          #+#    #+#             */
/*   Updated: 2018/12/07 11:43:18 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>

t_piece		*free_piece(t_piece *piece)
{
	free(piece);
	return (NULL);
}

void		print_result(t_fillit *final)
{
	int		i;
	int		y;

	i = 0;
	while (i < final->max_pos)
	{
		y = 0;
		while (y < final->max_pos)
		{
			ft_putchar(final->map[y][i]);
			++y;
		}
		ft_putchar('\n');
		++i;
	}
}

int			error(t_fillit *all)
{
	ft_putendl("error");
	free(all);
	return (1);
}

t_fillit	*norme(int fd, char *buff, int flag, t_fillit *all)
{
	free(buff);
	close(fd);
	if (flag == 0)
		return (all);
	return (NULL);
}
