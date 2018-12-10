/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:45:37 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 11:08:49 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_fillit	*all;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (1);
	}
	if (!(all = (t_fillit*)malloc(sizeof(t_fillit))))
		return (error(all));
	if (init_all(all) == 1)
		return (error(all));
	if (!(all == open_file(av[1], all)))
	{
		free_map(all);
		return (error(all));
	}
	if (fillit(all) == 1)
	{
		free_map(all);
		return (error(all));
	}
	print_result(all);
	free_map(all);
	free(all);
	return (0);
}
